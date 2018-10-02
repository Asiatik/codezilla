package Heap;

public class HeapUnderflowException extends Exception {
	public HeapUnderflowException(){
		super("Heap is empty!!");
	}
}
