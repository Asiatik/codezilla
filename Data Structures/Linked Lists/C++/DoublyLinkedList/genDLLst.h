#ifndef DOUBLY_LINKED_LIST
#define DOUBLY_LINKED_LIST

template<class T>
class DLLNode
{
	public:
		
		DLLNode(const T& el, DLLNode *n=0, DLLNode *p=0)
		{
			info=el;  next=n;  prev=p;
		}
		
		T info;
		DLLNode *next, *prev;
};

template<class T>
class DoublyLinkedList
{
	public:
		DLLNode<T> *head, *tail;
		
		DoublyLinkedList()
		{
			head=tail=0;
		}
		
	  void addToDLLHead(const T&);
	  void addToDLLTail(const T&);
	  
	  T deleteFromDLLHead();
	  T deleteFromDLLTail();
	  
	  void deleteOddNodes();
	  
	  void deleteDLLNode(T);
	  bool isInDLLList(T) const;
	  
	  DoublyLinkedList* merging(DoublyLinkedList*, DoublyLinkedList*);
	  
	  DoublyLinkedList* operator +(DoublyLinkedList*);
	  
	  DLLNode<T>* reverse();

      DLLNode<T>* middle();
      
	  void displayDLL(); 
	  
	  DoublyLinkedList<T>* addToDLLPosition(T, int);
	  DoublyLinkedList<T>* deleteFromDLLPosition(int);
};

#endif
