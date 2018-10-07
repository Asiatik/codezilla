#include "SimpleQueue.hpp"

/*
* SimpleQueue class constructor
* @params length of the queue
*/
template<typename T>
SimpleQueue<T>::SimpleQueue(int size){
	this->head_ptr = (T*) calloc(size,sizeof(T));
	this->tail = this->head_ptr - 1;
	this->size = size;
}


/*
* Return true if queue is empty or false,otherwise.
* Complexity : O(1)
* @return bool
*/
template<typename T>
bool SimpleQueue<T>::isEmpty(){
	return (this->tail < this->head_ptr);
}


/*
* Return true if queue is full or false,otherwise.
* Complexity : O(1)
* @return bool
*/
template <typename T>
bool SimpleQueue<T>::isFull(){
	return (this->tail == (this->head_ptr + this->size - 1));
}


/*
* Insert a new element in tail of the queue or throw an exception if queue is full.
* Complexity : O(1)
* @param element
* @throw QueueOverflowException
*/
template <typename T>
void SimpleQueue<T>::enqueue(T element){
	if(!this->isFull()){
		this->tail++;
		*this->tail = element;
	}else{
		throw this->overflow;	
	}
}


/*
* Remove head element of the queue or throw an exception if queue is empty
* Complexity : O(n)
* @return element
* @throw QueueUnderflowException
*/
template <typename T>
T* SimpleQueue<T>::dequeue(){
	if(!this->isEmpty()){
		T removedElement = *(this->head_ptr);
		this->shiftLeft();
		this->tail--;
		this->tail[1] = removedElement;
		return &this->tail[1];
	}else{
		throw this->underflow;
	}
}


/*
* When an element is removed, this method move each element to the previous position.
*/
template<typename T>
void SimpleQueue<T>::shiftLeft(){
	for(int *i = this->head_ptr; i < this->tail;i++){
		*i = *(i + 1);
	}
}


/*
* Return element in the head of the queue without remove, or NULL if queue is empty.
* Complexity : O(1)
* @return element
*/
template<typename T>
T* SimpleQueue<T>::head(){
	if(!this->isEmpty()){
		return this->head_ptr;
	}else{
		return NULL;
	}
}
