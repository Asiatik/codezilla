#include <cstdlib>
#include <exception>

class QueueUnderflowException : public std::exception{
	virtual const char* what() const throw(){
		return "Queue is Empty!!";
	}
};

class QueueOverflowException : public std::exception{
	virtual const char* what() const throw(){
		return "Queue is Full!!";
	}
};
