// BubbleSort.cpp 
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

//Given an array and its size, applies bubble sort to the array
void bubbleSort(int toSort[], int size)
{
	bool sorted;
	while (true)
	{
		//assume sorted is true until it is shown to be false
		sorted = true;
		for (int i = 0; i < size - 1; i++)
		{
			if (toSort[i] > toSort[i + 1])
			{
				sorted = false;
				swap(&toSort[i], &toSort[i + 1]);
			}
		}
		//If no swapping was ever done, the sorting is complete
		if (sorted)
			break;
	}
}

//Given an array and its size, applies bubble sort to the array
//Does so in debug mode (with prints of the array status on each swap
void bubbleSort_debugMode(int toSort[], int size)
{
	printf("Applying sort on array: ");
	printArray(toSort, size);
	bool sorted;
	while (true)
	{
		//assume sorted is true until it is shown to be false
		sorted = true;
		for (int i = 0; i < size - 1; i++)
		{
			if (toSort[i] > toSort[i + 1])
			{
				sorted = false;
				swap(&toSort[i], &toSort[i + 1]);
				printf("ARRAY CHANGES MADE!\n");
				printf("Swapped %d and %d\n", toSort[i], toSort[i + 1]);
				printf("Array is now: ");
				printArray(toSort, size);
			}
		}
		//If no swapping was ever done, the sorting is complete
		if (sorted)
			break;
	}
}

int main()
{
	int arr[] = { 64, 34, 25, 12, 22, 11, 90 };
	int size = sizeof(arr)/sizeof(arr[0]);
	bubbleSort(arr, size);
	printf("Sorted array: \n");
	printArray(arr, size);
    return 0;
}

