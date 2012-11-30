#include "GraphAlgs.h"

std::pair<std::vector<NodeID>, EdgeWeight> TSP(Graph* G){
	int* nodeID = new int[G->size()];
	for(int i=0; i<G->size(); i++){
		nodeID[i] = i;                   
	}

	double shortest = 0.0;
	std::vector<NodeID> result;
	
	for(int i=0; i<G->size(); i++){
		if(i!=G->size()-1)
			shortest += G->weight(nodeID[i],nodeID[i+1]);
		else
			shortest += G->weight(nodeID[i],nodeID[0]);
		result.push_back(nodeID[i]);
	}

	std::pair<std::vector<NodeID>, EdgeWeight> finalPair;
	(finalPair).first = result;
	(finalPair).second = shortest;

	tour(nodeID, G->size(), 0, G, &finalPair);
	return finalPair;
}
                                // if it is one
void tour(int* nodeID, int n, int start, Graph* G, std::pair<std::vector<NodeID>, EdgeWeight>* finalPair){    
	if(n-start==1){                     
		std::pair<std::vector<NodeID>, EdgeWeight> currentPair;
		for(int i=0; i<n; i++){
			if(i!=n){
				(currentPair).second += G->weight(nodeID[i],nodeID[i+1]);
				if((currentPair).second > (*finalPair).second)
					return;
			}
			else{
				(currentPair).second += G->weight(nodeID[i],nodeID[0]);
				(currentPair).first.push_back(nodeID[i]);
			}
		}
		*finalPair = currentPair;
		return;
	}
	else{
		for(int i=start; i<n; i++){
			swap(nodeID,start,i);
			tour(nodeID,n,start+1,G,finalPair);	
			swap(nodeID,start,i);
		}
	}
}

void swap(int* nodeID, int i, int j){
	int temp = nodeID[i];
	nodeID[i] = nodeID[j];
	nodeID[j] = temp;
}