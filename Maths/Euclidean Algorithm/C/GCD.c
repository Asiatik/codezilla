#include "stdio.h"

//You should probably function overload to support longs as well.
int gcd(int a, int b)
{
    if (a==0 || b==0)
    {
        return a + b;
    }
    return gcd(b, b % a); 
}

int main(int argc, char* argv[])
{
    printf("%d\n%d\n%d",gcd(100,10),gcd(100,-10),gcd(3,7));
}
