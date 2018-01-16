#include <stdio.h>
#include "TP1_function.h"
#define TAILLE_MAX_TRAME 64
#define MAX_NB_FIC 5
FILE *fic;

/*****************************************************************************/
/*                                                                           */
/* But : Demande à l'utilisateur, le fichier qu'il veut demultiplexer        */
/*       Jusqu'à ce que le nom de fichier soit valide                        */
/*                                                                           */
/*****************************************************************************/
void askFicName(char fic_name[]){
    for(;;){							//boucle infini
        printf("\nVeulliez saisir le nom du fichier que vous souhaitez demultiplexer\n ");
        scanf("%s",fic_name);
        if((fic=fopen(fic_name,"r")) == NULL){
            printf("\nnom de fichier incorrect\n");
        }
        else{
            break;
        }
    }
}
/*****************************************************************************/
/*                                                                           */
/* But : Supprimer les fichiers destinations déjà existant  		     	 */
/*                                                                           */
/*****************************************************************************/
void removeFicDest(){
   	int i;
	for(i=0;i<MAX_NB_FIC;i++){
	    char nom_fic[7];
	    sprintf(nom_fic, "f%d.txt",i);
            remove (nom_fic);
        }
}
/*****************************************************************************/
/*                                                                           */
/* But : Lecture d'une ligne du fichier source à chaque appel de la fonction */
/* Trame[]='\0' si endFile et ensuite le fichier source est fermé            */
/*                                                                           */
/*****************************************************************************/
void extractLigne(char trame[]){
    if((fgets(trame,TAILLE_MAX_TRAME,fic))==NULL){
        trame[0]='\0';
	fclose(fic);
	printf("\nFichier source fermé\n");
    }
    printf("%s",trame);
}
/****************************************************************************/
/*                                                                          */
/* But : Détermine la taille du tableau envoyer				   				*/
/* Return : La taille de la trame                                           */
/*                                                                          */
/****************************************************************************/
int sizeLigne(char trame[]){
    int i;
    for(i=0;trame[i]!='\0';i++);
    return i-2;
}
/*****************************************************************************/
/*                                                                           */
/* But : Vérifie que le checksum est valide				  					 */
/* Return : 1 si oui et 0 sinon                                              */
/*                                                                           */
/*****************************************************************************/
int verif_checksum(char trame[]){
    int taille=sizeLigne(trame);			//Appel de la fonction sizeLigne qui recupère la taille
    int checksum;
    switch(trame[taille-1]){
        case '1': checksum=1;break;
        case '2': checksum=2;break;
        case '3': checksum=3;break;
        case '4': checksum=4;break;
        case '5': checksum=5;break;
        case '6': checksum=6;break;
        case '7': checksum=7;break;
        case '8': checksum=8;break;
        case '9': checksum=9;break;
        case 'A': checksum=10;break;
        case 'B': checksum=11;break;
        case 'C': checksum=12;break;
        case 'D': checksum=13;break;
        case 'E': checksum=14;break;
        case 'F': checksum=15;break;
        case 'a': checksum=10;break;
        case 'b': checksum=11;break;
        case 'c': checksum=12;break;
        case 'd': checksum=13;break;
        case 'e': checksum=14;break;
        case 'f': checksum=15;break;
    }
    if((taille-2)%16==checksum) return 1; //Vérification de la valeur du checksum
    else return 0;
}
/*****************************************************************************/
/*                                                                           */
/* But : Vérifie que le 1er caractère est compris entre 1 et MAX_NB_FIC      */
/* Return : le n° fichier en char                                            */
/*                                                                           */
/*****************************************************************************/
char verifCaract1(char trame[]){
    int i,a=0;
    int b=(int)trame[0]-48;					//convertion du 1er caractère en int
    for(i=1;i<=MAX_NB_FIC;i++){
        if(b==i) a++;
    }
    int num_fic=trame[0];
    if(a==1){trame = strcpy(trame, trame + 1);return(num_fic);}				//Return : le n° fichier en char
    else return('0');						//Si le 1er caractère invalide indique le fichier 0
}
/****************************************************************************/
/*                                                                          */
/* But : Vérifie que la trame est au bon format				  				*/
/* Return : le n° fichier en char		                            		*/
/*                                                                          */
/****************************************************************************/
char verif_trame(char trame[]){
    if(verif_checksum(trame)==1)			//appel verif_checksum qui retoune 1 si le checksum est valide
        return verifCaract1(trame);			//Return : le n° fichier en char
    else
        return('0');						//Si checksum invalide indique le fichier 0
}
/****************************************************************************/
/*                                                                          */
/* But : Ouvre le fichier destination en fonction du paramètre num_fic      */
/* 	 Ecrit la trame vérifier et formaté dans celui-ci	            		*/
/*                                                                          */
/****************************************************************************/
void writeTrame(char num_fic,char trame[]){
    FILE *fic_dest;
    char fic_name[7];
    sprintf(fic_name, "f%c.txt", num_fic);
    if((fic_dest=fopen(fic_name,"a")) != NULL){
        printf("Fichier ouvert : %s\n\n",fic_name);
        fputs(trame,fic_dest);
        fputs("\n",fic_dest);
        fclose(fic_dest);
    }
    else{
        printf("Erreur lors de l'ouverture du fichier %s\n\n",fic_name);
    }
}
/****************************************************************************/
/*                                                                          */
/* But : Formatage de la trame                               		    	*/
/*                                                                          */
/****************************************************************************/
int traitementTrame(char trame[],char trame_formater[]){
    int taille=sizeLigne(trame),i;
    int reste=0;

    for(i=0;i<(taille-1) && i<7;i++){
        trame_formater[i]=trame[i];
    }
    for(i;i<7;i++){						//Ajoute des "?" si le message fait moins de 7 caractères
        trame_formater[i]='?';
        reste++;
    }
    trame = strcpy(trame, trame + 7);
    char checksum=(7-reste)+'0';	   //Pour finir ajoute à la fin le checksum en fonction du nombre de "?" ajoutés
    trame_formater[7]=checksum;		   //Le caractère de fin de chaine.
	trame_formater[8]='\0';

    if(reste==0) return 0;
    else return 1;
}
/****************************************************************************/
/*                                                                          */
/* But : afficher le (nombre de trames rejetées/ nombre de trames rejetées) */
/*                                                                          */
/****************************************************************************/
void rapport(){

    char trame[TAILLE_MAX_TRAME];
	char fic_name[7];
	int i,nb_trame_fic=0,trames_rejetees=0,trames_total=0;

	for(i=1;i<=MAX_NB_FIC;i++){
		nb_trame_fic=0;
	    sprintf(fic_name, "f%d.txt",i);
	    if((fic=fopen(fic_name,"r")) != NULL){					//lecture du dernier caractère de chaque trame valide
			while((fgets(trame,TAILLE_MAX_TRAME,fic))!=NULL){   //pour connaitre le nombre d'octets
				nb_trame_fic+=(int)(trame[7])-48;
				trames_total++;		
			}
			fclose(fic);
	    }
		printf("\n%s -> %d octets",fic_name,nb_trame_fic);
		nb_trame_fic=0;
	}

	//Count trames erronéés
	if((fic=fopen("f0.txt","r")) != NULL){
		while((fgets(trame,TAILLE_MAX_TRAME,fic))!=NULL){
				trames_total++;trames_rejetees++;	
		}
		fclose(fic);
	}
	float ratio=((float)trames_rejetees/(float)trames_total);
	printf("\n Ratio = %f \n",ratio);

}

