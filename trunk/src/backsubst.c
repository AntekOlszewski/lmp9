#include "backsubst.h"
/**
 * Zwraca 0 - wsteczne podstawienie zakonczone sukcesem
 * Zwraca 1 - błąd dzielenia przez 0 (element na diagonali = 0)
 * Zwraca 2 - błąd nieprawidłowych rozmiarów macierzy
 */
int  backsubst(Matrix *x, Matrix *mat, Matrix *b) {
	int i, j;
	double wynik;
	if (mat->c != mat->r)
		return 2;
	if (mat->c != b->r)
		return 2;
	for (i = 0; i < x->c; i++)
	{
		if (mat->data[i][i] == 0)
			return 1;
	}
	for (i = mat->c - 1; i >= 0; i--)
	{
		wynik = b->data[i][0];
		for (j = mat->c - 1; j > i; j--)
		{
			wynik -= mat->data[i][j] * x->data[j][0];
		}
			wynik /= mat->data[i][j];
			x->data[i][0] = wynik;
	}
	return 0;
}


