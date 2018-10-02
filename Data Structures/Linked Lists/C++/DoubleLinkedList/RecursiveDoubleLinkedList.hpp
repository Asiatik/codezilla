#ifndef _RECURSIVELIST_H_
#define _RECURSIVELIST_H_
/*
*@author Ionésio Junior
*/

#include "DoubleLinkedList.hpp"
/*
* Recursive Double Linked List Implementation
*/
//RecursiveDoubleLinkedList.hpp
template<class T>
class RecursiveDoubleLinkedList : public LinkedList<T>{
	private:
		T data;
		RecursiveDoubleLinkedList<T> *next;
		RecursiveDoubleLinkedList(T element);
		bool empty_root;
		void recursiveToVector(std::vector<T> * vetor);
		RecursiveDoubleLinkedList *searchPrevious(T element);
	public:
		RecursiveDoubleLinkedList();
		void insert(T element) override;
		void insertFirst(T element) override;		
		void remove(T element) override;
		void removeFirst() override;
		void removeLast() override;
		bool isEmpty() override;
		int size() override;
		std::vector<T> toVector() override;
		T *search(T element) override;
		T getData();
};


//RecursiveDoubleLinkedList.cpp

/*
* Empty Constructor of linked list node
*/
//////////////////////////////////////////////////////////////

template<class T>
RecursiveDoubleLinkedList<T>::RecursiveDoubleLinkedList(){
	this->empty_root = true;
}

/////////////////////////////////////////////////////////////

/*
* Constructor of linked list node
* @param element
*/
//////////////////////////////////////////////////////////////

template<class T>
RecursiveDoubleLinkedList<T>::RecursiveDoubleLinkedList(T element){
	this->data = element;
	this->empty_root = false;
}

/////////////////////////////////////////////////////////////

/*
* Return true  if linked list is empty or false,otherwise.
* Complexity : O(1)
* @return bool
*/
/////////////////////////////////////////////////////////////

template<class T>
bool RecursiveDoubleLinkedList<T>::isEmpty(){
	return this->empty_root;
}

/////////////////////////////////////////////////////////////

/*
* Get data stored in node
* @return element
*/
//////////////////////////////////////////////////////////////

template<class T>
T RecursiveDoubleLinkedList<T>::getData(){
	return this->data;
}

///////////////////////////////////////////////////////////////

/*
* Return size of list
* Complexity : O(n)
* @return int
*/
///////////////////////////////////////////////////////////////

template<class T>
int RecursiveDoubleLinkedList<T>::size(){
	if(!empty_root){	
		if(!next){
			return 1;	
		}else{
			return 1 + next->size();
		}
	}else{
		return 0;	
	}
}

////////////////////////////////////////////////////////////////

/*
* Search an element, if found return it return your pointer, else return NULL
* Complexity : O(n)
* @param element to be searched
* @return elementFoundPointer
*/
/////////////////////////////////////////////////////////////////

template<class T>
T * RecursiveDoubleLinkedList<T>::search(T element){
	if(data == element){
		RecursiveDoubleLinkedList<T> *previous = this->searchPrevious(element);
		if(previous){
			return &data;
		}else{
			if(this->empty_root){
				return NULL;			
			}else{
				return &data;			
			}		
		}	
	}else if(!next){
		return NULL;	
	}else{
		return next->search(element);
	}
}

//////////////////////////////////////////////////////////////////

/*
* Insert new element in last position of the list
* Complexity : O(n)
* @param new element
*/
//////////////////////////////////////////////////////////////////

template<class T>
void RecursiveDoubleLinkedList<T>::insert(T element){
	if(this->empty_root){
		this->data = element;
		this->empty_root = false;
		this->next = NULL;
	}else{
		if(!next){
			this->next = new RecursiveDoubleLinkedList<T>(element);
			this->next->next = NULL;
		}else{
			this->next->insert(element);
		}
	}
}

//////////////////////////////////////////////////////////////////

/*
* Remove an list element
* Complexity : O(n)
* @param element to be removed
*/
///////////////////////////////////////////////////////////////////

template<class T>
void RecursiveDoubleLinkedList<T>::remove(T element){
	RecursiveDoubleLinkedList<T> *previous = this->searchPrevious(element);
	if(!previous){
		if(data == element){
			if(next){
				RecursiveDoubleLinkedList<T> *removedNode = this->next;
				this->data = this->next->data;
				this->next = this->next->next;
				free(removedNode);
				removedNode = NULL;
			}else{
				this->empty_root = true;
				return;
			}
		}else{
			return;
		}
	}else{
		RecursiveDoubleLinkedList<T> *removedNode = previous->next;
		previous->next = previous->next->next;
		free(removedNode);
		removedNode = NULL;
	}
}

////////////////////////////////////////////////////////////////////

/*
* Search a previous node of element, or NULL if element isn't in the list
* Complexity : O(n)
* @param element
* @return NodePointer 
*/
////////////////////////////////////////////////////////////////////

template<class T>
RecursiveDoubleLinkedList<T> *RecursiveDoubleLinkedList<T>::searchPrevious(T element){
	if(!this->next){
		return NULL;	
	}else{
		if(next->data == element){
			return this;
		}else{
			next->searchPrevious(element);
		}
	}
}

////////////////////////////////////////////////////////////////////

/*
* Return an vector with list elements
* Complexity : O(n)
* @return vector
*/
/////////////////////////////////////////////////////////////////////

template<class T>
std::vector<T> RecursiveDoubleLinkedList<T>::toVector(){
	std::vector<T> result;
	if(!empty_root){
		this->recursiveToVector(&result);
	}	
	return result;
}

//////////////////////////////////////////////////////////////////////

/*
* Recursive method to build elements vector
*/
//////////////////////////////////////////////////////////////////////

template<class T>
void RecursiveDoubleLinkedList<T>::recursiveToVector(std::vector<T> *vetor){
	if(next){
		vetor->push_back(data);
		next->recursiveToVector(vetor);
	}else{
		vetor->push_back(data);
	}
}

///////////////////////////////////////////////////////////////////////


/*
* Insert in head position
* Complexity : O(1)
* @param element
*/
/////////////////////////////////////////////////////////////////////

template<class T>
void RecursiveDoubleLinkedList<T>::insertFirst(T element){
	if(this->isEmpty()){
		this->insert(element);	
	}else{
		RecursiveDoubleLinkedList<T> *newHead =	new RecursiveDoubleLinkedList<T>(this->data);
		newHead->next = this->next;
		this->data = element;
		this->next = newHead;
	}
}

//////////////////////////////////////////////////////////////////////

/*
* Remove first position
* Complexity : O(1)
* @param element
*/
/////////////////////////////////////////////////////////////////////

template<class T>
void RecursiveDoubleLinkedList<T>::removeFirst(){
	if(this->isEmpty()){
		return;	
	}else{	
		if(this->next){
			this->data = this->next->data;
			this->next = this->next->next;
		}else{
			this->empty_root = true;
			this->next = NULL;	
		}
	}
}

//////////////////////////////////////////////////////////////////////


/*
* Remove last position element
* Complexity : O(n)
* @param element
*/
/////////////////////////////////////////////////////////////////////

template<class T>
void RecursiveDoubleLinkedList<T>::removeLast(){
	if(!this->isEmpty()){		
		RecursiveDoubleLinkedList *previous = NULL;
		RecursiveDoubleLinkedList *aux = this;
		while(aux->next){
			previous = aux;
			aux = aux->next;	
		}
		
		if(previous){			
			previous->next = NULL;
		}else{
			this->empty_root = true;
			this->next = NULL;		
		}
	}
}

//////////////////////////////////////////////////////////////////////

#endif
