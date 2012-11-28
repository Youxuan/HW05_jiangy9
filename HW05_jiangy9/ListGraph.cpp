#include "ListGraph.h"
#include <list>

ListGraph::ListGraph(int numNodes){
	edgeList.resize(numNodes);
	num_edges = 0;
}

ListGraph::~ListGraph(){
}

void ListGraph::addEdge(NodeID u, NodeID v, EdgeWeight weight){
	EList::const_iterator it;
	bool count = false;
	for(it = edgeList[u].begin(); it != edgeList[u].end(); it++){         
		NWPair pair = (*it);
		if(pair.first == v)
			count = true;
	}
	if(count==false){
		NWPair pair (v, weight);
		edgeList[u].push_back(pair);
		num_edges++;
	}
    
	count = false;
	for(it = edgeList[v].begin(); it != edgeList[v].end(); it++){         
		NWPair pair = (*it);
		if(pair.first == u)
			count = true;
	}
	if(count==false){
		NWPair pair (u, weight);
		edgeList[v].push_back(pair);
	}

	
}

EdgeWeight ListGraph::weight(NodeID u, NodeID v) const{
	EList::const_iterator it;         
	for(it = edgeList[u].begin(); it != edgeList[u].end(); it++){
		NWPair pair = (*it);
		if(pair.first == v)
			return pair.second;
	}
	return 0.0;
	
}

std::list<NWPair> ListGraph::getAdj(NodeID u) const{
	return edgeList[u];
}

unsigned ListGraph::degree(NodeID u) const{
	return edgeList[u].size();
}

unsigned ListGraph::size() const{
	return edgeList.size();
}

unsigned ListGraph::numEdges() const{
	return num_edges;
}