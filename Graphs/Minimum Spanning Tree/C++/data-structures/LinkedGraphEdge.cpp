#include "LinkedGraphEdge.h"

LinkedGraphEdge::LinkedGraphEdge(int origin, int destination, int metric) {
	originNode = origin;
	destinationNode = destination;
	this->metric = metric;
}
