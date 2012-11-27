#include "ListGraph.h"
#include <list>

ListGraph::ListGraph(int numNodes){
	//edgeList.resize(numNodes);      Why did you say it is automatically initialized?        How about num_edges?
	EList* list = new EList();
	for(int j=0;j<numNodes;j++)
		(*list).push_back(NWPair(0,0));
	for(int i=0;i<numNodes;i++){
		edgeList[i].assign((*list).begin(), (*list).end());
	}
	num_edges = 0;
}

void ListGraph::addEdge(NodeID u, NodeID v, EdgeWeight weight){
	NWPair pair = edgeList[u].front();
	for(int i=0;i<edgeList.size();i++){
		if(pair.first == v && pair.second == 0)
			pair.second = weight;
		if(pair.first != edgeList[u].back().first)
			std::advance(pair,i+1);
	}

	pair = edgeList[v].front();
	for(int i=0;i<edgeList.size();i++){
		if(pair.first == u && pair.second == 0)
			pair.second = weight;
		if(pair.first != edgeList[v].back().first)
			std::advance(pair,i+1);
	}
	
}

EdgeWeight ListGraph::weight(NodeID u, NodeID v) const{
	double result = 0.0;
	NWPair pair = edgeList[u].front();
	for(int i=0;i<edgeList.size();i++){
		if(pair.first == v)
			result = pair.second;
		else
			std::advance(pair,i+1);
	}
	
	return result;
	/*
	EList::const_iterator it;           // begin() and front() ???
	for(it = edgeList[u].begin(); it != edgeList[u].end; it++){         // how do you do it++? Iterator works as pointer?
		NWPair pair = (*it);
		if(pair.first == v)
			return pair.second;
	}
	return 0.0;
	*/
}

std::list<NWPair> ListGraph::getAdj(NodeID u) const{
	EList* list = new EList();
	if(0 <= u < edgeList.size()){
		NWPair pair = edgeList[u].front();
		for(int i=0;i<edgeList.size();i++){
			if(pair.second != 0)
				(*list).push_back(pair);;
			if(pair.first != edgeList[u].back().first)
				std::advance(pair,i+1);
		}
	}
	return *list;
	//return edgeList[u];              why? But why?
}

unsigned ListGraph::degree(NodeID u) const{
	int count = 0;
	if(0 <= u < edgeList.size()){
		NWPair pair = edgeList[u].front();
		for(int i=0;i<edgeList.size();i++){
			if(pair.second != 0)
					count += 1;
			if(pair.first != edgeList[u].back().first)
				std::advance(pair,i+1);
		}
	}
	return count;

}

unsigned ListGraph::size() const{
	return edgeList.size();
}

unsigned ListGraph::numEdges() const{
	return num_edges;
}