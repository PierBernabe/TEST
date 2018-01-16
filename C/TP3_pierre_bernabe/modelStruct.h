#ifndef MODEL
#define MODEL

struct model_elem{
	int val;
	struct model_noeud *filsGauche;
	struct model_noeud *filsDroit;
};

typedef struct model_elem ELEMPILE;
typedef ELEMPILE *PILE;

#endif
