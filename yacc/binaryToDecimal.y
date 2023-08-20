%{
#include<stdio.h>
%}
%token ZERO ONE
%%
S : L    { printf("%d",$$);}
L : L B  { $$=$1*2+$2; }
  | B    { $$= $1; }
B : ZERO { $$=0; }
  | ONE  { $$=1; }
%%
int main(){
	printf("enter binary\n");
	yyparse();
}
int yyerror(char* e){
	printf("error %s",e);
}