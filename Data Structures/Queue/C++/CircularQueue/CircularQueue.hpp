#ifndef _CIRCULARQUEUE_H_
#define _CIRCULARQUEUE_H_
/*
*@author Ionésio Junior
*/

#include "resources/Queue.hpp"

/*
* Queue in circular implementation
*/
template<class T>
class CircularQueue : public Queue<T>{
	private:
		T *head_ptr;
		int tail;
		int head_index;
		int size;
		int elements;
	public:
		CircularQueue(int size);
		bool isEmpty() override;
		bool isFull() override;
		void enqueue(T element) override;
		T* dequeue() override;
		T* head() override;
};

#endif
