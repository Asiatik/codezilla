#include <iostream>

using namespace std;

void fibonacci(int number)
{
	int first = 0, second = 1, next;

	for (int i = 0; i < number; i++)
	{
		cout << "\n" << first;
		next = first + second;
		first = second;
		second = next;
	}
}

int main()
{
	int number;

	cout << "Enter number of terms for Series: ";
	cin >> number;

	cout << "Fibonacci Series are: \n";
	fibonacci(number);
}
