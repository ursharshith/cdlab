%option noyywrap
%{
    #include <stdio.h>
    int i=0,j=0;
%}

%%
[0-9]+ {printf("Integer Number\n");i++;}
[0-9]+"."[0-9]+ {printf("\nDecimal numbers\n");j++;}

%%

int main(){
    yylex();
    {printf("Integer Numbers:%d and Decimal Numbers:%d",i,j);}
}