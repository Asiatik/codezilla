#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE DoubleLinkedListTest
/*
* @author : Ionesio Junior
*/

#include <boost/test/unit_test.hpp>
#include "../IterativeDoubleLinkedList.hpp"
#include  "../RecursiveDoubleLinkedList.hpp"
#include <cstdlib>


struct setUp{
	LinkedList<int> *list1 = new IterativeDoubleLinkedList<int>();
	LinkedList<int> *list2 = new RecursiveDoubleLinkedList<int>();
};

BOOST_FIXTURE_TEST_SUITE(SingleLinkedListTest,setUp)

BOOST_AUTO_TEST_CASE(testIsEmpty){
	BOOST_CHECK(true == list1->isEmpty());
	BOOST_CHECK(true == list2->isEmpty());
	list1->insert(10);
	list2->insert(10);
	BOOST_CHECK(false == list1->isEmpty());
	BOOST_CHECK(false == list2->isEmpty());
	list1->remove(10);
	list2->remove(10);
	BOOST_CHECK(true == list1->isEmpty());
	BOOST_CHECK(true == list2->isEmpty());
}

BOOST_AUTO_TEST_CASE(testSize){
	BOOST_CHECK(0 == list1->size());
	BOOST_CHECK(0 == list2->size());
	
	for(int i = 0 ;i < 100;i++){
		list1->insert(i);
		list2->insert(i);
		BOOST_CHECK(i + 1 == list1->size());
		BOOST_CHECK(i + 1 == list2->size());
	}
	
	int size = list1->size();
	
	list1->remove(300);
	BOOST_CHECK(size == list1->size());
	
	for(int i = 0; i < 50;i++){
		list1->remove(i);
		list2->remove(i);
		size--;
		BOOST_CHECK(size == list1->size());
		BOOST_CHECK(size == list2->size());
	}
	
	BOOST_CHECK(50 == list1->size());
	BOOST_CHECK(50 == list2->size());

	for(int i = 99;i>=50;i--){
		list1->remove(i);
		list2->remove(i);
		size--;
		BOOST_CHECK(size == list1->size());
		BOOST_CHECK(size == list1->size());
	}
	
	BOOST_CHECK(0 == list1->size());
	BOOST_CHECK(0 == list2->size());
}

BOOST_AUTO_TEST_CASE(testSearch){
	BOOST_CHECK(true == list1->isEmpty());
	BOOST_CHECK(true == list2->isEmpty());
	//Search number not inserted / in empty list
	for(int i = 0 ; i < 10000;i++){
		BOOST_CHECK(NULL == list1->search(i));
		BOOST_CHECK(NULL == list2->search(i));
	}	
	
	for(int i = 0 ;  i <  1000;i++){
		if( i < 20){
			list1->insert(i);
			list2->insert(i);
			BOOST_CHECK(i == *list1->search(i));
			BOOST_CHECK(i == *list2->search(i));
		}else{
			BOOST_CHECK(NULL == list1->search(i));
			BOOST_CHECK(NULL == list2->search(i));
		}
	}
	
	for(int i = 0 ; i < 20;i++){
		list1->remove(i);
		list2->remove(i);
		BOOST_CHECK(NULL == list1->search(i));
		BOOST_CHECK(NULL == list2->search(i));
	}
}

BOOST_AUTO_TEST_CASE(testInsert){
	BOOST_CHECK(0 == list1->size());
	BOOST_CHECK(0 == list2->size());
	BOOST_CHECK(true == list1->isEmpty());
	BOOST_CHECK(true == list2->isEmpty());
	
	//Test insert dif elements	
	for(int i =  -100 ; i < 100;i++){
		list1->insert(i);
		list2->insert(i);
	}
	BOOST_CHECK(200 == list1->size());
	BOOST_CHECK(200 == list2->size());
	
	//Test insert equals elements)
	for(int i = 0 ; i < 20;i++){
		list1->insert(10);
		list2->insert(10);
	}
	
	BOOST_CHECK(220 == list1->size());
	BOOST_CHECK(220 == list2->size());
}

BOOST_AUTO_TEST_CASE(testRemove){
	BOOST_CHECK(0 == list1->size());
	BOOST_CHECK(0 == list2->size());
	BOOST_CHECK(true == list1->isEmpty());
	BOOST_CHECK(true == list2->isEmpty());	

	//List (0,1,2, ... , 99)
	for( int i = 0 ; i < 100;i++){
		list1->insert(i);
		list2->insert(i);
	}
	
	BOOST_CHECK(false == list1->isEmpty());
	BOOST_CHECK(false == list2->isEmpty());
	
	//Try remove not inserted element
	list1->remove(101);
	list2->remove(101);
	
	BOOST_CHECK(100 == list1->size());
	BOOST_CHECK(100 == list2->size());


	//Remove by head (0,1,2, ... , 99)
	for(int i = 0 ; i < 100 ;i++){
		list1->remove(i);
		list2->remove(i);
	}
	
        BOOST_CHECK(0 == list1->size());
        BOOST_CHECK(0 == list2->size());
        BOOST_CHECK(true == list1->isEmpty());
        BOOST_CHECK(true == list2->isEmpty());

        //List (0,1,2, ... , 99)
        for( int i = 0 ; i < 100;i++){
                list1->insert(i);
                list2->insert(i);
        }

        BOOST_CHECK(false == list1->isEmpty());
        BOOST_CHECK(false == list2->isEmpty());
	
	for(int i = 99 ; i >= 0;i--){
		list1->remove(i);
		list2->remove(i);
	}
	
        BOOST_CHECK(0 == list1->size());
        BOOST_CHECK(0 == list2->size());
        BOOST_CHECK(true == list1->isEmpty());
        BOOST_CHECK(true == list2->isEmpty());
}

BOOST_AUTO_TEST_CASE(testToVector){
	std::vector<int> result;
	for(int i = 0 ; i < 100;i++){
		result.push_back(rand() % 1000);
	}
	
	for(int i = 0 ; i < result.size();i++){
		list1->insert(result[i]);
		list2->insert(result[i]);
	}
	
	BOOST_CHECK(result == list1->toVector());
	BOOST_CHECK(result == list2->toVector());
}

BOOST_AUTO_TEST_CASE(testInsertFirst){
	std::vector<int> result;
	for(int i = 100;i > 0;i--){
		result.push_back(i);
	}
	
	for(int i = 1 ; i <= 100;i++){
		list1->insertFirst(i);
		list2->insertFirst(i);
	}
	
	BOOST_CHECK(result == list1->toVector());
	BOOST_CHECK(result == list2->toVector());

}

BOOST_AUTO_TEST_CASE(testRemoveFirst){
	std::vector<int> result;
	for(int i = 0 ; i < 100;i++){
		list1->insert(i);
		list2->insert(i);
		result.push_back(i);
	}
	
	for(int i = 0 ; i < 100;i++){
		BOOST_CHECK(result == list1->toVector());
		BOOST_CHECK(result == list2->toVector());
		list1->removeFirst();
		list2->removeFirst();
		result.erase(result.begin());
	}
	
	BOOST_CHECK(0 == list1->size());
	BOOST_CHECK(true == list1->isEmpty());
	BOOST_CHECK(0 == list2->size());
        BOOST_CHECK(true == list2->isEmpty());
}

BOOST_AUTO_TEST_CASE(testRemoveLast){
	std::vector<int> result;
	for(int i = 0 ; i < 100;i++){
		list1->insert(i);
		list2->insert(i);
		result.push_back(i);
	}
	

	for(int i = 99; i >= 0;i--){
		BOOST_CHECK(result == list1->toVector());
		BOOST_CHECK(result == list2->toVector());
		list1->removeLast();
		list2->removeLast();
		result.erase(result.begin() + i);
	}
}
BOOST_AUTO_TEST_SUITE_END()
