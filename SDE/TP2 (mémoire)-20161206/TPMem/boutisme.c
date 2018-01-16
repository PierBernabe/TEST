#include <stdlib.h>
#include <stdio.h>

/********************************************************************/
/*  Endianness                                                      */
/*  Tanguy Risset 2013, Tristan Roussillon 2016                     */
/********************************************************************/

int main(int argc, char *argv[])
{
  int i,ii,valeur,*addr;
  char *addr2;

  valeur=1313;
  addr=&valeur;

  fprintf(stdout,"La case memoire a l'adresse %p vaut %X en hexa et %d en decimal \n\n",addr,valeur,valeur);

  addr2=(char *)addr;
  fprintf(stdout,"Affichage des octets (en hexa):\n");
  for (i=0;i<4;i++)
    fprintf(stdout,"%p:  %2hhX\n",(addr2+i), *(addr2+i));
  fprintf(stdout,"\n");

  fprintf(stdout,"Affichage des bits:\n");
  for (i=0;i<4;i++) 
    {
      fprintf(stdout,"%p: ",(addr2+i));
      for (ii=0;ii<8;ii++)
	fprintf(stdout,"%d",(valeur>>(i*8+ii)&1));
      fprintf(stdout, "\n");
    }
  fprintf(stdout,"\n\n");

  return 0; 
}
