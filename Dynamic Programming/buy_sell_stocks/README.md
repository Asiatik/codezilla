Problem Statement:
Say you have an array for which the ith element is the price of a given stock on day i.
If you were only permitted to complete at most one transaction (ie, buy one and sell one share of the stock), design an algorithm to find the maximum profit.

Solution Approach:
If you buy your stock on day i, you’d obviously want to sell it on the day its price is maximum after that day. 
So essentially at every index i, you need to find the maximum in the array in the suffix. 
Now this part can be done in 2 ways : 
1) Have another array which stores that information. 
max[i] = max(max[i+1], A[i])

2) Start processing entries from the end maintaining a maximum till now. Constant additional space requirement.


