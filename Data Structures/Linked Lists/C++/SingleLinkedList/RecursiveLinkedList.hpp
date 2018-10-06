#ifndef _RECURSIVELIST_H_
#define _RECURSIVELIST_H_
/*
*@author Ionésio Junior
*/

#include "LinkedList.hpp"
/*
* Recursive Linked List Implementation
*/
//RecursiveLinkedList.hpp
template<class T>
class RecursiveSingleLinkedList : public LinkedList<T>{
	private:
		T data;
		RecursiveSingleLinkedList<T> *next;
		RecursiveSingleLinkedList(T element);
		bool empty_root;
		void recursiveToVector(std::vector<T> * vetor);
	public:
		RecursiveSingleLinkedList();
		void insert(T element) override;
		void remove(T element) override;
		T *search(T element) override;
		T *getRoot();
		int size() override;
		std::vector<T> toVector() override;
		bool isEmpty() override;
		RecursiveSingleLinkedList *searchPrevious(T element);
		T getData();
};

#endif
