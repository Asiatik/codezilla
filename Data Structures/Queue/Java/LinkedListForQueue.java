public class LinkedList {
	private class Node {
		int data;
		Node next;
	}

	private Node head;
	private Node tail;
	private int size;

	public int size() {
		return size;
	}

	public boolean isEmpty() {
		return size() == 0;
	}

	public void display() {
		Node temp = head;
		while (temp != null) {
			System.out.print(temp.data + " ");
			temp = temp.next;
		}
		System.out.println();
	}

	public int getFirst() throws Exception {
		if (this.size == 0)
			throw new Exception("LL Empty");
		else
			return this.head.data;
	}

	public int getLast() throws Exception {
		if (this.size == 0)
			throw new Exception("LL Empty");
		else
			return this.tail.data;
	}

	public int getAt(int idx) throws Exception {
		if (this.size == 0)
			throw new Exception("LL Empty");
		if (idx < 0 || idx >= this.size)
			throw new Exception("Invalid Index");
		Node temp = this.head;
		for (int i = 0; i < idx; i++)
			temp = temp.next;
		return temp.data;
	}

	public Node getNodeAt(int idx) throws Exception {
		if (this.size == 0)
			throw new Exception("LL Empty");
		if (idx < 0 || idx >= this.size)
			throw new Exception("Invalid Index");
		Node temp = this.head;
		for (int i = 0; i < idx; i++)
			temp = temp.next;
		return temp;
	}

	public void addLast(int item) {
		Node temp = new Node();
		temp.data = item;
		if (this.size == 0) {
			this.head = temp;
			this.tail = temp;
			size++;
		} else {
			this.tail.next = temp;
			this.tail = temp;
			size++;
		}
	}

	public void addFirst(int item) {
		if (size == 0) {
			addLast(item);
		} else {
			Node nn = new Node();
			nn.next = head;
			nn.data = item;
			this.head = nn;
			this.size++;
		}
	}

	public void addAt(int item, int idx) throws Exception {
		if (item < 0 || item > size) {
			throw new Exception("Invalid Index");
		} else if (idx == size) {
			addLast(item);
		} else if (idx == 0) {
			addFirst(item);
		} else {
			Node nn = new Node();
			nn.data = item;
			Node nm1 = getNodeAt(idx - 1);
			Node np1 = nm1.next;
			nm1.next = nn;
			nn.next = np1;
			this.size++;
		}
	}

	public int removeFirst() throws Exception {
		if (this.size == 0) {
			throw new Exception("LL Empty");
		}
		int rv = this.head.data;
		if (this.size == 1) {
			this.head = null;
			this.tail = null;
			this.size--;
		} else {
			this.head = this.head.next;
			this.size--;
		}
		return rv;
	}

	public int removeLast() throws Exception {
		if (this.size == 0) {
			throw new Exception("LL Empty");
		}
		int rv = this.tail.data;
		if (this.size == 1) {
			this.head = null;
			this.tail = null;
			this.size--;
		} else {
			Node nm1 = this.getNodeAt(this.size - 2);
			nm1.next = null;
			this.tail = nm1;
			this.size--;
		}
		return rv;
	}

	public int removeAt(int idx) throws Exception {
		if (this.size == 0) {
			throw new Exception("LL Empty");
		}
		if (idx < 0 || idx > size) {
			throw new Exception("Invalid Index");
		}
		if (idx == this.size - 1) {
			return removeLast();
		}
		if (idx == 0) {
			return removeFirst();
		} else {
			Node nm1 = this.getNodeAt(idx - 1);
			Node rv = nm1.next;
			nm1.next = rv.next;
			this.size--;
			return rv.data;
		}
	}

	public void ReverseDI() throws Exception {
		for (int i = 0; i < size / 2; i++) {
			Node n1 = this.getNodeAt(i);
			Node n2 = this.getNodeAt(size - 1 - i);
			int temp = n1.data;
			n1.data = n2.data;
			n2.data = temp;
		}
	}

	public void ReversePI() throws Exception {
		Node temp = this.head;
		Node temp1 = temp.next;
		Node temp2 = temp1.next;
		for (int i = 0; i < size - 2; i++) {
			temp1.next = temp;
			temp = temp1;
			temp1 = temp2;
			temp2 = temp2.next;
		}
		temp1.next = temp;
		temp = temp1;
		temp1 = temp2;
		head.next = null;
		Node t = head;
		head = tail;
		tail = t;
	}

	public void ReversePR() {
		ReversePRH(this.head.next, this.head);
		Node t = head;
		head = tail;
		tail = t;
		tail.next = null;
	}

	private void ReversePRH(Node curr, Node prev) {
		if (curr == null)
			return;
		ReversePRH(curr.next, curr);
		curr.next = prev;
	}

	public void ReverseDR() {
		int counter = 0;
		helper h = new helper();
		h.first = this.head;
		ReverseDRH(h, this.head.next, counter);
	}

	private class helper {
		Node first;
	}

	private void ReverseDRH(helper h, Node last, int counter) {
		if (last == null)
			return;
		ReverseDRH(h, last.next, counter + 1);
		if (counter >= size / 2 - 1) {
			int temp = h.first.data;
			h.first.data = last.data;
			last.data = temp;
		}
		h.first = h.first.next;
	}

	public void fold() {
		int counter = 0;
		helper h = new helper();
		h.first = this.head;
		foldH(h, this.head, counter);
	}

	public void foldH(helper h, Node last, int counter) {
		if (last == null)
			return;
		foldH(h, last.next, counter + 1);
		if (counter > size / 2) {
			Node temp = h.first.next;
			h.first.next = last;
			last.next = temp;
			h.first = temp;
		}
		if (counter == size / 2) {
			tail = last;
			tail.next = null;
		}
	}

	public Node midNode() {
		Node n = head;
		Node m = head;
		while (m != tail && m.next != tail) {
			m = m.next.next;
			n = n.next;
		}
		return n;
	}

	public int kFromLast(int k) {
		Node val = head;
		Node rv = head;
		int check = 1;
		while (val != tail) {
			if (check >= k)
				rv = rv.next;
			val = val.next;
			check++;
		}
		return rv.data;
	}

	public LinkedList merge2sortedLL(LinkedList other) {
		LinkedList rv = new LinkedList();
		Node ttemp = this.head;
		Node otemp = other.head;
		while (ttemp != null && otemp != null) {
			if (ttemp.data < otemp.data) {
				rv.addLast(ttemp.data);
				ttemp = ttemp.next;
			} else {
				rv.addLast(otemp.data);
				otemp = otemp.next;
			}
		}
		while (ttemp != null) {
			rv.addLast(ttemp.data);
			ttemp = ttemp.next;
		}
		while (otemp != null) {
			rv.addLast(otemp.data);
			otemp = otemp.next;
		}
		return rv;
	}

	public void mergeSort() {
		if (this.size == 1)
			return;
		Node mid1 = this.midNode();
		Node mid2 = mid1.next;
		LinkedList fh = new LinkedList();
		LinkedList sh = new LinkedList();
		fh.head = this.head;
		fh.tail = mid1;
		fh.tail.next = null;
		sh.head = mid2;
		sh.tail = this.tail;
		sh.tail.next = null;
		fh.size = (size + 1) / 2;
		sh.size = (size) / 2;
		fh.mergeSort();
		sh.mergeSort();
		LinkedList merge = fh.merge2sortedLL(sh);
		this.head = merge.head;
		this.tail = merge.tail;
		this.size = merge.size;
	}

	public boolean loop() {
		Node a = head;
		Node b = head;
		while (b != null && b.next != null) {
			a = a.next;
			b = b.next.next;
			if (a == b && a == b.next)
				return true;

		}
		return false;
	}

	public void rotate(int r) throws Exception {
		r = r % size;
		if (r == 0)
			return;
		if (r < 0)
			r = r + size;
		Node temp = this.getNodeAt(size - r);
		Node t = this.getNodeAt(size - r - 1);
		this.tail.next = head;
		head = temp;
		tail = t;
		this.tail.next = null;
	}

	public void kReverse(int k) throws Exception {
		LinkedList prev = null;
		LinkedList curr = null;

		while (this.size != 0) {
			curr = new LinkedList();
			for (int i = 1; i <= k; i++)
				curr.addFirst(this.removeFirst());

			if (prev == null)
				prev = curr;
			else {
				prev.tail.next = curr.head;
				prev.tail = curr.tail;
				prev.size = prev.size + curr.size;
			}
		}
		this.head = prev.head;
		this.tail = prev.tail;
		this.size = prev.size;
	}

	public void removeDuplicate() throws Exception {
		LinkedList temp = new LinkedList();
		Node n = new Node();
		n = head;
		while (n != null) {
			if (n.next == null || n.data != n.next.data)
				temp.addLast(n.data);
			n = n.next;
		}
		this.head = temp.head;
		this.tail = temp.tail;
		this.size = temp.size;
	}
}
