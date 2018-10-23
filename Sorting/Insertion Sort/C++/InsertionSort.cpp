// Insertion sort algorithm implemented in C++

#include <iostream>
using namespace std;

// Insertion sort function

void insertionSort(int array[],int size){
	int current;
	int i,j;
	for(i=0;i<size;i++){
		current=array[i];
		for(j=i;j>0 && array[j-1] > current;j--){
			array[j]=array[j-1];
		}
		array[j]=current;
	}
}

// Main function to perform sorting

int main(){
    int i;
    int array_size;
    cout<< "Enter the size of the array to be sorted: ";
    cin>> array_size;
    int array[array_size];
    cout<<"Enter the elements of the array to be sorted: ";
    for(i=0;i<array_size;i++){
        cin>>array[i];
    }
    insertionSort(array,array_size);
    cout<<"Sorted array is:\n";
    for(i=0;i<array_size;i++){
        cout<<array[i]<<"\n";
    }
    return 0;
}