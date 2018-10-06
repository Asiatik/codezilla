/**
 * A skip list is a data structure that allows fast search within an ordered
 * sequence of elements. Fast search is made possible by maintaining a linked
 * hierarchy and skipping over some elements. The elements that are skipped over
 * are chosen deterministically. The skip list contains T-type elements.
 * 
 */
public class DeterministicSkipList<T> implements SkipList<T> {

	private SkipListNode<T> head;
	private SkipListNode<T> tail;
	private int maxHeight;

	/**
	 * Constructs a new DeterministicSkipList which maximum height will be the one
	 * given as parameter. The sentinel nodes will be already connected after the
	 * creation of the skip list.
	 * 
	 * @param maxHeight The maximum height allowed to the skip list nodes.
	 * 
	 */
	@SuppressWarnings({ "unchecked", "rawtypes" })
	public DeterministicSkipList(int maxHeight) {
		this.head = new SkipListNode(Integer.MIN_VALUE, null, maxHeight);
		this.tail = new SkipListNode(Integer.MAX_VALUE, null, maxHeight);
		this.maxHeight = maxHeight;
		connectHeadToTail();
	}

	/**
	 * Connects the sentinel nodes of the skip list in all their levels.
	 * 
	 */
	private void connectHeadToTail() {
		for (int i = 0; i < this.maxHeight; i++) {
			this.getHead().setForward(i, this.getTail());
		}
	}

	public SkipListNode<T> getHead() {
		return this.head;
	}

	protected void setHead(SkipListNode<T> head) {
		this.head = head;
	}

	public SkipListNode<T> getTail() {
		return this.tail;
	}

	protected void setTail(SkipListNode<T> tail) {
		this.tail = tail;
	}

	public int getMaxHeight() {
		return this.maxHeight;
	}

	protected void setMaxHeight(int maxHeight) {
		this.maxHeight = maxHeight;
	}

	/**
	 * Returns the number of elements contained in the skip list. The sentinel nodes
	 * are not considered.
	 * 
	 * @return the size of the skip list.
	 * 
	 */
	@Override
	public int size() {
		SkipListNode<T> currentNode = this.getHead().getForward(0);
		int counter = 0;

		while (!currentNode.equals(this.getTail())) {
			currentNode = currentNode.getForward(0);
			counter++;
		}

		return counter;
	}

	/**
	 * Returns the height of the highest node of the skip list (the sentinel nodes
	 * are not considered). Returns zero if the skip list is empty.
	 * 
	 * @return the height of the highest node of the skip list.
	 * 
	 */
	@Override
	public int height() {
		int highest = 0;

		if (this.size() > 0) {
			SkipListNode<T> currentNode = this.getHead().getForward(0);

			while (!currentNode.equals(this.getTail())) {
				if (currentNode.height() > highest) {
					highest = currentNode.height();
				}

				currentNode = currentNode.getForward(0);
			}
		}

		return highest;
	}

	/**
	 * Inserts a new element (using the given height) at the skip list. If the skip
	 * list already contains a node with the same key, only updates the node value.
	 * 
	 * @param key    The key for access of the value to be inserted.
	 * @param value  The value to be inserted.
	 * @param height The height of the new node that will be created.
	 * 
	 */
	@SuppressWarnings("unchecked")
	@Override
	public void insert(int key, T value, int height) {
		if (height <= this.getMaxHeight()) {
			SkipListNode<T>[] update = new SkipListNode[this.getMaxHeight()];
			SkipListNode<T> target = this.searchPlace(update, key);

			target = target.getForward(0);

			if (target.getKey() == key) {
				target.setValue(value);
			}

			if ((height >= 1) && (value != null)) {
				target = new SkipListNode<T>(key, value, height);
				for (int i = 0; i < height; i++) {
					target.setForward(i, update[i].getForward(i));
					update[i].setForward(i, target);
				}
			}
		}
	}

	/**
	 * Removes a node (containing the given key) from the skip list. If the given
	 * key is not present in any of the skip list nodes, it remains unchanged.
	 * 
	 * @param key The key of the node to be removed.
	 * 
	 */
	@SuppressWarnings("unchecked")
	@Override
	public void remove(int key) {
		SkipListNode<T>[] update = new SkipListNode[this.getMaxHeight()];
		SkipListNode<T> target = this.searchPlace(update, key);

		target = target.getForward(0);

		if (target.getKey() == key) {
			int level = 0;
			while ((level < this.getMaxHeight()) && (!update[level].getForward(level).equals(target))) {
				update[level].setForward(level, target.getForward(level));
				level++;
			}
		}
	}

	private SkipListNode<T> searchPlace(SkipListNode<T>[] update, int key) {
		SkipListNode<T> target = this.getHead();

		for (int i = this.getMaxHeight() - 1; i >= 0; i--) {
			while (target.getForward(i).getKey() < key) {
				target = target.getForward(i);
			}

			update[i] = target;
		}

		return target;
	}

	/**
	 * Searches for a node (containing the given key) in the skip list. It will
	 * return the node if the skip list contains it. Otherwise, it will return null.
	 * 
	 * @param key the key of the node being searched for.
	 * 
	 * @return the node containing the given key, if it is in the skip list, or
	 *         null, otherwise.
	 * 
	 */
	@Override
	public SkipListNode<T> search(int key) {
		SkipListNode<T> target = this.getHead();

		for (int i = this.getMaxHeight() - 1; i >= 0; i--) {
			while (target.getForward(i).getKey() < key) {
				target = target.getForward(i);
			}
		}

		target = target.getForward(0);
		if (target.getKey() != key) {
			target = null;
		}

		return target;
	}

	/**
	 * Returns an array containing all nodes (including sentinel nodes) of the skip
	 * list in order.
	 * 
	 * @return the array containing all nodes of the skip list.
	 * 
	 */
	@SuppressWarnings("unchecked")
	@Override
	public SkipListNode<T>[] toArray() {
		int arraySize = this.size() + 2;
		SkipListNode<T>[] array = new SkipListNode[arraySize];
		SkipListNode<T> currentNode = this.getHead();

		for (int i = 0; i < arraySize; i++) {
			array[i] = currentNode;
			currentNode = currentNode.getForward(0);
		}

		return array;
	}

}
