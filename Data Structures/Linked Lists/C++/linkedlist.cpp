#include<iostream.h>
#include<conio.h>
class llnode
{
	public:
	int info;
	llnode *next;
	llnode(int a,llnode *ptr=0)
	{
		info=a;
		next=ptr;
	}
};
class llist
{
	llnode *head,*tail;
	public:
	llist()
	{
	head=tail=0;
	}
	void addtobeg(int a);
	void addtoend(int a);
	void addafter(int a,int b);
	void addbefore(int a,int b);
	void delhead();
	void delend();
	void delnode (int a);
	void addorder(int a);
	void modify(int a,int b);
	void reverse();
	void searching(int a);
	void sort();
	void display();
};
void llist::addtobeg(int a)
{
	llnode *p;
	if(head==0)
	{
		p=new llnode(a);
		tail=head=p;
	}
	else
	{
		p=new llnode(a);
		p->next=head;
		head=p;
	}
}
void llist::addtoend(int a)
{
	llnode *p;
	if(head==0)
	{
		p=new llnode(a);
		head=tail=p;
	}
	else
	{
		p=new llnode(a);
		tail->next=p;
		tail=p;
	}

}
void llist::addafter(int a,int b)
{
	llnode *p,*q;
	p=head;
	q=new llnode(a);
	while(p->info!=b)
	p=p->next;

	q->next=p->next;
	p->next=q;
}
void llist::addbefore(int a,int b)
{
	llnode *p,*r,*q;
	p=head;
	q=new llnode(a);
	while(p->info!=b)
	{
		r=p;
		p=p->next;
	}
	q->next=p;
	r->next=q;
}
void llist::delhead()
{
	llnode *p;
	if(head==0)
	cout<<"list is empty";

	else if(head==tail)
	{
	delete(head);
	head=tail=0;
	}

	else
	{
	p=head;
	head=head->next;
	delete(p);
	}
}
void llist::delend()
{
	llnode *p;
	if(head==0)
	cout<<"list is empty";
	if(head==tail)
	{
	delete (head);
	head=tail=0;
	}
	else
	{
	p=head;
	while(p->next!=tail)
		{
		p=p->next;
		}
	p->next=0;
	delete(tail);
	tail=p;
	}
}
void llist::delnode(int a)
{
	llnode *p,*r;
	p=head;
	while(p->info!=a)
	{
		r=p;
		p=p->next;
	}

	r->next=p->next;
	delete (p);
}
void llist::addorder(int a)
{
	llnode *p,*r,*q;
	if(head==0)
	{
	p=new llnode(a);
	tail=head=p;
	}

	else if(a<head->info)
	head=new llnode(a,head);

	else if(a>tail->info)
	{
		p=new llnode(a);
		tail->next=p;
		tail=p;
	}
	else
	{
	p=head;
	while(p->info<a)
	{
		r=p;
		p=p->next;
	}
	q=new llnode(a);
	r->next=q;
	q->next=p;
	}
}

void llist::modify(int a,int b)
{
	llnode *p;
	p=head;
	if(head==0)
	cout<<"linklist is empty";

	else if(head==tail)
	{
		if(p->info==a)
		p->info=b;
		else
		cout<<"element does not exist";
	}
	else
	{
		while(p!=0)
		{
			if(p->info==a)
			p->info=b;
			else
			p=p->next;
		}
	 }
}
void llist::reverse()
{
	llnode *p,*q,*r;
	p=head;
	head=tail;
	tail=p;
	q=p->next;
	r=q->next;
		while(q!=0)
		{
			q->next=p;
			p=q;
			q=r;
			r=r->next;
		}
		tail->next=0;

}
void llist::searching(int a)
{
	int count=0;
	llnode *p;
	if(head==0)
	cout<<"linklist is empty";
	else
	{
		p=head;
		while(p->info!=a)
		{
			p=p->next;
			count++;
		}
			cout<<"element is at position "<<count+1;

	}
}
void llist::sort()
{
	llnode *p,*q,*r;
	p=head;

	if(head==0)
	cout<<"linklist is empty";

	else
	{
		while(p!=tail)
		{
			q=p->next;
			while(q!=0)
			{
			if(p->info>q->info)
			{
				r=new llnode(p->info);
				p->info=q->info;
				q->info=r->info;
			}
			q=q->next;
			}
		p=p->next;
		}
	}
}

void llist::display()
{
	llnode *p;
	p=head;
	while(p!=0)
	{
		cout<<p->info<<"  ";
		p=p->next;
	}
}

void main()
{
	clrscr();
	int x,y,choice;
	char ch,ch1;
	llist ob;


	do
	{
	cout<<"Enter the operation\n1:Add to beginning\n";
	cout<<"2:Add to end\n3:Add after node\n4:Add before node\n";
	cout<<"5:Delete from beginning\n6:Delete from end\n";
	cout<<"7:Delete node in already created linklist\n8:Add orderly";
	cout<<"\n9:Modify\n10:Reverse\n11:searching:\n12:sort the link list:";

	do{
	cin>>choice;
	switch(choice)
	{
		case 1: cout<<"enter the element:\n";
			cin>>x;
			ob.addtobeg(x);
			cout<<"linklist after addition";
			ob.display();
			break;
		case 2: cout<<"enter the element:\n";
			cin>>x;
			ob.addtoend(x);
			cout<<"linklist after addition";
			ob.display();
			break;
		case 3: cout<<"enter the element to be added\n";
			cin>>x;
			cout<<"kiske baad\n";
			cin>>y;
			ob.addafter(x,y);
			cout<<"linklist after addition";
			ob.display();
			break;
		case 4: cout<<"enter the element:\n";
			cin>>x;
			cout<<"kiske pehle\n";
			cin>>y;
			ob.addbefore(x,y);
			cout<<"linklist after addition";
			ob.display();
			break;
		case 5: cout<<"linklist after deletion";
			ob.delhead();
			ob.display();
			break;
		case 6: cout<<"linklist after deletion";
			ob.delend();
			ob.display();
			break;
		case 7: cout<<"enter the element of node to be deleted";
			cin>>x;
			cout<<"linklist after deletion";
			ob.delnode(x);
			ob.display();
			break;
		case 8: cout<<"enter the elements:";
			while(x!=0)
			{
			cin>>x;
			if(x==0)
			break;
			else
			ob.addorder(x);
			}
			ob.display();
			break;
		case 9: cout<<"enter the element to be modify";
			cin>>x;
			cout<<"\nenter the new element";
			cin>>y;
			ob.modify(x,y);
			ob.display();
			break;
		case 10:ob.reverse();
			cout<<"reversed linklist is:\n";
			ob.display();
			break;
		case 11:cout<<"enter the element to search";
			cin>>x;
			ob.searching(x);
			break;
		case 12:cout<<"\nsorted list is:";
			ob.sort();
			ob.display();
			break;
		}
		cout<<"\ndo want to continue with the same data?";
		cin>>ch1;
		}while(ch1=='y'||ch1=='Y');
		cout<<"\ndo you want to enter new data?";
		cin>>ch;
		}while(ch=='Y'||ch=='y');
		getch();
}














