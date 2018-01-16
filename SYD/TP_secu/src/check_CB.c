#include <stdio.h>
#include <string.h>

int main(int argc, char * argv[])
{
  char CB[9]; 
  char ISBN[11];
  unsigned int nb;
  unsigned int prix;
  int i;
  int sum=0;
  int OK=0;
  unsigned short tab[10]={0,0,0,0,0,0,0,0,0,0};
  FILE * fd;

  strlcpy(ISBN,argv[1],11);
  sscanf(argv[2],"%d",&nb);
  sscanf(argv[3],"%d",&prix);
  strlcpy(CB,argv[4],9);

  // Check CB : 8 numbers exactly and nothing else 

  if (strlen(argv[4])==8) {
    for (i=0;i<8;i++) {
      tab[CB[i]-'0']+=1;
    }
    for (i=0;i<10;i++) {
      sum+=tab[i];
    }
    if (sum==8) OK=1; 
  }

  if (OK==1) printf("good CB number !\n");
  else printf("bad CB number !\n");

  if (OK==1) {
    fd=fopen("./system/commands","a");
    fprintf(fd,"%-10s\t\t%d\t\t%d\t\t%s\n",ISBN,nb,prix,CB);
    fclose(fd);
    printf("Command recorded !\n");
  }
}

