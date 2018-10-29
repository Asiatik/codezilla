// This is an implemation of MergeSortLinkedList class

#include <iostream>
#include <fstream>
#include <cmath>
#include "MergeSortLinkedList.h"

// Uncommenet to debug the code
//#define DEBUG 

// This is not a memober of class
template <class T>
void printList(Node<T>* temp) {
	while (temp != nullptr) {
		std::cout << "|" << temp->val << "|-->";
		temp = temp->next;
	}
	std::cout << "null" << std::endl;
	return;
}

template <class T1, class T2>
MergeSortLinkedList<T1, T2>::MergeSortLinkedList() {
}

template <class T1, class T2>
T2 MergeSortLinkedList<T1, T2>::getLength(Node<T1>* temp) {
	T2 length = 0;
	while (temp != nullptr) {
		temp = temp->next;
		length++;
	}
	return length;
}
// When the node is given
template <class T1, class T2>
void MergeSortLinkedList<T1, T2>::insertItem(Node<T1>*& head, Node<T1>* afterNode, T1 item) {
	// empty list or insert in the end
	if ((head == nullptr) || (afterNode->next == nullptr)) {
		insertItemAtEnd(head, item);
	}
	else { // insert in the middle
		Node<T1>* N = new Node<T1>(item);
		N->next = afterNode->next;
		afterNode->next = N;
	}
	return;
}
//when the item is given
template <class T1, class T2>
void MergeSortLinkedList<T1, T2>::insertItem(Node<T1>*& head, T1 afterItem, T1 item) {
	// empty list or insert in the end
	Node<T1>* findNode = head;
	// find the node
	while ((head != nullptr)&&(findNode->val != afterItem) && (findNode->next != nullptr)) {
		findNode = findNode->next;
	}
	if ((head == nullptr) || (findNode->next == nullptr)) {
		insertItemAtEnd(head, item);
	}
	else { // insert in the middle
		Node<T1>* N = new Node<T1>(item);
		N->next = findNode->next;
		findNode->next = N;
	}
	return;
}

template <class T1, class T2>
void MergeSortLinkedList<T1, T2>::insertItemAtEnd(Node<T1>*& head, T1 item) {
	// already initialized with item
	Node<T1>* N = new Node<T1>(item); 
	if (head == nullptr) {
		head = N;
	}
	else {
		Node<T1>* temp = head;
		while (temp->next != nullptr) {
			temp = temp->next;
		}
		temp->next = N;
	}
	return;
}

template <class T1, class T2>
void MergeSortLinkedList<T1, T2>::deleteItem(Node<T1>*& head, T1 item) {
	Node<T1>* prev, *deleteNode;
	deleteNode = head;
	while ((deleteNode != nullptr) && (deleteNode->val != item)) {
		prev = deleteNode;
		deleteNode = deleteNode->next;
	}
	if (deleteNode == nullptr) { 
		return; 
	}
	else if (deleteNode == head) {
		head = deleteNode->next; 
	}
	else { 
		prev->next = deleteNode->next; 
	}
	delete deleteNode;
	return;
}

template <class T1, class T2>
void MergeSortLinkedList<T1, T2>::deleteItemAtEnd(Node<T1>*& head) {
	Node<T1>* curr, *prev;
	curr = head;
	if (curr == nullptr) return;
	while (curr->next != nullptr) {
		prev = curr;
		curr = curr->next;
	}
	if (curr == head) head = nullptr;
	else prev->next = nullptr;
	delete curr;
	return;
}

template <class T1, class T2>
void MergeSortLinkedList<T1, T2>::mergeSort(Node<T1>*& newList) {
	sort(newList);
}

// left index, right index of the array to sort
template <class T1, class T2>
void MergeSortLinkedList<T1, T2>::sort(Node<T1>*& Head) {
	// base case
	if (Head == nullptr || Head->next == nullptr) return;
	// Split the list
	T2 mid = ceil(getLength(Head) / 2);
	Node<T1>* newRightHead = nullptr;
	Node<T1>* newLeftHead = nullptr;
#ifdef DEBUG
	std::cout << "List: ";
	printList<T1>(Head);
	std::cout << "mid point: " << mid << std::endl;
#endif
	newLeftHead = Head;
	for (T2 i = 1; i < mid; i++) {
		newLeftHead = newLeftHead->next;
	}
	// start of the right part
	newRightHead = newLeftHead->next;
	newLeftHead->next = nullptr;
	// reset to beginning
	newLeftHead = Head;
#ifdef DEBUG
	std::cout << "Left start: " << newLeftHead->val << " ";
	printList<T1>(newLeftHead);
#endif
	// Call merge sort on left chunk
	sort(newLeftHead);
#ifdef DEBUG
	std::cout << "Right start: " << newRightHead->val << " ";
	printList<T1>(newRightHead);
#endif
	// Call merge sort on right chunk
	sort(newRightHead);
	// Merge the sorted elemnts on right side
	Head = mergeSortedLists(newLeftHead, newRightHead);
}

template <class T1, class T2>
Node<T1>* MergeSortLinkedList<T1, T2>::mergeSortedLists(Node<T1>* leftHead, Node<T1>* rightHead) {
#ifdef DEBUG
	std::cout << "Merging the array: " << std::endl;
#endif
	Node<T1>* result = new Node<T1>; // dummy node
	Node<T1>* temp = result; 

	while (leftHead != nullptr && rightHead != nullptr) {
		if (leftHead->val > rightHead->val) {
			// move the right side list elememt to end of result
			temp->next = rightHead;
			rightHead = rightHead->next;
		}
		else {
			// move the left side list elememt to end of result
			temp->next = leftHead;
			leftHead = leftHead->next;
		}
		temp = temp->next;
		temp->next = nullptr;

	}
	// add rest of the elements
	if (leftHead != nullptr) {
		// just point to leftover list
		temp->next = leftHead;	
	}
	else if (rightHead != nullptr) {
		temp->next = rightHead;
	}
#ifdef DEBUG
	// print the sorted part
	std::cout << "--Left sorted: ";
	printList(leftHead);
	std::cout << "--Right sorted: ";
	printList(rightHead);
#endif
	// to delete dummy node
	rightHead = result->next;
	// delete dummy node
	delete result;

	return rightHead;
}

template <class T1, class T2>
MergeSortLinkedList<T1, T2>::~MergeSortLinkedList() {

}
