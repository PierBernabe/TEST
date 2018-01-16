#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "utilSudoku.h"
	 
int  main(int argc,char *argv[])
{
  FILE *fich;
  char *nomFich ;
  int sudoku[9][9];
  /*
  if (argc!=2)
    {
      fprintf(stdout," usage: %s nomFich.txt \n",argv[0]);
      exit(-1);
    }
  nomFich=(char *)malloc(100*sizeof(char));
  strcpy(nomFich,argv[1]);
  */

  //Lire et afficher le sudoku----------------------------------------
  nomFich="sudokuInit.txt";
  fich=fopen(nomFich,"r");
  if (!fich)
    {
      fprintf(stderr,"erreur d'ouverture du fichier\n");
      exit(-1);
    }
  
  lireSudoku(fich,sudoku); 
  fprintf(stdout," sudoku lu: \n");
  ecrireSudoku(stdout,sudoku);
  //------------------------------------------------------------------

  int a=sudokuValide(sudoku);

  printf("\n");

  sudokuFacil(sudoku);

   return(0);
}
