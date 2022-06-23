#ifndef dictionaryOpenHashing
#define dictionaryOpenHashing

#include <stdio.h>
#include <stdlib.h>

#define SIZE 0XA

typedef struct node {
    int data;
    struct node * link;
} node, *Group;

typedef Group Dictionary[SIZE];

// initialize the dictionary
void initDictionary(Dictionary D){
    int x;
    for(x = 0; x < SIZE; x++){
        D[x] = NULL;
    }
}

// get the hash value
int Hash(int data){
    return data % 10;
}

// check if a given element exsists in the dictionary
int member(Dictionary D, int data){
    int hash = Hash(data);
    Group ptr = D[hash];
    
    for(; ptr != NULL && ptr->data != data; ptr = ptr->link){}
    
    return (ptr != NULL) ? 1 : 0;
}

// insert an element into the dictionary
void insertDictionary(Dictionary D, int data){
    int hash = Hash(data);
    Group * ptr, temp;

    for(ptr = &D[hash]; *ptr != NULL && data > (*ptr)->data; ptr = &(*ptr)->link){}
    
	temp = (Group) malloc(sizeof(node));
    temp->data = data;
    temp->link = *ptr;
    *ptr = temp;
}

// delete an element from the dictionary
void deleteDictionary(Dictionary D, int data){
    int hash = Hash(data);
    Group * ptr, temp;
    
    for(ptr = &D[hash], temp = *ptr; *ptr != NULL && (*ptr)->data != data; temp = *ptr, ptr = &(*ptr)->link){}
    if(*ptr != NULL){
        temp = *ptr;
        *ptr = temp->link;
        free(temp);
    }
}

// display the dictionary
void displayDictionary(Dictionary D){
    int x;
    Group ptr;

    for(x = 0; x < SIZE; x++){
        printf("Group %d: ", x);
        ptr = D[x];
        
        if(ptr == NULL){
			printf("Empty");
		}
		
        for(; ptr != NULL; ptr = ptr->link){
			printf("%d ", ptr->data);
		}
        printf("\n");
    }
}
#endif
