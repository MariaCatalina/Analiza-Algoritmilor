#include <stdio.h>
#include <stdlib.h>
#include "StrandSort.h"
#include "RadixSort.h"
#include "BinaryTreeSort.h"
#include "HeapSort.h"
#include "CocktailSort.h"
#include "BubbleSort.h"
#include <time.h>

int getRandom(){
	return 42;
}

int main(){
	
	int i,a, n, *v1, *v2, *v3,*v4, *v5;
	int ok;
	printf("Introduceti modul de testare : \n");
	printf("1-> Mod de testare \n 2-> Mod de analiza \n");
	printf("Introduceti alegerea : ");
	scanf("%d",&ok );
 	
	if(ok == 1){
		n = 10;
		v1 = (int *)malloc(n * sizeof(int));
		v2 = (int *)malloc(n * sizeof(int));
		v3 = (int *)malloc(n * sizeof(int));
		v4 = (int *)malloc(n * sizeof(int));
		v5 = (int *)malloc(n *sizeof(int));
	for ( i = 0;i< n;i++){
		v1[i] = rand() % 320000 + 1;
		v2[i] = rand() % 320000 + 1;
		v3[i] = rand() % 320000 + 1;
		v4[i] = rand() % 320000 +1;
		v5[i] = rand() % 320000 + 1;
	}
	printf("\tMod de testare \n");
	printf("Vectorul de intrare :");
	for ( i = 0 ;i< n;i++)
		printf("%d ",v1[i]);
	printf("\n");
	printf("\n");

//StrandSort 
	printf("Strand Sort: ");
	sortareSS(v1,n,ok);
	printf("Count Strand Sort : %d \n",countS);
	printf("\n");

//Cocktail Sort
	printf("Cocktail Sort: ");
	SortareCS(v4,n,ok);
	printf("Count Cocktail Sort : %d", countC);
	printf("\n");
	printf("\n");

//Raxix Sort
	printf("Radix Sort: ");
	RadixS(v2,n,ok);
	printf("\n");
	printf("Count Radix Sort : %d\n", countR);
	printf("\n");

//Binary Tree Sort
	printf("Binary Tree Sort: ");
	BTreeSort(v3,n,ok);
	printf("\n");
	printf("Count Binary tree sort : %d\n", countB);
	printf("\n");

//Heap Sort
	printf("Heap Sort : ");
	SortareHS(v4,n,ok);
	printf("Counnt Heap Sort : %d ",countH);
	printf("\n");

	}

	if ( ok == 2 ){
	int *v1c, *v2c, *v3c;
	printf("\tMod de analiza \n");
/* Pentru fiecare sortare am declarat si alocat numararul necesar de vectori
deoarece odata cu apelul functiilor de sortare valorile lor raman sortate
datorita faptului ca vectorul este transmis automat prin referinta*/
	
	// alocari de memorie 
	n = 10;
	v1c = (int *) malloc(n * sizeof(int));
	for ( i = 0;i< n;i++){
		v1c[i] = rand() % 320000 + 1;
	}
//	functie predefinita pentru sortarea unui vector
	sortare(v1c,n);
	//	printf("%d ",v1c[i]);

	printf("Vector ordanat crescator cu 10 elemente : \n\n");
//StrandSort 
	sortareSS(v1c,n,ok);
	printf("Count Strand Sort : %d\n",countS);
	countS = 0;

//Cocktail Sort
	SortareCS(v1c,n,ok);
	printf("Count Cocktail Sort : %d\n", countC);
	countC = 0;
	
//Raxix Sort
	RadixS(v1c,n,ok);
	printf("Count Radix Sort : %d\n", countR);
	countR = 0;

//Binary Tree Sort
	BTreeSort(v1c,n,ok);
	printf("Count Binary tree sort : %d\n", countB);
	countB = 0;
	
//Heap Sort
	SortareHS(v1c,n,ok);
	printf("Count Heap Sort : %d\n",countH);
	countH = 0;
	printf("\n ");

	printf("Vector ordanat crescator cu 300 elemente : \n\n");

	n = 300;
	v2c = (int *) malloc(n * sizeof(int));
	for ( i = 0;i< n;i++){
		v2c[i] = rand() % 320000 + 1;
	}

//functia Bubble Sort
	sortare(v2c,n);
	
//StrandSort 
	sortareSS(v2c,n,ok);
	printf("Count Strand Sort : %d \n",countS);
	countS = 0;

//Cocktail Sort
	SortareCS(v2c,n,ok);
	printf("Count Cocktail Sort : %d\n", countC);
	countC = 0;

//Raxix Sort
	RadixS(v2c,n,ok);
	printf("Count Radix Sort : %d\n", countR);
	countR = 0;

//Binary Tree Sort
	BTreeSort(v2c,n,ok);
	printf("Count Binary tree sort : %d\n", countB);
	countB = 0;

//Heap Sort
	SortareHS(v2c,n,ok);
	printf("Count Heap Sort : %d \n",countH);
	countH = 0;
	printf("\n");

	printf("Vector ordanat crescator cu 10000 elemente : \n\n");

	n = 10000;
	v3c = (int *) malloc(n * sizeof(int));
	for ( i = 0;i< n;i++){
		v3c[i] = rand() % 320000 + 1;
	}
//	functie predefinita pentru sortarea unui vector
	sortare(v3c,n);

//StrandSort 
	sortareSS(v3c,n,ok);
	printf("Count Strand Sort : %d \n",countS);
	countS = 0;
//Cocktail Sort
	SortareCS(v3c,n,ok);
	printf("Count Cocktail Sort : %d\n", countC);
	countC = 0;
//Raxix Sort
	RadixS(v3c,n,ok);
	printf("Count Radix Sort : %d\n", countR);
	countR = 0;

//Binary Tree Sort
	BTreeSort(v3c,n,ok);
	printf("Count Binary tree sort : %d\n", countB);
	countB = 0;

//Heap Sort
	SortareHS(v3c,n,ok);
	printf("Count Heap Sort : %d \n",countH);
	countH = 0;
	printf("\n");
	
	printf("Vector generat aleator cu 10 elemente : \n\n");
	int *v1g , *v2g, *v3g, *v4g, *v5g;
	n = 10;
	v1g = (int *)malloc(n * sizeof(int));
	v2g = (int *)malloc(n * sizeof(int));
	v3g = (int *)malloc(n * sizeof(int));
	v4g = (int *)malloc(n * sizeof(int));
	v5g = (int *)malloc(n * sizeof(int));
	for ( i = 0;i< n;i++){
		v1g[i] = rand() % 320000 + 1;
		v2g[i] = rand() % 320000 + 1;
		v3g[i] = rand() % 320000 + 1;	
		v4g[i] = rand() % 320000 + 1;
		v5g[i] = rand() % 320000 + 1;
	}

//StrandSort 
	sortareSS(v1g,n,ok);
	printf("Count Strand Sort : %d\n",countS);
	countS = 0;

//Cocktail Sort
	SortareCS(v2g,n,ok);
	printf("Count Cocktail Sort : %d\n", countC);
	countC = 0;

//Raxix Sort
	RadixS(v3g,n,ok);
	printf("Count Radix Sort : %d\n", countR);
	countR = 0;
//Binary Tree Sort
	BTreeSort(v4g,n,ok);
	printf("Count Binary tree sort : %d\n", countB);
	countB = 0;
//Heap Sort
	SortareHS(v5g,n,ok);
	printf("Count Heap Sort : %d\n",countH);
	countH = 0;
	printf("\n");

	free(v1g);
	free(v2g);
	free(v3g);
	free(v4g);
	free(v5g);

	printf("Vector generat aleator cu 300 de elemente: \n\n"); 
	n = 300;

	v1g = (int *)malloc(n * sizeof(int));
	v2g = (int *)malloc(n * sizeof(int));
	v3g = (int *)malloc(n * sizeof(int));
	v4g = (int *)malloc(n * sizeof(int));
	v5g = (int *)malloc(n * sizeof(int));
	for ( i = 0;i< n;i++){
		v1g[i] = rand() % 320000 + 1;
		v2g[i] = rand() % 320000 + 1;
		v3g[i] = rand() % 320000 + 1;	
		v4g[i] = rand() % 320000 + 1;
		v5g[i] = rand() % 320000 + 1;
	}

//StrandSort 
	sortareSS(v1g,n,ok);
	printf("Count Strand Sort : %d \n",countS);
	countS = 0;

//Cocktail Sort
	SortareCS(v2g,n,ok);
	printf("Count Cocktail Sort : %d\n", countC);
	countC = 0;

//Raxix Sort
	RadixS(v3g,n,ok);
	printf("Count Radix Sort : %d\n", countR);
	countR = 0;
//Binary Tree Sort
	BTreeSort(v4g,n,ok);
	printf("Count Binary tree sort : %d\n", countB);
	countB = 0;
//Heap Sort
	SortareHS(v5g,n,ok);
	printf("Count Heap Sort : %d \n",countH);
	countH = 0;
	printf("\n");

	free(v1g);
	free(v2g);
	free(v3g);
	free(v4g);
	free(v5g);

	printf("Vector generat aleator cu 10000 de elemente: \n");
	printf("Timp de executie 1m pentru StrandSort \n\n");	
	n = 10000;

	v1g = (int *)malloc(n * sizeof(int));
	v2g = (int *)malloc(n * sizeof(int));
	v3g = (int *)malloc(n * sizeof(int));
	v4g = (int *)malloc(n * sizeof(int));
	v5g = (int *)malloc(n * sizeof(int));
	for ( i = 0;i< n;i++){
		v1g[i] = rand() % 320000 + 1;
		v2g[i] = rand() % 320000 + 1;
		v3g[i] = rand() % 320000 + 1;	
		v4g[i] = rand() % 320000 + 1;
		v5g[i] = rand() % 320000 + 1;
	}

//StrandSort 
	sortareSS(v1g,n,ok);
	printf("Count Strand Sort : %d \n",countS);
	countS = 0;

//Cocktail Sort
	SortareCS(v2g,n,ok);
	printf("Count Cocktail Sort : %d\n", countC);
	countC = 0;

//Raxix Sort
	RadixS(v3g,n,ok);
	printf("Count Radix Sort : %d\n", countR);
	countR = 0;

//Binary Tree Sort
	BTreeSort(v4g,n,ok);
	printf("Count Binary tree sort : %d\n", countB);
	countB = 0;

//Heap Sort
	SortareHS(v5g,n,ok);
	printf("Count Heap Sort : %d \n",countH);
	countH = 0;
	printf("\n");

	free(v1g);
	free(v2g);
	free(v3g);
	free(v4g);
	free(v5g);

	printf("Vector sortat descrescator cu 10 elemente: \n\n");
	int *v1d, *v2d, *v3d, *v4d, *v5d;
	n = 10;
	v1d = (int *)malloc(n * sizeof(int));
	v2d = (int *)malloc(n * sizeof(int));
	v3d = (int *)malloc(n * sizeof(int));
	v4d = (int *)malloc(n * sizeof(int));
	v5d = (int *)malloc(n * sizeof(int));
	for ( i = 0;i< n;i++){
		v1d[i] = rand() % 320000 + 1;
		v2d[i] = rand() % 320000 + 1;
		v3d[i] = rand() % 320000 + 1;	
		v4d[i] = rand() % 320000 + 1;
		v5d[i] = rand() % 320000 + 1;
	}
	sortareD(v1d,n);
	sortareD(v2d,n);
	sortareD(v3d,n);
	sortareD(v4d,n);
	sortareD(v5d,n);
//StrandSort 
	sortareSS(v1d,n,ok);
	printf("Count Strand Sort : %d \n",countS);
	countS = 0;

//Cocktail Sort
	SortareCS(v2d,n,ok);
	printf("Count Cocktail Sort : %d\n", countC);
	countC = 0;

//Raxix Sort
	RadixS(v3d,n,ok);
	printf("Count Radix Sort : %d\n", countR);
	countR = 0;
//Binary Tree Sort
	BTreeSort(v4d,n,ok);
	printf("Count Binary tree sort : %d\n", countB);
	countB = 0;
//Heap Sort
	SortareHS(v5d,n,ok);
	printf("Count Heap Sort : %d \n",countH);
	countH = 0;
	printf("\n");

	free(v1d);
	free(v2d);
	free(v3d);
	free(v4d);
	free(v5d);
	
	printf("Vector sortat descrescator cu 300 de elemente: \n\n");
	n = 300;

	v1d = (int *)malloc(n * sizeof(int));
	v2d = (int *)malloc(n * sizeof(int));
	v3d = (int *)malloc(n * sizeof(int));
	v4d = (int *)malloc(n * sizeof(int));
	v5d = (int *)malloc(n * sizeof(int));
	for ( i = 0;i< n;i++){
		v1d[i] = rand() % 320000 + 1;
		v2d[i] = rand() % 320000 + 1;
		v3d[i] = rand() % 320000 + 1;	
		v4d[i] = rand() % 320000 + 1;
		v5d[i] = rand() % 320000 + 1;
	}
	sortareD(v1d,n);
	sortareD(v2d,n);
	sortareD(v3d,n);
	sortareD(v4d,n);
	sortareD(v5d,n);
//StrandSort 
	sortareSS(v1d,n,ok);
	printf("Count Strand Sort : %d \n",countS);
	countS = 0;

//Cocktail Sort
	SortareCS(v2d,n,ok);
	printf("Count Cocktail Sort : %d\n", countC);
	countC = 0;

//Raxix Sort
	RadixS(v3d,n,ok);
	printf("Count Radix Sort : %d\n", countR);
	countR = 0;

//Binary Tree Sort
	BTreeSort(v4d,n,ok);
	printf("Count Binary tree sort : %d\n", countB);
	countB = 0;

//Heap Sort
	SortareHS(v5d,n,ok);
	printf("Count Heap Sort : %d \n",countH);
	countH = 0;
	printf("\n");

	free(v1d);
	free(v2d);
	free(v3d);
	free(v4d);
	free(v5d);

	printf("Vector sortat descrescator cu 10000 de elemente: \n");
	printf("Timp de rulare aproximativ 1m pentru StrandSort \n\n");
	n = 10000;
//alocare memorie pentru fiecare vector

	v1d = (int *)malloc(n * sizeof(int));
	v2d = (int *)malloc(n * sizeof(int));
	v3d = (int *)malloc(n * sizeof(int));
	v4d = (int *)malloc(n * sizeof(int));
	v5d = (int *)malloc(n * sizeof(int));

//initializare cu valori aletorii
	for ( i = 0;i< n;i++){
		v1d[i] = rand() % 320000 + 1;
		v2d[i] = rand() % 320000 + 1;
		v3d[i] = rand() % 320000 + 1;	
		v4d[i] = rand() % 320000 + 1;
		v5d[i] = rand() % 320000 + 1;
	}
	sortareD(v1d,n);
	sortareD(v2d,n);
	sortareD(v3d,n);
	sortareD(v4d,n);
	sortareD(v5d,n);

//StrandSort 
	printf("Functia de sortare Strand Sort are un timp de executie de aproximativ 5 m si i-am oprit executia pentru a nu ingreuna programul\n");
	//sortareSS(v3d,n,ok);
	printf("Count Strand Sort : %d \n",countS);
	countS = 0;

//Cocktail Sort
	SortareCS(v3d,n,ok);
	printf("Count Cocktail Sort : %d\n", countC);
	countC = 0;

//Raxix Sort
	RadixS(v3d,n,ok);
	printf("Count Radix Sort : %d\n", countR);
	countR = 0;
//Binary Tree Sort
	BTreeSort(v4d,n,ok);
	printf("Count Binary tree sort : %d\n", countB);
	countB = 0;
//Heap Sort
	SortareHS(v5d,n,ok);
	printf("Count Heap Sort : %d \n",countH);
	countH = 0;
	printf("\n");

	free(v1d);
	free(v2d);
	free(v3d);
	free(v4d);
	free(v5d);
	
}
return 0;
}
