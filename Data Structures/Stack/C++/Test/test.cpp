#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE StackTest

#include <boost/test/unit_test.hpp>
#include "../Stack.hpp"
#include <iostream>

struct StackInit{
	Stack<int> *stack = new Stack<int>(10);
};

BOOST_FIXTURE_TEST_SUITE(StackTest,StackInit)

BOOST_AUTO_TEST_CASE(testInit){
	BOOST_CHECK(true == stack->isEmpty());
	BOOST_CHECK(false == stack->isFull());
	BOOST_CHECK(NULL == stack->top());
}

BOOST_AUTO_TEST_CASE(testIsEmpty){
	BOOST_CHECK(true == stack->isEmpty());
	stack->push(5);
	BOOST_CHECK(false == stack->isEmpty());
	stack->top();
	BOOST_CHECK(false == stack->isEmpty());
	stack->pop();
	BOOST_CHECK(true == stack->isEmpty());
}

BOOST_AUTO_TEST_CASE(testIsFull){
	BOOST_CHECK(false == stack->isFull());
	for(int i = 0 ; i < 9;i++){
		stack->push(i);
	}
	BOOST_CHECK(false == stack->isFull());
	stack->push(20);
	BOOST_CHECK(true == stack->isFull());
}

BOOST_AUTO_TEST_CASE(testPush){
	BOOST_CHECK(true == stack->isEmpty());
	stack->push(0);
	BOOST_CHECK(false == stack->isEmpty());
	BOOST_CHECK(false == stack->isFull());
	BOOST_CHECK(0 == *(stack->top()));
	for(int i = 1 ; i < 10;i++){
		stack->push(i);
		BOOST_CHECK(i == *(stack->top()));
	}
	BOOST_CHECK(true == stack->isFull());
}

BOOST_AUTO_TEST_CASE(testPop){
	BOOST_CHECK(true == stack->isEmpty());
	for(int i = 0 ; i < 10;i++){
		stack->push(i);
	}
	BOOST_CHECK(false == stack->isEmpty());
	BOOST_CHECK(true == stack->isFull());
	
	for(int i = 9 ; i >= 0;i--){
		BOOST_CHECK(i == *(stack->pop()));
	}
	
	BOOST_CHECK(true == stack->isEmpty());
	BOOST_CHECK(false == stack->isFull());
}

BOOST_AUTO_TEST_CASE(testTop){
	BOOST_CHECK(true == stack->isEmpty());
	BOOST_CHECK(NULL == stack->top());
	for(int i = 0 ; i < 10;i++){
		stack->push(i);
		BOOST_CHECK(i == *(stack->top()));
	}
	BOOST_CHECK(true == stack->isFull());
	BOOST_CHECK(false == stack->isEmpty());
	
	for(int i = 9; i >= 0;i--){
		BOOST_CHECK(i == *(stack->top()));
		stack->pop();	
	}
	BOOST_CHECK(false == stack->isFull());
	BOOST_CHECK(true == stack->isEmpty());
}

BOOST_AUTO_TEST_CASE(testException){
	BOOST_CHECK_THROW(stack->pop(),StackUnderflowException);
	for(int i = 0; i < 10;i++){
		stack->push(i);
	}
	BOOST_CHECK_THROW(stack->push(10),StackOverflowException);
}

BOOST_AUTO_TEST_SUITE_END()
