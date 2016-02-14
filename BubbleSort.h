#include <stdio.h>
#include <stdlib.h>
#define BubbleSort
//functie de sortare descrescator
void sortareD ( int v[], int n ){
	int i, ok = 1, aux;
	do {
		ok = 1;
		for( i= 0; i< n-1 ;i++)
			if ( v[i] < v[i+1] ){
				ok = 0;
				aux = v[i];
				v[i] = v[i+1];
				v[i +1] = aux;
			}
	}while( ok != 1);
	
}

//functie de sortare crescator
void sortare ( int v[], int n ){
	int i, ok = 1, aux;
	do {
		ok = 1;
		for( i= 0; i< n-1 ;i++)
			if ( v[i] > v[i+1] ){
				ok = 0;
				aux = v[i];
				v[i] = v[i+1];
				v[i +1] = aux;
			}
	}while( ok != 1);
}

