#ifndef setComputerWord
#define setComputerWord

#include <stdio.h>

typedef unsigned char Set;

// initialize the set
void initSet(Set * S){
    *S = 0;
}

// check if a given element is a member of the set
int member(Set S, int n){
    return ((S & 1 << n) > 0) ? 1 : 0; 
}

// insert an element into the set
void insertBit(Set * S, int bit){
    if(bit <= sizeof(*S) * 8){
        *S = *S | (1 << bit);
    }
}

// delete the given element of the set
void deleteBit(Set * S, int bit){
    if(bit <= sizeof(*S) * 8){
        *S = *S & ~(1 << bit);
    }
}

// return the union of the given sets
Set Union(Set A, Set B){
    return A | B;
}

// return the union of the given sets
Set Intersection(Set A, Set B){
    return A & B;
}

// return the union of the given sets
Set Difference(Set A, Set B){
    return A & ~B;
}

// display the set
void displaySet(Set S){
    Set r;
    int size = sizeof(Set) * 8;

    printf("The bit pattern of %d is: ", S);
    for(r = 1 << size - 1; r > 0; r >>= 1){
        (S & r) ? printf("1") : printf("0");
    }
}
#endif
