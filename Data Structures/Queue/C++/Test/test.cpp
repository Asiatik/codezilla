#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE QueueTest

#include <boost/test/unit_test.hpp>
#include "CircularQueue/CircularQueue.hpp"
#include "StandardQueue/SimpleQueue.hpp"
#include <iostream>

struct QueueInit{
	Queue<int> *queue1 = new CircularQueue<int>(10);
	Queue<int> *queue2 = new SimpleQueue<int>(10);
};

BOOST_FIXTURE_TEST_SUITE(QueueTest,QueueInit)

BOOST_AUTO_TEST_CASE(testInit){
	BOOST_CHECK(true == queue1->isEmpty());
	BOOST_CHECK(false == queue1->isFull());
	BOOST_CHECK(NULL == queue1->head());
	BOOST_CHECK(true == queue2->isEmpty());
        BOOST_CHECK(false == queue2->isFull());
        BOOST_CHECK(NULL == queue2->head());
}

BOOST_AUTO_TEST_CASE(testIsEmpty){
	BOOST_CHECK(true == queue1->isEmpty());
        BOOST_CHECK(true == queue2->isEmpty());
	queue1->enqueue(5);
        queue2->enqueue(5);

	BOOST_CHECK(false == queue1->isEmpty());
        BOOST_CHECK(false == queue2->isEmpty());	
	queue1->head();
	queue2->head();
	BOOST_CHECK(false == queue1->isEmpty());
	BOOST_CHECK(false == queue2->isEmpty());
	
	
	queue1->dequeue();
	queue2->dequeue();
        BOOST_CHECK(true == queue1->isEmpty());
	BOOST_CHECK(true == queue2->isEmpty());
}

BOOST_AUTO_TEST_CASE(testIsFull){
	BOOST_CHECK(false == queue1->isFull());
        BOOST_CHECK(false == queue2->isFull());

	for(int i = 0 ; i < 9;i++){
		queue1->enqueue(i);
		queue2->enqueue(i);
	}

	BOOST_CHECK(false == queue1->isFull());
        BOOST_CHECK(false == queue2->isFull());

	queue1->enqueue(20);
	queue2->enqueue(20);
	BOOST_CHECK(true == queue1->isFull());
        BOOST_CHECK(true == queue2->isFull());
}

BOOST_AUTO_TEST_CASE(testEnqueue){
	BOOST_CHECK(true == queue1->isEmpty());
	BOOST_CHECK(true == queue2->isEmpty());
	queue1->enqueue(0);
	queue2->enqueue(4);
	BOOST_CHECK(false == queue1->isEmpty());
	BOOST_CHECK(false == queue2->isEmpty());
	BOOST_CHECK(false == queue1->isFull());
	BOOST_CHECK(false == queue2->isFull());
	BOOST_CHECK(0 == *(queue1->head()));

	for(int i = 1 ; i < 10;i++){
		queue1->enqueue(i);
		queue2->enqueue(i);
		BOOST_CHECK(0 == *(queue1->head()));
		BOOST_CHECK(4 == *(queue2->head()));
	}
	BOOST_CHECK(true == queue1->isFull());
	BOOST_CHECK(true == queue2->isFull());
}

BOOST_AUTO_TEST_CASE(testDequeue){
	BOOST_CHECK(true == queue1->isEmpty());
	BOOST_CHECK(true == queue2->isEmpty());
	
	for(int i = 0 ; i < 10;i++){
		queue1->enqueue(i);
		queue2->enqueue(i);
	}

	BOOST_CHECK(false == queue1->isEmpty());
	BOOST_CHECK(false == queue2->isEmpty());
	BOOST_CHECK(true == queue1->isFull());
	BOOST_CHECK(true == queue2->isFull());
	
	for(int i = 0 ; i < 10;i++){
		BOOST_CHECK(i == *(queue1->dequeue()));
		BOOST_CHECK(i == *(queue2->dequeue()));
	}
	
	BOOST_CHECK(true == queue1->isEmpty());
	BOOST_CHECK(true == queue2->isEmpty());
	BOOST_CHECK(false == queue1->isFull());
	BOOST_CHECK(false == queue2->isFull());

}

BOOST_AUTO_TEST_CASE(testHead){
	BOOST_CHECK(true == queue1->isEmpty());
	BOOST_CHECK(true == queue2->isEmpty());
	BOOST_CHECK(NULL == queue1->head());
	BOOST_CHECK(NULL == queue2->head());

	for(int i = 0 ; i < 10;i++){
		queue1->enqueue(i);
		queue2->enqueue(i);
		BOOST_CHECK(0 == *(queue1->head()));
		BOOST_CHECK(0 == *(queue2->head()));
	}
	BOOST_CHECK(true == queue1->isFull());
	BOOST_CHECK(true == queue2->isFull());
	BOOST_CHECK(false == queue1->isEmpty());
	BOOST_CHECK(false == queue2->isEmpty());
	
	for(int i = 0; i < 10;i++){
		BOOST_CHECK(i == *(queue1->head()));
		BOOST_CHECK(i == *(queue2->head()));
		BOOST_CHECK(queue1->head() == queue1->dequeue());
		queue2->dequeue();
	}
	BOOST_CHECK(false == queue1->isFull());
	BOOST_CHECK(false == queue2->isFull());
	BOOST_CHECK(true == queue1->isEmpty());
	BOOST_CHECK(true == queue2->isEmpty());
}

BOOST_AUTO_TEST_CASE(testException){
	BOOST_CHECK_THROW(queue1->dequeue(),QueueUnderflowException);
	BOOST_CHECK_THROW(queue2->dequeue(),QueueUnderflowException);
	for(int i = 0; i < 10;i++){
		queue1->enqueue(i);
		queue2->enqueue(i);
	}
	BOOST_CHECK_THROW(queue1->enqueue(10),QueueOverflowException);
	BOOST_CHECK_THROW(queue2->enqueue(10),QueueOverflowException);
}

BOOST_AUTO_TEST_SUITE_END()
