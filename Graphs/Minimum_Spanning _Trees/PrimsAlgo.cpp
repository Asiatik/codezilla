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
int findMinVerix(int*weights,bool*visited,int N)
{
 int minVertix=-1;
 for(int i=0;i<N;i++)
 {
 	if(!visited[i] && (minVertix==-1 || weights[i]<weights[minVertix]))
 		minVertix=i;
 }
 return minVertix;
}

void Prims(int**Edges,int N)
{
   int*parents=new int[N];
   int*weights=new int[N];
   bool*visited=new bool[N];
   for(int i=0;i<N;i++)
   {
   	visited[i]=false;     //initialising each vertix with INT_MAAX & as not visited
   	weights[i]=INT_MAX;
   }
   parents[0]=-1;
   weights[0]=0;
   for(int i=0;i<N;i++)                //Going to all N vertices 
   {
   	// Find Min Vertex
   	int minVertix=findMinVerix(weights,visited,N);   //finding minimum vetix from the unvisited vertix
   	visited[minVertix]=true;
   	// Explore un visted neighbours
   	for(int j=0;j<N;j++)
   	{
   		if(Edges[minVertix][j]!=0 && !visited[j])     //if there is edge and is not visited
   		{
   			if(Edges[minVertix][j]<weights[j]){       //if weight of edge is better than the weight of the vertix 
   				weights[j]=Edges[minVertix][j];       //then update else not , if we update then in parent of that 
   				parents[j]=minVertix;                 //neighbour vertix as minVertix
   			}
   		}
   	}
   }
   for(int i=1;i<N;i++)                                   //Then our MST->
   {                                                      //index parent
   	if(parents[i]<=i)                                     // 0      -1
   		cout<<parents[i]<<" "<<i<<" "<<weights[i]<<endl;  // 1       -
   	else                                                  // 2       -
   		cout<<i<<" "<<parents[i]<<" "<<weights[i]<<endl;  // n-1     -
   }                                                      // print from 1 to n-1
}

int main(int argc, char const *argv[])
{
	int N,E,a,b,w;
	cin>>N>>E;
	int**Edges=new int*[N];
	for(int i=0;i<N;i++){
	Edges[i]=new int[N];
	for(int j=0;j<N;j++)
		Edges[i][j]=0;
    }
	for(int i=0;i<E;i++)
	{
     cin>>a>>b>>w;
     Edges[a][b]=w;
     Edges[b][a]=w;
	}
	Prims(Edges,N);
	return 0;
}
