#ifndef _ITERATIVELIST_H_
#define _ITERATIVELIST_H_
/*
*@author Ionésio Junior
*/
#include "LinkedList.hpp"
/*
* Single Linked List in iterative implementation
*/

/*
*Node struct 
*/
template<class T>
struct Node{
	T data;
	Node<T> *next;
	Node(T value){
		this->data = value;
	}
};

/*
*Single Linked List class
*/
//SingleLinkedList.hpp
template<class T>
class IterativeSingleLinkedList : public LinkedList<T>{
	private:
		Node<T> *head;
	public:
		IterativeSingleLinkedList();
		void insert(T element) override;
		void remove(T element) override;
		int size() override;
		T *search(T element) override;
		Node<T> *getHead();
		std::vector<T> toVector() override;
		bool isEmpty() override;
};

//SingleLinkedList.cpp

/*
* Empty Constructor of linked list class
*/
////////////////////////////////////////////////

template<class T>
IterativeSingleLinkedList<T>::IterativeSingleLinkedList(){
	this->head = NULL;	
};

////////////////////////////////////////////////

/*
* Return true if list is empty or false,otherwise.
* Complexity : O(1)
* @return bool
*/
////////////////////////////////////////////////

template<class T>
bool IterativeSingleLinkedList<T>::isEmpty(){
	if(head){
		return false;
	}else{
		return true;	
	}
}

//////////////////////////////////////////////////

/*
* Get head of single linked list
* Complexity : O(1)
* @return Node
*/
//////////////////////////////////////////////////

template<class T>
Node<T> *IterativeSingleLinkedList<T>::getHead(){
	return this->head;
}

//////////////////////////////////////////////////

/*
* Insert new element in list
* Complexity : O(n)
* @param new element
*/
////////////////////////////////////////////////////

template<class T>
void IterativeSingleLinkedList<T>::insert(T element){
	if(!head){
		this->head = new Node<T>(element);
		this->head->next = NULL;	
	}else{
		Node<T> *aux = this->head;
		while(aux->next){
			aux = aux->next;
		}
		aux->next = new Node<T>(element);
		aux->next->next = NULL;
	}

}

//////////////////////////////////////////////////////


/*
* Remove an list element
* Complexity : O(n)
* @param element to be removed
*/
//////////////////////////////////////////////////////

template<class T>
void IterativeSingleLinkedList<T>::remove(T element){
	if(head){
		if(this->head->data == element){
			Node<T> *removedElement = this->head;
			this->head = this->head->next;
			free(removedElement);
			removedElement = NULL;
		}else{
			Node<T> *aux = this->head;
			while(aux->next){
				if(aux->next->data == element){
					Node<T> *removedElement = aux->next;
					aux->next = aux->next->next;
					free(removedElement);
					removedElement = NULL;
					break;
				}
				aux = aux->next;
			}
		}		
	}
}

////////////////////////////////////////////////////////

/*
* Return size of the list
* Complexity : O(n)
* @return int
*/
////////////////////////////////////////////////////////

template<class T>
int IterativeSingleLinkedList<T>::size(){
	if(head){
		Node<T> *aux = this->head;
		int count = 1;
		while(aux->next){
			aux = aux->next;
			count++;
		}
		return count;
	}else{
		return 0;
	}
}

/////////////////////////////////////////////////////////

/*
* Search an element, if found return your pointer, else return NULL
* Complexity : O(n)
* @param element to be searched
* @return elementFound
*/
/////////////////////////////////////////////////////////

template<class T>
T *IterativeSingleLinkedList<T>::search(T element){
	if(head){
		if(this->head->data == element){
			return &(this->head->data);
		}else{
			Node<T> *aux = this->head;
			while(aux->next){
				if(aux->next->data == element){
					return &(aux->next->data);
				}
				aux = aux->next;
			}
			return NULL;
		}
	}else{
		return NULL;
	}
}

//////////////////////////////////////////////////////////

/*
* Return vector with all elements list
* Complexity : O(n)
* @return vector
*/
//////////////////////////////////////////////////////////

template<class T>
std::vector<T> IterativeSingleLinkedList<T>::toVector(){
	std::vector<T> result;
	if(head){
		Node<T>	*aux = this->head;
		result.push_back(head->data);
		while(aux->next){
			result.push_back(aux->next->data);
			aux = aux->next;
		}
	}
	return result;
}

////////////////////////////////////////////////////////////
#endif
