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
%token CROCHET_LEFT
%token CROCHET_RIGHT

%union{int nb;instruction logo;};

%type <nb> NUMBER
%type <logo> PROG INST 

%%

PROG: INST{
	     $$=$1;
	     LOGO=$$;
      }
    | PROG INST{
	     ajoutNODEfin($1,$2);
	     $$=$1;
	     LOGO=$$;
      };
	

INST: FORWARD NUMBER{
	   $$=creerNODE(NODE_FORWARD,$2,0,0);
      }
    | RIGHT NUMBER{
	   $$=creerNODE(NODE_RIGHT,$2,0,0);
      }
    | LEFT NUMBER{
	   $$=creerNODE(NODE_LEFT,$2,0,0);
      }
    | REPEAT NUMBER CROCHET_LEFT PROG CROCHET_RIGHT{
	   $$=creerNODE(NODE_REPEAT,$2,0,$4);
      };



%%

int main(void){
	yyparse();
        affichage(LOGO);
	generationFic(LOGO);
	return 0;
}

