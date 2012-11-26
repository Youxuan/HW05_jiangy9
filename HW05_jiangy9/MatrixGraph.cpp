#include "MatrixGraph.h"
#include <list>

MatrixGraph::MatrixGraph(){
	M[0][0] = 0;
	num_edges = 0;
}

MatrixGraph::MatrixGraph(unsigned num_nodes){
	for(int i=0; i < num_nodes; i++){
		for(int j=0; j < num_nodes; j++)
			M[i][j] = 0;
	}
	num_edges = 0;
}

void MatrixGraph::addEdge(NodeID u, NodeID v, EdgeWeight weight){
	if(0 <= u < M.size() && 0 <= v < M.size() && u!=v && M[u][v]==0 && weight > 0){
		M[u][v] = weight;
		num_edges++;
	}
}

EdgeWeight MatrixGraph::weight(NodeID u, NodeID v) const{
	if(0 <= u < M.size() && 0 <= v < M.size())
		return M[u][v];
}

std::list<NWPair> MatrixGraph::getAdj(NodeID u) const{
	if(0 <= u < M.size()){
		for(int i = 0; i < M[u].size(); i++){
			if(M[u][i]!=0){
				EList.push_back(NWPair(i, M[u][i]));
			}
		}
	}
	return EList;
}

unsigned MatrixGraph::degree(NodeID u) const{
	int count = 0;
	if(0 <= u < M.size()){
		for(int i=0; i < M[u].size(); i++){
			if(M[u][i]!=0)
				count += 1;
		}
	}
	return count;
}

unsigned MatrixGraph::size() const{
	return M.size()*M.size();
}

unsigned MatrixGraph::numEdges() const{
	return num_edges;
}

