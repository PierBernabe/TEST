#include <stdlib.h>
#include <stdio.h>
#include <sys/msg.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <signal.h>
#include <string.h>
#include "semaphore.h"

int id_BAL;
int id_bdd;
key_t cle_bdd;
char *pchar;
int mutex;

void arret(){
  printf("\n-----Fermeture de la BAL-----\n");
  msgctl(id_BAL, IPC_RMID, NULL);
  printf("\n-----Détachement mémoire partagée-----\n");
  down(mutex);
  pchar[2]='$';
  up(mutex);
  shmdt(pchar);
  printf("\n-----Suppression semaphore bdd-----\n");
  //supprimersem(mutex);
  printf("\n-----Fin du processus agence-----\n");
  exit(1);
}

void extinction(){
  printf("------ Extinction de l'ensemble ------\n");
  printf("------ Transmission aux autres processus ------\n");
  printf("------ Arret agence ------\n");
  pchar[0]='%';
  up(mutex);
  arret();
}

void initialisationIPC(){
  //Initialisation BAL/mutex/BDD/Protection_SIGINT
  signal(SIGINT, extinction);
  if((id_BAL=msgget(100, 0666|IPC_CREAT))==-1){
    printf("\n------Erreur lors de la création de la BAL------");
    exit(1);
  }
  else printf("\n------BAL correctement créé------");

  mutex=open_semaphore(101);

  cle_bdd=111;
  if((id_bdd=shmget(cle_bdd, 400, 0666))==-1){
    printf("Erreur lors du rattachement à la BDD\n");
  }

  if((pchar=(char*)shmat(id_bdd,0,0))==-1){
    printf("\n------Erreur lors du rattachement------");
    exit(1);
  }

  else printf("\n------Segement correctement attaché------");
}
void reponseUtilisateur(int valide, int pid){
  if(valide==0){
    printf("------Commande impossible------\n");
    kill(pid,SIGUSR2);
  }
  else{
    printf("------Commande effectuée-------\n");
    kill(pid,SIGUSR1);
  }
}

int main(){
  printf("-----Processus Agence------\n\n");
  //Déclaration Variable
  //-------------------------------------------------------------------------------------------
  int valide,i,j,k,nb_demande,nb_places;
  char tmp[20],nb[2];
  struct msgbuf {
    long mtype;
    char dest[17];
    int nb_places;
    int pid;
  } message;

  initialisationIPC();


  //Traitement des requêtes utilisateur
  //-------------------------------------------------------------------------------------------
  while(1){	
    //récupération commande
    msgrcv(id_BAL, &message, sizeof(message), 1, 0);

    if(message.dest[0]=='0')extinction();

    printf("\nRequête recuperée :");
    printf("\nVol : %s\nNombre de places demandées : %d\npid : %d\n",message.dest,message.nb_places,message.pid);
    

    //Lecture et comparaison avec les vols disponibles
    //------------------------------------------------------------------------------------
    down(mutex);
    if(pchar[0]=='$') arret();
    
      
    valide=0;
    for(i=0;i<20;i++){
      for(k=0;k<20;k++){
        tmp[k]=pchar[i*20+k];
      }
      j=0;	
      k=0;		
      while(tmp[k]!='#' && message.dest[k]!='\0'){
        if(tmp[k]==message.dest[k]){
          j++;
        }
        k++;
      }
      if(j==strlen(message.dest)){
        nb_demande=10*(tmp[18]-'0')+(tmp[19]-'0');
        printf("Nombre de places avant commande : %d\n", nb_demande);
        if(nb_demande>=message.nb_places){
          nb_places=nb_demande-message.nb_places;
          printf("Commande possible\n");
          printf("Nombre de places après commande :%d\n",nb_places);
          pchar[i*20+18]=(nb_places/10)+'0';
          pchar[i*20+19]=(nb_places%10)+'0';
          valide++;
          break;
        }
      }
    }

    up(mutex);
    reponseUtilisateur(valide,message.pid);
  }

  return 0;
}
