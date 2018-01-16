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
RED 		yylval.color=yytext;return COLOR;
BLUE 		yylval.color=yytext;return COLOR;
GREEN 		yylval.color=yytext;return COLOR;
YELLOW 		yylval.color=yytext;return COLOR;
BLACK 		yylval.color=yytext;return COLOR;
BROWN 		yylval.color=yytext;return COLOR;
PINK 		yylval.color=yytext;return COLOR;
ALEACOLOR 	yylval.color=yytext;return COLOR;
[0-9]+		yylval.nb=atoi(yytext);return NUMBER;
\[		return CROCHET_LEFT;
\]		return CROCHET_RIGHT;
\n		

%%
