package Queue;

import static org.junit.Assert.assertEquals;
import static org.junit.Assert.assertFalse;
import static org.junit.Assert.assertTrue;

import org.junit.Before;
import org.junit.Test;

public class StudentQueueTest {

	public QueueInterface<Integer> queue1;
	public QueueInterface<Integer> queue2;
	public QueueInterface<Integer> queue3;

	@Before
	public void setUp() throws QueueOverflowException{
		
		getImplementations();
		
		// Fila com 3 elementos não cheia.
		queue1.enqueue(1);
		queue1.enqueue(2);
		queue1.enqueue(3);
		
		// Fila com 2 elementos de tamanho 2. Fila cheia.
		queue2.enqueue(1);
		queue2.enqueue(2);
		
	}
	
	private void getImplementations(){
		//TODO O aluno deve ajustar aqui para instanciar sua implementação
		queue1 = new SimpleQueue<>(4);
		queue2 = new SimpleQueue<>(2);
		queue3 = new SimpleQueue<>(3);
	}
	
	//MÉTODOS DE TESTE
	@Test
	public void testHead() {
		assertEquals(new Integer(1),queue1.head());
	}

	@Test
	public void testIsEmpty() {
		assertFalse(queue1.isEmpty());
		assertTrue(queue3.isEmpty());
	}

	@Test
	public void testIsFull() {
		assertFalse(queue1.isFull());
	}

	@Test
	public void testEnqueue() {
		try {
			queue1.enqueue(new Integer(5));
		} catch (QueueOverflowException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	}
	
	@Test(expected=QueueOverflowException.class)
	public void testEnqueueComErro() throws QueueOverflowException {
		queue2.enqueue(new Integer(5)); //vai depender do tamanho que a fila foi iniciada!!!
	}

	@Test
	public void testDequeue() {
		try {
			assertEquals(new Integer(1),queue1.dequeue());
		} catch (QueueUnderflowException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	}
	
	@Test(expected=QueueUnderflowException.class)
	public void testDequeueComErro() throws QueueUnderflowException {
		assertEquals(new Integer(1),queue3.dequeue()); //vai depender do tamanho que a fial foi iniciada!!!
	}
 	@Test
	public void testCircular() throws QueueUnderflowException, QueueOverflowException{

		assertTrue(queue2.isFull());
		queue2.dequeue();
		assertFalse(queue2.isFull());

		queue2.enqueue(10);
		assertTrue(queue2.isFull());

		queue2.dequeue();
		queue2.dequeue();
		assertTrue(queue2.isEmpty());
	} 
}