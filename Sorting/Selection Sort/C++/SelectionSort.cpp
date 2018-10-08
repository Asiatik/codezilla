// Selection sort algorithm for C++
//Created by Efren Aguilar

//#include "stdafx.h"

//Swaps the values of two integers
void swap(int* num1, int* num2)
{
	int temp = *num1;
	*num1 = *num2;
	*num2 = temp;
}


/* Function to print an array */
void printArray(int arr[], int arrSize)
{
	int i;
	for (i = 0; i < arrSize; i++)
		printf("%d ", arr[i]);
	printf("\n");
}

//Applies selection sort on the array of the given size
void selectionSort(int arr[], int arrSize)
{
	int startPos = 0;
	int smallestFoundIndex;

	while (startPos < arrSize)
	{
		smallestFoundIndex = startPos;

		for (int i = startPos+1; i < arrSize; i++)
			if(arr[i] <= arr[smallestFoundIndex])
				smallestFoundIndex = i;

		swap(&arr[startPos], &arr[smallestFoundIndex]);
		startPos++;
	}
}



int main()
{
	int arr[] = { -634 ,-524 ,-5, 4 ,42, 2643, 23, -9520, 1852 ,3, -510, -510, 3, 3, 3, 15 };
	int n = sizeof(arr) / sizeof(arr[0]);
	selectionSort(arr, n);
	printf("Sorted array: \n");
	printArray(arr, n);
    return 0;
}

