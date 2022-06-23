#ifndef heapMin
#define heapMin

#include "./heap.h"

// inserts a new element into the minHeap by swapping elements
void insertMin(Heap * H, int data){
	int child;
	if(H->last < SIZE){
		H->data[++H->last] = data;
		for(child = H->last; child > 0 && H->data[child] < H->data[Parent(child)]; child = Parent(child)){
			swap(H, Parent(child), child);
		}
	}
}

// inserts a new element into the Heap by shifting down elements
void insertMinShift(Heap * H, int data){
	int parent, child;
	if(H->last < SIZE){
		for(child = ++H->last, parent = Parent(child); child > 0 && data < H->data[parent]; child = parent, parent = Parent(child)){
			H->data[child] = H->data[parent];
		}
		H->data[child] = data;
	}
}

// deletes the root element of the minHeap
int deleteMin(Heap * H){
	int x, min = H->data[0], smallest;
	if(H->last > -1){
		H->data[0] = H->data[H->last--];
		for(x = 0, smallest = smallestChild(*H, x); x < H->last && smallest < H->last && H->data[x] > H->data[smallest]; x = smallest, smallest = smallestChild(*H, x)){
			swap(H, x, smallest);
		}		
	}
	
	return min;
}

// sorts the given heap using deleteMin
void minHeapSort(Heap * H){
	int oldLast = H->last, x, smallest;
	while(H->last > -1){
		swap(H, 0, H->last--);
		for(x = 0, smallest = smallestChild(*H, x); x < H->last && smallest < H->last && H->data[x] > H->data[smallest]; x = smallest, smallest = smallestChild(*H, x)){
			swap(H, x, smallest);			
		}
	}
	
	H->last = oldLast;
}

// minHeapifies a given tree
void subHeapifyMin(Heap * H, int parent){
	if(H->last > -1){
		int lchild = LChild(parent);
		if(lchild <= H->last){
			if(RChild(parent) > H->last){
				if(H->data[lchild] < H->data[parent]){
					swap(H, parent, lchild);
				}
			} else {
				int smallest = smallestChild(*H, parent);
				if(H->data[smallest] < H->data[parent]){
					swap(H, parent, smallest);
				}
			}
		}
	}
}

// sorts the given heap using minHeapify
void minHeapify(Heap * H){
	int parent;
	for(parent = Parent(H->last); parent > -1; parent--){
		subHeapifyMin(H, parent);
	}
	
	displayHeap(*H);
}
#endif
