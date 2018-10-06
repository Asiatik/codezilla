#ifndef _ITERATIVELIST_H_
#define _ITERATIVELIST_H_
/*
*@author Ionésio Junior
*/

#include "DoubleLinkedList.hpp"
/*
*Double Linked List node implementation
*/

template<class T>
struct Node{
	T data;
	Node<T> * next;
	Node<T> *previous;
	
	Node(T value){
		this->data = value;
	}

	Node(T value,Node<T> *next){
		this->data = value;
		this->next = next;
	}

	Node(Node<T> *previous){
		this->previous = previous;
	}

	Node(T value,Node<T> *next,Node<T> *previous){
		this->data = value;
		this->next = next;
		this->previous = previous;
	}
};

/*
* Double Linked List Class Implementation
*/
template<class T>
class IterativeDoubleLinkedList : public LinkedList<T>{
	private:
		Node<T> *head;
		Node<T> *tail;
		Node<T> *searchNode(T element);
		Node<T> *getHead();

	public:

		IterativeDoubleLinkedList();
		void insert(T element) override;
		void insertFirst(T element) override;		
		void remove(T element) override;
		void removeFirst() override;
		void removeLast() override;
		bool isEmpty() override;
		int size() override;
		std::vector<T> toVector() override;
		T *search(T element) override;	
};

#endif
