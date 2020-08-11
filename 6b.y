%{
	#include<stdio.h>
	#include<stdlib.h>
	extern int yylex();
	extern int yytext();
	extern FILE *yyin;
	int num_identifiers = 0, num_keywords = 0, num_operators = 0;
%}
%token ID KEY OP
%%
input:KEY input {num_keywords++;}
     |ID input {num_identifiers++;}
	|OP input {num_operators++;}
	|KEY {num_keywords++;}
	|ID {num_identifiers++;}
	|OP {num_operators++;}
%%
int main(int argc, char** argv){
	FILE *myfile = fopen(argv[1], "r");
	if(!myfile){
		printf("Cant Open File\n");
		return -1;
	}
	yyin = myfile;
	do{
		yyparse();
	}while(!feof(yyin));
	printf("Keywords: %d\n Identifiers:%d\n Operators:%d\n", num_keywords, num_identifiers, num_operators);
}

int yyerror(){
	printf("Invalid\n");
}
