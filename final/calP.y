%{
    #include<stdio.h>
%}

%token Number
%left '+' '-'
%left '*' '/' '%'
%left '(' ')'
 %%
A : e {printf("%d",$$);}
e : e '+' e {$$=$1+$3;}
| e '-' e {$$=$1-$3;}
| e '*' e {$$=$1*$3;}
| e '/' e {$$=$1/$3;}
| e '%' e {$$=$1%$3;}
| '(' e ')' {$$=$2;}
| Number {$$=$1;};
%%
int main(){
    printf("Enter an expression: ");
    yyparse();
    return 0;
}
int yyerror(){
    printf("invalid");
}