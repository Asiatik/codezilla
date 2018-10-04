#include <iostream>

int factorial(int n);

int main(int argv, char * argc[]) {
	std :: cout << factorial(5) << std :: endl;
	return 0;
}

int factorial(int n) {
	if(n == 1) {
		return 1;
	}
	else {
		return n * factorial(n-1);
	}
}
