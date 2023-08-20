%{
#include<stdio.h>
%}
%token id '+' '-' '*' '/' '^' '(' ')'
%left '+' '-'
%left '*' '/'
%left '^'
%left '(' ')'
%%
A : E { printf("\n");}
E : E '+' E { printf("+");}
  | E '-' E { printf("-");}
  | E '*' E { printf("*");}
  | E '/' E { printf("/");}
  | E '^' E { printf("^");}
  | '(' E ')' {}
  | id { printf("%d",$1);}
%%
int main(){
	printf("enter exp\n");
	yyparse();
}
int yyerror(char* e){
	printf("error %s",e);
}