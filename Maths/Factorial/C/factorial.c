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
	int n;
	printf("Enter a number");
	scanf("%d",&n);
	printf("Factorial = %lld", factorial(n));
}
