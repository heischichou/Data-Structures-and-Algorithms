#ifndef graphUndirectedAdjacencyMatrix
#define graphUndirectedAdjacencyMatrix

#include "./graphAdjacencyMatrix.h"

// insert an undirected edge into the adjacency matrix
void insertUndirected(Matrix M, Edge E){
	if(MAX_VERTICES > E.vertex > -1 && MAX_VERTICES > E.adj_vertex > -1 && E.vertex != E.adj_vertex){
        M[E.vertex][E.adj_vertex] = 1;
        M[E.adj_vertex][E.vertex] = 1;
    }
}

// insert a weighted undirected edge into the adjacency matrix
void insertWeightedUndirected(Matrix M, Edge E){
	if(MAX_VERTICES > E.vertex > -1 && MAX_VERTICES > E.adj_vertex > -1 && E.vertex != E.adj_vertex){
        M[E.vertex][E.adj_vertex] = E.weight;
        M[E.adj_vertex][E.vertex] = E.weight;
    }
}
#endif
