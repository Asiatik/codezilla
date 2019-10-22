
QuickSort is a Divide and Conquer algorithm. It picks an element as a pivot and partitions the given array around the picked pivot. There are many different versions of quickSort that picks a pivot in different ways.

1. Always pick the first element as the pivot.
2. Always pick the last element as the pivot (implemented below)
3. Pick a random element as the pivot.
4. Pick median as the pivot.
The key process in quickSort is partition(). The goal of partitions is to, given an array and an element x of an array as the pivot, put x at its correct position in the sorted array and put all the smaller elements (smaller than x) before x, and put all the greater elements (greater than x) after x. All of this should be done in linear time.

Analysis of QuickSort
The time taken by QuickSort, in general, can be written as the following:

 T(n) = T(k) + T(n-k-1) + O(n)
The first two terms are for two recursive calls, the last term is for the partition process. K is the number of elements that are smaller than the pivot.
The time taken by QuickSort depends upon the input array and partition strategy. Following are three cases:

Worst Case: The worst case occurs when the partition process always picks the greatest or smallest element as the pivot. If we consider the above partition strategy where the last element is always picked as the pivot, the worst case would occur when the array is already sorted in increasing or decreasing order. The following is a recurrence for the worst case:

 T(n) = T(0) + T(n-1) + O(n)
which is equivalent to  
 T(n) = T(n-1) + O(n)
The solution of above recurrence is O(n^2).

Best Case: The best case occurs when the partition process always picks the middle element as the pivot. The following is a recurrence for the best case.

 T(n) = 2T(n/2) + O(n)
The solution to the above recurrence is O(nLogn). It can be solved using case 2 of the Master Theorem.

Average Case:
To do the average case analysis, we need to consider all possible permutation of the array and calculate the time taken by every permutation which doesn’t look easy.
We can get an idea of the average case by considering the case when the partition puts O(n/9) elements in one set and O(9n/10) elements in another set. The following is the recurrence for this case.

 T(n) = T(n/9) + T(9n/10) + O(n)
 Solution of above recurrence is also O(nLogn)
 
Explanation:
arr[] = {10, 80, 30, 90, 40, 50, 70}
Indexes:  0   1   2   3   4   5   6 

low = 0, high =  6, pivot = arr[h] = 70
Initialize the index of smaller element, i = -1

Traverse the elements from j = low to high-1
j = 0 : Since arr[j] <= pivot, do i++ and swap(arr[i], arr[j])
i = 0 
arr[] = {10, 80, 30, 90, 40, 50, 70} // No change as i and j 
                                     // are same

j = 1 : Since arr[j] > pivot, do nothing
// No change in i and arr[]

j = 2 : Since arr[j] <= pivot, do i++ and swap(arr[i], arr[j])
i = 1
arr[] = {10, 30, 80, 90, 40, 50, 70} // We swap 80 and 30 

j = 3 : Since arr[j] > pivot, do nothing
// No change in i and arr[]

j = 4 : Since arr[j] <= pivot, do i++ and swap(arr[i], arr[j])
i = 2
arr[] = {10, 30, 40, 90, 80, 50, 70} // 80 and 40 Swapped
j = 5 : Since arr[j] <= pivot, do i++ and swap arr[i] with arr[j] 
i = 3 
arr[] = {10, 30, 40, 50, 80, 90, 70} // 90 and 50 Swapped 

We come out of the loop because j is now equal to high-1.
Finally, we place pivot in the correct position by swapping
arr[i+1] and arr[high] (or pivot) 
arr[] = {10, 30, 40, 50, 70, 90, 80} // 80 and 70 Swapped 

Now 70 is in its correct place. All elements smaller than
70 are before it and all elements greater than 70 are after
it.
