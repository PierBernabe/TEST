#include <stdlib.h>
#include <stdio.h>
#include <sys/msg.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <signal.h>
#include <string.h>
#include "semaphore.h"

//Variable globale necessaire car impossible de passer un paramètre d'entré avec la reception d'un signal
int id_BAL;
int mutex;
char *pchar;
int bddUtilisation;//indique si l'on a accès à la bdd
/************************************************
		       arret
*************************************************/

void arret(/*int id_BAL,int mutex,char *pchar*/){
  printf("------------------------------------\n");
  printf("         Fermeture des IPC          \n");
  printf("------------------------------------\n");
  printf("Fermeture de la BAL\n");
  msgctl(id_BAL, IPC_RMID, NULL);
  printf("Détachement mémoire partagée\n");
  down(mutex);
  pchar[2]='$';
  printf("Changement du 3eme caractère de la bdd par \"$\"\n");
  shmdt(pchar);
  up(mutex);
  printf("------------------------------------\n");
  printf("       Fin du processus agence      \n");
  printf("------------------------------------\n\n");
  exit(1);
}
/************************************************
	       Transmission d'arret
*************************************************/
void extinction(/*int id_BAL,int mutex,char *pchar*/){
  printf("------------------------------------\n");
  printf("       Transmission d'arret         \n");
  printf("------------------------------------\n");
  if(bddUtilisation==0)down(mutex);
  pchar[0]='%';
  up(mutex);
  printf("Changement du 1er caractère de la bdd par \"%\"\n");
  arret(/*id_BAL,mutex,pchar*/);
}
/************************************************
	           creationBAL
*************************************************/
/*int */creationBAL(){
  //int id_BAL;
  if((id_BAL=msgget(100, 0666|IPC_CREAT))==-1){
    printf("\nErreur lors de la création de la BAL\n\n");
    printf("------------------------------------\n");
    printf("       Fin du processus agence      \n");
    printf("------------------------------------\n\n");
    exit(1);
  }
  printf("BAL correctement créé\n");
  //return id_BAL;
}
/************************************************
	         connexionBDD
*************************************************/
/*char* */connexionBDD(/*int id_BAL,int mutex*/){
  key_t cle_bdd=111;
  int id_bdd;
  //char* pchar;
  if((id_bdd=shmget(cle_bdd, 400, 0666))==-1){
    printf("Erreur lors du rattachement à la BDD\n");
    arret(/*id_BAL,mutex,pchar*/);
  }

  if((pchar=(char*)shmat(id_bdd,0,0))==-1){
    printf("Erreur lors du rattachement à la BDD\n");
    arret(/*id_BAL,mutex,pchar*/);
  }
  else{
    printf("\nSegement correctement attaché\n");
    printf("------------------------------------\n");
    /*return pchar;*/
  }
}
/************************************************
	       reponseUtilisateur
*************************************************/
void reponseUtilisateur(int valide, int pid){
  if(valide==0){
    printf("-----------------------------------\n");
    printf("        Commande impossible        \n");
    printf("-----------------------------------\n\n");
    kill(pid,SIGUSR2);
  }
  else{
    printf("-----------------------------------\n");
    printf("         Commande effectuée        \n");
    printf("-----------------------------------\n\n");
    kill(pid,SIGUSR1);
  }
}
/************************************************
	      Verification Commande
*************************************************/
int verificationCommande(/*char* pchar,*/char dest[17],int nb_demande){
  int valide=0,i,j,k,nb_dispo,reste;
    char tmp[20],nb[2];

    for(i=0;i<20;i++){
      for(k=0;k<20;k++){
        tmp[k]=pchar[i*20+k];
      }
      j=0;k=0;		
      while(tmp[k]!='#' && dest[k]!='\0'){
        if(tmp[k]==dest[k]){
          j++;
        }
        k++;
      }
      if(j==strlen(dest)){
        nb_dispo=10*(tmp[18]-'0')+(tmp[19]-'0');
        printf("Nombre de places avant commande : %d\n", nb_dispo);
        if(nb_dispo>=nb_demande){
	  //Modification du nombre de places
          reste=nb_dispo-nb_demande;
          printf("Commande possible\n");
          printf("Nombre de places après commande :%d\n",reste);
          pchar[i*20+18]=(reste/10)+'0';
          pchar[i*20+19]=(reste%10)+'0';
          valide++;
          break;
        }
      }
    }
    return valide;
}

/************************************************
	       	     main
*************************************************/
int main(){
  printf("------------------------------------\n");
  printf("         Processus Agence           \n");
  printf("------------------------------------\n");
  //Protection contre SIGINT
  signal(SIGINT, extinction);
  int valide;
  struct msgbuf {
    long mtype;
    char dest[17];
    int nb_places;
    int pid;
  } message;

  //initialisation des IPC
  /*int id_BAL=*/creationBAL();
  /*int mutex=*/open_semaphore(101);
  /*char *pchar=*/connexionBDD(/*id_BAL,mutex*/);//id_BAL et mutex sont envoyés pour les fermer si echec attachement bdd

  while(1){	
    //Récupération commande
    msgrcv(id_BAL, &message, sizeof(message), 1, 0);
    if(message.dest[0]=='0')extinction(/*id_BAL,mutex,pchar*/);
    printf("Requête recuperée :\n");
    printf("Vol : %s\nNombre de places demandées : %d\npid : %d\n\n",message.dest,message.nb_places,message.pid);
    
    down(mutex);
    bddUtilisation=1;
    valide=verificationCommande(/*pchar,*/message.dest,message.nb_places);
    up(mutex);
    bddUtilisation=0;
    reponseUtilisateur(valide,message.pid);
  }
  return 0;
}
