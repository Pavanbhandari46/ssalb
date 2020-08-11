%{
	#include "y.tab.h"
	extern int yylval;
%}
%%

[+|-|/|*|=|>|<] {printf("Operation is %s\n", yytext);return OP;}
"int"|"char"|"float"|"bool"|"void"|"for"|"printf"|"do"|"while"|"if"|"else"|"return" {printf("Keyword is %s\n", yytext); return KEY;}
[a-zA-z][A-Za-z0-9]+ {printf("Identifier is %s\n", yytext); return ID;}
"\t" ;
. ;
%%
