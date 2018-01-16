#include <stdlib.h>
#include <stdio.h>
#include <sys/msg.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <signal.h>

void arret(){
	printf("\n-----Fin du processus utilisateur-----\n");
	exit(1);
}
void Succes(){
	printf("\nRéponse agence : Commande effectuée\n");
}
void Fail(){
	printf("\nRéponse agence : Commande impossible\n");
}
void protectionSignal(){
	signal(SIGINT,arret);
	signal(SIGUSR1,Succes);
	signal(SIGUSR2,Fail);
}

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
void fpurge(FILE *fp){
	char c;
	while((c=fgetc(fp))!='\n' && c!=EOF){}
}


int main(){
	printf("-----Processus Utilisateur------\n");
	protectionSignal();
	struct msgbuf {
		long mtype;
		char dest[17];
		int nb_places;
		int pid;
	} message;
	message.mtype=1;
	message.pid=getpid();
 	char test='o';
	int id_BAL=ConnexionBAL();
	while(test=='o' || test=='O'){
    
	  	printf("Saisir une destination :\n");
		
	  	scanf("%s",message.dest);
		message.nb_places=1000;	
	  	while((message.nb_places)>99){
	  		printf("\nSaisir un nombre de place inférieur à 100\n");
			message.nb_places=0;
	  		scanf("%d",&message.nb_places);
			fpurge(stdin);
	  	}
	  	printf("Commande de %d places pour %s, en cours de traitement ...\n",message.nb_places,message.dest);
	    	sleep(1);
	  	msgsnd(id_BAL, &message, sizeof(message), 0);
	  	pause();
		
		test='a';

		

		while(test!='o' && test!='O' && test!='n' && test!='N'){
			
	    		printf("Voulez-vous effectuer une autre commande (O/N) ?\n");
	   		scanf("%c", &test);
			fpurge(stdin);
			//printf("\ntest:%c\n",test);
		}
	}
        arret();

}
