#include<stdio.h>
void heapsort(int Array[],int n);
void Build_Heap (int Array[],int n);
void Heapify(int Array[],int i, int n);


void main()

{
	int x;
	int Array[10]={9,8,2,3,4,5,1,2,3,1};
	heapsort(Array,10);

	for(x=0;x<10;x++)
	{
	printf("Heap Sort %d\n",Array[x]);
	}



}

void heapsort(int Array[],int n)
{
	int temp;
	int i;
	Build_Heap(Array,n);
	for(i=n-1;i>1;i--)
	{
	temp=Array[0];
	Array[0]=A[i];
	Array[i]=temp;
	Heapify(Array,0,i-1);
	}

}

void Build_Heap (int Array[],int n)
{
	int i;
	for(i= (n-1)/2;i>0;i--)
	{
	Heapify(Array,i,n);
	}

}


void Heapify(int Array[],int i, int n)
{

	int largest;
	int left =2*i;
	int right = (2*i)+1;
	int temp2;


if((left<n) && ( Array[left]>Array[i]))
	{
		largest = left;
	}
else 
	largest =i;

if ((right<n) && (Array[right]>Array[largest]))
{largest=right;}

if(largest != i)
{
	temp2=Array[i];

	Array[i]=Array[largest];

	Array[largest]=temp2;
	Heapify(Array,largest,n);
}



}
