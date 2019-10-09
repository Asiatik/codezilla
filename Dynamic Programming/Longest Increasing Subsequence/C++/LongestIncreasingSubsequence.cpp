#include<iostream.h>
#include<conio.h>
#include<stdio.h>
void print_lcs(char **b,char *X,int m,int n);

void lcs(char *X,char *Y,int m,int n)
{

	int **c;
	c=new int*[m];
	for(int i=0;i<=m;i++)
		c[i]=new int[n];
	char **b;
	b=new char*[m];
	for (i=1;i<=m;i++)
		b[i]=new char[n];


	for(i=1;i<=m;i++)
		c[i][0]=0;
	for(int j=0;j<=n;j++)
		c[0][j]=0;
	for(i=1;i<=m;i++)
	{
		for(j=1;j<=n;j++)
		{
			if(X[i-1]==Y[j-1])
			{
				c[i][j]=c[i-1][j-1]+1;
				b[i][j]='d';
			}
			else if(c[i-1][j]>=c[i][j-1])
			{
				c[i][j]=c[i-1][j];
				b[i][j]='u';
			}
			else
			{
				c[i][j]=c[i][j-1];
				b[i][j]='s';
			}
		}
	}
	cout<<"\nTABLE COMPUTED BY LCS LENGTH:";
	for(i=0;i<=m;i++)
	{
		cout<<"\n";
		for(j=0;j<=n;j++)
			cout<<c[i][j]<<" ";
	}
	cout<<"\nTABLE IN WHICH \n d=where enteries are equal \n s,u=enteries unequal";
	for(i=1;i<=m;i++)
		b[i][0]='0';
	for(j=0;j<=n;j++)
		b[0][j]='0';
	for(i=0;i<=m;i++)
	{
		cout<<"\n";
		for(j=0;j<=n;j++)
			cout<<b[i][j]<<" ";
	}
	cout<<"\nTHE LONGEST COMMON SUBSEQUENCE IS :";
	print_lcs(b,X,m,n);
}

void print_lcs(char **b,char *X,int m,int n)
{

	if(m==0||n==0)
		return;
	if(b[m][n]=='d')
	{
		print_lcs(b,X,m-1,n-1);
		cout<<X[m-1]<<" ";
	}
	else if(b[m][n]=='u')
		print_lcs(b,X,m-1,n);
	else
		print_lcs(b,X,m,n-1);



}




void main()
{
	clrscr();
	char *X,*Y;
	int m,n;
	m=n=0;
	cout<<"Enter first string :";
	gets(X);
	while(X[m]!='\0')
		m++;
	cout<<"Length of string is :"<<m;
	cout<<"\nEnter second string :";
	gets(Y);
	while(Y[n]!='\0')
		n++;
	cout<<"Length of string is :"<<n;
	lcs(X,Y,m,n);
	getch();
}
