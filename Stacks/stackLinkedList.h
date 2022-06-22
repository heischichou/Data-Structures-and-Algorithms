#ifndef stackLinkedList
#define stackLinkedList

#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	int data;
	struct node * link;
} node, *Stack;

// initialize the stack
void initStack(Stack * S){
    *S = NULL;
}

// return the element at the top of the stack
int top(Stack S){
    return S->data;
}

// check if the stack is empty
int isEmpty(Stack S){
    return (S == NULL) ? 1 : 0;
}

// push to the stack
void push(Stack * S, int data){
    Stack temp;
    temp = (Stack) malloc(sizeof(node));
    
    temp->link = *S;
    temp->data = data;
    *S = temp;
}

// pop the stack
void pop(Stack * S){
    Stack temp;
    
    if(S != NULL){
        temp = *S;
        *S = temp->link;
        free(temp);
    }
}

// insert at the bottom of the stack
void insertBottom(Stack * S, char data){
	Stack temp;
	initStack(&temp);
	
	while(isEmpty(*S) == 0){
		push(&temp, top(*S));
		pop(S);
	}
	
	push(S, data);
	
	while(isEmpty(temp) == 0){
		push(S, top(temp));
		pop(&temp);
	}
}

// display the stack
void displayStack(Stack * S){
    Stack temp;
    initStack(&temp);
    
    while(isEmpty(*S) == 0){
        printf("%d ", top(*S));
        insertBottom(&temp, top(*S));
        pop(S);
    }
    
    *S = temp;
}
#endif
