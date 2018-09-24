#include <iostream>

/** 
* Linear search algorithm
* This is the exact implementation of the pseudocode written in README.
* Notice that even if the array list contains multiple items,
* it will return only one index.
* Thus this algorithm is well suited to find if a item is present.
* And not for finding the exact index if multiple items are present. 
* With C++ you have to be careful of integer overflows.
* So we must make sure that the length of itemList is below that of int.
*/

//Notice that itemList is passed by pointer. No unnecessary copy takes place.
int linearSearch(int itemList[],int itemListSize,int item)
{
    int index=0;
    while (index < itemListSize)
    {
        if (itemList[index] == item)
        {
            return index;
        }
        index++;
    }
    return -1;
    
}

 //Simple demonstration for the algorithm
int main(int argc,char* argv[])
{   
    int arr[] = {1,2,3,4,5};
    std::cout << linearSearch(arr,sizeof(arr)/sizeof(arr[0]),3) << std::endl;
    std::cout << linearSearch(arr,sizeof(arr)/sizeof(arr[0]),0);
    
}
