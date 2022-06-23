#ifndef graphUndirectedAdjacencyList
#define graphUndirectedAdjacencyList

#include "./graphAdjacencyList.h"

// insert an undirected edge into the adjacency list
void insertUndirected(AdjList L, Edge E){
	if(MAX_VERTICES > E.vertex > -1 && MAX_VERTICES > E.adj_vertex > -1 && E.vertex != E.adj_vertex){
        insertFirst(&L[E.vertex], E.adj_vertex);
        insertFirst(&L[E.adj_vertex], E.vertex);
    }
}
#endif
