%{
	#include<stdio.h>
	#include<stdlib.h>
	extern int yylex();
%}

%token ID
%left '+' '-'
%left '*' '/'

%%

expr:E {printf("%d\n",$1); return 0;}
E:E '+' E {$$=$1 + $3;}
 |E '-' E {$$=$1 - $3;}
 |E '*' E {$$=$1 * $3;}
 |E '/' E {$$=$1 / $3;}
 |'(' E')' {$$=$2;}
 |ID {$$=$1;}
 |;

%%

void main(){
	printf("Enter the expression: ");
	yyparse();
	printf("valid");
}

int yyerror(){
	printf("invalid");
}
