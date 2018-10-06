/**
 * A skip list is a data structure that allows fast search within an ordered
 * sequence of elements. Each node of a skip list is identified by its unique
 * key. The height of the node determines the number of nodes it can be linked
 * with. The T-typed satellite data is stored as value.
 * 
 */
public class SkipListNode<T> {

	private int key;
	private T value;
	private SkipListNode<T>[] forward;

	/**
	 * Constructs a SkipListNode whose key, height and satellite data are given as
	 * parameters.
	 * 
	 * @param key    The key for access of the node being created.
	 * @param value  The value to be stored at the node.
	 * @param height The height of the node.
	 * 
	 */
	@SuppressWarnings("unchecked")
	public SkipListNode(int key, T value, int height) {
		this.key = key;
		this.value = value;
		this.forward = new SkipListNode[height];
	}

	public int getKey() {
		return this.key;
	}

	public void setKey(int key) {
		this.key = key;
	}

	public T getValue() {
		return this.value;
	}

	public void setValue(T value) {
		this.value = value;
	}

	public SkipListNode<T>[] getForward() {
		return this.forward;
	}

	/**
	 * Given the specified level, returns the node linked to the one executing this
	 * method.
	 * 
	 * @return the forward node in the specified level.
	 * 
	 */
	public SkipListNode<T> getForward(int level) {
		return this.getForward()[level];
	}

	/**
	 * Given the specified level, creates a link from the node executing this method
	 * to the one given as parameter.
	 * 
	 * @param level   The level where the link must be created.
	 * @param forward the node that will be linked to the one executing this method.
	 * 
	 */
	public void setForward(int level, SkipListNode<T> forward) {
		this.getForward()[level] = forward;
	}

	/**
	 * Returns the height of the node executing this method.
	 * 
	 * @return the height of the node.
	 * 
	 */
	public int height() {
		return this.getForward().length;
	}

	/**
	 * Determines how many nodes are linked after the node executing this method.
	 * 
	 * @return the number of not null forwards of the node.
	 * 
	 */
	private int countForwardsNotNull() {
		int notNulls = 0;

		for (int i = 0; i < this.height(); i++) {
			if (this.getForward()[i] != null) {
				notNulls++;
			}
		}

		return notNulls;
	}

	/**
	 * Compares the node executing this method with the Object given as parameter to
	 * determine if they are equals. To be equals, the Object must contain the same
	 * key, the same height and be linked to the same number of nodes.
	 * 
	 * @return The boolean that indicates the equality between the node and the
	 *         object.
	 * 
	 */
	@SuppressWarnings("unchecked")
	@Override
	public boolean equals(Object obj) {
		boolean equals = false;

		if (obj instanceof SkipListNode) {
			equals = (this.key == ((SkipListNode<T>) obj).key) && (this.height() == ((SkipListNode<T>) obj).height())
					&& (this.countForwardsNotNull() == ((SkipListNode<T>) obj).countForwardsNotNull());
		}

		return equals;
	}

	/**
	 * Returns a textual representation of the node executing this method.
	 * 
	 * @return The textual representation of the node.
	 * 
	 */
	@Override
	public String toString() {
		String toString = "";

		if (this.getKey() == Integer.MIN_VALUE) {
			toString = "<ROOT, " + this.height() + ", " + this.countForwardsNotNull() + ">";
		} else if (this.getKey() == Integer.MAX_VALUE) {
			toString = "<NIL, " + this.height() + ">";
		} else {
			toString = "<" + this.getKey() + ", " + this.height() + ">";
		}

		return toString;
	}

}
