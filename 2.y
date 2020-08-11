%{
	#include<stdio.h>
	#include<stdlib.h>
	extern int yylex();
%}
%token A B
%%
expr: E"\n"{printf("Accepted\n");return 0;}

E:A T B
 |B

T:A T
 |;
%%

void main(){
	printf("Enter Sequence: ");
	yyparse();
}

int yyerror(){
	printf("Invalid\n");
}
