#ifndef setBitVector
#define setBitVector

#include <stdio.h>
#include <stdlib.h>

#define SIZE 8

typedef unsigned int Set[SIZE];

typedef enum {TRUE, FALSE} boolean;

// initialize the set
void initSet(Set S){
	int x;
	for(x = 0; x < SIZE; x++){
		S[x] = 0;
	}
}

// check if a given element is a member of the set
int member(Set S, int elem){
	return S[elem];
}

// insert an element into the set
void insertElem(Set S, int index){
	if(index > -1 && index < SIZE){
		S[index] = 1;
	}
}

// delete the given element of the set
void deleteElem(Set S, int index){
	if(index > -1 && index < SIZE){
		S[index] = 0;
	}
}

// return the union of the given sets
Set* Union(Set A, Set B){
	Set * C = (Set*) calloc(1, sizeof(Set));
	
	if(C != NULL){
		int x;
		for(x = 0; x < SIZE; x++){
			(*C)[x] = A[x] | B[x];
		}
	}
	
	return C;
}

// return the intersection of the given sets
Set* Intersection(Set A, Set B){
	Set * C = (Set*) calloc(1, sizeof(Set));
	
	if(C != NULL){
		int x;
		for(x = 0; x < SIZE; x++){
			(*C)[x] = A[x] & B[x];
		}
	}
	
	return C;
}

// return the difference of the given sets
Set* Difference(Set A, Set B){
    Set * C = (Set*) calloc(1, sizeof(Set));
	
	if(C != NULL){
		int x;
		for(x = 0; x < SIZE; x++){
			(*C)[x] = A[x] & ~B[x];
		}
	}

    return C;
}

// check if the given sets are equal
int Equals(Set A, Set B){
    int x, flag;

    for(x = 0, flag = (A[x] == B[x]) ? 1 : 0; x < SIZE && flag != 0; x++){
        flag = (A[x] == B[x]) ? 1 : 0;
    }

    return (flag == 1) ? 1 : 0;
}

// check if set B is a subset of set A
int isSubset(Set A, Set B) {
    int x;
    
    for(x = 0; x < SIZE && (A[x] & ~B[x]) == 0; x++){}

    return (x == SIZE) ? 1 : 0;
}

// display the set
void displaySet(Set S){
    int x;

    for(x = 0; x < SIZE; x++){
    	printf("S[%d]: %d\n", x, S[x]);
    }
}
#endif
