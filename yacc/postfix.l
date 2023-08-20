%{
#include<stdio.h>
#include "postfix.tab.h"
extern int yylval;
%}
%%
[0-9]+ {yylval=atoi(yytext); return id;}
[+-/^()*] { return yytext[0];}
\n { return 0;}
%%
int yywrap(){ return 1;}