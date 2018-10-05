#include <iostream>
#include <vector>
#include <algorithm>

/*
Kruskal's algorithm is a minimum-spanning-tree algorithm which finds
an edge of the least possible weight that connects any two trees
in the forest.[1] It is a greedy algorithm in graph theory as it finds a
minimum spanning tree for a connected weighted graph adding increasing cost
arcs at each step.[1] This means it finds a subset of the edges that forms
a tree that includes every vertex, where the total weight of all the edges
in the tree is minimized. If the graph is not connected, then it finds a minimum
spanning forest (a minimum spanning tree for each connected component).
(c) Wikipedia.org

This implementation is using DSU. O = M*log(N);
M - edges, N - nodes.
*/
//FUNCTIONS
int dsu_get(int v);
void dsu_unite(int a, int b);
std::vector<std::pair<int, std::pair<int, int> > > convertMatrixToEdges(int n, std::vector<std::vector<int> > m);
void find_mst(int weight, std::vector<std::pair<int, std::pair<int, int> > > graph);
void print_result(int weight, std::vector<std::pair<int, int> > *mst);
bool compare(std::pair<int, std::pair<int, int> > a,
	std::pair<int, std::pair<int, int> > b);
//Global array for DSU
std::vector<int> dsu;

int main()
{
	int n = 4;
	//We assign dsu array.
	dsu.assign(n, 0);
	for (int i = 0; i < n; ++i)
		dsu[i] = i;

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
	std::vector<std::pair<int, std::pair<int, int> > > new_graph = convertMatrixToEdges(n, graph);
	find_mst(n, new_graph);
	return 0;
}
int dsu_get(int v) {
	return (v == dsu[v]) ? v : (dsu[v] = dsu_get(dsu[v]));
}
void dsu_unite(int a, int b) {
	a = dsu_get(a);
	b = dsu_get(b);
	if (a != b)
		dsu[a] = b;
}
std::vector<std::pair<int, std::pair<int, int> > > convertMatrixToEdges(int n, std::vector<std::vector<int> > m) {
	std::vector<std::pair<int, std::pair<int, int> > > graph;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			if (m[i][j] != 0) {
				graph.push_back({ m[i][j],{ i,j } });
			}
		}
	}
	std::sort(graph.begin(), graph.end(), compare);
	return graph;
}

void find_mst(int n, std::vector<std::pair<int, std::pair<int, int> > > graph) {
	int weight = 0, m = graph.size();
	std::vector<std::pair<int, int> > mst;

	for (int i = 0; i < m; ++i) {
		int a = graph[i].second.first, b = graph[i].second.second, w = graph[i].first;
		if (dsu_get(a) != dsu_get(b)) {
			weight += w;
			mst.push_back(graph[i].second);
			dsu_unite(a, b);
		}
	}
	print_result(weight, &mst);
}

void print_result(int weight, std::vector<std::pair<int, int> >* mst) {
	std::cout << "An MST has weight " << weight << "\n";
	std::cout << "It consists of " << mst->size() << " edges: \n";
	for (int i = 0; i < mst->size(); ++i) {
		std::cout << mst->at(i).first << " " << mst->at(i).second << "\n";
	}
}
bool compare(std::pair<int, std::pair<int, int> > a,
	std::pair<int, std::pair<int, int> > b) {
	return (a.first < b.first);
}
