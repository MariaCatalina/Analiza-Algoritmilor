#define CocktailSort
#include <stdio.h>
#include <stdlib.h>
 int countC = 0;

//parcugere de la stanga la dreapta, de la elem de pe j la n - 1
void interschimb1( int v[], int n, int j){
	int i, aux;
	for(i = j; i < n - 1; i ++)
		if (v[i] > v[i + 1] ){
			aux = v[i];
			v[i] = v[i + 1];
			v[i + 1] = aux;
		//cost interschimbare = 3 + comparare;
			countC += 10;
		}
}

//parcurgere de la dreapta la stanga
void interschimb2(int v[], int n , int j){
	int i, aux;
	for( i = n - 1 ;i > j;i --)
		if( v[i] < v[i - 1] ){
			aux = v[i];
			v[i] = v[i - 1];
			v[i-1] = aux;	
			
		//cost interschimbare = 3 + comparare;
			countC += 10;
		}		
}

//functia de afisare a vectorului
void printCS(int v[] , int n){
	int i;
	for (i = 0; i < n; i ++){
		printf("%d ", v[i]);
		countC ++;
	}
	printf("\n");
}

//Functia de sortare
void SortareCS(int v[], int n, int ok){
	int i = 0, m = n;
	countC += 2;

	while( i <= n/2 ){
			interschimb1(v,n, i);
			n--;
			interschimb2(v,n,i);
			i++;
			countC += 6;
	}

	if( ok == 1)
		printCS(v,m); 
}
