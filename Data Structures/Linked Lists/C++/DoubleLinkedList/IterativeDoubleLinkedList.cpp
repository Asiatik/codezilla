#include "IterativeDoubleLinkedList.hpp"

template<class T>
IterativeDoubleLinkedList<T>::IterativeDoubleLinkedList(){
	this->head = NULL;
	this->tail = NULL;	
};


/*
* Return true if list is empty or false,otherwise.
* Complexity : O(1)
* @return bool
*/
template<class T>
bool IterativeDoubleLinkedList<T>::isEmpty(){
	if(this->head){
		return false;
	}else{
		return true;
	}
}


/*
* Insert new element in list
* Complexity : O(1)
* @param new element
*/
template<class T>
void IterativeDoubleLinkedList<T>::insert(T element){
	if(this->isEmpty()){
		Node<T> *head = new Node<T>(element);
		this->head = head;
		this->head->previous = NULL;
		this->tail = new Node<T>(this->head);
		this->tail->next = NULL;
		this->head->next = this->tail;
	}else{
		Node<T> *aux = this->head;
		while(aux != this->tail){
			aux = aux->next;
		}
		aux->data = element;
		aux->next = new Node<T>(aux);
		this->tail = aux->next;
		this->tail->next = NULL;
	}
}


/*
* Return size of the list
* Complexity : O(n)
* @return int
*/
template<class T>
int IterativeDoubleLinkedList<T>::size(){
	if(isEmpty()){
		return 0;	
	}else{
		int count = 0;
		Node<T> *aux = this->head;
		while(aux != this->tail){
			aux = aux->next;
			count++;
		}
		return count;
	}
}


/*
* Search an node, if found return your pointer, else return NULL
* Complexity : O(n)
* @param element to be searched
* @return NodeFound
*/
template<class T>
Node<T>* IterativeDoubleLinkedList<T>::searchNode(T element){
	if(!isEmpty()){
		Node<T> *aux = this->head;
		while(aux != this->tail){
			if(aux->data == element){
				return aux;
			}
			aux = aux->next;
		}
		return NULL;
	}else{
		return NULL;
	}
}


/*
* Search an element, if found return your pointer, else return NULL
* Complexity : O(n)
* @param element to be searched
* @return elementFound
*/
template<class T>
T* IterativeDoubleLinkedList<T>::search(T element){
	if(!isEmpty()){
		Node<T> *aux = this->head;
		while(aux != this->tail){
			if(aux->data == element){
				return &(aux->data);
			}
			aux = aux->next;
		}
		return NULL;
	}else{
		return NULL;
	}
}


/*
* Remove an list element
* Complexity : O(n)
* @param element to be removed
*/
template<class T>
void IterativeDoubleLinkedList<T>::remove(T element){
	if(!isEmpty()){
		Node<T> *foundNode = this->searchNode(element);
		if(foundNode){
			if(foundNode == this->head){
				this->removeFirst();
			}else{
				foundNode->next->previous = foundNode->previous;
				foundNode->previous->next = foundNode->next;
				free(foundNode);
				foundNode == NULL;
			}
		}
	}
}


/*
* Return head of double linked list
* Complexity : O(1)
* @return NodePointer
*/
template<class T>
Node<T> *IterativeDoubleLinkedList<T>::getHead(){
	return this->head;
}


/*
* Insert new element in head of linked list
* Complexity : O(1)
* @param element
*/
template<class T>
void IterativeDoubleLinkedList<T>::insertFirst(T element){
	if(!isEmpty()){
		Node<T> *newNode = new Node<T>(element,this->head);
		this->head->previous = newNode;
		this->head = newNode;
	}else{
		this->insert(element);
	}
}


/*
* Remove the first element of the list
* Complexity : O(1)
*/
template<class T>
void IterativeDoubleLinkedList<T>::removeFirst(){
	if(!isEmpty()){
		if(this->head->next == this->tail){
			free(this->head);
			this->head = NULL;
		}else{
			Node<T> *removedValue = this->head;
			this->head = this->head->next;
			this->head->previous == NULL;
			free(removedValue);
			removedValue = NULL;
		}
	}
}


/*
* Remove the last element of the list
* Complexity : O(1)
*/
template<class T>
void IterativeDoubleLinkedList<T>::removeLast(){
	if(!isEmpty()){
		if(this->head->next == this->tail){
			free(this->head);	
			this->head = NULL;
		}else{
			Node<T> *removedNode = this->tail->previous;
			this->tail->previous = this->tail->previous->previous;
			this->tail->previous->next = this->tail;
			free(removedNode);
			removedNode = NULL;
		}
	}
}


/*
* Return vector with all elements list
* Complexity : O(n)
* @return vector
*/
template<class T>
std::vector<T> IterativeDoubleLinkedList<T>::toVector(){
	std::vector<T> result;
	if(!isEmpty()){
		Node<T> *aux = this->head;
		while(aux != this->tail){
			result.push_back(aux->data);
			aux = aux->next;
		}
	}
	return result;
}

