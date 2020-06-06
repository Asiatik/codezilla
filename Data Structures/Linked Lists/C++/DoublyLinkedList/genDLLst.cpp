#include <iostream>
#include "genDLLst.h"

using namespace std;

template<class T>
void DoublyLinkedList<T>::addToDLLHead(const T& el)
{
	head=new DLLNode<T>(el, head);
	if(tail==0)
		tail=head;
	else
		head->next->prev=head;
}

template<class T>
void DoublyLinkedList<T>::addToDLLTail(const T& el)
{
	if(tail!=0)
	{
		tail=new DLLNode<T>(el, 0, tail);
		tail->prev->next=tail;
	}
	else   head=tail=new DLLNode<T>(el);
}

template<class T>
T DoublyLinkedList<T>::deleteFromDLLHead()
{
	T el=head->info;
	if(head==tail)
	{
		delete head;
		head=tail=0;
	}
	else
	{
		head=head->next;
		delete head->prev;
		//head->prev=0;
	}
	return el;
}

template<class T>
T DoublyLinkedList<T>::deleteFromDLLTail()
{
	T el=tail->info;
	if(head==tail)
	{
		delete head;
		head=tail=0;
	}
	else
	{
		tail=tail->prev;
		delete tail->next;
		//tail->next=0;
	}
	return el;
}

template<class T>
void DoublyLinkedList<T>::deleteOddNodes()
{
	deleteFromDLLHead();
	int c=1;
	DLLNode<T> *temp=head, *temp2;  
	
	for(DLLNode<T> *t=head; t; t=t->next, c++);
	
	while(temp && temp->next)
	{
		if(temp2)
		{	
			temp2=temp->next;
			delete temp2;
		}
		
		if(temp->next->next)
			temp->next=temp->next->next;
	
		if(temp->next)
		{
			temp->next->prev=temp;
			temp=temp->next;
		}
	}
	if(c%2!=0)
		deleteFromDLLTail();
}

template<class T>
void DoublyLinkedList<T>::deleteDLLNode(T el)
{
	if(head!=0)
   {
    if(head==tail && el==head->info)
    {
      delete head;
      head=tail=0;
	}
	
	else if(el==head->info)
	{
	  head=head->next;
	  delete head->prev;
	  head->prev=0;
	}
	
	else
	{
	  DLLNode<T> *pred, *tmp;
	  
	  for(pred=head, tmp=head->next; (tmp!=0 && !(tmp->info==el)); pred=pred->next, tmp=tmp->next);
	  
	  if(tmp!=0)
	  {
	  	pred->next=tmp->next;
	  	tmp->next->prev=tmp->prev;
	  	
	  	if(tmp==tail)
	    {
	    	tail=pred; delete tmp; tail->next=0; return ;
		}
	  	
	  	delete tmp;
	  	
	  	
	  }
	  
	  else 
	  	{
	  		cout<<"\nError while deleting - not found \n";
	  		return ;
		}
	  
	}
   cout<<"\nSuccessfully deleted the given element \n";
  }
  
  else 
    cout<<"\nError occured while deleting - empty list \n";
}

template<class T>
bool DoublyLinkedList<T>::isInDLLList(T inf) const
{
	DLLNode<T> *tmp;
  
    for(tmp=head; tmp!=0 && !(tmp->info==inf); tmp=tmp->next);
        return tmp!=0;
}


template<class T>
DoublyLinkedList<T>* DoublyLinkedList<T>::operator +(DoublyLinkedList<T>* l2)
{
  DoublyLinkedList<T>* res1=new DoublyLinkedList<T>();
  DLLNode<T> *t=this->head;
  
  while(t!=0)
  {
  	res1->addToDLLTail(t->info);
  	t=t->next;
  }
  
  t=l2->head;
  while(t!=0)
  {
  	res1->addToDLLTail(t->info);
  	t=t->next;
  }
  
  return res1;
}

template<class T>
DLLNode<T>* DoublyLinkedList<T>::reverse()
{
	DLLNode<T> *p1, *p2;
	p1=head;
	p2=p1->next;
	p1->next=NULL;
	p1->prev=p2;
	
	while(p2!=NULL)
	{
		p2->prev=p2->next;
		p2->next=p1;
		p1=p2;
		p2=p2->prev;
	}
	head=p1;
	cout<<"\nList is reversed !!! ";
}

template<class T>
void DoublyLinkedList<T>::displayDLL()
{
	DLLNode <T>*t;
	for(t=head; t!='\0'; t=t->next)
		cout<<t->info<<" ";
}

template<class T>
DoublyLinkedList<T>* DoublyLinkedList<T>::addToDLLPosition(T inf, int pos)
{
	DLLNode<T> *pred=NULL, *tmp=this->head;
	int count=1;
	if(tmp==0)
	{
		addToDLLTail(inf);   return this;
	}
	tmp=head->next;
	pred=head;
	while(tmp!=0)
	{
		count++;
		if(count==pos)  break;
		tmp=tmp->next;
		pred=pred->next;
	
	}
	if(pos==1)
	{   addToDLLHead(inf);  
	    return this;
    }
		
	if(count==pos)
	{
		pred->next=new DLLNode<T>(inf, tmp, pred);  
		tmp->prev=pred->next;
		return this;
	}
    else if(count<pos)
	{	addToDLLTail(inf);  
	    return this;
	}
}

template<class T>
DoublyLinkedList<T>* DoublyLinkedList<T>::deleteFromDLLPosition(int pos)
{
	   DLLNode<T> *pred=NULL, *tmp=this->head;
	   int count=1;
       if(tmp==0)   
	   {
	        cout<<"\nNo node is there, List is empty !!! \n";    return this;
       }
	    if(pos==1)
	    {
	    	deleteFromDLLHead();   return this;
		}
		tmp=head->next;
		pred=head;
		while(tmp!=0)
		{
			count++;
			if(count==pos)  break;
			tmp=tmp->next;
			pred=pred->next;
		}
		if(count<pos)
		{
			cout<<"\nNo Node found at given position "<<pos;    return this;
		}
		if(tmp==tail)   tail=pred;
		else            tmp->next->prev=pred;

		pred->next=tmp->next;
		delete tmp;
		return this;
}

template<class T>
DLLNode<T>* DoublyLinkedList<T>::middle()
{
	DLLNode<T> *h=head, *t=head->next;
	
	if(!head)    return head;
	while(t && t->next)
	{
		h=h->next;   t=t->next->next;
	}
	return h;
}

int main()
{
	DoublyLinkedList<int>* D=new DoublyLinkedList<int>();
	DoublyLinkedList<int>* l2=new DoublyLinkedList<int>();
	
	int ch;
	cout<<"Menu is - 1.addToHead   2.addToTail  3.deleteFromTail   4.deleteFromHead   5.displayDLL   6.isInDLLList  7.deleteDLLNode   8.reverse   9.middle   10.addFromDLLPosition   11.deleteFromDLLPosition   12.concatenate   13.deleteOddNodes\n";
	char more='y';
	while(more=='y' || more=='Y')
	{
		cin>>ch;
		switch(ch)
		{
			case 1: {int j;
             		 cout<<"Enter info value to be added to head : \n";
              		 cin>>j;
             		 D->addToDLLHead(j);
             		 cout<<"\nNew List is : ";
            		 D->displayDLL();
            		 break;}
            		 
            case 2: {int j;
              		 cout<<"Enter info value to be added to tail : \n";
  			  		 cin>>j;
  			 		 D->addToDLLTail(j);
  			 		 cout<<"\nNew List is : ";
  			 		 D->displayDLL();
             		 break;}
            
            case 3:  cout<<(D->deleteFromDLLTail())<<" is the deleted element from tail \n"; break;
            
            case 4:  cout<<(D->deleteFromDLLHead())<<" is the deleted element from head \n"; break;
            
            case 5:  D->displayDLL();  break;
            
            case 6: {int j;
             		 cout<<"Enter info value to be searched : \n";
              		 cin>>j;
              		 bool h=D->isInDLLList(j);
              		 cout<<"\n"<<h;
              		 break;}
            
            case 7:  {int j;
             		  cout<<"Enter info value to be deleted from list : \n";
  			  		  cin>>j;
  			  		  D->deleteDLLNode(j);
  			  		  cout<<"\nNew List is : ";
  			  		  D->displayDLL();
              		  break;}
              		  
            case 8:  { D->reverse();
	  			       D->displayDLL();
	 		           break;}
	 		
	 		case 9:  { DLLNode<int>* c=D->middle();
			 		   cout<<"\nThe Middle element is : "<<c->info;
				       break;
			         }
			
			case 10: { int n;   int p;
					   cout<<"\nEnter the info : ";
					   cin>>n;
					   cout<<"\nEnter the position : ";
					   cin>>p;
					   D->addToDLLPosition(n, p);
					   D->displayDLL();
				       break;
			         }
              		 
            case 11: { int p;
            		   cout<<"\nEnter the position : ";
            		   cin>>p;
            		   D->deleteFromDLLPosition(p);
            		   D->displayDLL();
				       break;
			         }
			
			case 12: { //float b1; 
			        	int b2;
						cout<<"\nEnter number of Nodes for list l2 : ";
						cin>>b2;
						cout<<"\nThe numbers will be added on list's head ,thus , enter numbers accordingly !!! \n";
						for(int i=0; i<b2; i++)
						{
							int a;
							cout<<"\nEnter info value ";
							cin>>a;
							l2->addToDLLHead(a);
						}
						cout<<"\nList 2 is : ";
						l2->displayDLL();
				
						D=D->operator+(l2);
						cout<<"\nResulting List is : ";
						D->displayDLL();
               			break;
					 }
					 
			case 13: {
						cout<<"\nOdd nodes are deleted : \n";
						D->deleteOddNodes();
						D->displayDLL();
						break;
					 }
		}
		cout<<"\nDo you want to continue (y/n) ";
        cin>>more;
        if(more=='y' || more=='Y') cout<<"\nSelect the choice from above menu \n";
	}
}

