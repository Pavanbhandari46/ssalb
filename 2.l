%{
	#include "y.tab.h"
	extern int yylval;
%}
%%
a {return A;}
b {return B;}
"\n" {return yytext[0];}
%%
