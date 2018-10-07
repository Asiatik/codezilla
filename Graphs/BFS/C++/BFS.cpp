/*
 *	adikul30
 *	Aditya Kulkarni <aditya.kulkarni15@siesgst.ac.in>
 */
#include <bits/stdc++.h>

using namespace std;

#define REP(i, a, b) for(int i = a; i < b; ++i)
#define pb push_back
#define MAX 100

typedef vector<int> vi;

bool visited[MAX];
vi adj[MAX];
int distance[MAX];
queue<int> q;

void bfs(int x){
	visited[x] = true;
	cout << x << endl;
	q.push(x);
	while(!q.empty()){
		int s = q.front();
		q.pop();
		for (auto u : adj[s]){
			if (visited[u]) continue;
			visited[u] = true;
			cout << u << endl;
			q.push(u);
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	int n = 5;
	REP(i,1,n+1)visited[i] = false;
	adj[1].pb(2);
	adj[1].pb(3);
	adj[1].pb(5);
	adj[2].pb(3);
	adj[3].pb(4);
	
	bfs(1);
	return 0;
}