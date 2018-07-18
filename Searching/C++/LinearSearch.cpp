#include<iostream>
using namespace std;

//this function will return position of number to be searched.
int findNum(int *arr,int num,int n){

	//ans will store the  
	int ans = -1;

	//loop to linearly search for number in the given array.
	for(int i=0;i<n;i++){

		//if arr[i] == num means we found the number on ith place.
		if(arr[i]==num){
			ans = i;
			return ans;
		}
	}
	return ans;
}

int main(){
	//n is the number of elements in the array
	int n;
	cin>>n;

	int arr[n];

	//loop to input the elements.
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}

	// num is the number to be searched in the array.
	int num;
	cin>>num;

	//NOTE: we will return with 0 base index, that means 1st element will be 0th element!
	cout<<findNum(arr,num,n);

	return 0;
}