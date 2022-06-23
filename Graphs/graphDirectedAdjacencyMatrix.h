#ifndef graphDirectedAdjacencyMatrix
#define graphDirectedAdjacencyMatrix

#include "./graphAdjacencyMatrix.h"

// insert a directed edge into the adjacency matrix
void insertDirected(Matrix M, Edge E){
	if(MAX_VERTICES > E.vertex > -1 && MAX_VERTICES > E.adj_vertex > -1 && E.vertex != E.adj_vertex){
        M[E.vertex][E.adj_vertex] = 1;
    }
}

// insert a directed edge into the adjacency matrix
void insertWeightedDirected(Matrix M, Edge E){
	if(MAX_VERTICES > E.vertex > -1 && MAX_VERTICES > E.adj_vertex > -1 && E.vertex != E.adj_vertex){
        M[E.vertex][E.adj_vertex] = E.weight;
    }
}
#endif
