/*
Background:
An expression is valid if and only if the number of opening braces is equal to the number of closing braces

i.e. 
(?<=\.) {2,}(?=[A-Z]) is a valid expression

[+-]?(\d+(\.\d+)?\.\d+)([eE][+-]?\d+)? is not a valid expression b/c it is missing a [

Valid braces include: {} [] ()
*/

/*
Problem:
Write a function that determines whether an input string is a valid expression or not

bool isValidExpression(string s)
*/

/*
Solution:
This can be easily solved using a stack data structure
Whenever an opening brace is detected, push to the stack
Whenever an ending brace is detected, pop off the stack

It does not matter what kind of brace appears in a certain order b/c a valid expression will always have opening braces preceding a closing brace

If the stack ever tries to pop an empty stack, then there are more ending braces that opening braces
If the stack finishes reading the entire string and the stack is not empty, there are more opening braces than closing
*/

#include <string>
#include <stack>
#include <iostream>

bool isValidExpression(std::string s) {

	std::string valid_open = "{[(";
	std::string valid_close = "}])";
	std::stack<char> stack;

	// Iterate through string, char-by-char
	for (char c : s) {

		// If the current char is a valid brace, push to stack
		if (valid_open.find(c) != std::string::npos) {
			stack.push(c);
			continue;
		}

		if (valid_close.find(c) != std::string::npos) {
			if (stack.empty()) {

				// More closing braces than opening
				return false;
			}
			stack.pop();
			continue;
		}

	}

	if (stack.empty()) {
		return true;
	}

	return false;
}

int main() {

	// Basic test cases
	std::cout << isValidExpression("(?<=.) {2,}(?=[A-Z])") << std::endl;
	std::cout << isValidExpression("(){}()") << std::endl;
	std::cout << isValidExpression("[+-]?(+(.d+)?.d+)([eE][+-]?d+?") << std::endl;

	return 1;
}