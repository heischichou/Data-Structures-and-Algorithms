#ifndef stackCursorBased
#define stackCursorBased

#define SIZE 10

typedef struct {
    int elem;
    int next;
} node;

typedef struct {
   node nodes[SIZE];
   int avail;
   int top;
} Stack;

typedef enum {TRUE, FALSE} boolean;

// initialize the stack
void initStack(Stack * S){
    int x;

    S->top = -1;
    for(x = SIZE - 1; x > 0; x--){
        S->nodes[x].next = x - 1;    
    }
    
    S->nodes[x].next = -1;   
    S->avail = SIZE - 1;
}

// return element at the top of the stack
int top(Stack S){
    return S.nodes[S.top].elem;
}

// check if the stack is full
int isFull(Stack S){
    return (S.top == 0) ? 1 : 0;
}

// check if the stack is empty
int isEmpty(Stack S){
    return (S.top == -1) ? 1 : 0;
}

// allocate space for the virtual heap
int alloc(Stack * S){
    int temp = S->avail;

    if(temp != 1){
        S->nodes[temp].next = S->avail;
    }
}

// deallocate space from the virtual heap
int free(Stack * S, int index){
    if(index > -1 && index < SIZE){
        S->nodes[index].next = S->avail;
        S->avail = index;
    }
}

// push to the stack
void push(Stack * S, int data){
    int temp = alloc(S);

    if(temp != 1){
        S->nodes[temp].elem = data;
        S->nodes[temp].next = S->top;
        S->top = temp;
    }
}

// pop the stack
void pop(Stack * S){
    if(isEmpty(*S) == 0){
        int temp = S->top;
        S->top = S->nodes[temp].next;
        free(S, temp);
    }
}
#endif
