#ifndef stackArray
#define stackArray

#include <stdio.h>
#include <stdlib.h>

#define SIZE 10

// stack versions 1 and 2
typedef struct {
	int data[SIZE];
	int top;
} StackV1, *StackV2;

// stack versions 3 and 4
typedef struct {
	int * data;
	int top;
} StackV3, *StackV4;

// initialize the stack - version 1
void initStackV1(StackV1 * S){
	S->top = - 1;
}

// initialize the stack - version 2
void initStackV2(StackV2 * S){
	*S = (StackV2) malloc(sizeof(StackV1));
	(*S)->top = -1;
}

// initialize the stack - version 3
void initStackV3(StackV3 * S){
	S->top = - 1;
	S->data = (int*) calloc(SIZE, sizeof(int));
}

// initialize the stack - version 4
void initStackV4(StackV4 * S){
	*S = (StackV4) malloc(sizeof(StackV3));
	(*S)->top = -1;
	(*S)->data = (int*) calloc(SIZE, sizeof(int));
}

// return the element at the top of the stack - version 1
int topV1(StackV1 S){
	return S.data[S.top];
}

// return the element at the top of the stack - version 2
int topV2(StackV2 S){
	return S->data[S->top];
}

// return the element at the top of the stack - version 3
int topV3(StackV3 S){
	return S.data[S.top];
}

// return the element at the top of the stack - version 4
int topV4(StackV4 S){
	return S->data[S->top];
}

// check if stack is empty - version 1
int isEmptyV1(StackV1 S){
	return (S.top == -1) ? 1 : 0;
}

// check if stack is empty - version 2
int isEmptyV2(StackV2 S){
	return (S->top == -1) ? 1 : 0;
}

// check if stack is empty - version 3
int isEmptyV3(StackV3 S){
	return (S.top == -1) ? 1 : 0;
}

// check if stack is empty - version 4
int isEmptyV4(StackV4 S){
	return (S->top == -1) ? 1 : 0;
}

// check if the stack is full - version 1
int isFullV1(StackV1 S){
	return (S.top == SIZE - 1) ? 1 : 0;
}

// check if the stack is full - version 2
int isFullV2(StackV2 S){
	return (S->top == SIZE - 1) ? 1 : 0;
}

// check if the stack is full - version 3
int isFullV3(StackV3 S){
	return (S.top == SIZE - 1) ? 1 : 0;
}

// check if the stack is full - version 4
int isFullV4(StackV4 S){
	return (S->top == SIZE - 1) ? 1 : 0;
}

// push to the stack - version 1
void pushV1(StackV1 * S, int data){
	if(S->top < SIZE - 1){
		S->data[++S->top] = data;
	}
}

// push to the stack - version 2
void pushV2(StackV2 * S, int data){
	if((*S)->top < SIZE - 1){
		(*S)->data[++(*S)->top] = data;
	}
}

// push to the stack - version 3
void pushV3(StackV3 * S, int data){
	if(S->top < SIZE - 1){
		S->data[++S->top] = data;
	}
}

// push to the stack - version 4
void pushV4(StackV4 * S, int data){
	if((*S)->top < SIZE - 1){
		(*S)->data[++(*S)->top] = data;
	}
}

// pop the stack - version 1
void popV1(StackV1 * S){
	if(S->top > -1){
		S->data[S->top--] = -1;
	}
}

// pop the stack - version 2
void popV2(StackV2 * S){
	if((*S)->top > -1){
		(*S)->data[(*S)->top--] = -1;
	}
}

// pop the stack - version 3
void popV3(StackV3 * S){
	if(S->top > -1){
		S->data[S->top--] = -1;
	}
}

// pop the stack - version 4
void popV4(StackV4 * S){
	if((*S)->top > -1){
		(*S)->data[(*S)->top--] = -1;
	}
}

// display the stack - version 1
void displayStack(StackV1 S){
	StackV1 temp = S;
	
	while(isEmptyV1(S) == 0){
		pushV1(&temp, topV1(S));
		printf("%d ", topV1(S));
		popV1(&S);
	}
}

// insert at the bottom of the stack - version 1
void insertBottomV1(StackV1 * S, int data){
	StackV1 temp;
	
	initStackV1(&temp);
	if(isFullV1(*S) != 1){
		while(isEmptyV1(*S) == 0){
			pushV1(&temp, topV1(*S));
			popV1(S);
		}
		
		pushV1(S, data);
		
		while(isEmptyV1(temp) == 0){
			pushV1(S, topV1(temp));
			popV1(&temp);
		}
	}
}

// insert at the bottom of the stack - version 2
void insertBottomV2(StackV2 * S, int data){
	StackV2 temp;
	
	initStackV2(&temp);
	if(isFullV2(*S) != 1){
		while(isEmptyV2(*S) == 0){
			pushV2(&temp, topV2(*S));
			popV2(S);
		}
		
		pushV2(S, data);
		
		while(isEmptyV2(temp) == 0){
			pushV2(S, topV2(temp));
			popV2(&temp);
		}
	}
}

// insert at the bottom of the stack - version 3
void insertBottomV3(StackV3 * S, int data){
	StackV3 temp;
	
	initStackV3(&temp);
	if(isFullV3(*S) != 1){
		while(isEmptyV3(*S) == 0){
			pushV3(&temp, topV3(*S));
			popV3(S);
		}
		
		pushV3(S, data);
		
		while(isEmptyV3(temp) == 0){
			pushV3(S, topV3(temp));
			popV3(&temp);
		}
	}
}

// insert at the bottom of the stack - version 4
void insertBottomV4(StackV4 * S, int data){
	StackV4 temp;
	
	initStackV4(&temp);
	if(isFullV4(*S) != 1){
		while(isEmptyV4(*S) == 0){
			pushV4(&temp, topV4(*S));
			popV4(S);
		}
		
		pushV4(S, data);
		
		while(isEmptyV4(temp) == 0){
			pushV4(S, topV4(temp));
			popV4(&temp);
		}
	}
}
#endif
