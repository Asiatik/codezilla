#include<iostream>
#include<algorithm>
#include<vector>
#include<utility>
/*
	Prim's algorithm is a greedy algorithm that finds a minimum spanning tree for a 
	weighted undirected graph. This means it finds a subset of the edges that forms a 
	tree that includes every vertex, where the total weight of all the edges in the tree 
	is minimized. The algorithm operates by building this tree one vertex at a time, from 
	an arbitrary starting vertex, at each step adding the cheapest possible connection 
	from the tree to another vertex.
											(c) Wikipedia.org
*/
void find_tree(int n, std::vector<std::vector<int> >);
void print_result(int weight, std::vector<std::pair<int, int> >*);
int INF = 1e9;

int main() {
	int n = 4;
	std::vector<std::vector<int> > graph;
	/*	Define graph like below
	A  B  C  D
	A	0  1  3  0
	B	0  0  2  0
	C	0  0  0  4
	D	0  0  0  0
	*/
	graph.push_back({ 0,1,3,0 });
	graph.push_back({ 0,0,2,0 });
	graph.push_back({ 0,0,0,4 });
	graph.push_back({ 0,0,0,0 });
	//We need to set all nodes that doesn't have edges to INF
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			if (i != j && graph[i][j] == 0)
				graph[i][j] = INF;
		}
	}
	find_tree(n, graph);
}

void find_tree(int n, std::vector<std::vector<int> > graph) {
	//Vector used shows did we used a node in a tree
	std::vector<bool> used(n);
	//min_edge is a smallest edge that node [i] has
	std::vector<int> min_edge(n, INF);
	//fin_edge is which other node this edge connects [i] with
	std::vector<int> fin_edge(n, -1);
	//container of the edges in MST
	std::vector<std::pair<int, int> > mst_edges;

	min_edge[0] = 0;
	int weight = 0;
	for (int i = 0; i < n; ++i) {
		//We find a node with the smallest-weight edge
		int v = -1;
		for (int j = 0; j < n; ++j) {
			if (!used[j] && (v == -1 || min_edge[j] < min_edge[i])) {
				v = j;
			}
		}
		if (min_edge[v] == INF) {
			std::cout << "There is not MST!";
			return;
			//There is no MST;
		}
		used[v] = true; //We add first node and other nodes following to algorithm
		if (fin_edge[v] != -1) {
			weight += min_edge[v];
			mst_edges.push_back({ v,fin_edge[v] });
		}
		for (int to = 0; to < n; ++to) { //We find the minimum edges with this node
			if (graph[v][to] < min_edge[to]) {
				min_edge[to] = graph[v][to];
				fin_edge[to] = v;
			}
		}
	}
	print_result(weight, &mst_edges);
}
void print_result(int weight, std::vector<std::pair<int, int> >* mst) {
	std::cout << "An MST has weight " << weight << "\n";
	std::cout << "It consists of " << mst->size() << " edges: \n";
	for (int i = 0; i < mst->size(); ++i) {
		std::cout << mst->at(i).first << " " << mst->at(i).second << "\n";
	}
}
