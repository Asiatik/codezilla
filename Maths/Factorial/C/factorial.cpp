#include <iostream>

int fact(int n) {
	if(n==0)	return 1;

	return n*fact(n-1);
}

int main() {
	int a = fact(5);
	cout <<a<<endl;
	return 0;
}
