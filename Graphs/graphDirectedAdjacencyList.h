#ifndef graphDirectedAdjacencyList
#define graphDirectedAdjacencyList

#include "./graphAdjacencyList.h"

// insert a directed edge into the adjacency list
void insertDirected(AdjList L, Edge E){
	if(MAX_VERTICES > E.vertex > -1 && MAX_VERTICES > E.adj_vertex > -1 && E.vertex != E.adj_vertex){
        insertFirst(&L[E.vertex], E.adj_vertex);
    }
}
#endif
