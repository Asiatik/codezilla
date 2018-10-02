## Merge Sort in Java\
##### It is a sorting algorithm which works on the principle of 'divide and conquer'. Initially the given array is divided into equal halves. This process goes on till the size of array becomes one. After that array is merged till the original array is formed but in ascending order\.

##### Below figure shows the graphical working of merge sort\.

<img src="Merge-Sort-Tutorial.png" width="450" height="450" />

##### Algorithm
```
MergeSort(arr[], l,  r)
If r > l
     1. Find the middle point to divide the array into two halves:  
             middle m = (l+r)/2
     2. Call mergeSort for first half:   
             Call mergeSort(arr, l, m)
     3. Call mergeSort for second half:
             Call mergeSort(arr, m+1, r)
     4. Merge the two halves sorted in step 2 and 3:
             Call merge(arr, l, m, r)
```
##### The merge(arr, l, m, r) is key process that assumes that arr[l..m] and arr[m+1..r] are sorted and merges the two sorted sub-arrays into one. See following C implementation for details.
