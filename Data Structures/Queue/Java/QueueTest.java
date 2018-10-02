package Queue;

import static org.junit.Assert.assertEquals;
import static org.junit.Assert.assertTrue;
import static org.junit.Assert.fail;

import org.junit.Before;
import org.junit.Test;


public class QueueTest {

	QueueInterface<Integer> queue;

	@Before
	public void setUp() throws Exception {
		queue = new SimpleQueue<>(5);
	}

	@Test
	public void test() throws QueueOverflowException, QueueUnderflowException {
		assertTrue(queue.isEmpty());
		assertEquals(null, queue.head());

		queue.enqueue(1);
		queue.enqueue(2);
		queue.enqueue(3);
		queue.enqueue(4);

		assertTrue(!queue.isEmpty());

		assertEquals(new Integer(1), queue.head());
		assertEquals(new Integer(1), queue.dequeue());

		assertEquals(new Integer(2), queue.head());
		assertEquals(new Integer(2), queue.dequeue());

		assertEquals(new Integer(3), queue.head());
		assertEquals(new Integer(3), queue.dequeue());

		queue.enqueue(5);
		queue.enqueue(6);

		assertEquals(new Integer(4), queue.head());
		assertEquals(new Integer(4), queue.dequeue());

		assertEquals(new Integer(5), queue.head());
		assertEquals(new Integer(5), queue.dequeue());

		assertEquals(new Integer(6), queue.head());
		assertEquals(new Integer(6), queue.dequeue());

		assertTrue(queue.isEmpty());

		assertEquals(null, queue.head());

		try {
			queue.dequeue();
			fail();
		} catch(QueueUnderflowException e) {}
	}

}
