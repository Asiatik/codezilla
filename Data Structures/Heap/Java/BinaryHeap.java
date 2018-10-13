package Heap;
/**
 * @author Ionesio Junior
 * */

/**
 * Binary Heap Implementation
 * */

public class BinaryHeap<T extends Comparable<T>> implements HeapInterface<T> {
	private T[] array;
	private int index;
	
	public BinaryHeap(){
		this.array = (T[]) new Comparable[10];
		this.index = -1;
	}
	
	@Override
	public boolean isEmpty() {
		return index  < 0;
	}
	
	@Override
	public void insert(T element) {
		if(this.isFull()){
			responsiveArray();
		}
		if(element != null){
			this.array[++index] = element;
			int i = index;
			while(i > 0 && this.array[this.parent(i)].compareTo(this.array[i]) < 0){
				T aux = this.array[i];
				this.array[i] = this.array[this.parent(i)];
				this.array[this.parent(i)] = aux;
				i = parent(i);
			}
		}
	}

	@Override
	public T extractRoot() throws HeapUnderflowException{
		if(size() < 1){
			throw new HeapUnderflowException();
		}
		T removedElement = this.array[0];
		this.array[0] = this.array[index--];
		heapify(array, 0);
		return removedElement;
	}
	
	@Override
	public T rootElement() {
		if(this.size() >= 1){
			return this.array[0];
		}else{
			return null;
		}
	}

	@Override
	public T[] heapSort(T[] array) {
		this.buildHeap(array);
		for(int i = index;i > 0 ; i--){
			T aux = this.array[0];
			this.array[0] = this.array[i];
			this.array[i] = aux;
			index--;
			this.heapify(array, 0);
		}
		return this.array;
	}

	@Override
	public void buildHeap(T[] array) {
		this.array = (T[]) new Comparable[array.length];
		this.index = -1;
		for(int i = 0 ;  i < array.length;i++){
			this.insert(array[i]);
		}
	}

	@Override
	public T[] toArray() {
		return this.array;
	}

	@Override
	public int size() {
		return this.index + 1;
	}


///////////////// AUXILIAR METHODS ////////////////////////////////////	
	/**
	 * Return True if heapArray is full or false if not
	 * @return boolean
	 * */
	private boolean isFull(){
		return index == this.array.length - 1;
	}
	
	/**
	 * This method resize internal array if needed
	 * */	
	private void responsiveArray(){
		T[] newArray = (T[]) new Comparable[this.array.length * 2];
		for(int i = 0 ; i < this.array.length;i++){
			newArray[i] = this.array[i];
		}
		this.array = newArray;
	}
	
	//Get parents and childs
	/**
	 * Return index of an element parent in internal array
	 * @param index of element
	 * @return index of element parent
	 * */
	private int parent(int index){
		return index/2;
	}
	/**
	 * Return index of an element left child in internal array
	 * @param index of element
	 * @return index of element parent
	 * */
	private int left(int index){
		return (2 * index);
	}
	
	/**
	 * Return index of an element right child in internal array
	 * @param index of element
	 * @return index of element parent
	 * */
	
	private int right(int index){
		return (2 * index) + 1;
	}
	
	/**
	 * Organize array to follow the  heap shape property
	 * */
	private void heapify(T[] array, int index){
		int left = left(index);
		int right = right(index);
		int largest;
		if(left <= this.index && this.array[left].compareTo(this.array[index]) > 0){
			largest = left;
		}else{
			largest = index;
		}
		if(right <= this.index && this.array[right].compareTo(this.array[largest]) > 0){
			largest = right;
		}
		if(largest != index){
			T aux = this.array[index];
			this.array[index] = this.array[largest];
			this.array[largest] = aux;
			heapify(this.array, largest);
		}
	}
}
