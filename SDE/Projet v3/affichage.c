#include <stdlib.h>
#include <stdio.h>
#include <sys/msg.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <signal.h>
#include "semaphore.h"

//Variable globale necessaire car impossible de passer un paramètre d'entré avec la reception d'un signal
int id;
char* pchar;
int mutex;
int mutex2;
int bddUtilisation;//indique si l'on a accès à la bdd
/************************************************
		       arret
*************************************************/
void arret(/*char* pchar,int mutex,int mutex2*/){
  printf("\n\n------------------------------------\n");
  printf("         Fermeture des IPC          \n");
  printf("------------------------------------\n");
  printf("Détachement mémoire partagée\n");
  sleep(2);
  down(mutex);
  pchar[1]='$';
  printf("Changement du 2eme caractère de la bdd par \"$\"\n");
  up(mutex);
  shmdt((char *)pchar);
  printf("------------------------------------\n");
  printf("     Fin du processus affichage     \n");
  printf("------------------------------------\n\n");
  exit(1);
}
/************************************************
	       Transmission d'arret
*************************************************/
void extinction(/*char* pchar,int mutex,int mutex2*/){
  printf("\n------------------------------------\n");
  printf("       Transmission d'arret         \n");
  printf("------------------------------------\n");
  sleep(2);
  if(bddUtilisation==0)down(mutex); 
  pchar[0]='%';
  up(mutex);
  printf("Changement du 1er caractère de la bdd par \"%\"\n");
  arret(/*pchar,mutex,mutex2*/);
}
/************************************************
	        fail attachement BDD
*************************************************/
void error(){
  printf("Erreur lors du rattachement à la BDD\n");
  printf("------------------------------------\n");
  printf("     Fin du processus affichage     \n");
  printf("------------------------------------\n\n");
  exit(1);
}
/************************************************
	         connexionBDD
*************************************************/
char* connexionBDD(){
  key_t cle_bdd=111;
  int id_bdd;
  char* pchar;
  if((id_bdd=shmget(cle_bdd, 400, 0666))==-1)
    error();

  if((pchar=(char*)shmat(id_bdd,0,0))==-1)
    error();
  else{
    printf("\nSegement correctement attaché\n");
    printf("------------------------------------\n");
    return pchar;
  }
}
/************************************************
	        Lecture de la BDD
*************************************************/
char* lectureBDD(/*char* pchar,int mutex2*/){
  int i,j,k;
  char tmp[20];
  printf("\n\n-----------------------------------------------");	
  printf("\nVols diponibles -> Nombre de places :\n");
  for(i=0;i<20;i++){
      for(k=0;k<20;k++){
        tmp[k]=pchar[i*20+k];
      }
      //Si place = 00 alors suppression
      if(tmp[18]=='0' && tmp[19]=='0'&& tmp[0]!='0'){
        for(k=0;k<18;k++){
          if(pchar[i*20+k]!='#') printf("%c", pchar[i*20+k]);
        }
        printf(" vol complet, SUPPRESSION");
        printf("\n");
        pchar[i*20]='0';
        up(mutex2);
      }
      //Sinon affichage
      else{
        if(tmp[0]!='0'){
          for(j=0;j<17 && tmp[j]!='#';j++){
            printf("%c",tmp[j]);
          }
	  if(j<8)printf("\t");	
          printf("\t->   %c%c\n",tmp[18],tmp[19]);
        }
      }
  }
  printf("\n-----------------------------------------------");	
}
/************************************************
	             main
*************************************************/
int main(){
  printf("------------------------------------\n");
  printf("       Processus Affichage          \n");
  printf("------------------------------------\n");

  signal(SIGINT,extinction);
  /*int */mutex=open_semaphore(101);
  /*int */mutex2=open_semaphore(102);
  /*char* */pchar=connexionBDD();
  while(1){		
    down(mutex);
    bddUtilisation=1;
    if(pchar[0]=='%') arret(/*pchar,mutex,mutex2*/);
    lectureBDD();
    up(mutex);
    bddUtilisation=0;
    sleep(3);
  }
}
