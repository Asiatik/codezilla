//The Fibonacci numbers are the numbers in the following integer sequence 0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, ……..
//This program prints the nth Fibonacci number
#include<bits/stdc++.h>
using namespace std;
int Fibo(int n)
{
	if (n<=1)
		return n;
	return Fibo(n-1)+Fibo(n-2);	
}
int main () 
{ 
  int n = 9; 
  printf("%d", Fibo(n)); 
  getchar(); 
  return 0; 
}

// Output: 34
