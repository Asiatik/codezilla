package BST;
/**
 * @author Ionesio Junior
 * */
import java.util.ArrayList;
import java.util.List;
/**
 * Binary Search Tree Implementation
 * */
public class BST<T extends Comparable<T>> implements BSTInterface<T> {
	//Attributes
	private Node<T> root;
	/**
	 * BST Constructor
	 * */
	public BST(){
		this.root = new Node<T>();
	}
	
	@Override
	public boolean isEmpty() {
		return this.root.getData() == null;
	}

	@Override
	public void insert(T element) {
		if(element == null)
			return;
		else{
			recursiveInsert(element,this.root,this.root.getParent());
		}
	}

	protected void recursiveInsert(T element,Node<T> node,Node<T> parent){
		if(!node.isNIL()){
			if(node.getData().equals(element)) return;
			if(node.getData().compareTo(element)> 0){
				recursiveInsert(element,node.getLeft(),node);
			}else{
				recursiveInsert(element,node.getRight(),node);
			}
		}else{
			node.setData(element);
			node.setRight(new Node<T>());
			node.setLeft(new Node<T>());
			node.setParent(parent);
		}
	}

	@Override
	public void remove(T element) {
		Node<T> foundNode = search(element);
		if(foundNode == new Node<T>()){
			return;
		}else{
			recursiveRemove(foundNode);
		}
	}
	protected void recursiveRemove(Node<T> node){
		if(node.isLeaf()){
			node.setData(null);
			node.setLeft(null);
			node.setRight(null);
		}else if(node.getLeft().isNIL()){
			node.setData(node.getRight().getData());
			node.getRight().getRight().setParent(node);
			node.getRight().getLeft().setParent(node);
			node.setLeft(node.getRight().getLeft());
			node.setRight(node.getRight().getRight());
		}else if(node.getRight().isNIL()){
			node.setData(node.getLeft().getData());
			node.getLeft().getRight().setParent(node);
			node.getLeft().getLeft().setParent(node);
			node.setRight(node.getLeft().getRight());
			node.setLeft(node.getLeft().getLeft());
		}else{
			T removedValue = node.getData();
			Node<T> sucessor = sucessor(removedValue);
			node.setData(sucessor.getData());
			sucessor.setData(removedValue);
			recursiveRemove(sucessor);
		}
	}

	@Override
	public int height() {
		return recursiveHeight(this.root) - 1;
	}
	public int recursiveHeight(Node<T> node){
		if(!node.isNIL()){
			int leftHeight = recursiveHeight(node.getLeft());
			int rightHeight = recursiveHeight(node.getRight());
			if(leftHeight > rightHeight){
				return leftHeight + 1;
			}else{
				return rightHeight + 1; 
			}
		}else{
			return 0;
		}
	}
	@Override
	public int size() {
		return recursiveSize(this.root);
	}
	private int recursiveSize(Node<T> node){
		if(!node.isNIL()){
			return 1 + recursiveSize(node.getLeft()) + recursiveSize(node.getRight());
		}else{
			return 0;
		}
	}

	@Override
	public Node<T> search(T element) {
		if(element == null || this.root.isNIL())
			return new Node<T>();
		else{
			return recursiveSearch(element,this.root);
		}
	}
	private Node<T> recursiveSearch(T element,Node<T> node){
		if(!node.isNIL()){
			if(node.getData().equals(element)){
				return node;
			}else if(node.getData().compareTo(element) > 0){
				return recursiveSearch(element,node.getLeft());
			}else{
				return recursiveSearch(element,node.getRight());
			}
		}
		return node;
	}
	
	@Override
	public Node<T> maximum() {
		if(size() == 0){
			return null;
		}else{
			return recursiveMaximum(this.root);
		}
	}
	
	protected Node<T> recursiveMaximum(Node<T> node){
		if(!node.getRight().isNIL()){
			return recursiveMaximum(node.getRight());
		}else{
			return node;
		}
	}

	@Override
	public Node<T> minimum() {
		if(size() == 0){
			return null;
		}else{
			return recursiveMinimum(this.root);
		}
	}
	
	protected Node<T> recursiveMinimum(Node<T> node){
		if(!node.getLeft().isNIL()){
			return recursiveMinimum(node.getLeft());
		}else{
			return node;
		}
	}
	
	@Override
	public Node<T> predecessor(T element) {
		Node<T> foundNode = search(element);
		
		if(foundNode.isNIL()){
			return null;
		}else if(!foundNode.getLeft().isNIL()){
			return recursiveMaximum(foundNode.getLeft());
		}else{
			Node<T> parent = foundNode.getParent();
			while(parent != null && !foundNode.equals(parent.getRight())){
				parent = parent.getParent();
				foundNode = foundNode.getParent();
			}
			return parent;
		}
	}

	@Override
	public Node<T> sucessor(T element) {
		Node<T> foundNode = search(element);
		if(foundNode.isNIL()){
			return null;
		}else if(!foundNode.getRight().isNIL()){
			return recursiveMinimum(foundNode.getRight());
		}else{
			Node<T> parent = foundNode.getParent();
			while(parent != null && !foundNode.equals(parent.getLeft())){
				parent = parent.getParent();
				foundNode = foundNode.getParent();
			}
			return parent;
		}
	}

	
	
	
	
	
	@Override
	public Node<T> getRoot() {
		return this.root;
	}

	@Override
	public T[] toArrayPreOrder() {
		T[] array = (T[]) new Comparable[this.size()];
		List<T> arrayList = new ArrayList<T>();
		recursivePreOrder(this.root,arrayList);
		for(int i = 0 ; i < arrayList.size();i++){
			array[i] = arrayList.get(i);
		}
		return array;
	}
	private void recursivePreOrder(Node<T> node,List list){
		if(!node.isNIL()){
			list.add(node.getData());
			recursivePreOrder(node.getLeft(),list);
			recursivePreOrder(node.getRight(),list);
		}
	}

	@Override
	public T[] toArrayOrder() {
		T[] array = (T[]) new Comparable[this.size()];
		List<T> arrayList = new ArrayList<T>();
		recursiveOrder(this.root,arrayList);
		for(int i = 0 ; i < arrayList.size();i++){
			array[i] = arrayList.get(i);
		}
		return array;
		
	}
	private void recursiveOrder(Node<T> node,List list){
		if(!node.isNIL()){
			recursiveOrder(node.getLeft(),list);
			list.add(node.getData());
			recursiveOrder(node.getRight(),list);
		}
	}
	@Override
	public T[] toArrayPostOrder() {
		T[] array = (T[]) new Comparable[this.size()];
		List<T> arrayList = new ArrayList<T>();
		recursiveOrder(this.root,arrayList);
		for(int i = 0 ; i < arrayList.size();i++){
			array[i] = arrayList.get(i);
		}
		return array;
		
	}
	private void recursivePostOrder(Node<T> node,List list){
		if(!node.isNIL()){
			recursivePostOrder(node.getLeft(),list);
			recursivePostOrder(node.getRight(),list);
			list.add(node.getData());
		}
	}
	protected void setRoot(Node<T> newRoot){
		this.root = newRoot;
	}
}