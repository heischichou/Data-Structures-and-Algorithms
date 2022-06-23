#ifndef dictionaryClosedHashingProgressiveOverflow
#define dictionaryClosedHashingProgressiveOverflow

#include <stdio.h>
#include <stdlib.h>

#define SIZE 0XA
#define SYNONYM SIZE / 2 - 1
#define EMPTY -1
#define DELETED -2

typedef struct node {
	int data;
	int link;
} node;

typedef struct {
	node nodes[SIZE];
	int avail;
} Dictionary;

// initialize the dictionary
void initDictionary(Dictionary * D){
	int x;
	for(x = 0; x < SYNONYM + 1; x++){
		D->nodes[x].data = D->nodes[x].link = EMPTY;
	}
	
	D->avail = SYNONYM + 1;
}

// get the hash value
int Hash(int data){
	return data % 10;
}

// check if a given element exsists in the dictionary
int member(Dictionary D, int data){
	int hash = Hash(data), x = hash;
	if(D.nodes[x].data != data){
		for(; x != -1 && D.nodes[x].data != data; x = D.nodes[x].link){}
	}
	
	return (D.nodes[x].data == data) ? 1 : 0;
}

// insert an element into the dictionary
void insertDictionary(Dictionary * D, int data){
	int hash = Hash(data);
	if(D->avail < SIZE){
		if(D->nodes[hash].data == EMPTY){
			D->nodes[hash].data = data;
		} else {
			D->nodes[D->avail].data = data;
			D->nodes[D->avail].link = D->nodes[hash].link;
			D->nodes[hash].link = D->avail++;
		}
	}
}

// delete an element from the dictionary
void deleteElem(Dictionary * D, int data){
	int hash = Hash(data), x = hash;
	if(D->nodes[x].data == data){
		D->nodes[x].data = DELETED;
	} else {
		for(; x != -1 && D->nodes[x].data != data; x = D->nodes[x].link){}
		if(D->nodes[x].data == data){
			D->nodes[x].data = DELETED;
		}
	}
}

// display the dictionary
void displayDictionary(Dictionary D){
	int x, y;

	for(x = 0; x <= SYNONYM; x++){
		printf("Group %d: ", x);
		
		if(D.nodes[x].data == EMPTY){
			printf("Empty");
		} else {
			for(y = x; y != -1; y = D.nodes[y].link){
				printf("%d ", D.nodes[y].data);
			}
		}
		
		printf("\n");
	}
}
#endif
