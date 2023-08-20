%{
#include <stdio.h>
#include <stdbool.h>

bool isPrime(int num) {
    if (num <= 1) {
        return false;
    }
    
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) {
            return false;
        }
    }
    
    return true;
}
%}

%%
[0-9]+     {
                int num = atoi(yytext);
                if (isPrime(num)) {
                    printf("%d is prime.\n", num);
                } else {
                    printf("%d is not prime.\n", num);
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