// 1-Make key,parent and MST to track the vertex included in MST instalize all of them
//-2-Make min-priority queue and push source in it
//3-while(!pq.empty()) extract min and for every adjacent vertex u find it its key is less than w(u,v)
//4- if true then(a) push the vertex in queue (b)make parent of u --v and (c)update key of u
#include<bits/stdc++.h> 
using namespace std; 
# define INF 0x3f3f3f3f 

typedef pair<int, int> iPair; 
class Graph 
{ 
    int V; // No. of vertices 
    list< pair<int, int> > *adj; 

public: 
    Graph(int V);
    void addEdge(int u, int v, int w); 
    void primMST(int s); 
}; 
Graph::Graph(int V) 
{ 
    this->V = V; 
    adj = new list<iPair> [V]; 
} 

void Graph::addEdge(int u, int v, int w) 
{ 
    adj[u].push_back(make_pair(v, w)); 
    adj[v].push_back(make_pair(u, w)); 
} 

// Prints shortest paths from src to all other vertices 
void Graph::primMST(int s) 
{ 
    priority_queue< iPair, vector <iPair> , greater<iPair> > pq; 

    int src = s;
    vector<int> key(V, INF); 

    vector<int> parent(V, -1); 
    vector<bool> inMST(V, false); 
    int sum=0; 
    pq.push(make_pair(0, src)); 
    key[src] = 0; 
    while (!pq.empty()) 
    { 
        int u = pq.top().second; 
        pq.pop(); 
        inMST[u] = true; 

        // 'i' is used to get all adjacent vertices of a vertex 
        list< pair<int, int> >::iterator i; 
        for (i = adj[u].begin(); i != adj[u].end(); ++i) 
        { 
            // Get vertex label and weight of current adjacent 
            // of u. 
            int v = (*i).first; 
            int weight = (*i).second; 

            // If v is not in MST and weight of (u,v) is smaller 
            // than current key of v 
            if (inMST[v] == false && key[v] > weight) 
            { 
                // Updating key of v 
                key[v] = weight; 
                pq.push(make_pair(key[v], v)); 
                parent[v] = u; 
            } 
        } 
    } 

         
         for (int i = 0; i < V; ++i)  sum=sum+key[i];
         printf("%d\n",sum);

} 

// Driver program to test methods of graph class 
int main()
{
    int n,s,m,src,dst,w;
    cin>>n>>m;
    Graph g(n);
    for (int i = 0; i < m; ++i)
    {
        cin>>src>>dst>>w;
        g.addEdge(src-1,dst-1,w);
    }
    cin>>s;
    g.primMST(s-1);
    return 0;
}