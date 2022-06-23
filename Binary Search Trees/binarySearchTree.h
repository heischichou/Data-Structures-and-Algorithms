#ifndef binarySearchTree
#define binarySearchTree

#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	int data;
	struct node * lchild;
	struct node * rchild;
} node, *Tree;

// initialize the tree
void initBST(Tree * T){
	*T = NULL;
}

// checks if the given data exists in the tree, returns 1 if present, otherwise, 0
int isMember(Tree T, int data){
	for(; T != NULL && T->data != data; T = (data < T->data) ? T->lchild : T->rchild){}
    return (T != NULL && T->data == data) ? 1 : 0;
}

// checks if the given data exists in the tree, returns 1 if present, otherwise, 0 - recursive version
int isMemberRecursive(Tree T, int data){
	if(T != NULL){
		if(T->data == data){ return 1; }
		return (data < T->data) ? isMemberRecursive(T->lchild, data) : isMemberRecursive(T->rchild, data);
	} else {
		return 0;
	}
}

// insert an element into the BST
void insertBST(Tree * T, int data){
	Tree * trav;
	
	for(trav = T; *trav != NULL && (*trav)->data != data; trav = (data < (*trav)->data) ? &(*trav)->lchild : &(*trav)->rchild){}
	if(*trav == NULL){
		*trav = (node*) malloc(sizeof(node));
		(*trav)->data = data;
		(*trav)->lchild = (*trav)->rchild = NULL;
	}
}

// insert an element into the BST - recursive version
void insertBSTRecursive(Tree * T, int data) {
	if(*T != NULL && (*T)->data != data){
		(data < (*T)->data) ? insertBSTRecursive(&(*T)->lchild, data) : insertBSTRecursive(&(*T)->rchild, data);
	} else {
		if((*T)->data != data){
			*T = (node*) malloc(sizeof(node));
			(*T)->data = data;
			(*T)->rchild = (*T)->lchild = NULL;
		}
	}
}

// delete the minimum element of the tree and return the deleted element
int deleteMin(Tree * T){
    int min;
    Tree * trav, temp;
    
    for(trav = T; *trav != NULL && (*trav)->lchild != NULL; trav = &(*trav)->lchild){}
    if(*trav != NULL){
        temp = *trav;
        min = temp->data;
        *trav = temp->rchild;
        free(temp);
    }
    return min;
}

// delete the maximum element of the tree and return the deleted element
int deleteMax(Tree * T){
    int max;
    Tree * trav, temp;
    
    for(trav = T; *trav != NULL && (*trav)->rchild != NULL; trav = &(*trav)->rchild){}
    if(*trav != NULL){
        temp = *trav;
        max = temp->data;
        *trav = temp->lchild;
        free(temp);
    }
    
    return max;
}

// delete a member in the tree and return the deleted element
int deleteElem(Tree * T, int data){
	int elem;
	Tree *trav, *trav2, temp;
	
	for(trav = T; *trav != NULL && (*trav)->data != data; trav = (data < (*trav)->data) ? &(*trav)->lchild : &(*trav)->rchild){}
	if((*trav)->lchild == NULL && (*trav)->rchild == NULL){
		elem = (*trav)->data;
		free(*trav);
	}
	
	else if((*trav)->lchild != NULL && (*trav)->rchild == NULL){
		temp = *trav;
		*trav = temp->lchild;
		free(temp);
	}
	
	else if((*trav)->rchild != NULL){
		temp = *trav;
		*trav = temp->rchild;
		free(temp);
	}
	
	else {
		for(trav2 = &(*trav)->lchild; (*trav2)->rchild != NULL; trav2 = &(*trav2)->rchild){}
		elem = (*trav)->data;
		(*trav)->data = (*trav2)->data;
		temp = *trav2;
		*trav2 = temp->lchild;
		free(temp);
	}
	
	return elem;
}

// delete a member in the tree and return the deleted element - recursive version
int deleteElemRecursive(Tree * T, int data){
	if(*T != NULL){
		if(data != (*T)->data){
			return (data < (*T)->data) ? deleteElemRecursive(&(*T)->lchild, data) : deleteElemRecursive(&(*T)->rchild, data);
		} else {
			int elem;
			
			if((*T)->lchild == NULL && (*T)->rchild == NULL){
				elem = (*T)->data;
				free(*T);
			}
			
			else if((*T)->lchild != NULL && (*T)->rchild == NULL){
				elem = (*T)->data;
				Tree temp = *T;
				*T = temp->lchild;
				free(temp);
			}
			
			else if((*T)->rchild != NULL){
				elem = (*T)->data;
				Tree temp = *T;
				*T = temp->rchild;
				free(temp);
			}
			
			else {
				Tree * trav, temp;
				for(trav = &(*T)->lchild; (*trav)->rchild != NULL; trav = &(*trav)->rchild){}
				// substitue immediate predecessor with its left child
				elem = (*T)->data;
				(*T)->data = (*trav)->data;
				temp = *trav;
				*trav = temp->lchild;
				free(temp);
			}
			
			return elem;
		}
	} else {
		return -1;
	}
}

// preorder traversal
void preorder(Tree T){
	if(T != NULL){
		printf("%d ", T->data);
		preorder(T->lchild);
		preorder(T->rchild);
	}
}

// inorder traversal
void inorder(Tree T){
	if(T != NULL){
		inorder(T->lchild);
		printf("%d ", T->data);
		inorder(T->rchild);
	}
}

// postorder traversal
void postorder(Tree T){
	if(T != NULL){
		postorder(T->lchild);
		postorder(T->rchild);
		printf("%d ", T->data);
	}
}

// display the entire tree
void displayBST(Tree T){
    if(T == NULL){
        printf("BST is empty.");
    } else {
        printf("\nElements of BST: ");
        preorder(T);
    }
}
#endif
