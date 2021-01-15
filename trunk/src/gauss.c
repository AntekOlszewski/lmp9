#include "gauss.h"
#include <tgmath.h>
/**
 * Zwraca 0 - elimnacja zakonczona sukcesem
 * Zwraca 1 - macierz osobliwa - dzielenie przez 0
 */
int eliminate(Matrix *mat, Matrix *b){

	int i, j, k, m, ielmax;
	double  tmp1, term, s, elmax;
	double *tmp;
	for (i = 0; i < mat->r - 1 ; i++) {
		ielmax = i;
		elmax = fabs(mat->data[i][i]);
       		for (m = i + 1; m < mat->r; m++) {
			if ( fabs(mat->data[m][i]) > elmax ) {
				elmax = fabs(mat->data[m][i]);
				ielmax = m;
			}		
		}
		if (elmax == 0) return 1;
		if (ielmax != i) {
			tmp = mat->data[i];
			mat->data[i] = mat->data[ielmax];
			mat->data[ielmax] = tmp;
			tmp1 = b->data[i][0];
			b->data[i][0] = b->data[ielmax][0];
			b->data[ielmax][0] = tmp1;
		}
		for (k = i + 1; k < mat->r; k++) {
			term = mat->data[k][i] / mat->data[i][i];
			for (j = 0; j < mat->c; j++) {
		          	  mat->data[k][j] = mat->data[k][j] - term * mat->data[i][j]; 
				  b->data[k][0] = b->data[k][0] - term * b->data[i][0];
			}
	        }
	}
        return 0;
}
