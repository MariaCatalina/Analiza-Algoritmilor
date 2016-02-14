#define BinaryTreeSort
#include <stdio.h>
#include <stdlib.h>
int countB = 0;

//Declarare arbore
typedef struct Tree{
	int val;
	struct Tree * right;
	struct Tree * left;
}Tree;

//Functie de initializare
int isEmpty(Tree *t){
	if ( t == NULL ){
		countB ++;
		return 1;
	}
	else
		return 0;
}

//Functie de adugare nod nou
void addTree(Tree *& t , int x){
	if( isEmpty(t) == 1){

		t = (Tree *)malloc(sizeof(Tree));
		t->val = x;
		t->right = NULL;
		t->left = NULL;
//count pentru initializari
		countB += 9;
	}
	else
		if (x < t->val){
//count pentru comparare, atribuire si apel de functie
			countB += 3;
			return addTree(t->left, x);
		}
		else{
			countB ++;
			return addTree(t->right,x);
		}
}

//Functie de afisare a arborelui
void printTree(Tree *t){
	if( !isEmpty(t) ){

		countB += 5;
		printTree(t->left);
		printf("%d ", t->val);
		printTree(t->right);
	}
}

void BTreeSort( int v[], int n, int ok){
	int i;
	Tree *t = NULL;
//adugare elemente in arbore
	for ( i = 0;i < n;i ++){
		countB ++;
		addTree(t,v[i]);
	}
//afisarea se face face doar pentru Mod de testare
	if ( ok == 1)
		printTree(t);
	free(t);
}
