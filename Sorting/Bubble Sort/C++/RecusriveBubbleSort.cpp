// RecusriveBubbleSort.cpp
// Recursive implementation of the BubbleSort algorithm
// Created by Efren Aguilar for the codezilla project

//#include "stdafx.h"

//Given two int pointers, swaps the values they point to
void swap(int* num1, int* num2)
{
	int temp = *num1;
	*num1 = *num2;
	*num2 = temp;
}

//Given an array and its size, prints it to the console
void printArray(int arr[], int size)
{
	for (int i = 0; i < size; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}

//Given an array and its size, applies a recursive bubble sort to the array
void bubbleSort_Recursive(int arr[], int arrSize)
{
	//Base Case
	if (arrSize == 1)
		return;

	//Ultimately gets the largest element to the end of the array
	for (int i = 0; i < arrSize - 1; i++)
	{
		if (arr[i] > arr[i + 1])
			swap(&arr[i], &arr[i + 1]);
	}

	//Recurse on what still needs to be sorted
	bubbleSort_Recursive(arr, arrSize - 1);
}


int main()
{
	int arr[] = { -634 ,-524 ,-5, 4 ,42, 2643, 23, -9520, 1852 ,3, -510, -510, 3, 3, 3, 15 };
	int n = sizeof(arr) / sizeof(arr[0]);
	bubbleSort_Recursive(arr, n);
	printf("Sorted array: \n");
	printArray(arr, n);
	return 0;
}

