#ifndef MERGESORTLINKEDLIST_H
#define MERGESORTLINKEDLIST_H

// Node of a linked list
template <class T>
class Node {
public:
	T val;
	Node<T>* next;
	Node<T>() {
		next = nullptr;
	}
	Node(T value) {
		next = nullptr;
		val = value;
	}
};

template <class T1, class T2>
class MergeSortLinkedList {
public:
	MergeSortLinkedList();
	T2 getLength(Node<T1>* N);
	void insertItem(Node<T1>*& head, Node<T1>* afterNode, T1 item);
	void insertItem(Node<T1>*& head, T1 afterItem, T1 item);
	void insertItemAtEnd(Node<T1>*& head, T1 item);
	void deleteItemAtEnd(Node<T1>*& head);
	void deleteItem(Node<T1>*& head, T1 item);
	void mergeSort(Node<T1>*& newList);
	~MergeSortLinkedList();
private:
	void sort(Node<T1>*& Head);
	Node<T1>* mergeSortedLists(Node<T1>* leftHead, Node<T1>* rightHead);
};

// To avoid linker error
#include "MergeSortLinkedList.cpp"

#endif
