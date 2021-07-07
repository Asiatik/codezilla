/**
 * A skip list is a data structure that allows fast search within an ordered
 * sequence of elements. Fast search is made possible by maintaining a linked
 * hierarchy and skipping over some elements. The elements that are skipped over
 * may be chosen probabilistically or deterministically. The skip list contains
 * T-type elements.
 * 
 */
public interface SkipList<T> {

	/**
	 * Returns the number of elements contained in the skip list. The sentinel nodes
	 * are not considered.
	 * 
	 * @return the size of the skip list.
	 * 
	 */
	public int size();

	/**
	 * Returns the height of the highest node of the skip list (the sentinel nodes
	 * are not considered). Returns zero if the skip list is empty.
	 * 
	 * @return the height of the highest node of the skip list.
	 * 
	 */
	public int height();

	/**
	 * Inserts a new element (using the given height) in the skip list. If the skip
	 * list already contains a node with the same key, this method only updates the
	 * node value.
	 * 
	 * @param key    The key for access of the value to be inserted.
	 * @param value  The value to be inserted.
	 * @param height The height of the new node that will be created.
	 * 
	 */
	public void insert(int key, T value, int height);

	/**
	 * Removes a node (containing the given key) from the skip list. If the given
	 * key is not present in any of the skip list nodes, it remains unchanged.
	 * 
	 * @param key The key of the node to be removed.
	 * 
	 */
	public void remove(int key);

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
	public SkipListNode<T> search(int key);

	/**
	 * Returns an array containing all nodes (including sentinel nodes) of the skip
	 * list in order.
	 * 
	 * @return the array containing all nodes of the skip list.
	 * 
	 */
	public SkipListNode<T>[] toArray();

}
