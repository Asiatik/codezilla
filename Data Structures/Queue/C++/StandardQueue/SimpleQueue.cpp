#include<iostream.h>
#include<conio.h>
class queue
{
	private:
		int arr[10];
		int r,f;
	public:
		queue()
		{
			f=r=-1 ;
		}
	void enqueue(int a);
	int dequeue();
	void display();
};
void queue::enqueue(int a)
{
	cout<<a;
	if(f==-1)
	{
		f=r=0;
		arr[r]=a;
		cout<<arr[r];
	}
	else
	{
	  r++;
	  arr[r]=a;
	  cout<<arr[r];

	}
}
int queue::dequeue()
{
	int x;
	if(f==-1)
	{
		cout<<"Nothing to delete";
		return -999;
	}
	else if(f==r)
	{
		x=f;
		r=f=-1;
	}
	else
	{
	    x=f;
	    f++;
	}
	return arr[x];
}
void queue::display()
{
	if(f==-1)
	cout<<"Nothing to display";
	else
	{
		int i=f;
		while(i<r+1)
		{
			cout<<arr[i]<<"  ";
			i++;
		}
	}
}
void main()
{
	clrscr();
	int size;
	queue ob;
	char ans='y';
	while(ans=='y'||ans=='Y')
	{
	clrscr();
	cout<<"\n1.To insert an element into queue.\n2.To remove an element from queue"
		"\n3.To display the elements of Stack"
		"\n\nEnter your choice\n";
	cin>>size;
	switch(size)
	{
		case 1:
			int a;
			cout<<"\nEnter the element to be insert to queue\n";
			cin>>a;
			ob.enqueue(a);
			break;
		case 2:
			a=ob.dequeue();
			if(a!=-999)
			cout<<"\n"<<a<<" is removed\n";
			break;

		case 3:
			ob.display();
			break;
		default:
			cout<<"\nWrong choice!!!!!!\n";
	}
	cout<<"\nEnter 'y' to continue else 'n' to quit\n";
	cin>>ans;
	}
	getch();
}
