# Selection Sort in Java

## Introduction
The selection sort algorithm it's a very simple one, but it has O(n<sup>2</sup>) time complexity, making it inefficient on large arrays, and generally performs worse than the similar [insertion sort](https://github.com/Asiatik/codezilla/tree/master/Sorting/Insertion%20Sort).
Anyway, in certain situations, it can perform better than more complicated algorithms, particularly where auxiliary memory is limited. 

## The algorithm
The algorithm divides the input array into two parts: the subarray of items already sorted, which is built up from left to right, and the subarray of items remaining to be sorted that occupy the rest of the array. Initially, the sorted subarray is empty and the unsorted subarray is the entire input array. The algorithm proceeds by finding the smallest (or largest, depending on sorting order) element in the unsorted subarray, exchanging (swapping) it with the leftmost unsorted element (putting it in sorted order), and moving the subarray boundaries one element to the right. 
