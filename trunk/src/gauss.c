#include "gauss.h"
#include <tgmath.h>

int eliminate(Matrix *mat, Matrix *b){
	int i, j, k, r, l;
	double  term, val, tmp;
	if( mat->r != mat->c) { 
		return 2;
	}
	if (mat->r != b->r) {
		return 3;
	}
    	for (i = 0; i < mat->r -1; i++) {
	    r = i;
	    val = fabs(mat->data[i][i]);
	    for(l = i; l < mat->c; l++)
	    {
	    	if(fabs(mat->data[l][i]) > val)
		{
			r = l;
			val = fabs(mat->data[l][i]);
		}
	    }
	    if(val == 0)
	    	return 1;
	    for(l = 0; l < mat->r; l++)
	    {
	    	tmp = mat->data[i][l];
		mat->data[i][l] = mat->data[r][l];
		mat->data[r][l] = tmp;
	    }
	    tmp = b->data[i][0];
	    b->data[i][0] = b->data[r][0];
	    b->data[r][0] = tmp;
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
