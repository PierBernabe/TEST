#ifndef _NODE_H
#define _NODE_H

//#define NODE_ENTIER 0
#define NODE_FORWARD 1
#define NODE_LEFT 2
#define NODE_RIGHT 3
#define NODE_REPEAT 4

typedef struct node{
	int type;
	int val;
	struct node *successeur;
	struct node *sous_prog;
}NODE;
typedef NODE* instruction;
static NODE* LOGO;

NODE *creerNODE(int type,int valeur,NODE *successeur,NODE *sous_prog);
void ajoutNODEfin(NODE *root,NODE *suivant);
void calculeNewPosition(double position[2],double module,double argument);
void affichage(NODE *root);
void afficherLOGO(NODE *root,int i);
void afficheFormatSVG(NODE *root,double position[2],double angle,int repetition);
void generationFic(NODE *root);
void putsCommande(NODE *root,double position[2],double angle,int repetition);




#endif
