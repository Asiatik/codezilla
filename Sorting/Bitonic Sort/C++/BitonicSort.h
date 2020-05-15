// Implementation of Bitonic sort
#ifndef BITONICSORT_H
#define BITONICSORT_H

#include <cmath>
#include <cassert> 
#include <algorithm>

//#define DEBUG 

// This is not a memober of class
template <class T1, class T2>
void printList(T1 temp, T2 startIndex, T2 length) {
	for (T2 i = startIndex; i < startIndex + length; i++) {
		std::cout << temp[i] << " ";
	}
	std::cout << std::endl;
	return;
}

template<class T1, class T2>
class bitonicSort {
private:
	bitonicSort() { }
	void compareAndSwap(bool increasing, T1 *arr, T2 index1, T2 index2);
	void bitonicMerge(bool increasing, T1 *arr, T2 startIndex, T2 length);
	void bitonicSeq(bool increasing, T1 *arr, T2 startIndex, T2 length);

public:
	void bitonicsort(T1 *arr, T2 length);
};

template<class T1, class T2>
void bitonicSort<T1, T2>::compareAndSwap(bool increasing, T1 *arr, T2 index1, T2 index2) {
	if (increasing && (arr[index1] > arr[index2]))
		std::swap(arr[index1], arr[index2]);
	else if ((!increasing) && (arr[index1] < arr[index2]))
		std::swap(arr[index1], arr[index2]);
}

template<class T1, class T2>
void bitonicSort<T1, T2>::bitonicMerge(bool increasing, T1 *arr, T2 startIndex, T2 length) {
	if (length < 2) return;
	// Compare and swap the elements if they are not in specified order
	for (T2 i = startIndex; i < startIndex + length / 2; i++) {
		compareAndSwap(increasing, arr, i, i + length / 2);
	}
	T2 halfArrLength = length / 2;
	// Call bitonic merge again on reduced size
	bitonicMerge(increasing, arr, startIndex, halfArrLength);
#ifdef DEBUG
	if (halfArrLength > 1){
		std::cout << "Lower part: ";
		printList(arr, startIndex, length);
	}
#endif // DEBUG
	bitonicMerge(increasing, arr, startIndex + halfArrLength, halfArrLength);
#ifdef DEBUG
	if (halfArrLength > 1){
		std::cout << "Upper part: ";
		printList(arr, startIndex + halfArrLength, length);
	}
#endif // DEBUG
}

template<class T1, class T2>
void bitonicSort<T1, T2>::bitonicSeq(bool increasing, T1 *arr, T2 startIndex, T2 length) {
	if (length < 2) return;
	T2 leftIndex = startIndex + length / 2;
	T2 rightIndex = startIndex;

	// Sort lower part to increasing
	bitonicSeq(true, arr, rightIndex, length / 2);
	// Sort upper part to decreasing
	bitonicSeq(false, arr, leftIndex, length / 2);
	// Merge the bitonic sequences
	bitonicMerge(increasing, arr, startIndex, length);
#ifdef DEBUG
	std::cout << "After Merge: ";
	printList(arr, startIndex, length);
#endif // DEBUG

}

template<class T1, class T2>
void bitonicSort<T1, T2>::bitonicsort(T1 *arr, T2 length) {
	// Bitonic sort is for 2^n
	assert(ceil(log2(length)) == floor(log2(length)));
	bitonicSeq(true, arr, 0, length);
}

#endif