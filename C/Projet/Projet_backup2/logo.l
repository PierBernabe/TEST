%{
#include<stdio.h>
#include "node.h"
#include"logo.tab.h"
%}

%%

FORWARD		return FORWARD;
RIGHT		return RIGHT;
LEFT		return LEFT;
REPEAT		return REPEAT;
[0-9]+		yylval.nb=atoi(yytext);return NUMBER;
\[		return CROCHET_LEFT;
\]		return CROCHET_RIGHT;
\n		

%%