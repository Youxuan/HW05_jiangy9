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
	for(it = edgeList[u].begin(); it != edgeList[u].end(); it++){         
		NWPair pair = (*it);
		if(pair.first == v)
			pair.second = weight;
	}
    
	for(it = edgeList[v].begin(); it != edgeList[v].end(); it++){         
		NWPair pair = (*it);
		if(pair.first == u)
			pair.second = weight;
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
	int count = 0;
	EList::const_iterator it;          
	for(it = edgeList[u].begin(); it != edgeList[u].end(); it++){         
		NWPair pair = (*it);
		if(pair.second != 0)
			count += 1;
	}
	return count;

}

unsigned ListGraph::size() const{
	return edgeList.size();
}

unsigned ListGraph::numEdges() const{
	return num_edges;
}