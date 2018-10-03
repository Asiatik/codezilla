package BST;
/**
 * @author Ionesio Junior
 * */

/**
 * Binary Search Tree Interface
 * */
public interface BSTInterface<T> {
	/**
	 * Search an element in a binary search tree structure
	 * @return Node with element
	 * */
	public Node<T> search(T element);
	/**
	 * Insert an element in a binary search tree
	 * @param element
	 * */
	public void insert(T element);
	/**
	 * Remove an element in a binary search tree
	 * */
	public void remove(T element);
	/**
	 * Get node with the predecessor of data element
	 * @return Node with predecessor
	 * */
	public Node<T> predecessor(T element);
	/**
	 * Get node with the sucessor of data element
	 * @return Node with sucessor
	 * */
	public Node<T> sucessor(T element);
	/**
	 * Return Root Node
	 * @return Node root
	 * */
	public Node<T> getRoot();
	/**
	 * Return True if binary search tree is empty or False if not
	 * */
	public boolean isEmpty();
	/**
	 * Return node with maximum data value in binary search tree
	 * @return Node maximum
	 * */
	public Node<T> maximum();
	/**
	 * Return node with minimum data value in binary search tree
	 * @return minimum
	 * */
	public Node<T> minimum();
	/**
	 * Return array with bst elements in order(left , root, right)
	 * @return Ordered array
	 * */
	public T[] toArrayOrder();
	/**
	 * Return array with bst elements in pre order(root,left,right)
	 * @return Pre Order array
	 * */
	public T[] toArrayPreOrder();
	/**
	 * Return array with bst elements in post order(left,right,root)
	 * @return Post Order array
	 * */
	public T[] toArrayPostOrder();
	/**
	 * Return number of elements in Binary Search Tree
	 * @return size
	 * */
	public int size();
	/**
	 * Return max height of Binary Search Tree
	 * @return height
	 * */
	public int height();

}
