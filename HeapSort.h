#define HeapSort
#include <stdio.h>
#include <stdlib.h>
int countH = 0;

//functie ce returneaza pe ce pozitie se afla parintele unui element
int parent( int poz){
	
	int i = (poz - 1 )/2;
	countH += 3;
	if (i < 0){
		countH ++;
		return -1;
	}
	return i;
}

//fucntie ce returneaza pe ce pozitie se afla fiul din stanga
int leftSub(int poz, int dimV){
	int i = 2 * poz +1 ;
	countH += 3;
	if( i > dimV ){
		countH ++;
		return -1;
	}
	return i;
}

/*verificare daca parintele unui element este mai mic decat el si
interchimbare in caz afirmativ */
void pushUP(int v[], int poz, int n){

	int p = parent(poz), aux;
	countH += 2;
	while (	v[p] < v[poz] ){
		aux = v[p];
		v[p] = v[poz];
		v[poz] = aux;
		poz = p;
		p = parent(poz); 
		countH += 6;
	}
}

/*verificare daca copii unui element sunt mai mari decat el
verificare care dintre copii este mai mare si interschimbare cu parintele
in caz afirmativ */ 
void pushDown(int v[], int poz, int n){
	int aux, r, l, max;
	r = 2 * poz  + 2;
	countH += 3;
	if ( r > n ){
		r = -1;
		countH += 2;
	}
	l = leftSub(poz,n);
	countH += 2;
/*daca copilul stang este mai mare decat lunginea vectorului se iese 
din functie*/
	if ( l == -1 ){
		countH++;
		return;
	}
	max = l;
	countH ++;
	if( r != -1 ){
		countH ++;
		if ( v[max] < v[r] ){	
			max = r;
			countH += 4;
		}
	}
	if ( v[max] >= v[poz] ){
		aux = v[max];
		v[max] = v[poz];
		v[poz] = aux;
		countH += 10;
	}
	countH ++;
	pushDown(v,max,n);
}

//extragerea elementului maxim din vector si stergerea lui
int extractMax(int v[],int *n){
	int aux;
	if ( (*n) > 0){
		aux = v[0];
		v[0] = v[(*n) - 1];
		(*n) --;
		pushDown(v,0,(*n));
		countH += 8;
		return aux;
	}
	else
		return 0;
	
}

//functie de afisare a vectorului
void afHs(int v[], int n){
	int i;
	for (i = n - 1;i>= 0;i--){
		printf("%d ",v[i]);
		countH ++;
	}
	printf("\n");
}

//functia  de sortare
void SortareHS( int v[], int n, int ok){
	int i , h[n], f = n;
	countH ++;
	for ( i = 0;i < n;i ++){
		countH ++;
		pushUP(v,i,n);
	}
 
	for ( i = 0 ;i < f;i++){
		h[i] = extractMax(v,&n);
		countH += 2;
	}
	if( ok == 1 ) 
		afHs(h,f);
}
