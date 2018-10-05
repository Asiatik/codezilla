#ifndef GEN_LINKED_LIST
#define GEN_LINKED_LIST

template<class T>
class SLLNode
{
  public:
  	  
  	  T info;
  	  SLLNode *next;
  	  
	  SLLNode(T el, SLLNode *ptr=0)
  	  {
  	  	info=el;
  	  	next=ptr;
	  }
};

template<class T>
class SLList
{
  public:
  	
  	  SLList()
  	  {
  	  	head=tail=0;
	  }
	  
	  ~SLList();
	  
	  int isEmpty()
	  {
	  	return head==0;
	  }
	  
	  void addToHead(T);
	  void addToTail(T);
	  
	  T deleteFromHead();
	  T deleteFromTail();
	  
	  void deleteNode(T);
	  bool isInList(T) const;
	  
	  SLList<T>* operator +(SLList<T>*);
	  
	  SLLNode<T>* reverse();

      T count(SLLNode<T>*);
      void change();
      
	  void display(); 
	  
	  SLList<T>* addToPosition(T, int);
	  SLList<T>* deleteFromPosition(int);
  	  
  	  SLLNode<T> *head, *tail;
};

#endif
