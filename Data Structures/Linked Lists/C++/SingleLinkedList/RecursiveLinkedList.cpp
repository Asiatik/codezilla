#include "RecursiveLinkedList.hpp"

/*
* Empty Constructor of linked list node
*/
template<class T>
RecursiveSingleLinkedList<T>::RecursiveSingleLinkedList(){
	this->empty_root = true;
}


/*
* Constructor of linked list node
* @param element
*/
template<class T>
RecursiveSingleLinkedList<T>::RecursiveSingleLinkedList(T element){
	this->data = element;
	this->empty_root = false;
}


/*
* Return true  if linked list is empty or false,otherwise.
* Complexity : O(1)
* @return bool
*/
template<class T>
bool RecursiveSingleLinkedList<T>::isEmpty(){
	return this->empty_root;
}


/*
* Get data stored in node
* @return element
*/
template<class T>
T RecursiveSingleLinkedList<T>::getData(){
	return this->data;
}


/*
* Return size of list
* Complexity : O(n)
* @return int
*/
template<class T>
int RecursiveSingleLinkedList<T>::size(){
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


/*
* Search an element, if found return it return your pointer, else return NULL
* Complexity : O(n)
* @param element to be searched
* @return elementFoundPointer
*/
template<class T>
T * RecursiveSingleLinkedList<T>::search(T element){
	if(data == element){
		RecursiveSingleLinkedList<T> *previous = this->searchPrevious(element);
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


/*
* Insert new element in last position of the list
* Complexity : O(n)
* @param new element
*/
template<class T>
void RecursiveSingleLinkedList<T>::insert(T element){
	if(this->empty_root){
		this->data = element;
		this->empty_root = false;
		this->next = NULL;
	}else{
		if(!next){
			this->next = new RecursiveSingleLinkedList<T>(element);
			this->next->next = NULL;
		}else{
			this->next->insert(element);
		}
	}
}


/*
* Remove an list element
* Complexity : O(n)
* @param element to be removed
*/
template<class T>
void RecursiveSingleLinkedList<T>::remove(T element){
	RecursiveSingleLinkedList<T> *previous = this->searchPrevious(element);
	if(!previous){
		if(data == element){
			if(next){
				RecursiveSingleLinkedList<T> *removedNode = this->next;
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
		RecursiveSingleLinkedList<T> *removedNode = previous->next;
		previous->next = previous->next->next;
		free(removedNode);
		removedNode = NULL;
	}
}


/*
* Search a previous node of element, or NULL if element isn't in the list
* Complexity : O(n)
* @param element
* @return NodePointer 
*/
template<class T>
RecursiveSingleLinkedList<T> *RecursiveSingleLinkedList<T>::searchPrevious(T element){
	if(!next){
		return NULL;	
	}else{
		if(next->data == element){
			return this;
		}else{
			next->searchPrevious(element);
		}
	}
}


/*
* Return head of the list
* Complexity : O(1)
* @return elementPointer
*/
template<class T>
T *RecursiveSingleLinkedList<T>::getRoot(){
	if(this->empty_root){
		return NULL;
	}else{
		return &data;
	}
}


/*
* Return an vector with list elements
* Complexity : O(n)
* @return vector
*/
template<class T>
std::vector<T> RecursiveSingleLinkedList<T>::toVector(){
	std::vector<T> result;
	if(!empty_root){
		this->recursiveToVector(&result);
	}	
	return result;
}


/*
* Recursive method to build elements vector
*/
template<class T>
void RecursiveSingleLinkedList<T>::recursiveToVector(std::vector<T> *vetor){
	if(next){
		vetor->push_back(data);
		next->recursiveToVector(vetor);
	}else{
		vetor->push_back(data);
	}
}

