#include "gauss.h"

/**
 * Zwraca 0 - elimnacja zakonczona sukcesem
 * Zwraca 1 - macierz osobliwa - dzielenie przez 0
 */
int eliminate(Matrix *mat, Matrix *b){



	int i, j, k;
    	for (i = 0; i < mat->r; i++) {
            for (k = i + 1; k <= mat->r; k++) {
		    double  term = mat->dane[k][i] / mat->dane[i][i];//a[k][i] / a[i][i];
	            for (j = 0; j < mat->c+1; j++) {
                	    mat->dane[k][j] = mat->dane[k][j] - term * mat->dane[i][j]; //a[k][j]=a[k][j]-term*a[i][j];
	            }
	            b->dane[k][0] = b->dane[k][0] - term * mat->dane[i][j];
								        }
}
        return 0;
}
