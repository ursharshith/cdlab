%{
#include<stdio.h>
#include "evaluate.tab.h"
int yylval;
%}
%%
[0-9]+ { yylval=atoi(yytext); return id;}
[+-/^()*] { return yytext[0];}
\n { return id;}
%%
int yywrap(){ return 1;}

