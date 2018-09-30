/*********************************************************************************
* Instructions: 
*    To compile: g++ MergeSort_LinkedlistTest.cpp -o MergeSort_LinkedlistTest -std=c++11
*    To run: ./MergeSort_LinkedlistTest [#elements]
*    Where #elements is number of elements in an array, default is 100.
* Author: Mounika Ponugoti
*********************************************************************************/
#include <iostream>
#include <fstream>
#include <iomanip>
#include <ctime>
#include <cstdlib>
#include "MergeSortLinkedList.h"

#define NUM_MAX 15

// Number of elements in an array
int length = 100;

// Initialize the list with random values
template <class T1, class T2>
void initializeList(Node<T1>*& newList, T2 length) {
	// mark head
	Node<T1>* head = nullptr;
	for (T2 i = 0; i < length; i++) {
		// new node
		Node<T1>* N = new Node<T1>;
		N->val = static_cast <T1> (rand()) / static_cast <T1> (RAND_MAX / NUM_MAX);
		// If the list is empty this is the head
		if (newList == nullptr) {
			newList = N;
			head = newList;
		}
		else {
			newList->next = N;
			newList = newList->next;
		}
	}
	newList = head;
	head = nullptr;
	delete head;
}

int main(int argc, char **argv)
{
	if (argc == 2) {
		length = std::atoi(argv[1]);
	}
	if (argc > 2) {
		std::cout << "Usage: ./main [#elemnts]" << std::endl;
		exit(1);
	}
	// Seed for random number generator
	srand(time(NULL));
	// Sorting integer Array
	Node<int> *newList = nullptr;
	initializeList<int, int>(newList, length);
	std::cout << "Unsorted Array: " << std::endl;
	printList <int>(newList);

	MergeSortLinkedList<int, int> mergeSort_obj;
	mergeSort_obj.mergeSort(newList);
	std::cout << "Sorted Array: " << std::endl;
	printList<int>(newList);

	// Sorting floating point numbers
	Node<double> *newList_f = nullptr;
	MergeSortLinkedList<double, int> mergeSort_obj_2;
	// Slower, because always go through the entire list to find where to add new element
	mergeSort_obj_2.insertItem(newList_f, -2, 150);
	mergeSort_obj_2.insertItemAtEnd(newList_f, 10.5);
	mergeSort_obj_2.insertItemAtEnd(newList_f, 0.1);
	mergeSort_obj_2.insertItemAtEnd(newList_f, 4.5);
	mergeSort_obj_2.insertItemAtEnd(newList_f, 2.7);
	mergeSort_obj_2.insertItem(newList_f, newList_f->next, 8.9);
	mergeSort_obj_2.insertItem(newList_f, 4.5, 12.9);
	mergeSort_obj_2.insertItemAtEnd(newList_f, 0.01);
	mergeSort_obj_2.insertItem(newList_f, newList_f->next->next->next, -1.9);
	mergeSort_obj_2.insertItem(newList_f, 0.01, 100);

//	initializeList<float, int>(newList_f, length);
	std::cout << "Unsorted Array: " << std::endl;
	std::cout << std::fixed << std::setprecision(2);
	printList<double>(newList_f);

	mergeSort_obj_2.mergeSort(newList_f);
	std::cout << "Sorted Array: " << std::endl;
	printList<double>(newList_f);

	// Free the allocated memory */
	delete[] newList;
	delete[] newList_f;
	return 0;
}
