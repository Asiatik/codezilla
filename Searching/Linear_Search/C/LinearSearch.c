#include "stdio.h"

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
    printf("%d\n",linearSearch(arr,sizeof(arr)/sizeof(arr[0]),3));
    printf("%d",linearSearch(arr,sizeof(arr)/sizeof(arr[0]),0));
    
}
