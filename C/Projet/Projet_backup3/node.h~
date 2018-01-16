#ifndef _NODE_H
#define _NODE_H

#define NODE_FORWARD 1
#define NODE_LEFT 2
#define NODE_RIGHT 3
#define NODE_REPEAT 4
#define NODE_COLOR 5

typedef struct node{
	int type;
	int val;
        char color[10];
	struct node *successeur;
	struct node *sous_prog;
}NODE;
typedef NODE* instruction;
static NODE* LOGO;
//gestion des NOEUDs
NODE *creerNODE(int type,int valeur,char* color,NODE *successeur,NODE *sous_prog);
NODE *ajoutNODEfin(NODE *root,NODE *suivant);
void liberationLISTE(NODE *root);
//Calcule new position
void calculeNewPosition(double position[3],double module);
//Affichage sur l'écran
void affichage(NODE *root);
void afficherLOGO(NODE *root,int i);
void afficheFormatSVG(NODE *root,double position[3],char color[10],int repetition);
//Ecriture dans un fichier svg
void generationFic(NODE *root);
void putsCommande(NODE *root,double position[3],char color[10],int repetition);

#endif
