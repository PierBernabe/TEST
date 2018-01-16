#include <stdlib.h>
#include <stdio.h>
int main(int argc, char *argv[])
{
  int i,valeur,tableau[64];
  int *addr;

  /* initialisation du tableau avec valeur*/
  valeur = 1313; 
  for (i=0;i<64;i++)
    {
      tableau[i] = valeur;
    }

  fprintf(stdout,"tableau[0] est à l'addresse %p et vaut %X en hexa et %d en decimal \n\n",
	  &(tableau[0]),tableau[0], tableau[0]);

  fprintf(stdout,"Entrez une addresse ou vous voulez lire (en hexa): ");
  fscanf(stdin,"%p",&addr);
  fprintf(stdout,"\nLa case memoire a l'addresse %p vaut %X en hexa et %d en decimal \n\n",addr,*addr,*addr);

  return 0; 
}
