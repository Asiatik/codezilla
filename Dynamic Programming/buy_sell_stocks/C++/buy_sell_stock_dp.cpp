/*@author Navneet Jain
 * Say you have an array for which the ith element is the price of a given stock on day i.
 * If you were only permitted to complete at most one transaction (ie, buy one and sell one share of the stock), design an algorithm to find the maximum profit.

 */
#include<iostream>
#include<vector>
#include<climits>
using namespace std;

int maxProfit(const vector<int> &A) {
	int buy = A[0], flag = 0, i = 1, max_sell = INT_MIN;
	int sol = 0;
	while(i < A.size()){
		int diff = A[i] - A[i-1];
		//It's a greedy appoach. If current diff is greater than 0, then add that to the solution.
		if(diff > 0){
			sol = sol + diff;
		}
		i++;
	}

	return sol;
}

int main(){
	vector<int> A = {1,2};
	cout << maxProfit(A);
}
