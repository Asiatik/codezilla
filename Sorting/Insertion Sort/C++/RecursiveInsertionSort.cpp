// RecursiveInsertionSort.cpp
// Recursive implementation of the InsertionSort algorithm
// Created by Efren Aguilar for the codezilla project

//#include "stdafx.h"

//Given an array and its size, prints it to the console
void printArray(int arr[], int size)
{
	for (int i = 0; i < size; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}

//Given an array and its size, applies a recursive insertion sort to the array
void insertionSort_Recursive(int arr[], int arrSize)
{
	//Base case
	if (arrSize <= 1)
		return;

	//Sort all the elements of the array up to the last one
	insertionSort_Recursive(arr, arrSize - 1);

	int lastElem = arr[arrSize - 1];
	int j = arrSize - 2;

	//Insert the last element into its proper position
	while (j >= 0 && arr[j] > lastElem)
	{
		arr[j + 1] = arr[j];
		j--;
	}
	arr[j + 1] = lastElem;
}

int main()
{
	int arr[] = { -634 ,-524 ,-5, 4 ,42, 2643, 23, -9520, 1852 ,3, -510, -510, 3, 3, 3, 15 };
	int n = sizeof(arr) / sizeof(arr[0]);
	insertionSort_Recursive(arr, n);
	printf("Sorted array: \n");
	printArray(arr, n);
	return 0;
}

