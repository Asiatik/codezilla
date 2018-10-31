#include <iostream>

//Using template here to support both long and ints.
template <class integer>
integer gcd(integer a, integer b)
{
    if (a == 0 || b == 0)
    {
        return a + b;
    }
    return gcd(b, b % a);
}

int main( int argv,char* argc[] )
{
    std::cout << gcd (100,10) << std::endl;
    std::cout << gcd (-100,10) << std::endl;
    std::cout << gcd (3,1) << std::endl;
    std::cout << gcd(3L,1L);
}
