#include <stdio.h>

long int fact(int n) {
	if(n==1)	return 1;
	return n*fact(n-1);
}

int main() {
	long int a = fact(3);
	printf("%ld \n",a);
	return 0;
}
