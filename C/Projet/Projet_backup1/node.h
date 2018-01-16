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
typedef NODE* LOGO;


static NODE *root;

NODE *creerNODE(int type,int valeur,NODE *successeur,NODE *sous_prog);
void afficherNode(NODE *root,int i);

#endif
