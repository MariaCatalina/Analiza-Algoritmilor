#define	RadixSort
#include <stdio.h>
#include <stdlib.h>
int countR = 0;
struct queue{
	int front , rear;
	int elem[10000];
}q;


int isEmpty(queue *q) {
	if( q->front == -1 ){
		countR += 2;
		return 1;
	}
	else
		return 0;
}

void enQueue(queue *& q, int x){
	if ( isEmpty(q) == 1){
		q->front = 0;
		q->rear = 0;
		countR += 6;
	}
	else{
		q->rear ++;
		countR ++;
		}
	q->elem[q->rear] = x;
	countR += 3;
}

int  deQueue(queue*q){
	int x;
	if ( q->front != -1 && q->front <= q->rear){
		x = q->elem[q->front];	
		q->front ++;
		countR += 10;
	return x;
	}
	else
		return -1;
}

int maxim(int v[], int n){
	int max, i;
	max = -32000;
	countR ++;
	for ( i = 0;i < n;i++){
		if( v[i] > max){
			max = v[i];
			countR += 3;			
		}
	}
	return max;
	}

int nr_cifre( int x){
	if ( x == 0){
		countR ++;
		return 0;
	}
	else {
		countR += 2;
		return 1 + nr_cifre(x/10);
	}
}

void RadixS (int vect[], int n, int ok){
int i, j,  x, p, cop, nr = 1;
	p = nr_cifre(maxim(vect,n));
	countR += 2;
	queue *q[10];

//initializare coada
	for(i = 0;i <= 9;i++){
		q[i] = ( queue*) malloc(sizeof(queue));
		q[i]->front = -1;
		q[i]->rear = -1;
		countR += 5;
	}	
	while ( p > 0 ){
		countR ++;
	//parcurgere vector
		for (i = 0; i < n; i++){
			cop = ( vect[i] / nr ) % 10;
			enQueue( q[cop], vect[i]); 
			countR += 5;
		}

		j = 0;
		countR ++;
		for ( i = 0 ; i <= 9 ;i++){
			x = deQueue(q[i]);
			countR += 2;
			while ( x != -1 ){
				vect[j++] = x;
				x = deQueue(q[i]);
				countR += 6;
			}
	
		}
//initializare coada
		for(i = 0;i < 9;i++){
			q[i]->front = -1;
			q[i]->rear = -1;
			countR += 6;
		}

		p--;
		nr = nr * 10;
		countR += 3;
	}
	if( ok == 1){
		for( i = 0;i < n;i++){
			printf("%d ", vect[i]);
			countR ++;
		}
	}
	for( i = 0;i <= 9;i ++){
		free(q[i]);
 		countR ++;
	}
}
