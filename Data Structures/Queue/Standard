public class Queue {
	protected int[] data;
	protected int front;
	protected int size;

	public Queue() {
		this(5);
	}

	public Queue(int cap) {
		data = new int[cap];
		this.front = 0;
		this.size = 0;
	}

	public void enQueue(int item) throws Exception {
		if (this.size == this.data.length)
			throw new Exception("Queue Full");
		int idx = (this.front + this.size) % this.data.length;
		this.data[idx] = item;
		this.size++;
	}

	public int deQueue() throws Exception {
		if (this.size == 0)
			throw new Exception("Queue Empty");
		int val = this.data[front];
		data[this.front] = 0;
		this.size--;
		front = (front + 1) % this.data.length;
		return val;
	}

	public int getFront() throws Exception {
		if (this.size == 0)
			throw new Exception("Queue Empty");
		return data[front];
	}

	public int size() {
		return this.size;
	}

	public boolean isEmpty() {
		if (this.size == 0)
			return true;
		else
			return false;
	}

	public void display() {
		for (int i = 0; i < this.size; i++) {
			System.out.print(data[(front + i) % this.data.length] + " ");
		}
		System.out.println();
	}
}
