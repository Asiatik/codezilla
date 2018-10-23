#include "BinaryHeap.hpp"

/*
* Binary Heap constructor
* @param size
*/
//////////////////////////////////////////////////////////////////////
template<typename T>
BinaryHeap<T>::BinaryHeap( int size ){
	this->array = new Array<T>(size);
	this->index = -1;
}

//////////////////////////////////////////////////////////////////////

/*
* Return true if heap i empty or false,otherwise.
* Complexity : O(1)
* @return bool
*/
/////////////////////////////////////////////////////////////////////

template <typename T>
bool BinaryHeap<T>::isEmpty(){
	return this->index < 0;
}

/////////////////////////////////////////////////////////////////////

/* Return number of elements inside the heap structure
*  Complexity : O(1)
*  @return size
*/
/////////////////////////////////////////////////////////////////////

template<typename T>
int BinaryHeap<T>::size(){
	return this->index + 1;
}

////////////////////////////////////////////////////////////////////

/*
* Return true if heap is full or false,otherwise.
* Complexity : O(1)
* @return bool
*/
////////////////////////////////////////////////////////////////////

template <typename T>
bool BinaryHeap<T>::isFull(){
	return this->index == this->array->size - 1;
}

////////////////////////////////////////////////////////////////////

/*
* Insert an element in leaf position,after correct your position by value
* Complexity : O(log(n))
* @param element
*/
///////////////////////////////////////////////////////////////////

template <typename T>
void BinaryHeap<T>::insert(T element){
	if(this->isFull()){
		this->responsiveArray();
	}
	if(&element != NULL){
		this->array->ptr[++index] = element;
		int i = this->index;
		while(i >= 0 && this->array->ptr[this->parent(i)] < this->array->ptr[i]){
			T aux = this->array->ptr[i];
			this->array->ptr[i] = this->array->ptr[this->parent(i)];
			this->array->ptr[this->parent(i)] = aux;
			i = this->parent(i);
		}
	}
}

///////////////////////////////////////////////////////////////////

/*
* Remove and return root element
* Complexity : O(1)
* @return elementPointer
*/
//////////////////////////////////////////////////////////////////

template<typename T>
T BinaryHeap<T>::extractRoot(){
	if(this->isEmpty()){
		throw underflow;
	}else{
		T removedElement = *(this->array->ptr);
		*(this->array->ptr) = this->array->ptr[this->index--];
		this->heapify(0);
		return removedElement;
	}
}

////////////////////////////////////////////////////////////////////

/*
* Return root element value without remove it
* Complexity: O(1)
* @param element
*/
/////////////////////////////////////////////////////////////////

template<typename T>
T* BinaryHeap<T>::rootElement(){
	if(this->isEmpty()){
		return NULL;
	}else{
		return this->array->ptr;
	}
}

/////////////////////////////////////////////////////////////////

/*
* Sort an array using heap structure
* Complexity : O(n.log(n))
* @param unsorted array
* @param size of array
* @return sorted array
*/
/////////////////////////////////////////////////////////////////

template<typename T>
Array<T> BinaryHeap<T>::heapSort(T inputArray[],int size){
	this->buildHeap(inputArray,size);
	for(int i = this->index;i > 0;i--){
		T aux = this->array->ptr[0];
		this->array->ptr[0] = this->array->ptr[i];
		this->array->ptr[i] = aux;
		this->index--;
		this->heapify(0);
	}
	return *this->array;
}

////////////////////////////////////////////////////////////////

/*
* Build heap structure using an array of elements
* @param array of elements
* @param size of array
*/
////////////////////////////////////////////////////////////////

template<typename T>
void BinaryHeap<T>::buildHeap(T inputArray[],int size){
	this->array->ptr= (T*) calloc(size,sizeof(T));
	this->array->size = size;
	this->index = -1;
	for(int i = 0; i < size;i++){
		this->insert(inputArray[i]);
	}
}

//////////////////////////////////////////////////////////////


/* Return array structure with elements inside the heap
*  Complexity : O(1)
*  @return array of elements
*/
//////////////////////////////////////////////////////////////

template<typename T>
Array<T> BinaryHeap<T>::toArray(){
	return *this->array;
}

/////////////////////////////////////////////////////////////


////////////////////////////////////////////	AUXILIAR METHODS	///////////////////////////////////////////////////////


//////////////////////////////////////

template<typename T>
int BinaryHeap<T>::parent(int index){
	return index/2;
}

///////////////////////////////////////


////////////////////////////////////

template<typename T>
int BinaryHeap<T>::left(int index){
	return (2 * index);
}

/////////////////////////////////////


////////////////////////////////////

template<typename T>
int BinaryHeap<T>::right(int index){
	return (2 * index) + 1;
}

/////////////////////////////////////

/*
* Change node/left/right node positions using value of this nodes and raising the max value to the top
* Complexity : O(log(n))
* @param node
*/
//////////////////////////////////////////////////////////////////////////////////////////////

template<typename T>
void BinaryHeap<T>::heapify(int index){
	int left = this->left(index);
	int right = this->right(index);
	int largest;
	if(left <= this->index && this->array->ptr[left] > this->array->ptr[index]){
		largest = left;
	}else{
		largest = index;
	}

	if(right <=this->index && this->array->ptr[right] > this->array->ptr[largest]){
		largest = right;
	}
	
	if(largest != index){
		T aux = this->array->ptr[index];
		this->array->ptr[index] = this->array->ptr[largest];
		this->array->ptr[largest] = aux;
		this->heapify(largest);
	}
}

/////////////////////////////////////////////////////////////////////////////////////////////

/*
* Duplicate storage size
* Complexity : O(1)
*/
/////////////////////////////////////////////////////////////////////////

template<typename T>
void BinaryHeap<T>::responsiveArray(){
	this->array->ptr = (T*) realloc(this->array->ptr,(this->array->size * 2)  * sizeof(T));	
	this->array->size = this->array->size * 2;
}

/////////////////////////////////////////////////////////////////////////

