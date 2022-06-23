#ifndef heapMax
#define heapMax

#include "./heap.h"

// inserts a new element into the maxHeap by swapping elements
void insertMax(Heap * H, int data){
	int child;
	if(H->last < SIZE){
		H->data[++H->last] = data;
		for(child = H->last; child > 0 && H->data[child] > H->data[Parent(child)]; child = Parent(child)){
			swap(H, Parent(child), child);
		}
	}	
}

// inserts a new element into the Heap by shifting down elements
void insertMaxShift(Heap * H, int data){
	int parent, child;
	if(H->last < SIZE){
		for(child = ++H->last, parent = Parent(child); child > 0 && data > H->data[parent]; child = parent, parent = Parent(child)){
			H->data[child] = H->data[parent];			
		}
		H->data[child] = data;
	}
}

// deletes the root element of the maxHeap
int deleteMax(Heap * H){
	int x, max = H->data[0], biggest;
	if(H->last - 1){
		H->data[0] = H->data[H->last--];
		for(x = 0, biggest = biggestChild(*H, x); x > H->last && biggest > H->last && H->data[x] < H->data[biggest]; x = biggest, biggest = biggestChild(*H, biggest)){
			swap(H, x, biggest);			
		}
	}
}

// sorts the given heap using deleteMax
void maxHeapSort(Heap * H){
	int oldLast = H->last, x, biggest;
	while(H->last > -1){
		swap(H, 0, H->last--);
		for(x = 0, biggest = biggestChild(*H, x); x < H->last && biggest < H->last && H->data[x] < H->data[biggest]; x = biggest, biggest = biggestChild(*H, x)){
			swap(H, x, biggest);			
		}
	}
	
	H->last = oldLast;
}

// maxHeapifies a given tree
void subHeapifyMax(Heap * H, int parent){
	if(H->last > -1){
		int lchild = LChild(parent);
		if(lchild <= H->last){
			if(RChild(parent) > H->last){
				if(H->data[lchild] > H->data[parent]){
					swap(H, parent, lchild);
				}
			} else {
				int biggest = biggestChild(*H, parent);
				if(H->data[biggest] > H->data[parent]){
					swap(H, parent, biggest);
				}
			}
		}
	}
}

// sorts the given heap using maxHeapify
void maxHeapify(Heap * H){
	int parent;
	for(parent = Parent(H->last); parent > -1; parent--){
		subHeapifyMax(H, parent);
	}
	
	displayHeap(*H);
}
#endif
