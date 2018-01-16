#include <stdio.h>
#include <stdlib.h>
#include "node.h"


/*--------------------------------------------------------         
                CREATION D'UN NOEUD
--------------------------------------------------------*/
NODE *creerNODE(int type,int valeur,NODE *successeur,NODE *sous_prog){
  NODE *x;

  x=(NODE *)malloc(sizeof(NODE));

  x->type=type;
  x->val=valeur;

  x->successeur=successeur;
  x->sous_prog=sous_prog;

  return (x);
}

/*--------------------------------------------------------         
                AFFICHAGE D'UN ARBRE
--------------------------------------------------------*/
void afficherNode(NODE *root,int i)
{
if(i==0){
  if (root==NULL) return;
  
  switch(root->type)
    {
    case  NODE_FORWARD:
      printf(" FORWARD %d \n",root->val);
      break;
   case  NODE_LEFT:
      printf(" LEFT %d \n",root->val);
      break;
   case  NODE_RIGHT:
      printf(" RIGHT %d \n",root->val);
      break;
   case  NODE_REPEAT:
      printf(" REPEAT %d [",root->val);
	  afficherNode(root->sous_prog,1);
	  printf("]\n");
      break;
    default:
      printf(" ? ");
      break;
    }
	if (root->successeur!=0)
    {
      afficherNode(root->successeur,0);
    }
}
else{
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
   case  NODE_REPEAT:
      printf(" REPEAT %d [",root->val);
	  afficherNode(root->sous_prog,1);
	  printf("]");
      break;
    default:
      printf(" ? ");
      break;
    }
	 if (root->successeur!=0)
    {
      afficherNode(root->successeur,1);
    }
	
}


}




