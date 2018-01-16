#include <stdlib.h>
#include <stdio.h>

void* allocation_matrix(int ncol, int nlign)
{
  int **matrix, *data;
  int   i, j;

  data = (int *)malloc(ncol * nlign * sizeof(int));

  if (data != NULL) {
    matrix = (int **)malloc(nlign * sizeof(int*));
    if (matrix != NULL) {
      for (i = 0 ; i < nlign ; ++i) {
	/* arithmetique sur pointeur */
	matrix[i] = data + i * ncol;
      }
    }
  }

  return matrix;
}

int main(int argc, char *argv[])
{
  int taille, i, j, nlign, ncol;
  int **matrix;

  if (argc > 2) {
    taille = atoi(argv[1]);
  } else {
    fprintf(stderr,
	    "Usage : %s <n> <0|1>, n entier\n"
	    "        si le deuxieme argument est a 0 : remplissage par colonne\n"
	    "        si le deuxieme argument est a 1 : remplissage par ligne\n",
	    argv[0]
            );
    return 1;
  }

  matrix = allocation_matrix(taille, taille);
  nlign = ncol = taille;

  if (atoi(argv[2]) == 0) {
    /* remplissage par colonne */
    printf("Remplissage de la matrice %d x %d par colonne\n", nlign, ncol);
    for (j = 0 ; j < nlign ; ++j)
      for (i = 0 ; i < ncol ; ++i)
	matrix[j][i] = 1;
  } else {
    /* remplissage par ligne */
    printf("Remplissage de la matrice %d x %d par lignes\n", nlign, ncol);
    for (i = 0 ; i < ncol ; ++i)
      for (j = 0 ; j < nlign ; ++j)
	matrix[j][i] = 1;
  }

  free(matrix[0]); /* libere les donnees */
  free(matrix); /* libere la matrice. */

  return 0;
}

