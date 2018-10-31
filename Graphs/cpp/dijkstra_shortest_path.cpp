/*
 * dijkstra_shortest_path.cpp
 * 
 * Created On: 2-Oct-182018
 *     Author: hplapi
 */
#include<iostream>
#include<vector>
#include<map>
#include<climits>

using namespace std;

map<char, int> s_path;	
vector<char> unvisited;				//  unvisited nodes in the graph

map<char, int> dijkstra_shortest_path(char, vector<vector<int> >);
void initialize(int,char);			//  initialisation of each vertex
char find_min();				//  find minimum weighted node in unvisited vector
void relax(int,int,int);		//  relaxation of each node next to the one passed
void print_path(char, map<char, int>); // print shortest paths

/* 	utility method for dijkstra's shortest path algortithm
	parameters:
		s: source node for shortest path
		graph: 2d array of weights along where x[i][j] is the weight of edge i->j
			Example graph is like below, with edges named A-E:
				A  B  C  D  E
			A	0  10  0  0  5
			B	0  0  1  0  2  
			C	0  0  0  4  0  
			D	7  0  6  0  0  
			E	0  3  9  2  0  
	returns:
		Returns map mapping minimum weight of each node from starting node 's'
		Example response for above graph:
			A : 0
			B : 10
			C : 11
			D : 15
*/
map<char, int> dijkstra_shortest_path(char s, vector<vector<int> > graph)
{	int n = graph.size();
	initialize(n,s);

	while(unvisited.size()!=0)			//  no unvisited node should be left
	{	char c=find_min();
		for(int i=0;i<n;i++)
			if(graph[c-'A'][i]!=0)
				relax(i,c-'A',graph[c-'A'][i]);
		}
	return s_path;
}

void initialize(int n,char s)
{	//  make every node unvisited & mark its distance infinity
	for(int i=0;i<n;i++)
	{	unvisited.push_back((char)('A'+i));
		s_path.insert(pair<char,int>((char)('A'+i),INT_MAX));
		}
	s_path[s]=0;			//  mark distance for source node as 0
	}

char find_min()
{	/*		c : minimum weighted node in unvisited
			a : weight of node c
			k : its index in the unvisited vector
		*/
	char c=unvisited[0];
	int a=s_path.find(unvisited[0])->second,k=0;
	for(int i=1;i<unvisited.size();i++)
	{	int j=s_path.find(unvisited[i])->second;
		if(j<a)
		{	a=s_path.find(unvisited[i])->second;
			c=unvisited[i];
			k=i;
			}
		}
	unvisited.erase(unvisited.begin()+k);		//  delete visited node
	return c;
	}

void relax(int i,int j,int w)
{	if(s_path[(char)('A'+i)]>s_path[(char)('A'+j)]+w)
		s_path[(char)('A'+i)]=s_path[(char)('A'+j)]+w;
	}


// main function
int main()
{
    int n=5;							// number of nodes in graph
	char s='A';							// source node
	vector<vector<int> > graph;			//  directed graph
	map<char,int> paths;				//  nodes with their distances from source

	/*	Define graph like below
			A  B  C  D  E
		A	0  10  0  0  5
		B	0  0  1  0  2  
		C	0  0  0  4  0  
		D	7  0  6  0  0  
		E	0  3  9  2  0  
	*/
	vector<int> x={0, 10, 0, 0, 5};
	graph.push_back(x);
	x = {0, 0, 1, 0, 2};
	graph.push_back(x);
	x = {0, 0, 0, 4, 0};
	graph.push_back(x);
	x = {7, 0, 6, 0, 0};
	graph.push_back(x);
	x = {0, 3, 9, 2, 0};
	graph.push_back(x);

	paths = dijkstra_shortest_path(s, graph);
	print_path(s, paths);
	return 0;
}

void print_path(char s, map<char, int> s_path)
{	for(int i=0;i<s_path.size();i++)
		cout<<"\n"<<(char)('A'+i)<<" : "<<s_path[(char)('A'+i)];
	}
