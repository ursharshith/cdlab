%{
#include<stdio.h>
#include "binaryToDecimal.tab.h"
%}
%%
[0] { return ZERO;}
[1] { return ONE; }
. { return yytext[0];}
\n { return 0;}
%%
int yywrap(){ return 1;}