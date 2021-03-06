#include <stdlib.h>
#include <stdio.h>
#include <sys/msg.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <signal.h>
/************************************************
	               arret
*************************************************/
void arret(){
	printf("------------------------------------\n");
	printf("    Fin du processus utilisateur    \n");
	printf("------------------------------------\n");
	exit(1);
}
/************************************************
	       affichage réponse
*************************************************/
void Succes(){
	printf("-----------------------------------\n");
	printf("Réponse agence : Commande effectuée\n");
	printf("-----------------------------------\n\n");
}
void Fail(){
	printf("------------------------------------\n");
	printf("Réponse agence : Commande impossible\n");
	printf("------------------------------------\n\n");
}
/************************************************
	       Protection signaux
*************************************************/
void protectionSignal(){
	signal(SIGINT,arret);
	signal(SIGUSR1,Succes);
	signal(SIGUSR2,Fail);
}
/************************************************
	      Connexion à la BAL
*************************************************/
int ConnexionBAL(){
	int id_BAL;
	if ((id_BAL=msgget(100, 0666))==-1){
		printf("\nErreur de Connexion avec la boîte à lettre\n\n");
		arret();
	} 
	else{
		printf("\nConnexion à la BAL effectuée\n");
		return(id_BAL);
	}
}
/************************************************
	   suppression du buffer scanf
*************************************************/
void fpurge(FILE *fp){
	char c;
	while((c=fgetc(fp))!='\n' && c!=EOF){}
}
/************************************************
	           newCommande
*************************************************/
int newCommande(){
	char t='a';
	while(t!='o' && t!='O' && t!='n' && t!='N'){	
	    	printf("Voulez-vous effectuer une autre commande (O/N) ?\n");
	   	scanf("%c", &t);
		fpurge(stdin);
	}

	if(t=='o' || t=='O'){
		printf("\n\n------------------------------------------------------------------------\n");
		return 1;
	}
	else
		return 0;
}
/************************************************
	             main
*************************************************/
int main(){
	printf("------------------------------------\n");
	printf("       Processus Utilisateur        \n");
	printf("------------------------------------\n");
	int commande=1;	
	struct msgbuf {
		long mtype;
		char dest[17];
		int nb_places;
		int pid;
	} message;
	message.mtype=1;
	message.pid=getpid();
	//protection contre les signaux INT/USR1/USR2
	protectionSignal();

	//Connexion à la boîte à lettre
	int id_BAL=ConnexionBAL();
	
	while(commande){
    
		//Demande de la destination et du nombre de places
	  	printf("\nSaisir une destination :\n");
	  	scanf("%s",message.dest);
		message.nb_places=1000;	
	  	while((message.nb_places)>99){
	  		printf("\nSaisir un nombre de place inférieur à 100\n");
			message.nb_places=0;
	  		scanf("%d",&message.nb_places);
			fpurge(stdin);
	  	}
	  	printf("\nCommande de %d places pour %s, en cours de traitement ...\n\n",message.nb_places,message.dest);
	    	sleep(1);
		
		//envoie de la commande
	  	msgsnd(id_BAL, &message, sizeof(message), 0);
		
		//attente de la reponse d'agence	  	
		pause();
		
		commande=newCommande();
	}
        arret();
	return 0;
}
