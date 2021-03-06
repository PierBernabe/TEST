%{
#include <stdio.h>
#include <string.h>
#include "node.h"


void yyerror(const char *str){
	fprintf(stderr,"error: %s\n",str);
}

int yywrap(){
	return 1;
}
%}

%token FORWARD
%token RIGHT
%token LEFT
%token REPEAT
%token NUMBER
%token COLOR
%token BLUE
%token RED
%token GREEN
%token YELLOW
%token BLACK
%token CROCHET_LEFT
%token CROCHET_RIGHT

//Declaration des types
%union{int nb;instruction logo;char* color;};

%type <nb> NUMBER
%type <logo> PROG INST RACINE
%type <color> COLOR 

%%
RACINE:PROG{
		LOGO=$1;
	};

PROG: INST{
	     $$=$1;     
      }
    | PROG INST{
	     $$=ajoutNODEfin($1,$2); //ajoute la nouvelle INST à la suite de la liste modélisant PROG
      };
	
INST: FORWARD NUMBER{
	   $$=creerNODE(NODE_FORWARD,$2,"",0,0);
      }
    | RIGHT NUMBER{
	   $$=creerNODE(NODE_RIGHT,$2,"",0,0);
      }
    | LEFT NUMBER{
	   $$=creerNODE(NODE_LEFT,$2,"",0,0);
      }
    | REPEAT NUMBER CROCHET_LEFT PROG CROCHET_RIGHT{
	   $$=creerNODE(NODE_REPEAT,$2,"",0,$4);//création d'une nouvelle node qui aura comme sous programme de la node
      }
    | COLOR{
	   $$=creerNODE(NODE_COLOR,0,$1,0,0);
      };
%%

int main(void){
	yyparse();
        affichage(LOGO);
	generationFic(LOGO);
	printf("\nSuppression de la liste :\n");
	liberationLISTE(LOGO);
	return 0;
}

