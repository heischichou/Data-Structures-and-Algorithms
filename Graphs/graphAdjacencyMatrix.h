#ifndef graphAdjacencyMatrix
#define graphAdjacencyMatrix

#include <stdio.h>
#include <stdlib.h>

#define MAX 9999
#define MAX_EDGES 10
#define MAX_VERTICES MAX_EDGES-1

typedef struct {
	int vertex;
    int adj_vertex;
    int weight;
} Edge;

typedef struct {
    Edge edges[MAX_EDGES];
    int edge_count;
} EdgeList;

typedef struct {
	int data[MAX_VERTICES];
	int top;
} Stack;

typedef struct node {
	int vertex;
	struct node * link;
} vertex, *List;

typedef struct {
	List front;
	List rear;
} Queue;

typedef int visited[MAX_VERTICES];
typedef int Matrix[MAX_VERTICES][MAX_VERTICES];

// return least between two values helper
int min(int a, int b){
	return (a < b) ? a : b;
}

// print an array helper
void print(int A[]){
	int x;
	for(x = 0; x < MAX_VERTICES; x++){
		printf("%-5d ", A[x]);
	}
}

/*
 * Stack functions
*/

// initialize stack
void initStack(Stack * S){
	S->top = -1;
}

// return the element at the top of the stack
int top(Stack S){
	return S.data[S.top];
}

// insert element to the top of the stack
void push(Stack * S, int data){
	if(S->top < MAX_VERTICES){
		S->data[++S->top] = data;
	}
}

// delete the top element from the stack
void pop(Stack * S){
	if(S->top > -1){
		S->data[S->top--] = -1;
	}
}

/*
 * Queue functions
*/

// initialize the queue
void initQueue(Queue * Q){
	Q->rear = Q->front = NULL;
}

// return the element at the front of the queue
int front(Queue Q){
	return Q.front->vertex;
}

// return the element at the rear of the queue
int rear(Queue Q){
	return Q.rear->vertex;
}

// enqueue a new element
void enqueue(Queue * Q, int data){
	List temp = (List) malloc(sizeof(vertex));
	temp->vertex = data;
	temp->link = NULL;
	
	if(Q->rear != NULL) { Q->rear->link = temp; }
	Q->rear = temp;

	if(Q->front == NULL){
		Q->front = temp;
	}
}

// dequeue element at the front of the queue
void dequeue(Queue * Q){
	if(Q->front != NULL){
		List temp = Q->front;
		Q->front = temp->link;
		free(temp);
		
		if(Q->front == NULL){
			Q->rear = Q->front;
		}
	}
}

/*
 * Adjacency Matrix functions
*/

// initialize the adjacency matrix	
void initMatrix(Matrix M){
    int x, y;
    for(x = 0; x < MAX_VERTICES; x++){
        for(y = 0; y < MAX_VERTICES; y++){
            M[x][y] = 0;
            // M[x][y] = MAX;
        }
    }
}

// init array of visited nodes
void initVisited(visited V){
	int u;
	for(u = 0; u < MAX_VERTICES; u++){
		V[u] = 0;
	}
}

// print the adjacency matrix
void printMatrix(Matrix M){
    int x, y;
    printf("%-5s", "");
    for(x = 0; x < MAX_VERTICES; x++){
    	printf("%-5d", x);   
    }
    printf("\n");
    for(x = 0; x < MAX_VERTICES; x++){
    	printf("%-5d", x);
        for(y = 0; y < MAX_VERTICES; y++){
            printf("%-5d", M[x][y]);
        }
        printf("\n");
    }
}

// iterative depth-first search traversal of the matrix
void dfsIterative(Matrix M, Stack * S, visited V, int start){
    int y;

    push(S, start);
    V[start] = 1;
    
    printf("\n%d ", top(*S));
    
    while(S->top > -1){
        for(y = 0; y < MAX_VERTICES; y++){
            if(V[y] == 0 && M[top(*S)][y] == 1){
                push(S, y);
                V[y] = 1;
                printf("%d ", top(*S));
                y = 0;
            }
        }
        pop(S);
    }
}

// recursive depth-first search traversal of the matrix
void dfsRecursive(Matrix M, visited V, int start){
	if(V[start] == 0){
		int u;
		V[start] = 1;
		printf("%d ", start);
		
		for(u = 0; u < MAX_VERTICES; u++){
			if(V[u] == 0 && M[u][start] == 1){
				dfsRecursive(M, V, u);
			}
		}	
	}
}

// iterative breadth-first search traversal of the matrix
void bfsIterative(Matrix M, Queue * Q, visited V, int start){
    int y;

	printf("\n");
    enqueue(Q, start);
    while(Q->front != NULL){
    	V[front(*Q)] = 1;
    	printf("%d ", front(*Q));
    	
        for(y = 0; y < MAX_VERTICES; y++){
        	if(V[y] < 1 && M[y][front(*Q)] == 1){
        		enqueue(Q, y);
        		V[y] = 2;
			}
        }
        dequeue(Q);
    }
}

// Dijkstra's Algorithm
int * Dijkstra(Matrix M, visited S, int start){
	int * D, min_index, x, w, v;
	S[start] = 1;
	
	D = (int*) malloc(sizeof(int) * MAX_VERTICES);
	
	// initialize D
	for(x = 0; x < MAX_VERTICES; x++){
		D[x] = M[start][x];
	}
	
	for(x = (start + 1) % MAX_VERTICES; x != start; x = (x + 1) % MAX_VERTICES){
		for(w = (start + 1) % MAX_VERTICES, min_index = x; w != start; w = (w + 1) % MAX_VERTICES){
			if(S[w] == 0 && D[min_index] > D[w]){
				min_index = w;
			}
		}
		
		S[min_index] = 1;
		
		for(v = (start + 1) % MAX_VERTICES; v != start; v = (v + 1) % MAX_VERTICES){
			if(S[v] == 0){
				D[v] = min(D[v], D[min_index] + M[min_index][v]);
			}
		}
	}
	
	return D;
}

// Floyd's Algorithm
void Floyds(Matrix M, Matrix C){
	int x, y, z;
	
	// duplicate the matrix
	for(x = 0; x < MAX_VERTICES; x++){
		for(y = (x + 1) % MAX_VERTICES; y != x; y = (y + 1) % MAX_VERTICES){
			C[x][y] = M[x][y];
		}
	}
	
	// set the intersections to 0
	for(x = 0; x < MAX_VERTICES; x++){
		C[x][x] = 0;
	}
	
	// shortest path matrix
	for(z = 0; z < MAX_VERTICES; z++){
		for(x = (z + 1) % MAX_VERTICES; x != z; x = (x + 1) % MAX_VERTICES){
			for(y = 0; y < MAX_VERTICES; y++){
				if(C[x][y] > C[x][z] + C[z][y]){
					C[x][y] = C[x][z] + C[z][y];
				}
			}
		}
	}
}
#endif
