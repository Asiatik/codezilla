#ifndef _QUEUE_H_
#define _QUEUE_H_
/*
*@author Ionésio Junior
*/
#include <cstdlib>
#include <iostream>
#include "Exceptions.hpp"

/*
* Queue Abstract class implementation
*/
template<class T>
class Queue{
	public:
		QueueUnderflowException underflow;
		QueueOverflowException overflow;
		virtual bool isEmpty() = 0;
		virtual bool isFull() = 0;
		virtual void enqueue(T element) = 0;
		virtual T* dequeue() = 0;
		virtual T* head() = 0;
};

#endif
