#ifndef _HEAP_H_
#define _HEAP_H_

/*
*@author Ionésio Junior
*/

#include <iostream>
#include <stdlib.h>
#include "Exception.hpp"

/* Auxiliar array structure implementation
*  
*/
template <typename T>
struct Array{
	int size;
	T *ptr;
	bool operator==(Array<T> &other){
		if(this->size != other.size){
			return false;
		}else{
            for(int i = 0; i < this->size;i++){
                if(this->ptr[i] != other.ptr[i]){
                    return false;
                }
            }
            return true;
        }
	}

	T operator[](int index){
		return this->ptr[index];
	}
	
	bool operator!=(Array<T> other){
		return !(*this == other);
	}

	Array(int length){
		this->size = length;
		this->ptr = (T*) calloc(this->size,sizeof(T));
	}
};

/*
* Binary Heap class
*/
template <typename T> 
class BinaryHeap{
	private:
		HeapUnderflowException underflow;
		Array<T> *array;
		int index;
		int parent(int index);
		int left(int index);
		int right(int index);
		void heapify(int index);
		void responsiveArray();
	public:
		BinaryHeap(int size);
		bool isEmpty();			
		bool isFull();
		void insert(T element);
		T extractRoot();
		T* rootElement();
		Array<T> heapSort(T inputArray[],int size);
		Array<T> toArray();
		void buildHeap(T inputArray[],int size);
		int size();
};

#endif
