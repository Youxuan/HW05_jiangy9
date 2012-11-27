#include "MatrixGraph.h"
#include <list>

MatrixGraph::MatrixGraph(unsigned num_nodes){
	M.resize(num_nodes);
	for(int i=0; i < num_nodes; i++){ 
		M[i].resize(num_nodes);
		for(int j=0; j < num_nodes; j++){
			M[i][j] = 0;
			M[j][i] = 0;
		}
	}
	num_edges = 0;
}

MatrixGraph::~MatrixGraph(){
}

void MatrixGraph::addEdge(NodeID u, NodeID v, EdgeWeight weight){
		M[u][v] = weight;
		M[v][u] = weight;
		num_edges++;
}

EdgeWeight MatrixGraph::weight(NodeID u, NodeID v) const{
		return M[u][v];
}

std::list<NWPair> MatrixGraph::getAdj(NodeID u) const{
	EList* list = new EList();
	NWPair pair;
	for(int i = 0; i < M[u].size(); i++){ 
		if(M[u][i]!=0){
			pair.first = i;
			pair.second = M[u][i];
			(*list).push_back(pair);
		}
	}
	return *list;
}

unsigned MatrixGraph::degree(NodeID u) const{
	int count = 0;
	for(int i=0; i < M[u].size(); i++){
		if(M[u][i]!=0)
			count += 1;
	}
	
	return count;
}

unsigned MatrixGraph::size() const{
	return M.size();
}

unsigned MatrixGraph::numEdges() const{
	return num_edges;
}

