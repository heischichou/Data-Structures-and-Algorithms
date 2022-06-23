#ifndef heap
#define heap

#include <stdio.h>

#define SIZE 10

typedef struct {
	int data[SIZE];
	int last;
} Heap;

// returns the index of the left child
int LChild(int index){
	return (index * 2) + 1;
}

// returns the index of the right child
int RChild(int index){
	return (index * 2) + 2;
}

// returns the index of the parent
int Parent(int index){
	return (index - 1) / 2;
}

// returns the index of the biggest child
int biggestChild(Heap H, int parent){
	int lchild = LChild(parent), rchild = RChild(parent);
	return (H.data[lchild] > H.data[rchild]) ? lchild : rchild; 
}

// swaps the values of the two given indices
void swap(Heap * H, int parent, int child){
	int temp = H->data[child];
	H->data[child] = H->data[parent];
	H->data[parent] = temp;
}

// initializes the Heap structure
void init(Heap * H){
	H->last = -1;
}

// displays the Heap
void displayHeap(Heap H){
	int x;
	for(x = 0; x <= H.last; x++){
		printf("[%d]: %d\n", x, H.data[x]);
	}
	printf("\n");
}
#endif
