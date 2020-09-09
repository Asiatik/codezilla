#include<iostream>
using namespace std;

void insertion(int n, int a[]){
	int key,j;
	for(int i=1;i<n;i++){
		key = a[i];
		j = i-1;
		while(j>=0 && a[j]>key){
			a[j+1] = a[j];
			j--;
		}
		a[j+1]=key;
	}
}

int main(){
	int n;
	cout<<"Enter the size of the array : ";
	cin>>n;
	int a[n];
	cout<<"Enter the array elements\n";
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	insertion(n,a);
	cout<<"The sorted array is : ";
	for(int j=0;j<n;j++){
		cout<<a[j]<<" ";
	}
	return 0;
}
