/*********************************************************************************
* Instructions: 
*    To compile: g++ MergeSort_ArrayTest.cpp -o MergeSort_ArrayTest -std=c++11
*    To run: ./MergeSort_ArrayTest [#elements]
*    Where #elements is number of elements in an array, default is 100.
* Author: Mounika Ponugoti
*********************************************************************************/
#include <iostream>
#include <fstream>
#include <iomanip>
#include <ctime>
#include <cstdlib>
#include "MergeSortArray.h"

// Number of elements in an array
int length = 100;

// Prints the array
template <class T, class N>
void printArray(T *arr, N length) {
	for (N i = 0; i < length; i++) {
		std::cout << arr[i] << " ";
	}
	std::cout << std::endl;
}

// Initialize the array with random values
template <class T, class N>
void initializeArray(T *arr, N length) {
	for (N i = 0; i < length; i++) {
		arr[i] = static_cast <T> (rand()) / static_cast <T> (RAND_MAX/10);
	}
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
	int *arr = new int[length];
	initializeArray<int, int>(arr, length);
	std::cout << "Unsorted Array: " << std::endl;
	printArray<int, int>(arr, length);

	MergeSortArray<int, int> mergeSort_obj;
	mergeSort_obj.mergeSort(arr, length);
	std::cout << "Sorted Array: " << std::endl;
	printArray(arr, length);

	// Sorting floating point numbers
	float *arr_f = new float[length];
	initializeArray<float, int>(arr_f, length);
	std::cout << "Unsorted Array: " << std::endl;
	std::cout << std::fixed << std::setprecision(2);
	printArray<float, int>(arr_f, length);

	MergeSortArray<float, int> mergeSort_obj_2;
	mergeSort_obj_2.mergeSort(arr_f, length);
	std::cout << "Sorted Array: " << std::endl;
	printArray(arr_f, length);

	// Free the allocated memory
	delete[] arr;
	delete[] arr_f;
	return 0;
}
