#ifndef _DOUBLELINKEDLIST_H_
#define _DOUBLELINKEDLIST_H_
/*
*@author Ionésio Junior
*/

#include <cstdlib>
#include <iostream>
#include <vector>

/*
* Double Linked List Abstract Class
*/

template<class T>
class LinkedList{
	public:
		virtual void insert(T element) = 0;
		virtual void insertFirst(T element) = 0;		
		virtual void remove(T element) = 0;
		virtual void removeFirst() = 0;
		virtual void removeLast() = 0;
		virtual bool isEmpty() = 0;
		virtual int size() = 0;
		virtual std::vector<T> toVector() = 0;
		virtual T *search(T element) = 0;
		
};
#endif
