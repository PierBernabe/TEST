#include <stdlib.h>
#include <stdio.h>

#define MEGA 1024*1024

int main() {

  char a; 
  fprintf(stdout, "Tapez un caractere pour allouer un tableau \n");
  fscanf(stdin,"%c",&a);

  //allocation sur la pile de 4 Mio
  int tab[MEGA]; 

  fprintf(stdout, "Tableau alloue, tapez un caractere pour finir \n");
  fscanf(stdin,"%c",&a);

  return 0; 
}
