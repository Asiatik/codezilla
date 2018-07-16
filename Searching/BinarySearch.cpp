#include<iostream>
using namespace std;

int findNumber(int* arr,int num,int n){

	//start is the starting index of the array
	int start = 0;

	//end is the ending index of the array
	int end = n-1;

	while(start<=end){
		//mid will store the middle element of the array
		int mid = (start+end)/2;

		//checking if the element is present in the middle position
		if(arr[mid] == num)
			return mid;

		//if the middle element is smalller than the number to be searched then 
		//we will have to search in the right part of the array that is why we take start pointer to mid+1
		else if(arr[mid] < num)
			start = mid+1;

		//if the middle element is higher than the number to be searched then 
		//we will have to search in the left part of the array that is why we take end pointer to mid-1
		else
			end = mid-1;
	}

	return -1;

}

int main(){
	//number of elements for array.
	int n;
	cin>>n;

	//arr is the array to store the elements.
	int arr[n];

	//input loop to store array elements.
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}

	//num is the number to be searched
	int num;
	cin>>num;
	cout<<findNumber(arr,num,n);
	return 0;
}