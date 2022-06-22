#ifndef queueArray
#define queuearray

#include <stdio.h>

#define SIZE 10

typedef struct {
    int elem[SIZE];
    int front;
    int rear;
} Queue;

typedef enum {TRUE, FALSE} boolean;

// initialize the queue
void initQueue(int front, Queue * Q){
    if(front <= SIZE){
        Q->front = front % SIZE;

        if(front == 0){
            Q->rear = SIZE - 1;
        } else {
            Q->rear = front - 1;
        }
    }
}

// return the element at the front of the queue
int front(Queue Q){
    return Q.elem[Q.front];
}

// return the element at the rear of the queue
int rear(Queue Q){
    return Q.elem[Q.rear];
}

// check if the queue is full
int isFull(Queue Q){
	return (Q.front == ((Q.rear + 1) % SIZE) + 1) ? 1 : 0;
}

// check if the queue is empty
int isEmpty(Queue Q){
	// full queue front is ahead of rear by 2 cells
	// empty queue if front is ahead of rear by cell
	return (Q.front == (Q.rear + 1) % SIZE) ? 1 : 0;
}

// enqueue a new element
void enqueue(int elem, Queue * Q){
    if(isEmpty(*Q) == 1){
        Q->rear = Q->front;
    }
    
    else if (isFull(*Q) == 0){
        Q->rear = (Q->rear + 1) % SIZE;
    }
    
    Q->elem[Q->rear] = elem;
}

// dequeue element at the front of the queue
void dequeue(Queue * Q){
    if (isEmpty(*Q) == 0){
        Q->elem[Q->front] = -1;
        Q->front = (Q->front + 1) % SIZE;
    }
}
#endif
