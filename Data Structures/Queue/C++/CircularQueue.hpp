#ifndef _CIRCULARQUEUE_H_
#define _CIRCULARQUEUE_H_
/*
*@author Ionésio Junior
*/

#include "Queue.hpp"
/*
* Queue in circular implementation
*/

//CircularQueue.hpp
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

//Queue.cpp

/*
* SimpleQueue class constructor
* @params length of the queue
*/
//////////////////////////////////////////

template<class T>
CircularQueue<T>::CircularQueue(int size){
	this->head_ptr = (T*) calloc(size,sizeof(T));
	this->head_index = -1;
	this->tail = -1;
	this->elements = 0;
	this->size = size;
}

//////////////////////////////////////////


/*
* Insert a new element in tail of the queue or throw an exception if queue is full.
* Complexity : O(1)
* @param element
* @throw QueueOverflowException
*/
//////////////////////////////////////////

template<class T>
void CircularQueue<T>::enqueue(T element){
	if(this->isFull()){
		throw this->overflow;
	}
	this->elements++;
	if(this->head_index == -1 && this->tail == -1){
		this->head_index = (this->head_index + 1 ) % this->size;
	}
	this->tail = (this->tail + 1 ) % this->size;
	this->head_ptr[this->tail] = element;
}

///////////////////////////////////////////

/*
* Remove head element of the queue or throw an exception if queue is empty
* Complexity : O(1)
* @return element
* @throw QueueUnderflowException
*/
///////////////////////////////////////////

template<class T>
T* CircularQueue<T>::dequeue(){
	if(this->isEmpty()){
		throw this->underflow;
	}
	this->elements--;
	T* aux = &this->head_ptr[this->head_index];
	this->head_index = (this->head_index + 1) % size;
	return aux;
}

/////////////////////////////////////////////


/*
* Return element in the head of the queue without remove, or NULL if queue is empty.
* Complexity: O(1)
* @return element
*/
/////////////////////////////////////////////

template<class T>
T* CircularQueue<T>::head(){
	if(this->isEmpty()){
		return NULL;
	}else{
		return &this->head_ptr[this->head_index];
	}
}

///////////////////////////////////////////////


/*
* Return true if queue is empty or false,otherwise.
* Complexity : O(1)
* @return bool
*/
///////////////////////////////////////////////

template<class T>
bool CircularQueue<T>::isEmpty(){
	return this->elements == 0;
}

////////////////////////////////////////////////


/*
* Return true if queue is full or false,otherwise.
* Complexity : O(1)
* @return bool
*/
/////////////////////////////////////////////////

template<class T>
bool CircularQueue<T>::isFull(){
	return this->elements == this->size;
}

//////////////////////////////////////////////////

#endif
