package Queue;
/*
 * @author Ionésio Junior
 * */

/*
 * Queue in Circular implementation
 * */
public class CircularQueue<T> implements QueueInterface<T> {
  
  	private T[] array;
  	private int tail;
  	private int head;
  	private int elements;
  
  	public CircularQueue(int size) {
  		array = (T[]) new Object[size];
  		head = -1;
  		tail = -1;
  		elements = 0;
  	}
  
  	@Override
  	public void enqueue(T element) throws QueueOverflowException {
  		if(isFull()){
  			throw new QueueOverflowException();
  		}
  		if(element != null){
  			this.elements++;
  			if(this.head == -1 && this.tail == -1){
  				this.head = (this.head + 1) % this.array.length;
  			}
  			this.tail = (this.tail + 1) % this.array.length;
  			this.array[this.tail] = element;
  		}
  	}
  
  	@Override
  	public T dequeue() throws QueueUnderflowException {
  		if(isEmpty()){
  			throw new QueueUnderflowException();
  		}
  		this.elements--;
  		T aux = this.array[this.head];
  		this.head = (this.head  + 1) % this.array.length;
  		return aux;
  	}
  
  	@Override
  	public T head() {
  		if(isEmpty()){
  			return null;
  		}
  		return this.array[this.head];
  	}
  
  	@Override
  	public boolean isEmpty() {
  		return this.elements == 0;
  	}
  
  	@Override
  	public boolean isFull() {
  		return this.elements == this.array.length;
  	}
  
  }