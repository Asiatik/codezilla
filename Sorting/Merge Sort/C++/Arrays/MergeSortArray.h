#ifndef MERGESORTARRAY_H
#define MERGESORTARRAY_H

template <class T, class N>
class MergeSortArray {
public:
	MergeSortArray();
	void mergeSort(T* arr, N len);
	~MergeSortArray();
private:
	void sort(T* arr, N left, N right);
	void mergeTheArray(T* arr, N left_start, N right_start, N right_end);
	// Buffer
	T *newArray;
};
// To avoid linker error
#include "MergeSortArray.cpp"

#endif
