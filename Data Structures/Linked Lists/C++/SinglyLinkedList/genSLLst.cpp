#include <iostream>
#include "genSLLst.h"

using namespace std;

template<class T>
SLList<T> :: ~SLList()
{
  for(SLLNode<T> *p; !isEmpty(); )
  {
  	p=head->next;
  	delete head;
  	head=p;
  }
  
}

template<class T>
void SLList<T> :: addToHead(T el)
{
  head=new SLLNode<T>(el, head);
  
  if(tail==0)
     tail=head;
}

template<class T>
void SLList<T> :: addToTail(T el)
{
  if(tail!=0)
  {
  	tail->next=new SLLNode<T>(el);
  	tail=tail->next;
  }
  
  else
    head=tail=new SLLNode<T>(el);
    
}

template<class T>
T SLList<T> :: deleteFromHead()
{
  T el=head->info;
  SLLNode<T> *tmp=head;
  
  if(head==tail)
     head=tail=0;

  else
     head=head->next;
     
  delete tmp;
  return el;
     
}

template<class T>
T SLList<T> :: deleteFromTail()
{
  T el=tail->info;
  
  if(head==tail)
  {
  	delete head;
  	head=tail=0;
  }
  
  else
  {
  	SLLNode<T> *tmp;
  	
  	for(tmp=head; tmp->next!=tail; tmp=tmp->next);
  	       delete tail;
  	       
  	tail=tmp;
  	tail->next=0;
  	
  }
  
  return el;
}

template<class T>
void SLList<T> :: deleteNode(T el)
{ 
  if(head!=0)
  {
    if(head==tail && el==head->info)
    {
      delete head;
      head=tail=0;
      cout<<"\nSuccessfully deleted the given element \n";   return ;
	}
	
	else if(el==head->info)
	{
	  SLLNode<T> *tmp=head;
	  head=head->next;
	  delete tmp;
	  cout<<"\nSuccessfully deleted the given element \n";   return ;
	}
	
	else
	{
	  SLLNode<T> *pred, *tmp;
	  
	  for(pred=head, tmp=head->next; (tmp!=0 && !(tmp->info==el)); pred=pred->next, tmp=tmp->next);
	  
	  if(tmp!=0)
	  {
	  	pred->next=tmp->next;
	  	
	  	if(tmp==tail)
	  	     tail=pred;
	  	
	  	delete tmp;
	  	cout<<"\nSuccessfully deleted the given element \n";  return ;
	  	
	  }
	  cout<<"\nError occured while deleting - element not found in list \n";
	}
   
  }
  
  else 
    cout<<"\nNo node present in list to delete \n";
}

template<class T>
bool SLList<T> :: isInList(T el) const
{
  SLLNode<T> *tmp;
  
  for(tmp=head; tmp!=0 && !(tmp->info==el); tmp=tmp->next);
        return tmp!=0;
        
}

template<class T>
SLList<T>* SLList<T> :: operator +(SLList<T>* l2)
{ 
  SLList<T>* res1=new SLList<T>();
  SLLNode<T> *t=this->head;
  
  while(t!=0)
  {
  	res1->addToTail(t->info);
  	t=t->next;
  }
  
  t=l2->head;
  while(t!=0)
  {
  	res1->addToTail(t->info);
  	t=t->next;
  }
  
  return res1;
  
}

template<class T>
SLLNode<T>* SLList<T>::reverse()
{
	SLLNode<T> *prev=NULL;
	SLLNode<T> *temp;
	tail=head;
	while(head!=0)
	{
		temp=head->next;
		head->next=prev;
		prev=head;
		head=temp;
	}
	head=prev;
}

template<class T>
T SLList<T>::count(SLLNode<T> *head)
{
	if(head==0)   return 0;
	else          return (1+count(head->next));
}

template<class T>
void SLList<T>::display()
{
	SLLNode<T> *t;
	for(t=head; t!=0; t=t->next)
		cout<<t->info<<" ";
}

template<class T>
SLList<T>* SLList<T>::addToPosition(T inf, int pos)
{
	SLLNode<T> *pred=NULL, *tmp=this->head;
	int count=1;
	if(tmp==0)
	{
		addToTail(inf);   return this;
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
	{   addToHead(inf);  
	    return this;
    }
		
	if(count==pos)
	{
		pred->next=new SLLNode<T>(inf, tmp);  return this;
	}
    else if(count<pos)
	{	addToTail(inf);  
	    return this;
	}
}

template<class T>
SLList<T>* SLList<T>::deleteFromPosition(int pos)
{
	   SLLNode<T> *pred=NULL, *tmp=this->head;
	   int count=1;
       if(tmp==0)   
	   {
	        cout<<"\nNo node is there, List is empty !!! \n";    return this;
       }
	    if(pos==1)
	    {
	    	deleteFromHead();   return this;
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
		pred->next=tmp->next;
		if(tmp==tail)   tail=pred;
		delete tmp;
		return this;
}

template<class T>
void SLList<T>::change()
{
	SLLNode<T>* tmp=head;
	if(head==tail)	return;
	head=head->next;
	tail->next=tmp;
	tail=tmp;
	tail->next=0;
}

int main()
{ 
  SLList<float>* I=new SLList<float>();
  //SLList<float>* l1=new SLList<float>();
  SLList<float>* l2=new SLList<float>();
 // SLList<float>* res=new SLList<float>();
  
  int ch;
  cout<<"Menu is - \n"<<"1.addToHead \n2.addToTail \n3.deleteFromHead \n4.deleteFromTail \n5.deleteNode \n6.isInList \n7.concatenate \n8.reverse \n9.addToPositon \n10.deleteFromPosition \n11.change \n12.count\n";
  
  char more='y';
  
  while(more=='y' || more=='Y'){
  cin>>ch;
  switch(ch)
  {
  	case 1 : {float j;
              cout<<"Enter info value to be added to head : \n";
              cin>>j;
              I->addToHead(j);
              cout<<"\nNew List is : ";
              I->display();
              break;}
              
  	case 2 :  {float j;
              cout<<"Enter info value to be added to tail : \n";
  			  cin>>j;
  			  I->addToTail(j);
  			  cout<<"\nNew List is : ";
  			  I->display();
              break;}
              
  	case 3 :  cout<<(I->deleteFromHead())<<" is the deleted element from head \n"; break;
  	
  	case 4 :  cout<<(I->deleteFromTail())<<" is the deleted element from tail \n"; break;
  	
  	case 5 : {float j;
              cout<<"Enter info value to be deleted from list : \n";
  			  cin>>j;
  			  I->deleteNode(j);
  			  cout<<"\nNew List is : ";
  			  I->display();
              break;}
  		
  	case 6 :  {float j;
              cout<<"Enter info value to be searched : \n";
              cin>>j;
              bool h=I->isInList(j);
              cout<<"\n"<<h;
              break;}
              
    case 7 :  { //float b1; 
				float b2;
    			/*
				cout<<"\nEnter number of Nodes for list l1 : ";
				cin>>b1;
				for(int i=0; i<b1; i++)
				{
					float a;
					cout<<"\nEnter info value ";
					cin>>a;
					l1->addToHead(a);
				}
				cout<<"\nList 1 is : ";
				l1->display();*/
				
				cout<<"\nEnter number of Nodes for list l2 : ";
				cin>>b2;
				cout<<"\nThe numbers will be added on list's head ,thus , enter numbers accordingly !!! \n";
				for(int i=0; i<b2; i++)
				{
					float a;
					cout<<"\nEnter info value ";
					cin>>a;
					l2->addToHead(a);
				}
				cout<<"\nList 2 is : ";
				l2->display();
				
				I=I->operator+(l2);
				cout<<"\nResulting List is : ";
				I->display();
                break;}
    
	case 8 :  { I->reverse();
				cout<<"\nThe reversed list is : ";
	  			I->display();
	 		    break;}
	 		    
	case 9 :   {float a; int pos;
	            cout<<"The position starts from index 1 , Enter accordingly !!! \nEnter info to be stored at position : ";
	            cin>>a;
	            cout<<"\nEnter position where info should be stored : ";
		        cin>>pos;
		        I=I->addToPosition(a, pos);
		        I->display();
				break;
           	   }
         	
    case 10:   {int pos;
	            cout<<"The position starts from index 1 , Enter accordingly !!! \nEnter position where info should be deleted : ";
		        cin>>pos;
		        I=I->deleteFromPosition(pos);
		        I->display();
				break;
           	   }  
	
	case 11:  {I->change();
			   cout<<"\nThe changed list is : ";
			   I->display();
		       break;
	          }
	
	case 12:  { int c=I->count(I->head);
				cout<<"\nTotal Nodes in List are : "<<c;
         		break;
	          }     	
	          
  	default :"\nYou have entered wrong choice !! ";
  }
  
  cout<<"\nDo you want to continue (y/n) ";
  cin>>more;
  if(more=='y' || more=='Y') cout<<"\nSelect the choice from above menu \n";
  }
  
  return 0;
}
