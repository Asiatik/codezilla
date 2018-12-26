#include <bits/stdc++.h>
using namespace std;

#define mod 1000000007
#define pb push_back
#define mp make_pair
#define ft first
#define sc second
#define PI 3.14159265358979323
#define debug(x) cout<<"Case "<<x<<": "
#define For(i,n) for(long long i=0;i<n;i++)
#define Frabs(i,a,b) for(long long i = a; i < b; i++)
#define Frabr(i,a,b) for(long long i = a; i >=b; i--)
#define sync ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
typedef long long int           ll;
typedef long double             ld;
typedef unsigned long long int ull;
typedef vector <int>            vi;
typedef vector <ll>            vll;
typedef pair <int, int>        pii;
typedef pair <ll, ll>          pll;
typedef vector < pii >        vpii;
typedef vector < pll >        vpll;
typedef vector <string>         vs;

//Handle:cyber_rajat
class Edge
{
public:
	int source;
	int destination;
	int weight;
};

bool compare(Edge a,Edge b)  //sorts on basis of weight
{
 return a.weight<b.weight;
}

int findParent(int vertix , int*parent)
{
	if(parent[vertix]==vertix)               //if parent[vertix]==vertix means it is parent itself else call further 
		return vertix;
	return findParent(parent[vertix],parent);
}                                              //Union Find Algorithm is involved in it

void Kruskals(Edge*input,int N,int E)
{
 sort(input,input+E,compare);    //sorting the input on basis of weight as we need to start from minimum weight
 Edge*output=new Edge[N-1];     //out MST will contain N-1 edges
 int*parent=new int[N]; 
 for(int i=0;i<N;i++)      
 	parent[i]=i;                //initial parent vertix to be itself

 int count=0;                  //edges should be N-1
 int i=0;                      //starting from input no 0
 while(count!=N-1)
 {
 	int sourceParent=findParent(input[i].source,parent);      //finding Parent of sourse and destination
 	int destParent=findParent(input[i].destination,parent);
 	if(sourceParent!=destParent)                             //If parent of source and destination is same it
 	{                                                        // means already path exists and introducing this
 		output[count]=input[i];                              //edge will cause cyclisation,which should not happen
 		count++;                                             //so leave it and move further if parents are differnt
 		parent[sourceParent]=destParent;                     //then insert them to MST,increse counte of edges inMST
 	}                                                        //and make parent of both sourse and destination same
 	i++;                                                     //by allocating one as parent of the other
 }
 for(int i=0;i<N-1;i++)
 {
 	if(output[i].source<=output[i].destination)              //printing small vertix first
     cout<<output[i].source<<" "<<output[i].destination<<" "<<output[i].weight<<endl;
 	else
 	 cout<<output[i].destination<<" "<<output[i].source<<" "<<output[i].weight<<endl;
 }

}

int main(int argc, char const *argv[])
{
	int N,E;
	cin>>N>>E;
	Edge*input=new Edge[E];
	for(int i=0;i<E;i++)               //inputting source,destination and weight of edge
	{
      cin>>input[i].source;
      cin>>input[i].destination;
      cin>>input[i].weight;
	}

    Kruskals(input,N,E);
	return 0;
}
