#ifndef _ITERATIVELIST_H_
#define _ITERATIVELIST_H_
/*
*@author Ionésio Junior
*/
#include "LinkedList.hpp"
/*
* Single Linked List in iterative implementation
*/

/*
*Node struct 
*/
template<class T>
struct Node{
	T data;
	Node<T> *next;
	Node(T value){
		this->data = value;
	}
};

/*
*Single Linked List class
*/
//SingleLinkedList.hpp
template<class T>
class IterativeSingleLinkedList : public LinkedList<T>{
	private:
		Node<T> *head;
	public:
		IterativeSingleLinkedList();
		void insert(T element) override;
		void remove(T element) override;
		int size() override;
		T *search(T element) override;
		Node<T> *getHead();
		std::vector<T> toVector() override;
		bool isEmpty() override;
};

#endif
