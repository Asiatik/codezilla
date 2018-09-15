//Program to perform Merge sort on an array
//A much better sorting algorithm for an array would be quicksort
//For linked lists, merge sort will be much better.
#include<iostream>
using namespace std;

void merge(int arr[], int left, int middle, int right)
{
	int n1 = middle - left + 1;//get the number of elements from left to mid
	int n2 = right - middle;//get the number of elements from mid to right.
	int i,j,k;
	
	
	//creating temporary arrays
	int Left[n1], Right[n2];
	//the below loops are made to copy the data into the left 
	//and right side array
	for(i=0;i<n1;i++)
		Left[i] = arr[left+i];
		
	for(j=0;j<n2;j++)
		Right[j] = arr[middle + 1 + j];
	
	i=0;
	j=0;
	k=left;
	//arr[k] is the sorted array
	while(i<n1 && j<n2)
	{
		if(Left[i] <= Right[j])
		{
			arr[k] = Left[i];
			i++;
		}
		else
		{
			arr[k] = Right[j];
			j++;
		}
		k++;
	}	
	
	//a while loop to copy the remaining elements of Left[], if
	//there is any
	while(i<n1)
	{
		arr[k] = Left[i];
		i++;
		k++;
	}
	
	//a while loop to copy the remaining elements of Right[], if 
	//there is any
	while(j<n2)
	{
		arr[k] = Right[j];
		j++;
		k++;
	}
	
}

//function to recursively sort the array
void mergeSort(int arr[], int left, int right)
{
	if(left<right)
	{
		int mid = left + (right - left)/2;//this is done to avoid overflow
		
		mergeSort(arr, left, mid);
		mergeSort(arr, mid+1,right);
		
		merge(arr, left, mid, right);
	}
}

int main()
{
	int n;//size of the array
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	int startIndex;
	int endIndex;
  
	//the range of startIndex and endIndex should be between
	//0 and size_of_array-1 
	//including this to sort sub parts of the array
	//as well as the entire array if needed based on the 
	//input given.
	
  cin>>startIndex;//between 0 and n-1
	cin>>endIndex;//between 0 and n-1
	
  mergeSort(arr,startIndex,endIndex);
	//after mergesort print the array. Can also print the sorted array from the given startIndex and EndIndex
  for(int i=0;i<n;i++)
	{
		cout<<arr[i]<<" ";
	}
	return 0;
}
