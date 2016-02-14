#define StrandSort
#include <stdio.h>
#include <stdlib.h>

int countS = 0;

typedef struct node{
	int val;
	struct node *next;
}nod;

int isEmpty( nod *l){
	if (l == NULL ){
		countS ++;
		return 1;
	}
	else
		return 0;
}
//Functie de adugare nod la sfarsitul listei
void add(nod *& l, int a){
	if( isEmpty(l) ){
		l = (nod*)malloc(sizeof(nod));
		l->val = a;
		l->next = NULL;
//count = apel functie, atribuiri si indexare l->nevt , l->val
		countS += 6;
	}
	else
		add(l->next,a);
}

//Functie de stergere a unui noid din lista
void del(nod *&l , int x){
	if( ! isEmpty(l) ){
//count = apel functie si comparatie
		countS += 2;
		if ( l->val == x){
			l = l->next;
			countS += 3;
		}
		else{
			countS ++;
			del(l->next,x);
		}
	}
}

// parcurgerea listei nesortate si returnare sublista
nod * parcurgere ( nod *& l ){
	int a;
	nod * t = NULL;
	countS ++;
//adaug prima valoare din lista
	if ( ! isEmpty(l) ){
		add(t,l->val);
		a = l->val;
		countS += 5;
	}
	if (l->next != NULL){
		l = l->next;
		countS += 4;
	}
	del(l,a);
	countS ++;

	while (l != NULL ){
		countS ++;
	//parcurgere lista si extreagere elementele in ordine crescatoate
		if ( l->val >= a ){
			add(t,l->val);
			a = l->val;
			l = l->next;
	//sterge elem care a fost adugat in sublista
			del(l,a);
			countS += 8;
		}
		else
			break;
	}
	return t;	
}

//functie de concatenare a doau liste
nod * concat (nod * a, nod * b){
	nod *l = NULL;
	countS ++;
//cat timp mai sunt elemente in ambele list
	while( a != NULL && b != NULL){
		countS += 2;
		if (a->val <= b->val ){
			add(l,a->val);
			a = a->next;
			countS += 6;
		}
		else
			if ( b->val < a->val ){
				add(l,b->val);
				b = b->next;
				countS += 6;
			}
	}
//daca mai raman elem in a
	while (a != NULL ){
		add(l,a->val);
		a = a->next;
		countS += 4;
	}
//daca mai raman elem in b
	while (b != NULL){
		add(l,b->val);
		b = b->next;
		countS += 4;
	} 
	return l;
}

//functia de afisare a listei
void print( nod * l){
	if( l == NULL){
		printf("\n");
		countS ++;
	}
	else {
		countS += 2;
		printf("%d ",l->val);
		print(l->next);
	}
}

//functia de sortare
void sortareSS(int v[], int n, int ok){
	int i;
	nod * lst_sort = NULL;
	nod * fin = NULL;
	nod * l = NULL;
	countS += 3;

//adugare elemante in lista
	for (i = 0; i < n;i++){
		add(l,v[i]);
		countS ++;
	}
//cat timp existe elemente in lista apeleaza functiile de prelucrare
	while ( l != NULL ){
		
		lst_sort = parcurgere(l);
		fin = concat(fin,lst_sort);
		countS += 3;		
	} 

//functia de afisare se executa daca este in mod de testare
	if( ok == 1)
		print(fin);

	free(concat(fin,l));
	//free(parcurgere(l));
	free(fin);
	fin = NULL;
	free(lst_sort);
	free(l);
}

