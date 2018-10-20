#ifndef MST_LINKEDGRAPHEDGE_H_
#define MST_LINKEDGRAPHEDGE_H_

class LinkedGraphEdge {

public:
	int originNode;
	int destinationNode;
	int metric;
	
	LinkedGraphEdge() = default;
	LinkedGraphEdge(int origin, int destination, int metric);
	~LinkedGraphEdge() = default;
	
};

#endif //MST_LINKEDGRAPHEDGE_H_
