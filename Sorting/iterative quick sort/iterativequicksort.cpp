// An iterative quick sort implementation 
#include <iostream>
using namespace std; 
void swap ( int a, int b ) 
{ 
    int t = a; 
    a = b; 
    b = t; 
} 
  
int partition (int arr[], int l, int h) 
{ 
    int x = arr[h]; 
    int i = (l - 1); 
  
    for (int j = l; j <= h- 1; j++) 
    { 
        if (arr[j] <= x) 
        { 
            i++; 
            swap (arr[i], arr[j]); 
        } 
    } 
    swap (arr[i + 1], arr[h]); 
    return (i + 1); 
} 
  
void quickSortIterative (int arr[], int l, int h) 
{ 
    
    int stack[ h - l + 1 ];   
    int top = -1; 
    stack[ ++top ] = l; 
    stack[ ++top ] = h;    
    while ( top >= 0 ) 
    { 
        
        h = stack[ top-- ]; 
        l = stack[ top-- ]; 
  
       
        int p = partition( arr, l, h ); 
  
        
        if ( p-1 > l ) 
        { 
            stack[ ++top ] = l; 
            stack[ ++top ] = p - 1; 
        } 
  
       
        if ( p+1 < h ) 
        { 
            stack[ ++top ] = p + 1; 
            stack[ ++top ] = h; 
        } 
    } 
} 
 
int main() 
{ 
    int arr[] = {4, 3, 5, 2, 1, 3, 2, 3}; 
    int n = 8; 
    quickSortIterative( arr, 0, n - 1 ); 
    for (int i = 0; i < n; ++i ) 
        cout<<arr[i];
    return 0; 
} 
