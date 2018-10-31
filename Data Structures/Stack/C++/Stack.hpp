/*
* @author Ionésio Junior
*/

#include <iostream>
#include <stdlib.h>
#include "Exceptions.hpp"

//Stack.hpp
template <typename T> 
class Stack{
	private:
		StackOverflowException overflow;
		StackUnderflowException underflow;
		T *top_ptr;
		T *begin;
		int size;
	public:
		Stack(int size);
		bool isEmpty();		
		bool isFull();
		void push(T element);
		T* pop();
		T* top();		
};


//Stack.cpp

/*
* Constructor of stack class 
* @param lenght of stack
*/
///////////////////////////////////////////////////////////////////////////

template<typename T>
Stack<T>::Stack(int size){
	this->size = size;
	this->begin  = (T*) calloc(this->size,sizeof(T));
	this->top_ptr = this->begin - 1;
}

///////////////////////////////////////////////////////////////////////////


/*
* Return True if stack is empty or false,otherwise
* Complexity: O(1)
* @return bool
*/
///////////////////////////////////////////////////////////////////////////

template<typename T>
bool Stack<T>::isEmpty(){
	return this->top_ptr == (this->begin - 1);
}

///////////////////////////////////////////////////////////////////////////

/*
* Return True if stack is full or false,otherwise
* Complexity: O(1)
* @return bool
*/
///////////////////////////////////////////////////////////////////////////

template<typename T>
bool Stack<T>::isFull(){
	return this->top_ptr == (this->begin + size - 1);
}

////////////////////////////////////////////////////////////////////////////


/*
* Insert a new element in the top of stack or throw an exception if stack is full
* null elements aren't allowed
* Complexity : O(1)
* @param element
* @throw StackOverflowException
*/
////////////////////////////////////////////////////////////////////////////

template <typename T>
void Stack<T>::push(T element){
		if(!this->isFull()){
			this->top_ptr++;
			*this->top_ptr = element;
		}else{
			throw overflow;
		}
}

/////////////////////////////////////////////////////////////////////////////


/*
* Remove element in top of the stack of throw an exception if stack is empty.
* Complexity: O(1)
* @throw StackUnderflowException
*/
//////////////////////////////////////////////////////////////////////////////

template <typename T>
T* Stack<T>::pop(){
	if(!this->isEmpty()){
		T* removedValue = this->top_ptr;
		--this->top_ptr;
		return removedValue;
	}else{
		throw underflow;
	}
}

///////////////////////////////////////////////////////////////////////////////

/*
* Return the top  element of stack without remove this.(if stack is empty, return NULL).
* Complexity: O(1)
* @return element
*/
///////////////////////////////////////////////////////////////////////////////

template <typename T>
T* Stack<T>::top(){
	if(!this->isEmpty()){
		return (this->top_ptr);
	}else{
		return NULL;
	}
}

////////////////////////////////////////////////////////////////////////////////
