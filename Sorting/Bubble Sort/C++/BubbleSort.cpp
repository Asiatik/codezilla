#include<iostream.h>
#include<conio.h>
#include<stdlib.h>
int bsort(int ar[],int size)
{
int tmp,cnt=0;
for(int i=0;i<size;i++)
{
	for(int j=0;j<size-i;j++)
	{
		if(ar[j]>ar[j+1])
		{
		cnt++;
		tmp=ar[j];
		ar[j]=ar[j+1];
		ar[j+1]=tmp;
		}
	}
}
return cnt;
}
void main()
{
clrscr();
	randomize();
	int cnt,size;
	for(int k=0;k<14;k++)
	{
	size=random(10)+10;
	int *a=new int[size];
	for(int i=0;i<size;i++)
	{
	a[i]=random(100);
	cout<<a[i]<<" ";
	}
	cnt=bsort(a,size-1);
	cout<<"\n";
	for(int i1=0;i1<size;i1++)
	cout<<a[i1]<<" ";
	cout<<"cmp"<<cnt<<"\n\n";
	}
	getch();
}
