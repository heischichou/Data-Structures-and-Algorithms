#ifndef dictionaryClosedHashing
#define dictionaryClosedHashing

#include <stdio.h>
#include <stdlib.h>

#define EMPTY -1
#define DELETED -2
#define SIZE 0XA

typedef int Dictionary[SIZE];

// initialize the dictionary
void initDictionary(Dictionary D){
	int x;
	for(x = 0; x < SIZE; x++){
		D[x] = EMPTY;
	}
}

// get the hash value
int Hash(int data){
	return data % 10;
}

// check if a given element exsists in the dictionary
int member(Dictionary D, int data){
	int hash = Hash(data), x = hash;
	if(D[x] != data){
		for(x = (x + 1) % SIZE; x != hash && D[x] != data ; x = (x + 1) % SIZE){}
	}
	
	return (D[x] == data) ? 1 : 0;
}

// insert an element into the dictionary
void insertDictionary(Dictionary D, int data){
	int hash = Hash(data), x = hash;
	if(D[x] != EMPTY){
		for(x = (x + 1) % SIZE; x != hash && D[x] != EMPTY; x = (x + 1) % SIZE){}
	}
	
	if(D[x] == EMPTY){
		D[x] = data;
	}
}

// delete an element from the dictionary
void deleteDictionary(Dictionary D, int data){
	int hash = Hash(data), x = hash;

	if(D[x] != data){
		for(x = (x + 1) % SIZE; x != hash && D[x] != data; x = (x + 1) % SIZE){}
	}
	
	if(D[x] == data){
		D[x] = DELETED;
	}
}

// display a group in the dictionary
void displayGroup(Dictionary D, int index){
	int hash = Hash(D[index]), x = hash;
	
	printf("Group %d: %d ", index, D[x]);
	if(D[x] != EMPTY){
		for(x = (x + 1) % SIZE; x != hash && D[x] != EMPTY; x = (x + 1) % SIZE){
			if(hash == Hash(D[x])){
				printf("%d ", D[x]);
			}
	    }
	}
	
	printf("\n");
}

// display the dictionary
void displayDictionary(Dictionary D){
	int x;
	for(x = 0; x < SIZE; x++){
		displayGroup(D, x);
	}
}
#endif
