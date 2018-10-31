package BST;
/**
 * @author Ionesio Junior
 * */
import static org.junit.Assert.*;

import org.junit.Assert;
import org.junit.Before;
import org.junit.Test;

import BST.BST;
import BST.BSTInterface;

/**
 * BST Validation Tests
 * */
public class BSTTest {
	
	public BSTInterface<Integer> bst;
	public Node<Integer> NIL;
	@Before
	public void setUp() throws Exception {
		bst = new BST();
		NIL = new Node<Integer>();
	}

	@Test
	public void testSearch() {
		Assert.assertEquals(NIL,bst.search(new Integer(9)));
		bst.insert(new Integer(9));
		Assert.assertEquals(new Integer(9), bst.search(9).getData());
		Assert.assertEquals(NIL,bst.search(15));
		bst.insert(new Integer(10));
		bst.insert(new Integer(15));
		bst.insert(new Integer(30));
		bst.insert(new Integer(7));
		Assert.assertEquals(new Integer(10),bst.search(new Integer(10)).getData());
		Assert.assertEquals(new Integer(15),bst.search(new Integer(15)).getData());
		Assert.assertEquals(new Integer(7),bst.search(new Integer(7)).getData());
		Assert.assertEquals(NIL,bst.search(new Integer(45)));
	}

	@Test
	public void testInsert() {
		Assert.assertTrue(bst.isEmpty());
		bst.insert(new Integer(10));
		Assert.assertFalse(bst.isEmpty());
		bst.insert(new Integer(20));
		bst.insert(new Integer(30));
		bst.insert(new Integer(5));
		bst.insert(new Integer(7));
		bst.insert(new Integer(3));
		bst.insert(new Integer(15));
		bst.insert(new Integer(25));
		
		//tests
		Assert.assertEquals(new Integer(10), bst.getRoot().getData());
		Assert.assertEquals(new Integer(20), bst.getRoot().getRight().getData());
		Assert.assertEquals(new Integer(5),bst.getRoot().getLeft().getData());
		Assert.assertEquals(new Integer(7), bst.getRoot().getLeft().getRight().getData());
		Assert.assertEquals(new Integer(3), bst.getRoot().getLeft().getLeft().getData());
	}
	
	@Test
	public void testMaximum(){
		Assert.assertTrue(bst.isEmpty());
		bst.insert(new Integer(10));
		Assert.assertFalse(bst.isEmpty());
		bst.insert(new Integer(20));
		bst.insert(new Integer(30));
		Assert.assertEquals(new Integer(30), bst.maximum().getData());
		bst.insert(new Integer(5));
		bst.insert(new Integer(7));
		bst.insert(new Integer(100));
		bst.insert(new Integer(3));
		bst.insert(new Integer(15));
		bst.insert(new Integer(25));

		//tests
		Assert.assertEquals(new Integer(100), bst.maximum().getData());
	}

	
	@Test
	public void testMinimum(){
		Assert.assertTrue(bst.isEmpty());
		bst.insert(new Integer(10));
		Assert.assertFalse(bst.isEmpty());
		bst.insert(new Integer(20));
		bst.insert(new Integer(30));
		Assert.assertEquals(new Integer(10), bst.minimum().getData());
		bst.insert(new Integer(5));
		bst.insert(new Integer(7));
		Assert.assertEquals(new Integer(5), bst.minimum().getData());
		bst.insert(new Integer(100));
		bst.insert(new Integer(3));
		bst.insert(new Integer(15));
		bst.insert(new Integer(25));
		Assert.assertEquals(new Integer(3), bst.minimum().getData());
	}
	
	
	@Test
	public void testSucessor(){
		bst.insert(new Integer(10));
		Assert.assertNull(bst.sucessor(new Integer(10)));
		bst.insert(new Integer(20));
		Assert.assertEquals(new Integer(20), bst.sucessor(new Integer(10)).getData());
		bst.insert(new Integer(30));
		Assert.assertEquals(new Integer(30), bst.sucessor(new Integer(20)).getData());
		Assert.assertNotEquals(new Integer(30), bst.sucessor(new Integer(10)).getData());
		bst.insert(new Integer(5));
		Assert.assertEquals(new Integer(10), bst.sucessor(new Integer(5)).getData());
		bst.insert(new Integer(7));
		Assert.assertEquals(new Integer(7), bst.sucessor(new Integer(5)).getData());
		bst.insert(new Integer(100));
		Assert.assertEquals(new Integer(100), bst.sucessor(new Integer(30)).getData());
		Assert.assertNotEquals(new Integer(100), bst.sucessor(new Integer(20)).getData());
		bst.insert(new Integer(3));
		Assert.assertEquals(new Integer(5), bst.sucessor(new Integer(3)).getData());
		bst.insert(new Integer(15));
		Assert.assertEquals(new Integer(20), bst.sucessor(new Integer(15)).getData());
		bst.insert(new Integer(25));
		Assert.assertEquals(new Integer(30), bst.sucessor(new Integer(25)).getData());
	}
	
	
	@Test
	public void testPredecessor(){
		bst.insert(new Integer(10));
		Assert.assertNull(bst.predecessor(new Integer(10)));
		bst.insert(new Integer(20));
		Assert.assertEquals(new Integer(10), bst.predecessor(new Integer(20)).getData());
		bst.insert(new Integer(30));
		Assert.assertEquals(new Integer(20), bst.predecessor(new Integer(30)).getData());
		bst.insert(new Integer(5));
		Assert.assertEquals(new Integer(5), bst.predecessor(new Integer(10)).getData());
		bst.insert(new Integer(7));
		Assert.assertEquals(new Integer(5), bst.predecessor(new Integer(7)).getData());
		Assert.assertNotEquals(new Integer(5), bst.predecessor(new Integer(10)).getData());
		bst.insert(new Integer(100));
		Assert.assertEquals(new Integer(30), bst.predecessor(new Integer(100)).getData());
		bst.insert(new Integer(3));
		Assert.assertEquals(new Integer(3), bst.predecessor(new Integer(5)).getData());
		bst.insert(new Integer(15));
		Assert.assertEquals(new Integer(10), bst.predecessor(new Integer(15)).getData());
		bst.insert(new Integer(25));
		Assert.assertEquals(new Integer(20), bst.predecessor(new Integer(25)).getData());
	}

	
	@Test
	public void testRemove() {
		Assert.assertTrue(bst.isEmpty());
		bst.insert(new Integer(10));
		Assert.assertFalse(bst.isEmpty());
		bst.insert(new Integer(20));
		bst.insert(new Integer(30));
		bst.insert(new Integer(5));
		bst.insert(new Integer(7));
		bst.insert(new Integer(3));
		bst.insert(new Integer(15));
		
		bst.remove(new Integer(10));
		Assert.assertEquals(new Integer(15), bst.getRoot().getData());
		Assert.assertEquals(new Node<Integer>(),bst.search(new Integer(10)));
		bst.remove(new Integer(30));
		Assert.assertEquals(new Integer(15), bst.getRoot().getData());
		Assert.assertEquals(new Node<Integer>(),bst.search(new Integer(30)));
		bst.remove(new Integer(5));
		Assert.assertEquals(new Node<Integer>(),bst.search(new Integer(5)));
		Assert.assertEquals(new Integer(7),bst.getRoot().getLeft().getData());
		bst.remove(new Integer(20));
		bst.remove(new Integer(15));
		bst.remove(new Integer(7));
		bst.remove(new Integer(3));
		Assert.assertTrue(bst.isEmpty());
	}
	
	@Test
	public void testOrder(){
		Assert.assertTrue(bst.isEmpty());
		bst.insert(new Integer(10));
		Assert.assertFalse(bst.isEmpty());
		bst.insert(new Integer(20));
		bst.insert(new Integer(30));
		bst.insert(new Integer(5));
		bst.insert(new Integer(7));
		bst.insert(new Integer(3));
		bst.insert(new Integer(15));
		
		Comparable[] postOrder = bst.toArrayPostOrder();
		Comparable[] preOrder = bst.toArrayPreOrder();
		Comparable[] order = bst.toArrayOrder();
		
		//Print Post Order Array
		System.out.println("Array Post Order: ");
		for(int i = 0; i < postOrder.length;i++){
			System.out.print(postOrder[i] + " ");
		}
		System.out.println("");
		
		//Print Order Array
		System.out.println("Array Order: ");
		for(int i = 0; i < order.length;i++){
			System.out.print(order[i] + " ");
		}
		System.out.println("");
		
		//Print Pre Order Array
		System.out.println("Array Pre Order: ");
		for(int i = 0; i < preOrder.length;i++){
			System.out.print(preOrder[i] + " ");
		}
		System.out.println("");
	}
	
	@Test
	public void testHeight(){
		bst.insert(new Integer(30));
		bst.insert(new Integer(10));
		bst.insert(new Integer(15));
		bst.insert(new Integer(14));
		bst.insert(new Integer(13));
		bst.insert(new Integer(12));
		bst.insert(new Integer(11));
		bst.insert(new Integer(42));
		bst.insert(new Integer(5));
		bst.insert(new Integer(3));
		bst.insert(new Integer(2));
		Assert.assertEquals(6, bst.height());
		
	}
}
