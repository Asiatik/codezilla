/* @author Navneet Jain
 * You are given a set of coins A. In how many ways can you make sum B assuming you have infinite amount of each coin in the set.
 * Question link - https://www.interviewbit.com/problems/coin-sum-infinite/

 */
#include <iostream>
#include<vector>
#include <algorithm>
using namespace std;

int coinchange(vector<int> &A, int B) {

    int ways[B+1];
    //presetting ways array to 0
	for(int i = 0 ; i <= B; i++){
		ways[i] =0;
	}
    
    ways[0] = 1;
    
	//loop over each coin value
    for(int i = 0; i < A.size(); i++){
        for(int j = A[i]; j <= B; j++){
            ways[j] = ways[j] + ways[j-A[i]];
            ways[j] = ways[j]%1000007;
        }
    }
    
    return ways[B];
}

int main(){
	int sum_to_make=4;
	vector<int> coin_arr = {1,2,3};
	cout << coinchange(coin_arr, sum_to_make);

}
