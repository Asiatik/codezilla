#include <iostream>
#include <vector>
#include <ctime>
#include <cstring>
#include "BitonicSort.h"

#define SIZE 16
#define NUM_MAX 100

bool testDifferentElements(int* sortWithBitonic, int* sortWithLibrary) {
	bitonicSort<int, int>* b;
	for (int i = 0; i < SIZE; i++) {
		sortWithBitonic[i] = rand() / (RAND_MAX / NUM_MAX);
	}
	memcpy(sortWithLibrary, sortWithBitonic, SIZE * sizeof(int));
	b->bitonicsort(sortWithBitonic, SIZE);
	std::sort(sortWithLibrary, sortWithLibrary + SIZE);
	return std::equal(sortWithBitonic, sortWithBitonic + SIZE, sortWithLibrary);
}

bool testSortedElements(int* sortWithBitonic, int* sortWithLibrary) {
	bitonicSort<int, int>* b;
	for (int i = 0; i < SIZE; i++) {
		sortWithLibrary[i] = rand() / (RAND_MAX / NUM_MAX);
	}
	std::sort(sortWithLibrary, sortWithLibrary + SIZE);
	memcpy(sortWithLibrary, sortWithBitonic, SIZE * sizeof(int));
	b->bitonicsort(sortWithBitonic, SIZE);
	return std::equal(sortWithBitonic, sortWithBitonic + SIZE, sortWithLibrary);
}

bool testRepeatedElements(int* sortWithBitonic, int* sortWithLibrary) {
	bitonicSort<int, int>* b;
	for (int i = 0; i < SIZE; i++) {
		sortWithBitonic[i] = (rand() / (RAND_MAX / NUM_MAX)) % 15;
	}
	memcpy(sortWithLibrary, sortWithBitonic, SIZE * sizeof(int));
	b->bitonicsort(sortWithBitonic, SIZE);
	std::sort(sortWithLibrary, sortWithLibrary + SIZE);
	return std::equal(sortWithBitonic, sortWithBitonic + SIZE, sortWithLibrary);
}

bool testSingleElement() {
	bitonicSort<int, int>* b;
	int sortWithBitonic = 10;
	int sortWithLibrary = 10;
	b->bitonicsort(&sortWithBitonic, 1);
	return std::equal(&sortWithBitonic, &sortWithBitonic + 1, &sortWithLibrary);
}

int main(int argc, char **argv) {
	int* sortWithBitonic = new int[SIZE];
	int* sortWithLibrary = new int[SIZE];
	srand(time(NULL));
	std::cout << "Starting test with randowm numbers....... " << std::endl;
	assert(testDifferentElements(sortWithBitonic, sortWithLibrary));
	std::cout << "Starting test with sorted array....... " << std::endl;
	assert(testSortedElements(sortWithBitonic, sortWithLibrary));
	std::cout << "Starting test with duplicates....... " << std::endl;
	assert(testRepeatedElements(sortWithBitonic, sortWithLibrary));
	std::cout << "Starting test with single element....... " << std::endl;
	assert(testSingleElement());
	std::cout << "SUCCESS....... All tests passed" << std::endl;

	delete sortWithBitonic;
	delete sortWithLibrary;
}
