#include <stdlib.h>
#include <stdio.h>
#include <sys/msg.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <signal.h>
#include "semaphore.h"

//mettre shmctl(id,IPC_RMID,0); pour dire que le segment mémoire sera supprimé losque tout le monde ne l'utilisera plus


char *pchar;
int mutex;
int mutex2;
int id;

void arret(){
  printf("\n-----Détachement mémoire partagée-----\n");
  sleep(2);
  down(mutex);
  pchar[1]='$';
  up(mutex);
  shmdt((char *)pchar);
  printf("\n-----Suppression des sémaphore-----\n");
  //remove_semaphore(mutex);
  //remove_semaphore(mutex2);
  printf("\n-----Fin du processus affichage-----\n");
  exit(1);
}

void extinction(){
  printf("------ Extinction de l'ensemble ------\n");
  printf("------ Transmission aux autres processus ------\n");
  printf("------ Arret affichage ------\n");
  sleep(2);
  pchar[0]='%';
  up(mutex);
  arret();
}


int main(){
  printf("-----Processus Affichage------\n\n");

  //Déclaration Variable
  //-------------------------------------------------------------------------------------------
  int i,j,k;
  char tmp[20];

  //Initialisation mutex/mutex2/BDD/Protection_SIGINT
  //-------------------------------------------------------------------------------------------
  signal(SIGINT,extinction);

  mutex=open_semaphore(101);
  mutex2=open_semaphore(102);
  key_t cle=111;
  if((id=shmget(cle, 400, 0666))==-1){
    printf("Erreur lors du rattachement à la BDD\n");
  }
  if((pchar=(char*)shmat(id,0,0))==-1){
    printf("\n------Erreur lors du rattachement------");
    exit(1);
  }
  else printf("\n------Segement correctement attaché------");


  //Lecture BDD 
  //-------------------------------------------------------------------------------------------
  while(1){
    printf("\n-----------------------------------------------");	
    printf("\nVols diponibles -> Nombre de places :\n");		
    down(mutex);
    if(pchar[0]=='%') arret();
    for(i=0;i<20;i++){
      for(k=0;k<20;k++){
        tmp[k]=pchar[i*20+k];
      }

      if(tmp[18]=='0' && tmp[19]=='0'&& tmp[0]!='0'){
        for(k=0;k<18;k++){
          if(pchar[i*20+k]!='#') printf("%c", pchar[i*20+k]);
        }
        printf(" vol complet, SUPPRESSION");
        printf("\n");
        pchar[i*20]='0';
        up(mutex2);
      }
      else{
        if(tmp[0]!='0'){
          for(j=0;j<17 && tmp[j]!='#';j++){
            printf("%c",tmp[j]);
          }
          printf("  ->   %c%c\n",tmp[18],tmp[19]);
        }
      }
    }	
    up(mutex);
    printf("\n-----------------------------------------------");
    sleep(3);
  }
}
