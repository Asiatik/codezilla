//Counting sort which takes negative numbers as well 
//Using c++ 17
#include <iostream> 
#include <vector> 
#include <algorithm> 

void countSort(std::vector <int>& arr) {  
    auto [min, max] = std::minmax_element(arr.begin(), arr.end());
    int range = (*max) - (*min) + 1; 
      
    std::vector<int> count(range), output(arr.size());

    for(int i = 0; i < arr.size(); i++) 
        count[arr[i]-(*min)]++; 
          
    for(int i = 1; i < count.size(); i++) 
           count[i] += count[i-1]; 
    
    for(int i = arr.size()-1; i >= 0; i--) {  
         output[ count[arr[i]-(*min)] -1 ] = arr[i];  
              count[arr[i]-(*min)]--;  
    } 
      
    for(int i=0; i < arr.size(); i++) 
            arr[i] = output[i]; 
} 
  
void printArray(std::vector <int> & arr)  {  
    for (int i=0; i < arr.size(); i++)
        std::cout << arr[i] << " \n"[i==arr.size()-1];
} 
  
int main() { 
    std::vector<int> arr = {-5, -10, 0, -3, 8, 5, -1, 10}; 
    countSort (arr); 
    printArray (arr); 
    return 0; 
} 