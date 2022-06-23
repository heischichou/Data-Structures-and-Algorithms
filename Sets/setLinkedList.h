#ifndef setLinkedList
#define setLinkedList

#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    unsigned int data;
    struct node * link;
} node, *Set;

typedef enum {TRUE, FALSE} boolean;

// initialize the set
void initSet(Set * S){
    *S = NULL;
}

// get the cardinality of the given set
int getCardinality(Set S){
    int count;
    for(count = 0; S != NULL; count++, S = S->link){}
    
    return count;
}

// check if a given element is a member of the set
int member(Set S, unsigned int member){
    for(; S != NULL && S->data != member; S = S->link){}
    return (S != NULL) ? 1 : 0;
}

// insert an element into the set
void insertElem(Set * S, unsigned int data){
    node * temp = (node*) malloc(sizeof(node));
    
    if(temp != NULL){
    	temp->data = data;
	    temp->link = *S;
	    *S = temp;
    }
}

// delete an element from the given set
void deleteElem(Set * S, unsigned int member){
    Set * trav, temp;
    
    for(trav = S; *trav != NULL;){
    	if((*trav)->data == member){
            temp = *trav;
            *S = temp->link;

            free(*S);
        } else {
            trav = &(*trav)->link;
        }
	}
}

// return the union of the given sets
Set Union(Set A, Set B){
    Set C = NULL, *c = &C;

    for(; A != NULL && B != NULL; c = &(*c)->link){
        *c = (Set) calloc(1, sizeof(node));
        
        if(A->data < B->data){
            (*c)->data = A->data;
            A = A->link;
        } else {
            if(A->data == B->data){
                A = A->link;
            }

            (*c)->data = B->data;
            B = B->link;
        }
    }

    if(A == NULL && B != NULL){
        A = B;
    }

    for(; A != NULL; A = A->link){
        *c = (Set) calloc(1, sizeof(node));
        
        if(*c != NULL){
            (*c)->data = A->data;
            c = &(*c)->link;
        }
    }

    return C;
}

// returns the intersection of the given sets
Set Intersection(Set A, Set B){
    Set b, C = NULL, *c = &C;
    
    for(; A != NULL; A = A->link){
        for(b = B; b != NULL && A->data != b->data; b = b->link){}
        if(b != NULL && A->data == b->data){
            if(*c != NULL){
                c = &(*c)->link;
            }

            *c = (Set) malloc(sizeof(node));
            (*c)->data = A->data;
            (*c)->link = NULL;
        }
    }

    return C;
}

// returns the difference of the given sets
Set Difference(Set A, Set B){
    Set b, C = NULL, *c = &C;

    for(; A != NULL; A = A->link){
        for(b = B; b != NULL && A->data != b->data; b = b->link){}
        if(b == NULL){
            if(*c != NULL){
                c = &(*c)->link;
            }

            *c = (Set) malloc(sizeof(node));
            (*c)->data = A->data;
            (*c)->link = NULL;
        }
    }

    return C;
}

// check if the given sets are equal
int Equals(Set A, Set B){
    node * b;
    int countA = getCardinality(A), countB = getCardinality(B), flag;

    for(flag = (countA == countB) ? 1 : 0; A != NULL && flag != 0; A = A->link){
        for(b = B; b != NULL && A->data != b->data; b = b->link){}
        flag = (b != NULL) ? 1 : 0;
    }

    return flag;
}

// display the set
void displaySet(Set S){
    for(; S != NULL; S = S->link){
        printf("%d ", S->data);
    }
}
#endif
