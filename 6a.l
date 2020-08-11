%{
	#include<stdio.h>
	int comment=0;
%}
%X E F
%%
"//" {BEGIN F,comment++;}
<F>. ;
<F>"\n" {BEGIN 0;}
"/*" {BEGIN E,comment++;}
<E>. ;
<E>"\n" ;
<E>"*/" {BEGIN 0;}
%%

void main(int argc, char** argv){
	yyin = fopen(argv[1],"r");
	yyout = fopen(argv[2],"w");
	yylex();
	printf("No. of comments removed: %d\n",comment);
}

