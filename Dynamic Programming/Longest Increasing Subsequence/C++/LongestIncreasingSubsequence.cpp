/*@author Navneet Jain
 *
 * Find the longest increasing subsequence of a given sequence / array.
 * In other words, find a subsequence of array in which the subsequence’s elements are in strictly increasing order, and in which the subsequence is as long as possible. 
 * This subsequence is not necessarily contiguous, or unique.
 * In this case, we only care about the length of the longest increasing subsequence.

 * Example :

 * Input : [0, 8, 4, 12, 2, 10, 6, 14, 1, 9, 5, 13, 3, 11, 7, 15]
 * Output : 6
 * The sequence : [0, 2, 6, 9, 13, 15] or [0, 4, 6, 9, 11, 15] or [0, 4, 6, 9, 13, 15]

*/

#include<iostream>
#include<vector>

int longestSubsequence(const std::vector<int> &A)
{
    std::vector<int> B(A.size(), 1);
    int max_value = 1;
    
    for(unsigned int i = 1 ; i < A.size(); i++)
    {
        for(unsigned int j = 0 ; j < i; j++)
        {
            if(A[j] < A[i])
            {
                B[i] = std::max(B[i] , B[j] + 1); 
                max_value = std::max(B[i], max_value);
            }
        }
    }
    
    return max_value;
}

int main()
{
	std::vector<int> A = {0, 8, 4, 12, 2, 10, 6, 14, 1, 9, 5, 13, 3, 11, 7, 15};
	std::cout << longestSubsequence(A);
}
