#include <stdlib.h>
#include <stdio.h>

#define MEGA 1024*1024

int main() {

  char a; 
  fprintf(stdout, "Tapez un caractere pour allouer un tableau \n");
  fscanf(stdin,"%c",&a);

  //allocation dynamique sur le tas de 4 Mio
  int* tab = malloc(MEGA*sizeof(int));

  fprintf(stdout, "Tableau alloue sur le tas, tapez un caractere pour finir \n");
  fscanf(stdin,"%c",&a);

  free(tab);

  return 0; 
}
