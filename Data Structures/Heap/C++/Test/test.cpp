#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE HeapTest
/*
* @author : Ionesio Junior
*/

#include <boost/test/unit_test.hpp>
#include "../BinaryHeap.hpp"
#include <cstdlib>
#include <iostream>
#include <time.h>
#include <vector>


struct setUp{
	BinaryHeap<int> *heap = new BinaryHeap<int>(10);
	int empty[0] = {};
	int even[10] = {9,8,7,6,5,4,3,2,1,0};
	int odd[9] = {9,8,7,6,5,4,3,2,1};
	int repeated[9] = {8,5,8,5,9,5,7,8,5};
	
	int equal[5] = {5,5,5,5,5};
	
	int repeatedOrdered[9] = {5,5,5,5,7,8,8,8,9};
	int evenOrdered[10] = {0,1,2,3,4,5,6,7,8,9};
	int oddOrdered[9] = {1,2,3,4,5,6,7,8,9};
};

BOOST_FIXTURE_TEST_SUITE(HeapTest,setUp)
BOOST_AUTO_TEST_CASE(testInit){
	BOOST_CHECK(true == heap->isEmpty());
	BOOST_CHECK(false == heap->isFull());
	BOOST_CHECK(NULL == heap->rootElement());
	BOOST_CHECK(0 == heap->size());
}

BOOST_AUTO_TEST_CASE(testIsEmpty){
	BOOST_CHECK(true == heap->isEmpty());
	heap->insert(10);
	BOOST_CHECK(false == heap->isEmpty());
	heap->extractRoot();
	BOOST_CHECK(true == heap->isEmpty());
}

BOOST_AUTO_TEST_CASE(testSize){
	BOOST_CHECK(0 == heap->size());
	for(int i = 0 ; i < 5;i++){
		heap->insert(i);
		BOOST_CHECK(i + 1 == heap->size());
	}
	BOOST_CHECK(5 == heap->size());
	for(int i = 10; i < 20 ;i = i + 2){
		heap->insert(i);
	}
	BOOST_CHECK(10 == heap->size());
	
	for(int i = 0 ; i < 5;i++){
		heap->extractRoot();
	}
	
	BOOST_CHECK(5 == heap->size());
}


BOOST_AUTO_TEST_CASE(testInsert){
	BOOST_CHECK(0 == heap->size());
	
	//Test insert repeated elements
	heap->insert(5);
	BOOST_CHECK(1 == heap->size());
	heap->insert(5);
	BOOST_CHECK(2 == heap->size());
	
	heap->extractRoot();
	heap->extractRoot();
	BOOST_CHECK(0 == heap->size());

	//Test responsive array
	for(int i = 0 ; i < 10;i++){
		heap->insert(i);
		BOOST_CHECK(i == *heap->rootElement());
	}
	BOOST_CHECK(true == heap->isFull());
	heap->insert(10);
	BOOST_CHECK(false == heap->isFull());
	BOOST_CHECK(11 == heap->size());
}

BOOST_AUTO_TEST_CASE(testExtractRoot){
	BOOST_CHECK(0 == heap->size());
	BOOST_CHECK(true == heap->isEmpty());
	
	for(int i = 0; i < 100;i++){
		heap->insert(i);
	}
	
	BOOST_CHECK(100 == heap->size());
	BOOST_CHECK(false == heap->isEmpty());
	BOOST_CHECK(99 == *heap->rootElement());

	for(int i = 99; i >= 0;i--){
		BOOST_CHECK(i == heap->extractRoot());
	}
	
	BOOST_CHECK(0 == heap->size());
	BOOST_CHECK(true == heap->isEmpty());
	
	for(int i = 0 ; i < 10;i++){
		if(i < 5){
			heap->insert(10);
		}else{
			heap->insert(20);
		}
	}
	
	BOOST_CHECK(10 == heap->size());
	
	for(int i = 0 ; i < 10;i++){
		if(i < 5){
			BOOST_CHECK(20 == heap->extractRoot());
		}else{
			BOOST_CHECK(10 == heap->extractRoot());
		}
	}
}

BOOST_AUTO_TEST_CASE(testRootElement){
	BOOST_CHECK(true == heap->isEmpty());
	heap->insert(100);
	for(int i = 0 ; i < 10;i++){
		BOOST_CHECK(100 == *heap->rootElement());
	}
	
	BOOST_CHECK(1 == heap->size());
	
	for(int i = 0 ; i < 10;i++){
		heap->insert(i);
		BOOST_CHECK(100 == *heap->rootElement());
	}
	
	for(int i = 0 ; i <= 10;i++){
		BOOST_CHECK(*heap->rootElement() == heap->extractRoot());
	}
}

BOOST_AUTO_TEST_CASE(testHeapSort){
	//Test Even Array
	Array<int> result = heap->heapSort(even,10);
	for(int i = 0 ; i < result.size;i++){
		BOOST_CHECK(evenOrdered[i] == result[i]);
	}
	
	
	//Test Odd Array
	result = heap->heapSort(odd,9);
	for(int i = 0 ; i < result.size;i++){
		BOOST_CHECK(oddOrdered[i] == result[i]);
	}
	
	
	//Test Empty array
	result = heap->heapSort(empty,0);
	for(int i = 0; i < result.size;i++){
		BOOST_CHECK(empty[i] == result[i]);
	}
	
	//Test Repeated Array
	result = heap->heapSort(repeated,9);
	for(int i = 0 ; i < result.size;i++){
		BOOST_CHECK(repeatedOrdered[i] == result[i]);
	}

	//Test equal array
	result = heap->heapSort(equal,5);
	for(int i = 0 ; i < result.size;i++){
		BOOST_CHECK(equal[i] == result[i]);
	}
}

BOOST_AUTO_TEST_CASE(testBuildHeap){
	
	//Test even array
	BOOST_CHECK(0 == heap->size());
	BOOST_CHECK(true == heap->isEmpty());
	heap->buildHeap(even,10);
	BOOST_CHECK(10 == heap->size());
	BOOST_CHECK(false == heap->isEmpty());
	for(int i = 9 ; i >= 0;i--){
		BOOST_CHECK(i == heap->extractRoot());
	}

	//Test odd array
        BOOST_CHECK(0 == heap->size());
        BOOST_CHECK(true == heap->isEmpty());
        heap->buildHeap(odd,9);
        BOOST_CHECK(9 == heap->size());
        BOOST_CHECK(false == heap->isEmpty());
        for(int i = 9 ; i > 0;i--){
                BOOST_CHECK(i == heap->extractRoot());
        }
	
	//Test empty array	
        BOOST_CHECK(0 == heap->size());
        BOOST_CHECK(true == heap->isEmpty());
        heap->buildHeap(empty,0);
        BOOST_CHECK(0 == heap->size());
        BOOST_CHECK(true == heap->isEmpty());
        
	//Test equal array
        BOOST_CHECK(0 == heap->size());
        BOOST_CHECK(true == heap->isEmpty());
        heap->buildHeap(equal,5);
        BOOST_CHECK(5 == heap->size());
        BOOST_CHECK(false == heap->isEmpty());
        for(int i = 5 ; i > 0;i--){
                BOOST_CHECK(5 == heap->extractRoot());
        }

	//Test repeated array
	int reverseRepeated[9] = {9,8,8,8,7,5,5,5,5};
        BOOST_CHECK(0 == heap->size());
        BOOST_CHECK(true == heap->isEmpty());
        heap->buildHeap(repeated,9);
        BOOST_CHECK(9 == heap->size());
        BOOST_CHECK(false == heap->isEmpty());
        for(int i = 0 ; i < 9;i++){
		BOOST_CHECK(reverseRepeated[i] == heap->extractRoot());
        }
}

BOOST_AUTO_TEST_CASE(testException){
	BOOST_CHECK_THROW(heap->extractRoot(),HeapUnderflowException);
}


BOOST_AUTO_TEST_SUITE_END()
