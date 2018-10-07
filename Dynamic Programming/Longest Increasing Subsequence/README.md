Problem Statement:
Find the longest increasing subsequence of a given sequence / array.
In other words, find a subsequence of array in which the subsequence’s elements are in strictly increasing order, and in which the subsequence is as long as possible. 
This subsequence is not necessarily contiguous, or unique.
In this case, we only care about the length of the longest increasing subsequence.

Example :

Input : [0, 8, 4, 12, 2, 10, 6, 14, 1, 9, 5, 13, 3, 11, 7, 15]
Output : 6
The sequence : [0, 2, 6, 9, 13, 15] or [0, 4, 6, 9, 11, 15] or [0, 4, 6, 9, 13, 15]


Solution Approach:
The solution approach here is DP. We calculate the longest increasing subsequence for substring of length 1 to n. For every number, we see what all numbers, before the current index, are smaller than the current number and find the longest length subsequence based on that.
For above example,
	The longest subsequence array would be 
	     1, 1, 2, 3, 2, 3, 3, 4, 2, 4, 3, 4, 3, 5, 4, 6 
	
	Hence the answer is 6
