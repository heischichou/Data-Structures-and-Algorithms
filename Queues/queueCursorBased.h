#ifndef queueCursorBased
#define queueCursorBased

#include <stdio.h>
#include <stdlib.h>

#define SIZE 10

typedef struct {
	int data;
	int link;
} node;

typedef struct {
	node nodes[SIZE];
	int avail;
	int front;
	int rear;
} Queue;

// initialize the queue
void initQueue(Queue * Q){
	int x;
	for(x = 0; x < SIZE - 1; x++){
		Q->nodes[x].link = x + 1;
	}
	
	Q->avail = 0;
	Q->nodes[x].link = Q->rear = Q->front = -1;
}

// return the element at the front of the queue
int front(Queue Q){
	return (Q.front != - 1) ? Q.nodes[Q.front].data : -1;
}

// return the element at the front of the queue
int rear(Queue Q){
	return (Q.rear != - 1) ? Q.nodes[Q.rear].data : -1;
}

// allocate space for the virtual heap
int alloc(Queue * Q){
	int avail = Q->avail;
	
	if(avail != -1){
		Q->avail = Q->nodes[avail].link;
	}
	
	return avail;
}

// deallocate space from the virtual heap
void free(Queue * Q, int index){
	if(index > -1 && index < SIZE){
        Q->nodes[index].link = Q->avail;
        Q->avail = index;
    }
}

// enqueue a new element
void enqueue(Queue * Q, int data){
	int temp = alloc(Q);
	
	if(temp != -1){
        Q->nodes[temp].data = data;
        Q->nodes[temp].link = -1;
        
        (Q->rear == -1) ? Q->front = temp : Q->nodes[Q->rear].link = temp;
        Q->rear = temp;
    }
}

// dequeue element at the front of the queue
void dequeue(Queue * Q){	
	int temp = Q->front;
	
	if(temp != -1){
        Q->front = Q->nodes[temp].link;
        free(Q, temp);
        
        if(Q->front == -1){
            Q->rear = -1;
        }
    }
}
#endif
