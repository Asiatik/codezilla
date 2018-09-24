#include <iostream>

/* 
* Binary search algorithm
* This is the exact implementation of the pseudocode written in README.
* Notice that even if the array list contains multiple items,
* it will return only one index.
* Thus this algorithm is well suited to find if a item is present.
* And not for finding the exact index if multiple items are present.
* 
* With C++ you have to be careful of integer overflows.
* So we must make sure that the length of itemList is below that of int.
* Also the size of the array must also be sent.
*/

//Notice that itemList is passed as a pointer here. No expensive copying takes place.
int binarySearch(int itemList[],int itemListSize,int item)
{
    int leftIndex = 0;
    int rightIndex = itemListSize;
    int middleIndex;
    while (leftIndex <= rightIndex)
    {
        middleIndex = (leftIndex+rightIndex)/2;
        if (itemList[middleIndex] < item)
        {
            leftIndex = middleIndex + 1;
        }
        else if(itemList[middleIndex] > item)
        {
            rightIndex = middleIndex - 1;
        }
        else{
            return middleIndex;
        }
    }
    return -1;
    
}

//Simple demonstration for the algorithm
int main(int argc,char* argv[])
{   
    int arr[] = {1,2,3,4,5};
    std::cout << binarySearch(arr,sizeof(arr)/sizeof(arr[0]),3) << std::endl;
    std::cout << binarySearch(arr,sizeof(arr)/sizeof(arr[0]),0);
    
}
