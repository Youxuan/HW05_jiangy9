#include "ListGraph.h"
#include <list>

ListGraph::ListGraph(){
	num_edges = 0;
}

ListGraph::ListGraph(int numNodes){
	EList(numNodes, NWPair(0,0));
	for(int i=0;i<numNodes;i++){
		edgeList[i].assign(EList.begin(), EList.end());
	}
	num_edges = 0;
}

void ListGraph::addEdge(NodeID u, NodeID v, EdgeWeight weight){
	if(0 <= u < edgeList.size() && 0 <= v < edgeList.size() && u!=v && weight > 0){
		NWPair pair = edgeList[u].back();
		for(int i=0;i<edgeList.size();i++){
			if(pair.first == v && pair.second != 0)
				pair.second = weight;
			if(pair != edgeList[u].front())
				std::advance(pair,i+1);
		}
	}
}

EdgeWeight ListGraph::weight(NodeID u, NodeID v) const{
	double result = 0.0;
	if(0 <= u < edgeList.size() && 0 <= v < edgeList.size()){
		NWPair pair = edgeList[u].back();
		for(int i=0;i<edgeList.size();i++){
			if(pair.first == v && pair.second != 0)
				result = pair.second;
			if(pair != edgeList[u].front())
				std::advance(pair,i+1);
		}
	}
	return result;
}

std::list<NWPair> ListGraph::getAdj(NodeID u) const{
	if(0 <= u < edgeList.size()){
		NWPair pair = edgeList[u].back();
		for(int i=0;i<edgeList.size();i++){
			if(pair.second != 0)
				EList.push_back(pair);;
			if(pair != edgeList[u].front())
				std::advance(pair,i+1);
		}
	}
	return EList;
}

unsigned ListGraph::degree(NodeID u) const{
	int count = 0;
	if(0 <= u < edgeList.size()){
		NWPair pair = edgeList[u].back();
		for(int i=0;i<edgeList.size();i++){
			if(pair.second != 0)
					count += 1;
			if(pair != edgeList[u].front())
				std::advance(pair,i+1);
		}
	}
	return count;
}

unsigned ListGraph::size() const{
	return edgeList.size()*edgeList.size();
}

unsigned ListGraph::numEdges() const{
	return num_edges;
}