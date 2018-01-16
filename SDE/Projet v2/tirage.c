#include <stdlib.h>
#include <stdio.h>
#include <sys/msg.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <signal.h>
#include <unistd.h>
#include <string.h>
#include "semaphore.h"
#include "shmem.h"
#define TAILLE 400

int descpipe[2];
int mutex,mutex2;
char *attach;
key_t cle1,cle2;
int id;
void arret_ecrivain(){
  printf("------ Extinction de l'ensemble ------\n");
  printf("------ Transmission aux autres processus ------\n");
  printf("------ Arret agence ------\n");
  attach[0]=='$';
       //envoie d'un message dans la BAL
	int id_BAL=ConnexionBAL();
	struct msgbuf {
		long mtype;
		char dest[17];
		int nb_places;
		int pid;
	} message;
	message.mtype=1;
	message.dest[0]='0';
	msgsnd(id_BAL, &message, sizeof(message), 0);
        //-----------------------------------------------	


  
  while((attach[1]!='$') || (attach[2]!='$')){
    up(mutex);
    sleep(1);
    down(mutex);
  }
  up(mutex);
  printf("\n-----détachement bdd-----\n");
  shmdt((char*)attach);
  printf("\n-----Suppression bdd-----\n");
  shmctl(id,IPC_RMID,0);
  printf("\n-----Suppression des sémaphore-----\n");
  remove_semaphore(mutex);
  remove_semaphore(mutex2);
  printf("\n-----Suppression tube-----\n");
  close(descpipe[0]);
  printf("\n-----Fin du processus ecrivain-----\n");

  exit(1);
}

void arret_tirage(){
  printf("\n-----Fin du processus tirage-----\n");
  close(descpipe[1]);
  printf("\n-----Fin du processus tirage-----\n");
  exit(1);
}

//permet d'indiquer à agence qu'il doit s'éteindre
int ConnexionBAL(){
	int id_BAL;
	if ((id_BAL=msgget(100, 0666))==-1){
		printf("-----Connexion BAL fail-----\n");
		exit(1);
	} 
	else{
		printf("------Connexion effectuée-----\n");
		return(id_BAL);
	}
}

// Fonction générant un nombre aléatoire de place compris entre 1 et 99

int alea(){
  return (1 + (rand() % (99)));
}

// Fonction générant un nombre aléatoire entre 1 et 30 pour tirer au hasard une destination

int aleaDest(){
  return (rand() % (30));
}


int main(){
  int ecrivain,i,j;
  int nbPlaces,nbDest; // Variables utilisées lors du tirage
  char dest[21],destr[21];
  int tailleDest;
  int nbDiese;
  cle1=101;
  cle2=102;
  char tab[30][17]; // Tableau à double entrées contenant 30 destinations possibles

  // Lecture du fichier de destination, et ajout des destinations dans le tableau 'tab'

  FILE* fichier=fopen("destinations.txt", "r");
  if (fichier==NULL){
    printf("Echec ouverture du fichier des destinations\n");
  }
  else {
    for(i=0;i<30;i++){
      fgets(tab[i], 17, fichier);
    }
  }

  // Création du tube ordinaire

  if (pipe(descpipe)==-1) {
    printf("Erreur de création du pipe\n");
    exit(1);
  }

  // Fork -> création du fils Ecrivain 

  ecrivain=fork();
  if (ecrivain==-1){
    printf("Erreur création du fils\n");
    exit(1);
  }

  // Entré dans le processus Ecrivain

  if (ecrivain==0){
    signal(SIGINT,arret_ecrivain);
    // Processus Ecrivain ---------------------------------------------------------------------------------------------
    close(descpipe[1]);
    key_t cle_BDD=111;
    if((create_semaphore(cle1))==-1) {
      printf("Erreur création sémaphore 1 ! \n");
    }

    if((create_semaphore(cle2))==-1) {
      printf("Erreur création sémaphore 2 ! \n");
    }

    if((mutex=open_semaphore(cle1))==-1){
      printf("Erreur attachement sem 1\n");
    }
    if((mutex2=open_semaphore(cle2))==-1){
      printf("Erreur attachement sem 2\n");
    }
    if ((init_semaphore(mutex2, 20))==-1){
      printf("erreur init mutex 2\n");
    }
    if ((init_semaphore(mutex, 1))==-1){
      printf("erreur init mutex\n");
    }

    // Création de la mémoire partagé avec la cle 111

    if ((id=shmget(cle_BDD, TAILLE, 0666|IPC_CREAT))==-1){
      printf("Erreur lors de la création de la mémoire partagée !\n");
      exit(1);
    }
    else {
      // Attachement à la mémoire partagé
      attach=(char*)shmat(id, 0, 0);
    }
    for(i=0;i<400;i++){
      attach[i]='0';
    }
    while (1){
      down(mutex2);
      read(descpipe[0], &destr, 21); // Lecture du tube ordinaire

      down(mutex);
      if(attach[0]=='%'){
        kill(SIGINT, getppid());
        arret_ecrivain();
      }

      for(i=0;i<20;i++){
        if(attach[20*i]=='0'){
          printf("Ecriture dans la BDD : ");
          for(j=0;j<20;j++){
            attach[(20*i)+j]=destr[j];
            printf("%c", attach[20*i+j]);

          }
          printf("\n");
          break;
        }
      }
      up(mutex);
      sleep(2);
    }

  }  
  // Entré dans le processus tirage---------------------------------------------------------------------------------

  else {
    signal(SIGINT,arret_tirage);
    // Processus Tirage
    close(descpipe[0]);
    while(1){
      int k;   
      nbPlaces=alea(); // Génération du nombre de places
      nbDest=aleaDest();  // Tirage de la destination
      tailleDest=strlen(tab[nbDest]); // taille de la destination pour formatage du message

      for(k=0;k<tailleDest-2 && k<17;k++){

        dest[k]=tab[nbDest][k];
      }
      for(k;k<18;k++){
        dest[k]='#';
      }

      if(nbPlaces<10){
        dest[18]='0';
        dest[19]=nbPlaces+'0';
      }
      else{
        dest[18]=(nbPlaces/10)+'0';
        dest[19]=(nbPlaces%10)+'0';
      }
      dest[20]='\0';

      write(descpipe[1], dest, 21);  // Envoi du message dans le tube
    }
  }
}
