#include "gauss.h"
#include <stdio.h>
#include "mat_io.h"
/**
 * Zwraca 0 - elimnacja zakonczona sukcesem
 * Zwraca 1 - macierz osobliwa - dzielenie przez 0
 */
int eliminate(Matrix *mat, Matrix *b){
	int i, j, k;
	double  term, s;
	printf("pocz gausa");
    	for (i = 0; i < mat->r -1; i++) {
	    if ( mat->data[i][i] == 0 ) return 1;
            for (k = i + 1; k < mat->r; k++) {
		    term = mat->data[k][i] / mat->data[i][i];
		    for (j = 0; j < mat->c; j++){
                	    mat->data[k][j] = mat->data[k][j] - term * mat->data[i][j]; 
	            }
		    b->data[k][0] = b->data[k][0] - term * b->data[i][0];
	    }
	}
	

        return 0;
}
