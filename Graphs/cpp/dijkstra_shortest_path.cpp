
#include<iostream.h>
#include<conio.h>
#define max 10

class dijik
{
	public:
		int adj[max][max];
		char Q[max];
		int s,d;
		int key[max];
		int size;
		int *parent;
		int p;
		dijik();
		void input();
		void di();
		void display();
		void call(int);
		int minkey(int);
};

dijik :: dijik()
{
	size=0;
	for(int i=0;i<max;i++)
	{
		Q[i]='F';
		for(int j=0;j<max;j++)
		adj[i][j]=0;
	}
}

void dijik :: input()
{

	cout<<"\nEnter no of vertices  ";
	cin>>size;
	cout<<"\nEnter values of adjacency matrix : \n";


	for(int l=0;l<size;l++)
	{
		for(int m=0;m<size;m++)
		{
			cin>>adj[l][m];
		}
	}

	cout<<"\nMATRIX REPRESENTATION:\n";
	for(int a=0;a<size;a++)
	{
		for(int b=0;b<size;b++)
		{
			cout<<adj[a][b]<<" ";
		}
		cout<<endl;
	}

	cout<<"\nEnter the starting vertex: ";
	cin>>s;
	cout<<"\nEnter the destination vertex: ";
	cin>>d;

	parent=new int[size];


}


void dijik :: di()
{
	int u;

	for(int i=0;i<size;i++)
	{
		key[i]=1000;
		Q[i]='F';
		parent[i]=-1;
	}
	key[s]=0;

//for( i=0;i<size;i++)
  //	cout<<"\nKEY: "<<key[i]<<endl;
	for(int j=s;j<size;j++)
	{
		u=minkey(size);
		cout<<"\nMinkey: "<<u;
		Q[u]='T';
		for(int v=0;v<size;v++)
		{
			if(adj[u][v]!=0&&Q[v]=='F'&&(key[u]+adj[u][v])<key[v])
			{
				parent[v]=u;
				key[v]=adj[u][v]+key[u];
			}
		}
		j++;
	}
	cout<<"\nSpanned path in graph :\n";

	cout<<"CHILD"<<" "<<"PARENT"<<" "<<"WEIGHT"<<endl;
	for(int l=0;l<size;l++)
	{
		cout<<"("<<l<<")--->("<<parent[l]<<")weight: ("<<key[l]<<")"<<endl;
	}
}

int dijik :: minkey(int sz)
{

	int v=0;
	int min_index=0;
	int min=1000;
	for(v=0;v<sz;v++)
	{
		if(Q[v]=='F'&&key[v]<min)
		{
			//cout<<"\nv: "<<v<<"\n";
			min=key[v];
			min_index=v;
		}
	}
	return min_index;
}


void dijik :: display()
{
	cout<<"\nPath is : ";
	p=d;
	call(p);
	cout<<"\b\b";
	cout<<endl;
}

void dijik :: call(int a)
{
	if(parent[a]!=-1)
	{
		call(parent[a]);
	}
	cout<<a<<"->";

}
int main()
{
	clrscr();

	dijik d;
	d.input();
	d.di();
	d.display();
	getch();
	return 0;
}
