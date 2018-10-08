#include<iostream.h>
#include<conio.h>
class Heaps
{

		int *a;
		int size;
		int heapsize;
	public:
		Heaps(int n)
		{
			size=n;
			a=new int[size];
		}
		void input();
		void swap(int &, int &);
		int maxheapify(int i);
		void buildmaxheap();
		void heapsort();
		void print();

};

void Heaps::input()
{
	for(int i=0; i<size; i++)
		cin>>a[i];
}

void Heaps::swap(int &a, int &b)
{
	int temp;
	temp=a;
	a=b;
	b=temp;
}

int Heaps::maxheapify(int i)                    //finding largest elment
{                                                //in a subtree
	int large,cnt=0;
	int l=(2*i)+1;
	int r=(2*i)+2;
	if((l<heapsize)&&(a[i]<a[l]))
	{       cnt++;
		large=l;
	}
	else
	{
		cnt++;
		large=i;
	}
	if((r<heapsize)&&(a[large]<a[r]))
	{
		cnt++;
		large=r;
	}
	if(i!=large)
	{
		swap(a[i],a[large]);
		maxheapify(large);
	}
	return cnt;
}

void Heaps::buildmaxheap()
{       int cn;
	heapsize=size;
	for(int i=(size/2-1); i>=0;i--)            //parent is floor of i/2
	cn=maxheapify(i);
	cout<<"no. of comparisions"<<cn;
}

void Heaps::heapsort()
{
	buildmaxheap();
	for(int i=size-1;i>0;i--)
	{
		swap(a[heapsize-1],a[0]);
		heapsize--;                  //largest element placed at last position
		maxheapify(0);               //check on last placed node
	}
}

void Heaps::print()
{
	for(int i=0; i<size; i++)
		cout<<a[i]<<"  ";
}

void main()
{
	clrscr();
	int a[20],n;
	cout<<"--------------Enter the size of array: ---------\n";
	cin>>n;
	Heaps h(n);
	cout<<"\n-----------Enter the elements of the array:--------\n";
	h.input();
	h.heapsort();
	cout<<"\n----------Array after sorting is:---------- ";
	h.print();
	getch();
}






