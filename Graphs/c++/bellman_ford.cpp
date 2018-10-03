#include<iostream>
#include<vector>
#include<map>
#include<climits>

using namespace std;

vector<vector<int> > graph;						//  directed graph
map<char,int> s_path;							//  nodes with their distances from source

void initialize(int,char);						//  initialisation of each vertex
void relax(int,int,int);				//  relaxation of each node next to the one passed
void print_path(char);					//  prints the distance of each vertex from source


int main()
{	int n=4;        // number of nodes in graph
	char s='A';     // source node
	bool neg_cycle=false;				//  determine whether negative cycle exists or not
	
    /*	Define graph like below
			A  B  C  D
		A	0  1  3  0
		B	0  0  2  0
		C	0  0  0  4
		D	0  0  0  0  
	*/
	vector<int> x={0, 1, 3, 0};
	graph.push_back(x);
	x = {0, 0, 2, 0};
	graph.push_back(x);
	x = {0, 0, 0, 4};
	graph.push_back(x);
	x = {0, 0, 0, 0};
	graph.push_back(x);

    initialize(n,s);
	for(int i=0;i<n-1;i++)
		for(int j=0;j<n;j++)
			for(int k=0;k<n;k++)
				if(graph[j][k]!=0)
					relax(j,k,graph[j][k]);
                    
	for(int j=0;j<n;j++)
		for(int k=0;k<n;k++)
			if(graph[j][k]!=0)
				if(s_path[(char)('A'+j)]>s_path[(char)('A'+k)]+graph[j][k])
					neg_cycle=true;
	if(neg_cycle==true)
		cout<<"There exists a negative cycle...\nThus Bellman ford can't work here...!";
	else
		print_path(s);
	return 0;
	}

void initialize(int n,char s)
{	//  make every node unvisited & mark its distance infinity
	for(int i=0;i<n;i++)
	{	s_path.insert(pair<char,int>((char)('A'+i),INT_MAX));
		}
	s_path[s]=0;			//  mark distance for source node as 0
	}

void relax(int i,int j,int w)
{	if(s_path[(char)('A'+j)]>s_path[(char)('A'+i)]+w)
		s_path[(char)('A'+j)]=s_path[(char)('A'+i)]+w;
	}

void print_path(char s)
{	for(int i=0;i<s_path.size();i++)
		cout<<"\n"<<(char)('A'+i)<<" : "<<s_path[(char)('A'+i)];
	}
