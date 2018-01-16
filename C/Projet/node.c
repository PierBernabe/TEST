#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include "node.h"
#define POSITION_X 500
#define POSITION_Y 600
#define ANGLE 0
#define _USE_MATH_DEFINES

FILE *fic_dest;

/*--------------------------------------------------------         
                CREATION D'UN NOEUD
--------------------------------------------------------*/
//Cette fonction attend en paramètre d'entré :
//	- Type ( FORWARD / LEFT ...)
//      - Valeur ( distance / angle ...)
//	- Color contient un chaine de caractère ( NULL si type noeud != COLOR)
//	- Successeur 
//	- sous_prog utile pour une node REPEAT
NODE *creerNODE(int type,int valeur,char* color,NODE *successeur,NODE *sous_prog){
	NODE *x;
	char tmp[10];
	int i=0;
	while(color[i]!='\0'){
		tmp[i]=color[i];
		i++;
	}
	tmp[i]='\0';
	
	x=(NODE *)malloc(sizeof(NODE));//Allocation mémoire 

	//Initialisation
	x->type=type;
	x->val=valeur;
	  
	strcpy(x->color,tmp);;
	x->successeur=successeur;
	x->sous_prog=sous_prog;
	return (x);
}

/*--------------------------------------------------------         
                AJOUT D'UN NOEUD A LA FIN
--------------------------------------------------------*/
//attent une liste "root" et une liste "suivant" 
//puis ajoute la liste "suivant au successeur du dernier élément de root
NODE *ajoutNODEfin(NODE *root,NODE *suivant){
	NODE *x;
	x=root;
	
	//Boucle jusqu'au dernier element de la liste
	while(x->successeur!=NULL){
		x=x->successeur;
	}
	x->successeur=suivant;//Ajout du NODE suivant à la fin de root
	return root;
}
/*--------------------------------------------------------         
                  LIBERATION LISTE
--------------------------------------------------------*/
//Attend une liste et libère tous les éléments
//1 par 1 en partant du bas
//utilisation de la récursicité
void liberationLISTE(NODE *root){
	
	if(root==NULL)return;
	else {
		if(root->sous_prog!=NULL){
			printf("---------Sous Prog----------\n");
			liberationLISTE(root->sous_prog);
			printf("-------Fin Sous Prog--------\n");
		}
		liberationLISTE(root->successeur);
		printf("type : %d valeur : %d\n",root->type,root->val);
		free(root);
	}	
}
/*--------------------------------------------------------         
               CALCULE NEW POSITION
--------------------------------------------------------*/
//position 0 = x 
//position 1 = y
//position 2 = angle
//Cette fonction calcule la nouvelle position
void calculeNewPosition(double position[3],double module){
	position[0]+=module*cos((position[2]*M_PI/180));
	position[1]+=module*sin((position[2]*M_PI/180));
}


/************************************************************************************/
/*--------------------------------------------------------         
           AFFICHAGE LOGO / AFFICHAGE FORMAT SVG
--------------------------------------------------------*/
//fonction qui permet d'executer les fonctions :
//		- afficherLOGO
//		- afficherFormatSVG 
void affichage(NODE *root){
	double position[3]={POSITION_X,POSITION_Y,ANGLE};
        char color[10]="BLACK";
        printf("\n--------Affichage de LOGO---------\n");
	afficherLOGO(root,0);

	printf("\n--------Affichage format svg--------\n");
        printf("<?xml version=\"1.0\" encoding=\"utf-8\"?>\n<svg xmlns=\"http://www.w3.org/2000/svg\" version=\"1.1\" width=\"200\" height=\"200\">\n<title>LOGO</title>\n<desc>Du LOGO.</desc>\n<rect width=\"1000\" height=\"1000\" style=\"fill:rgb(255,255,255);stroke-width:3;stroke:rgb(0,0,0)\" />\n");
  	afficheFormatSVG(root,position,color,1);
        printf("</svg>");
        printf("\n-------------------------------------------------\n");
}

/*--------------------------------------------------------         
                AFFICHAGE D'UN LOGO
--------------------------------------------------------*/
//Affiche 1 par 1 les éléments de la liste et leur valeur
//la variable i permet de différencier les sous programmes
// i=1 => sous programme
void afficherLOGO(NODE *root,int i){
	  if (root==NULL) return;
	  
	  switch(root->type)
	    {
	    case  NODE_FORWARD:
	      printf(" FORWARD %d ",root->val);
	      break;
	   case  NODE_LEFT:
	      printf(" LEFT %d ",root->val);
	      break;
	   case  NODE_RIGHT:
	      printf(" RIGHT %d ",root->val);
	      break;
	   case  NODE_COLOR:
	      printf(" COLOR %s ",root->color);
	      break;
	   case  NODE_REPEAT:
	      printf(" REPEAT %d [",root->val);
	      afficherLOGO(root->sous_prog,1);
	      printf("]");
	      break;
	    default:
	      printf(" ? ");
	      break;
	    }
          if(i==0){printf("\n");}
	  if (root->successeur!=0)
	    {
	      afficherLOGO(root->successeur,i);
	    }
}

/*--------------------------------------------------------         
                AFFICHE FORMAT SVG
--------------------------------------------------------*/
//affiche à l'écran toutes les lignes qui vont êtes écrite au format dans le fichier
//"repetition" permet de gérer les REPEAT
void afficheFormatSVG(NODE *root,double position[3],char color[10],int repetition){
	NODE *tmp;
	int i;
	for(i=0;i<repetition;i++){
        tmp=root;
		while(tmp!=NULL){

		    switch(tmp->type)
		    {
			    case  NODE_FORWARD:
				  printf("<line x1=\"%lf\" y1=\"%lf\" ",position[0],position[1]);
				  calculeNewPosition(position,tmp->val);
				  printf("x2=\"%lf\" y2=\"%lf\" stroke=\"%s\" /> \n",position[0],position[1],color);
				  break;
			    case  NODE_LEFT:
				  position[2]-=(double)(tmp->val);
				  break;
			    case  NODE_RIGHT:
			      	  position[2]+=(double)(tmp->val);
			      	  break;
			    case  NODE_COLOR:
			      	  strcpy(color,tmp->color);

			      	  break;
			    case  NODE_REPEAT:
				  afficheFormatSVG(tmp->sous_prog,position,color,tmp->val);
			    	  break;
	 	    }
		    if(tmp->successeur!=NULL){
		    	  tmp=tmp->successeur;
		    }
		    else break;
		}	
	}
}
/************************************************************************************/
/*--------------------------------------------------------         
       CREATION FICHIER / ECRITURE EN-TETE ET PIED
--------------------------------------------------------*/
//Crée le fichier
//écriture en-tete
//lancement de la fonction putsCommande
//écriture balise fermante
void generationFic(NODE *root){
	
        double position[3]={POSITION_X,POSITION_Y,ANGLE};
	char color[10]="BLACK";

	if((fic_dest=fopen("Instruction.svg","w+")) != NULL){
		fputs("<?xml version=\"1.0\" encoding=\"utf-8\"?>\n<svg xmlns=\"http://www.w3.org/2000/svg\" version=\"1.1\" width=\"1000\" height=\"1000\">\n<title>LOGO</title>\n<desc>Du LOGO.</desc>\n<rect width=\"1000\" height=\"1000\" style=\"fill:rgb(255,255,255);stroke-width:3;stroke:rgb(0,0,0)\" />\n",fic_dest);
		putsCommande(root,position,color,1);
		fputs("</svg>",fic_dest);

		fclose(fic_dest);
	}
	else{
        	printf("Erreur lors de l'ouverture du fichier %s\n\n","Instruction.svg");
    	}
}

/*--------------------------------------------------------         
                ECRITURE DES COMMANDES DANS LE FIC
--------------------------------------------------------*/
//fonction exactement de la même manière que afficheFormatSVG
//mais écrit dans le fichier
void putsCommande(NODE *root,double position[3],char color[10],int repetition){
	NODE *tmp;
	int i;

	for(i=0;i<repetition;i++){
        tmp=root;
		while(tmp!=NULL){
		    switch(tmp->type){
		    case  NODE_FORWARD:
			  fprintf(fic_dest,"<line x1=\"%lf\" y1=\"%lf\" ",position[0],position[1]);
		          calculeNewPosition(position,tmp->val);
			  fprintf(fic_dest,"x2=\"%lf\" y2=\"%lf\" stroke=\"%s\" /> \n",position[0],position[1],color);
		          break;
		    case  NODE_LEFT:
		          position[2]-=(double)(tmp->val);
		          break;
		    case  NODE_RIGHT:
		      	  position[2]+=(double)(tmp->val);
		      	  break;
		    case  NODE_COLOR:
		      	  color=(tmp->color);
		      	  break;
		    case  NODE_REPEAT:
			  putsCommande(tmp->sous_prog,position,color,tmp->val);
		    	  break;
	 	    }
		    if(tmp->successeur!=NULL){
		    	  tmp=tmp->successeur;
		    }
		    else break;
		}	
	}
}
















