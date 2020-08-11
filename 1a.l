%{
	#include<stdio.h>
	int idt=0, opt=0, brkt=0;
%}

%%
[+ *] {opt++;}
[0-9] {idt++;}
[(] {brkt++;}
[)] {brkt--;}
%%

void main(){
	printf("Enter the expression: ");
	yylex();
	printf("No. of opt: %d\n",opt);
	printf("No. of idt: %d\n",idt);
	if((opt>=idt)|| brkt!=0 || idt==1)
		printf("Invalid expression\n");
	else
		printf("Valid expression\n");
}
