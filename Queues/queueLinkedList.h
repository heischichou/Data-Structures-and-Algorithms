#ifndef queueLinkedList
#define queueLinkedList

#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int elem;
    struct node * next;
} node;

typedef struct {
	node * front;
	node * rear;
} Queue;

typedef enum {TRUE, FALSE} boolean;

// initialize the queue
void initialize(Queue * Q){
	Q->front = Q->rear = NULL;
}

// return the element at the front of the queue
int front(Queue Q){
	return Q.front->elem;
}

// return the element at the rear of the queue
int rear(Queue Q){
	return Q.rear->elem;
}

// check if queue is empty
int isEmpty(Queue Q){
	return (Q.front == NULL) ? 1 : 0;
}

// enqueue an element
void enqueue(Queue * Q, int data){
	node * temp = (node*) malloc(sizeof(node));
	temp->data = data;
	temp->link = NULL;
	
	if(Q->rear != NULL) { Q->rear->link = temp; }
	Q->rear = temp;
	
	if(isEmpty(*Q) == 0){
		Q->front = temp;
	}
}

// dequeue element at the front of the queue
void dequeue(Queue * Q){
	if(isEmpty(*Q) == 0){
		node * temp = Q->front;
		Q->front = temp->link;
		free(temp);
		
		if(isEmpty(*Q)){
			Q->rear = Q->front;
		}
	}
}
#endif
