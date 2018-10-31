#ifndef _HEAPEXCEPTION_H_
#define _HEAPEXCEPTION_H_

#include <exception>
/*
* @author : Ionesio Junior
*/
class HeapUnderflowException : public std::exception{
	virtual const char* what() const throw(){
		return "Heap is Empty!!";
	}
};

#endif
