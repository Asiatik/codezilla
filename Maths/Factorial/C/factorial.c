#include "stdio.h"
/*Recursive program to find Factorial
  of Small numbers*/

long long int factorial(long long n) {
    if(n == 1||n == 0) {
        return 1;
    }
    else {
        return n * factorial(n-1);
    }
}

int main(int argc, char * argv[]) {
    long long int n;
    printf("Enter a number:");
    scanf("%lld",&n);
    printf("Factorial:%lld\n",factorial(n));
}
