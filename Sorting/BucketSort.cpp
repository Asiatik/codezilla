#include <iostream> 
#include <algorithm> 
#include <vector> 
using namespace std; 
static void BucketSort(int* data, int count) {
	int minValue = data[0];
	int maxValue = data[0];
	for (int i = 1; i < count; i++)
	{
		if (data[i] > maxValue)
			maxValue = data[i];
		if (data[i] < minValue)
			minValue = data[i];
	}
	int bucketLength = maxValue - minValue + 1;
	vector<int>* bucket = new vector<int>[bucketLength];
  for (int i = 0; i < bucketLength; i++)
	{
		bucket[i] = vector<int>();}
for (int i = 0; i < count; i++)
	{
		bucket[data[i] - minValue].push_back(data[i]);}
  int k = 0;
	for (int i = 0; i < bucketLength; i++)
	{
		int bucketSize = bucket[i].size();
		if (bucketSize > 0)
		{
			for (int j = 0; j < bucketSize; j++)
			{
				data[k] = bucket[i][j];
				k++;
			}}}}
int main() 
{ 
    float arr[] = {0.708, 0.455, 0.025, 0.9899, 0.321, 0.758}; 
    int n = sizeof(arr)/sizeof(arr[0]); 
    bucketSort(arr, n);  
    cout << "Sorted array is \n"; 
    for (int i=0; i<n; i++) 
       cout << arr[i] << " "; 
    return 0; 
} 
