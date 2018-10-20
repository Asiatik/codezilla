#ifndef MST_LINKEDGRAPH_H_
#define MST_LINKEDGRAPH_H_

#include <string>
#include "ArrayList.h"
#include "LinkedList.h"
#include "LinkedGraphEdge.h"

class LinkedGraph {
	
private:
	ArrayList<LinkedList<LinkedGraphEdge*>*>* nodes = new ArrayList<LinkedList<LinkedGraphEdge*>*>();
	
public:
	LinkedGraph() = default;
	LinkedGraph(int nodeCount);
	~LinkedGraph() = default;
	
	void addNodes(int count);
	void addEdge(int origin, int destination, int metric);
	void clear();
	std::string toString();
	int totalEdgeMetric();
	bool containsEdge(int from, int to);
	
	LinkedGraph* findMstPrim();
	LinkedGraph* findMstKruskal();
	
};

#endif //MST_LINKEDGRAPH_H_
