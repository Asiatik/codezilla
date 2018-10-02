public class QusingLL {
	private LinkedList ll = new LinkedList();

	public void enQueue(int item) {
		ll.addLast(item);
	}

	public void deQueue() throws Exception {
		ll.removeFirst();
	}

	public void size() {
		ll.size();
	}

	public void isEmpty() {
		ll.isEmpty();
	}

	public void display() {
		ll.display();
	}
}
