#ifndef setArray
#define setArray

#include <stdio.h>
#include <stdlib.h>

#define SIZE 0XA

typedef struct {
    int elem[SIZE];
    int count;
} Set;

// initialize the set
void initSet(Set * S){
    S->count = -1;
}

// check if a given element is a member of the set
int member(Set S, int data){
    int x;
    for(x = 0; x < S.count && S.elem[x] != data; x++){}
    return (x < S.count) ? 1 : 0;
}

// insert an element into the set
void insertElem(Set * S, int data){
	if(S->count < SIZE - 1){
		S->elem[++S->count] = data;
	}
}

// return the union of the given sets
Set* Union(Set A, Set B){
    Set * C = (Set*) calloc(1, sizeof(Set));
    
    if(C != NULL){
	    int a, b;
	
	    for(a = 0, b = 0; a <= A.count && b <= B.count; C->count++){
	        if(A.elem[a] < B.elem[b]){
	            C->elem[C->count] = A.elem[a++];
	        } else {
	            if(A.elem[a] == B.elem[b]){
	                a++;
	            }
	
	            C->elem[C->count] = B.elem[b++];
	        }
	    }
	
	    if(b <= B.count){
	        A = B;
	        a = b;
	    }
	
	    for(; a <= A.count; C->count++, a++){
	        C->elem[C->count] = A.elem[a]; 
	    }
    }

    return C;
}

// returns the intersection of the given sets
Set* Intersection(Set A, Set B){
    Set * C = (Set*) calloc(1, sizeof(Set));
    
    if(C != NULL){
	    C->count = -1;
	    int a, b;

	    for(a = 0; a <= A.count; a++){
	        for(b = 0; b <= B.count; b++){
	            if(A.elem[a] == B.elem[b]){
	                C->elem[++C->count] = A.elem[a];
				}
			}
		}
	}

    return C;
}

// returns the difference of the given sets
Set* Difference(Set A, Set B){
    Set * C = (Set*) calloc(1, sizeof(Set));
    if(C != NULL){
	    int a, b;
	
	    for(a = 0, b = 0; a <= A.count && b <= B.count; C->count++){
	        if(A.elem[a] < B.elem[b]){
	            C->elem[C->count] = A.elem[a++];
	        }
			
			else if (A.elem[a] > B.elem[b]) {
				b++;
	    	}
	    	
	    	else {
	    		a++;
	    		b++;
			}
	    }
	
	    for(; a <= A.count; a++){
			C->elem[++C->count] = A.elem[a];
		}
	}

    return C;
}

// display the set
void displaySet(Set S){
    int x;
    for(x = 0; x < S.count; x++){
        printf("%d ", S.elem[x]);
    }
}

// search for an element in the set using the binary search method
int binarySearch(Set S, int elem){
	int low, mid, high;
    
	for(low = 0, high = S.count - 1, mid = (low + high) / 2; low < high && S.elem[mid] != elem; mid = (low + high) / 2){
		(elem > S.elem[mid]) ? low = mid + 1 : high = mid - 1;
	}
	
	return elem == S.elem[mid] ? 1 : 0;
}
#endif
