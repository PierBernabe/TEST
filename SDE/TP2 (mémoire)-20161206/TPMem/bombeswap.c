#include <stdlib.h>
#include <stdio.h>

#define GIGA 1024*1024*1024

int main(int argc, char* argv[]) {

  int nb, k, k1, k2, i1, i2;
  unsigned long int c; 

  if (argc > 1) {
    nb = 2 * atoi(argv[1]);
  } else {
    fprintf(stderr, "Usage : %s <n>, n entier petit: 1, 2, ...\n", argv[0]);
    return 1;
  }

  char* tab[nb]; 
  for (k = 0; k < nb; k++) {
    tab[k] = (char *) malloc(GIGA * sizeof(char)); 
  }
  fprintf(stdout, "Memoire allouee: %d Gio\n", nb); 

  c = 0; 
  while(1) {
    k1 = random()%(nb); 
    k2 = random()%(nb);
    i1 = random()%(GIGA); 
    i2 = random()%(GIGA);
    tab[k1][i1] = tab[k2][i2]; 
    tab[k2][i1] = tab[k1][i2]; 
    c += 2; 
    if ((c % 500) == 0)
      fprintf(stdout, "%lu eme affectation...\n", c); 
  }
  return 0; 

}
