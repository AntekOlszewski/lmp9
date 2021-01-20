#include "gauss.h"
#include "backsubst.h"
#include "mat_io.h"
#include <stdlib.h>
#include <stdio.h>


int main(int argc, char ** argv) {
	int res;
 	Matrix * A = readFromFile(argv[1]);
	Matrix * b = readFromFile(argv[2]);
	Matrix * x;

	if (A == NULL) {
		printf("Problem z formatem macierzy A.\n");       
		return -1;
	}
	if (b == NULL) {
		printf("Problem z formatem macierzy B\n");
		return -2;
	}
	printToScreen(A);
	printToScreen(b);

	res = eliminate(A,b);
	if (res == 1)
	{
		printf("Macierz osobliwa\n");
		return 1;
	}
	else if(res == 2)
	{
		printf("Macierz niekwadratowa.\n");
		return 1;
	}
	else if(res == 3)
	{
		printf("Liczba wierszy macierzy A jest rozna od liczby wierszy macierzy B\n");
		return 1;
	}
	}
	x = createMatrix(b->r, 1);
	if (x != NULL) {
		if ((res = backsubst(x,A,b)) != 1){
			printf("Blad dzielenia przez 0.\n");
			return 1;
		}
		printToScreen(x);
	  freeMatrix(x);
	} else {
					fprintf(stderr,"Błąd! Nie mogłem utworzyć wektora wynikowego x.\n");
	}

	freeMatrix(A);
	freeMatrix(b);

	return 0;
}
