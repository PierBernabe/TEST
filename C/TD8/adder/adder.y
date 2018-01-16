%{
#include<stdio.h>
#include<string.h>

void yyerror(const char *str){
	fprintf(stderr,"error: %s\n",str);
}

int yywrap(){return 1;}
%}

%token NUMBER
%token PLUS

%%
SOM: EXPR{
	fprintf(stdout,"somme:%d\n",$1);
	$$=$1;
	}
EXPR: NUMBER{
	$$=$1;
	}
    | NUMBER PLUS EXPR{
	$$=$1+$3;	
	}
%%

main(){
	yyparse();
}

//page 285
