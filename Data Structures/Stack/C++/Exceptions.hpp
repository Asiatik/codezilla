/*
*@author Ionesio Junior
*/

#include <iostream>
#include <exception>

class StackOverflowException : public std::exception {
	virtual const char* what() const throw(){
		return "Stack is Full!!!"; 
	}
};

class StackUnderflowException : public std::exception{
	virtual const char* what() const throw(){
		return "Stack is Empty!!";
	}
};
