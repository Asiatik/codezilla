// This is an implemation of MergeSortArray class

#include <iostream>
#include <fstream>
#include <cmath>
#include "MergeSortArray.h"

// Uncommenet to debug the code
//#define DEBUG 

// This is not a memober of class
template <class T, class N>
void printArray(T *arr, N left, N right) {
	for (N i = left; i <= right; i++) {
		std::cout << arr[i] << " ";
	}
	std::cout << std::endl;
}

template <class T, class N>
MergeSortArray<T, N>::MergeSortArray() {
	newArray = nullptr;
}

template <class T, class N>
void MergeSortArray<T, N>::mergeSort(T* arr, N len) {
	newArray = new T[len];
#ifdef DEBUG
	std::cout << "Length: " << len << std::endl;
#endif
	sort(arr, 0, len-1);
}

// left index, right index of the array to sort
template <class T, class N>
void MergeSortArray<T, N>::sort(T* arr, N left, N right) {
	if (right == left) return;
	// Split the array
	N mid = floor((left+right) / 2);

#ifdef DEBUG
	std::cout << "Left start: " << left << " ";
	std::cout << "Left end: " << mid << std::endl;
	printArray(arr, left, mid);
#endif
	// Call merge sort on left chunk
	sort(arr, left, mid);
#ifdef DEBUG
	std::cout << "Right start: " << mid+1 << " ";
	std::cout << "Right end: " << right << std::endl;
	printArray(arr, mid+1, right);
#endif
	// Call merge sort on right chunk
	sort(arr, mid+1, right);
	// Merge the sorted elemnts on right side
	mergeTheArray(arr, left, mid, right);
}

template <class T, class N>
void MergeSortArray<T, N>::mergeTheArray(T* arr, N left, N mid, N right) {
#ifdef DEBUG
	std::cout << "Merging the array: " << std::endl;
	std::cout << "Left start: " << left << " Mid: " << mid << " Right end : " << right << std::endl;
#endif
	// Left chunk is arr[left....mid]
	// Right chunk is arr[mid+1....right]

	N k = left;
	N i = left;
	N j = mid+1;
	// Compare left and right chunk
	while (i <= mid && j <= right) {
		if (arr[i] > arr[j]) {
			newArray[k] = arr[j];
			j++;
		}
		else {
			newArray[k] = arr[i];
			i++;
		}
		k++;
	}
	// Copy the rest of the elements from left chunk if any
	if (i <= mid) {
		for (; k <= right; k++) {
			newArray[k] = arr[i];
			i++;
		}
	}
	// Copy the rest of the elements from right chunk if any
	else if (j <= right) {
		for (; k <= right; k++) {
			newArray[k] = arr[j];
			j++;
		}
	}
	// arr[left...right] is replaced with sorted values stored in newArray[left....right]
	for (k = left; k <= right; k++) {
		arr[k] = newArray[k];
	}
#ifdef DEBUG
	// print the sorted part
	printArray(arr, left, right);
#endif
}

template <class T, class N>
MergeSortArray<T, N>::~MergeSortArray() {
	delete[] newArray;
}
