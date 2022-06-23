#ifndef graphAdjacencyList
#define graphAdjacencyList

#include <stdio.h>
#include <stdlib.h>

#define MAX 9999
#define MAX_EDGES 10
#define MAX_VERTICES MAX_EDGES-1

typedef struct {
	int vertex;
    int adj_vertex;
} Edge;

typedef struct {
    Edge edges[MAX_VERTICES];
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
typedef List AdjList[MAX_VERTICES];

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
	
	if(Q->rear != NULL){ Q->rear->link = temp; }
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
 * Adjacency List functions
*/

// initialize the adjacency list	
void initAdjList(AdjList L){
    int x;
    for(x = 0; x < MAX_VERTICES; x++){
        L[x] = NULL;
    }
}

// init array of visited nodes
void initVisited(visited V){
	int u;
	for(u = 0; u < MAX_VERTICES; u++){
		V[u] = 0;
	}
}

// insert node first in list
void insertFirst(List * L, int data){
	List temp = (List) malloc(sizeof(vertex));
	temp->vertex = data;
	temp->link = *L;
	*L = temp;
}

// insert node last in list
void insertLast(List * L, int vertex){
	List * trav, temp;
	
	for(trav = L; *trav != NULL; trav = &(*trav)->link){}
	if(*trav == NULL){
		temp = (List) malloc(sizeof(vertex));
		temp->vertex = vertex;
		temp->link = NULL;
		*trav = temp;
	}
}

// insert node in its sorted position in the list
void insertSorted(List * L, int vertex){
	List * trav, temp = (List) malloc(sizeof(vertex));
	
	for(trav = L; *trav != NULL && vertex < (*trav)->vertex ; trav = &(*trav)->link){}
	temp->vertex = vertex;
	temp->link = *trav;
	*trav = temp;
}

// print the adjacency matrix
void printMatrix(AdjList L){
    int x;
    List trav;
    
    for(x = 0; x < MAX_VERTICES; x++){
    	printf("%d |", x);
    	
   		for(trav = L[x]; trav != NULL; trav = trav->link){
    		printf(" %d", trav->vertex);
		}
		
        printf("\n");
    }
}

// iterative depth-first search traversal of the matrix
void dfsIterative(AdjList L, Stack * S, visited V, int start){
    List trav;

    push(S, start);
    V[start] = 1;
    
    printf("\n%d ", top(*S));
    
    while(S->top > -1){
        for(trav = L[top(*S)]; trav != NULL; trav = trav->link) {
        	if(V[trav->vertex] == 0){
                push(S, trav->vertex);
                V[trav->vertex] = 1;
                printf("%d ", top(*S));
                trav = L[top(*S)];
        	}
		}
        pop(S);
    }
}

// recursive depth-first search traversal of the matrix
void dfsRecursive(AdjList L, visited V, int start){
	if(V[start] == 0){
		List temp;
		V[start] = 1;
		printf("%d ", start);
		
		for(temp = L[start]; temp != NULL; temp = temp->link){
			if(V[temp->vertex] == 0){
				dfsRecursive(L, V, temp->vertex);
			}
		}	
	}
}

// iterative breadth-first search traversal of the matrix
void bfsIterative(AdjList L, Queue * Q, visited V, int start){
    List trav;

    enqueue(Q, start);
	printf("\n");
    
    while(Q->front != NULL){
    	V[front(*Q)] = 1;
    	printf("%d ", front(*Q));
    	
        for(trav = L[front(*Q)]; trav != NULL; trav = trav->link) {
        	if(V[trav->vertex] < 1){
                enqueue(Q, trav->vertex);
                V[trav->vertex] = 2;
        	}
		}
        dequeue(Q);
    }
}
#endif
