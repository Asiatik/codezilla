#ifndef _SIMPLEQUEUE_H_
#define _SIMPLEQUEUE_H_

/*
*@author Ionésio Junior
*/
#include "resources/Queue.hpp"

//Queue.hpp
/*
* Simple Queue Implementation
*/

template<typename T> 
class SimpleQueue : public Queue<T>{
	private:
		T *head_ptr;
		T *tail;
		int size;
		void shiftLeft();
	public:
		SimpleQueue(int size);
		bool isEmpty() override;
		bool isFull() override;
		void enqueue(T element) override;
		T* dequeue() override;
		T* head() override;		
};

#endif
