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

void dfs(int s){
	if (visited[s]) return;
	visited[s] = true;
	cout << s << endl;
	for (auto u : adj[s]){
		dfs(u);
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	int n = 5;
	REP(i,1,n+1) visited[i] = false;
	adj[1].pb(2);
	adj[1].pb(3);
	adj[1].pb(5);
	adj[2].pb(3);
	adj[3].pb(4);
	dfs(1);
	
	return 0;
}