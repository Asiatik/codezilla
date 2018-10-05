#include <iostream>
template<class T>
T factorial(T n);

int main(int argv, char * argc[]) {

	std :: cout << factorial(5) << std :: endl;
	return 0;
}
template <class T>
T factorial(T n) {
	if(n == 1) {
		return 1;
	}
	else {
		return n * factorial(n-1);
	}
}
