#ifndef _RECURSIVELIST_H_
#define _RECURSIVELIST_H_
/*
*@author Ionésio Junior
*/

#include "DoubleLinkedList.hpp"
/*
* Recursive Double Linked List Implementation
*/
//RecursiveDoubleLinkedList.hpp
template<class T>
class RecursiveDoubleLinkedList : public LinkedList<T>{
	private:
		T data;
		RecursiveDoubleLinkedList<T> *next;
		RecursiveDoubleLinkedList(T element);
		bool empty_root;
		void recursiveToVector(std::vector<T> * vetor);
		RecursiveDoubleLinkedList *searchPrevious(T element);
	public:
		RecursiveDoubleLinkedList();
		void insert(T element) override;
		void insertFirst(T element) override;		
		void remove(T element) override;
		void removeFirst() override;
		void removeLast() override;
		bool isEmpty() override;
		int size() override;
		std::vector<T> toVector() override;
		T *search(T element) override;
		T getData();
};

#endif
