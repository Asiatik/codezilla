package Heap;
/**
 * @author Ionesio Junior
 * */

/**
 * Binary Heap Interface
 * */
public interface HeapInterface<T> {

	/**
	 * Return True if heapArray is Empty or false if not
	 * @return boolean
	 * */
	public boolean isEmpty();
	/**
	 * Insert an element in Heap structure
	 * @param 
	 * */
	public void insert(T element);
	/**
	 * Remove root element of Heap Structure and return it
	 * @return T element
	 * */
	public T extractRoot() throws HeapUnderflowException;
	/**
	 * Return root element of Heap Structure without remove
	 * @return T element
	 * */
	public T rootElement();
	/**
	 * Ordination Method using heap Structure
	 * @param T[] disorderly Array
	 * @return T[] ordered Array
	 * */
	public T[] heapSort(T[] array);
	/**
	 * Build an Heap Structure  using recieved array
	 * @param T array
	 * */
	public void buildHeap(T[] array);
	/**
	 * Return  array used in the heap structure
	 * @return T[] array
	 * */
	public T[]  toArray();
	/**
	 * Return number of elements in Heap
	 * @return size
	 * */
	public int size();

}
