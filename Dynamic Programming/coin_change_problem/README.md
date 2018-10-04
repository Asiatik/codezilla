Problem Statement:
You are given a set of coins A. In how many ways can you make sum B assuming you have infinite amount of each coin in the set.
Input : 
	S = [1, 2, 3] 
	N = 4

Return : 4

Explanation : The 4 possible ways are
{1, 1, 1, 1}
{1, 1, 2}
{2, 2}
{1, 3}	


Solution Approach:
The solution approach here is DP. We calculate the ways to count number from 1 to n based on a subproblem.

Suppose we want to calculate the number of ways to calcualate 4 with given coin denomination 1.
So the subproblem here is with 1 as the coin available, the number of ways to calculate 4 is equal to the number of ways to calcualate 3.
Taking this as a subproblem, we can see that
	numOfWays[4] = numOfWays[4] + numofWays[3]

To generalize,
	numOfWays[value] = numOfWays[value] + numofWays[value-current_denomination]

Looping over every coin denomination available, we can compute the result



