#include "stdio.h"


long long factorial(long long n) {
	if(n == 1) {
		return 1;
	}
	else {
		return n * factorial(n-1);
	}
}

int main(int argc, char * argv[]) {
	
	long long n;
	printf("Enter a number: ");
	scanf("%lld",&n);
	printf("Factorial = %lld\n", factorial(n));
}
