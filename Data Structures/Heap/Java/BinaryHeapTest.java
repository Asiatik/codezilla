package Heap;
/**
 * @author Ionesio Junior
 * */

/**
 * Binary Heap Validation Tests
 * */
import static org.junit.Assert.*;

import org.junit.Assert;
import org.junit.Before;
import org.junit.Test;

import Heap.BinaryHeap;

/**
 * Binary Heap validation tests
 * */
public class BinaryHeapTest {
	public HeapInterface<Integer> heap;
	@Before
	public void setUp() throws Exception {
		this.heap = new BinaryHeap<Integer>();
	}

	@Test
	public void testIsEmpty() {
		Assert.assertTrue(heap.isEmpty());
		heap.insert(new Integer(9));
		Assert.assertFalse(heap.isEmpty());
		
	}

	@Test
	public void testInsert() {
		heap.insert(new Integer(9));
		Assert.assertEquals(new Integer(9), heap.rootElement());
		heap.insert(new Integer(8));
		Assert.assertEquals(new Integer(9), heap.rootElement());
		heap.insert(new Integer(10));
		Assert.assertEquals(new Integer(10), heap.rootElement());
		Assert.assertEquals(3, heap.size());
	}

	@Test
	public void testRootElement() {
		heap.insert(new Integer(20));
		Assert.assertEquals(new Integer(20),heap.rootElement());
		heap.insert(new Integer(50));
		Assert.assertEquals(new Integer(50), heap.rootElement());
		heap.insert(new Integer(10));
		Assert.assertNotEquals(new Integer(10), heap.rootElement());
	}

	@Test
	public void testBuildHeap() {
		Assert.assertEquals(0,heap.size());
		heap.insert(new Integer(99));
		Assert.assertEquals(new Integer(99), heap.rootElement());
		Assert.assertEquals(1,heap.size());
		Comparable[] array = new Integer[20];
		for(int i = 0 ; i < array.length;i++){
			array[i] = new Integer(i);
		}
		heap.buildHeap((Integer[]) array);
		Assert.assertEquals(new Integer(19), heap.rootElement());
		Assert.assertEquals(20, heap.size());
	}

	@Test
	public void testToArray() {
		Comparable[] array = new Integer[20];
		for(int i = 0 ; i < array.length;i++){
			array[i] = new Integer(i);
		}
		heap.buildHeap((Integer[]) array);
		Comparable[] returnArray = heap.toArray();
		Integer[] Array = {19,18,17,13,16,8,10,12,9,15,2,7,1,5,4,11,0,6,3,14};
		Assert.assertArrayEquals(Array, returnArray);
	}

	@Test
	public void testSize() {
		Assert.assertEquals(0, heap.size());
		for(int i = 0 ; i < 100;i++){
			heap.insert(new Integer(i));
		}
		Assert.assertEquals(100,heap.size());
	}
	
	@Test
	public void testExtractRoot() throws HeapUnderflowException{
		Assert.assertEquals(0, heap.size());
		for(int i = 0 ; i < 100;i++){
			heap.insert(new Integer(i));
		}
		Assert.assertEquals(100, heap.size());
		for(int i = 99; i >= 0; i--){
			Assert.assertEquals(new Integer(i), heap.extractRoot());
			Assert.assertEquals(i, heap.size());
		}
	}
	
	@Test
	public void testHeapSort(){
		Comparable[] array = new Integer[10];
		int index = 0;
		for(int i = 9; i >= 0 ; i--){
			array[index++] = new Integer(i);
			System.out.print(array[index - 1] + " ");
		}
		System.out.println("");
		Comparable[] returnArray = heap.heapSort((Integer[]) array);
		for(int i = 0 ; i < returnArray.length;i++){
			System.out.print(returnArray[i] + " ");
		}
	}
}
