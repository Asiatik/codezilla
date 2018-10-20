#include <sstream>
#include <limits>
#include "LinkedGraph.h"

LinkedGraph::LinkedGraph(int nodeCount) {
	addNodes(nodeCount);
}

void LinkedGraph::addNodes(int count) {
	for (int i = 0; i < count; i++) {
		nodes->add(new LinkedList<LinkedGraphEdge*>());
	}
}

void LinkedGraph::addEdge(int origin, int destination, int metric) {
	if (origin < nodes->getSize() && destination < nodes->getSize()
	    && origin >= 0 && destination >= 0 && metric > 0) {
		LinkedGraphEdge* edge = new LinkedGraphEdge(origin, destination, metric);
		nodes->get(origin)->add(edge);
		nodes->get(destination)->add(edge);
	}
}

void LinkedGraph::clear() {
	for (int i = 0; i < nodes->getSize(); i++) {
		delete nodes->get(i);
	}
	delete nodes;
	nodes = new ArrayList<LinkedList<LinkedGraphEdge*>*>();
}

std::string LinkedGraph::toString() {
	std::stringstream stringStream;
	for (int i = 0; i < nodes->getSize(); i++) {
		stringStream << std::to_string(i) << " : ";
		for (int k = 0; k < nodes->get(i)->getSize(); k++) {
			if (k > 0) {
				stringStream << ", ";
			}
			stringStream << "{";
			stringStream << std::to_string(nodes->get(i)->get(k)->originNode);
			stringStream << "->";
			stringStream << std::to_string(nodes->get(i)->get(k)->destinationNode);
			stringStream << ", ";
			stringStream << std::to_string(nodes->get(i)->get(k)->metric);
			stringStream << "}";
		}
		stringStream << "\n";
	}
	stringStream.flush();
	return stringStream.str();
}

int LinkedGraph::totalEdgeMetric() {
	int result = 0;
	for (int i = 0; i < nodes->getSize(); i++) {
		for (int k = 0; k < nodes->get(i)->getSize(); k++) {
			result += nodes->get(i)->get(k)->metric;
		}
	}
	result >>= 1;
	return result;
}

bool LinkedGraph::containsEdge(int from, int to) {
	if (from < nodes->getSize() && to < nodes->getSize()
			&& from >= 0 && to >= 0
			&& from != to) {
		LinkedList<LinkedGraphEdge*>* adjacencyList = nodes->get(from);
		for (int i = 0; i < adjacencyList->getSize(); i++) {
			if (adjacencyList->get(i)->originNode == to
					|| adjacencyList->get(i)->destinationNode == to) {
				return true;
			}
		}
	}
	return false;
}

LinkedGraph* LinkedGraph::findMstPrim() {
	LinkedGraph* result = new LinkedGraph(nodes->getSize());
	bool nodeIncluded[nodes->getSize()] = {}; // { false ... }
	
	int cheapestConnectionMetric[nodes->getSize()];
	std::fill_n(cheapestConnectionMetric, nodes->getSize(), std::numeric_limits<int>::max());
	LinkedGraphEdge* cheapestConnectionEdge[nodes->getSize()];
	std::fill_n(cheapestConnectionEdge, nodes->getSize(), nullptr);
	
	int currentNode = 0;
	for (int nodesRemaining = nodes->getSize(); nodesRemaining > 0 && currentNode != -1; nodesRemaining--) {
		nodeIncluded[currentNode] = true;
		if (cheapestConnectionEdge[currentNode] != nullptr) {
			LinkedGraphEdge* edge = cheapestConnectionEdge[currentNode];
			result->addEdge(edge->originNode, edge->destinationNode, edge->metric);
		}
		
		for (int i = 0; i < nodes->get(currentNode)->getSize(); i++) {
			LinkedGraphEdge* edge = nodes->get(currentNode)->get(i);
			if (edge->originNode == currentNode
					&& !nodeIncluded[edge->destinationNode]
					&& edge->metric < cheapestConnectionMetric[edge->destinationNode]) {
				cheapestConnectionMetric[edge->destinationNode] = edge->metric;
				cheapestConnectionEdge[edge->destinationNode] = edge;
			}
			else if (edge->destinationNode == currentNode
					&& !nodeIncluded[edge->originNode]
					&& edge->metric < cheapestConnectionMetric[edge->originNode]) {
				cheapestConnectionMetric[edge->originNode] = edge->metric;
				cheapestConnectionEdge[edge->originNode] = edge;
			}
		}
		
		int lowestMetric = std::numeric_limits<int>::max();
		int lowestMetricNode = -1;
		for (int i = 0; i < nodes->getSize(); i++) {
			if (!nodeIncluded[i] && cheapestConnectionMetric[i] < lowestMetric) {
				lowestMetric = cheapestConnectionMetric[i];
				lowestMetricNode = i;
			}
		}
		currentNode = lowestMetricNode;
	}
	return result;
}

LinkedGraph* LinkedGraph::findMstKruskal() {
	LinkedGraph* result = new LinkedGraph(nodes->getSize());
	int treeId[nodes->getSize()];
	for (int i = 0; i < nodes->getSize(); i++) {
		treeId[i] = i;
	}
	int trees = nodes->getSize();
	LinkedList<LinkedGraphEdge*> remainingEdges = LinkedList<LinkedGraphEdge*>();
	for (int i = 0; i < nodes->getSize(); i++) {
		for (int k = 0; k < nodes->get(i)->getSize(); k++) {
			if (!remainingEdges.contains(nodes->get(i)->get(k))) {
				remainingEdges.add(nodes->get(i)->get(k));
			}
		}
	}
	
	while (trees > 1 && remainingEdges.getSize() > 0) {
		int lowestMetric = std::numeric_limits<int>::max();
		LinkedGraphEdge* lowestMetricEdge = nullptr;
		
		for (int i = 0; i < remainingEdges.getSize(); i++) {
			LinkedGraphEdge* edge = remainingEdges.get(i);
			if (edge->metric < lowestMetric) {
				lowestMetric = edge->metric;
				lowestMetricEdge = edge;
			}
		}
		
		if (lowestMetricEdge != nullptr) {
			remainingEdges.remove(lowestMetricEdge);
			if (treeId[lowestMetricEdge->originNode] != treeId[lowestMetricEdge->destinationNode]) {
				result->addEdge(lowestMetricEdge->originNode, lowestMetricEdge->destinationNode, lowestMetricEdge->metric);
				int mergedTreeId = treeId[lowestMetricEdge->destinationNode];
				for (int i = 0; i < nodes->getSize(); i++) {
					if (treeId[i] == mergedTreeId) {
						treeId[i] = treeId[lowestMetricEdge->originNode];
					}
				}
				--trees;
			}
		}
	}
	return result;
}
