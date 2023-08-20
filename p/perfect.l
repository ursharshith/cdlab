%{
#include <stdio.h>

int isPerfect(int num) {
    int sum = 0;
    for (int i = 1; i < num; i++) {
        if (num % i == 0) {
            sum += i;
        }
    }
    return (sum == num);
}
%}

%%
[0-9]+     {
                int num = atoi(yytext);
                if (isPerfect(num)) {
                    printf("%d is a perfect number.\n", num);
                } else {
                    printf("%d is not a perfect number.\n", num);
                }
            }
\n          /* ignore newline character */
.           /* ignore other characters */
%%
int yywrap(){};
int main() {
    yylex();
    return 0;
}