%{
#include<stdio.h>
#include"adder.tab.h"
%}
%%
[0-9]+	yylval=atoi(yytext);return NUMBER;
\+	return PLUS;
\n
[\t]+
%%