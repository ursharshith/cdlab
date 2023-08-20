%{
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
%}
%token id '*' '+' '-' '/' '(' ')'
%left '+' '-'
%left '*' '/'
%left '^'
%left '(' ')'
%%
A : E		{ printf("ans=%d",$$);}
E : E '+' E	{ $$=$1+$3;}
  | E '-' E	{ $$=$1-$3;}
  | E '*' E	{ $$=$1*$3;}
  | E '/' E	{ $$=$1/$3;}
  | E '^' E	{ $$=pow($1,$3);}
  | '(' E ')'	{ $$=$2;}
  | id		{ $$=$1;}
%%
int main(){
	printf("enter exp\n");
	yyparse();
}
int yyerror(char*c ){
	printf("error %s",c);
}
