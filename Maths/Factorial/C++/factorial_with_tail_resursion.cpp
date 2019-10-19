#include <iostream>

long long int factorial_with_tail_recursion(long long int number, long long int accumulator=1 ){
    if(number<=0)
        return accumulator;
    else
        return factorial_with_tail_recursion(number-1, accumulator*number);
}

int main(){
    std::cout<<factorial_with_tail_recursion(6)<<std::endl;
    std::cout<<factorial_with_tail_recursion(7)<<std::endl;
    std::cout<<factorial_with_tail_recursion(8)<<std::endl;
    return 0;
}