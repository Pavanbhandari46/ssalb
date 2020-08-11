#include<stdio.h>
#include<string.h>

FILE *fp1, *fp2;
char res[3], arg1[3], op[3], arg2[3];

void main(){
	fp1=fopen("input.txt","r");
	fp2=fopen("output.txt","w");

	while(!feof(fp1)){
		fscanf(fp1,"%s%s%s%s",res,arg1,op,arg2);
		if(strcmp(op,"+")==0){
			fprintf(fp2,"\n\nLD R0,%s",arg1);
			fprintf(fp2,"\nLD R1,%s",arg2);
			fprintf(fp2,"\nADD R2,R0,R1");
			fprintf(fp2,"\nST %s,R2",res);
		}
		if(strcmp(op,"-")==0){
			fprintf(fp2,"\n\nLD R0,%s",arg1);
			fprintf(fp2,"\nLD R1,%s",arg2);
			fprintf(fp2,"\nSUB R2,R0,R1");
			fprintf(fp2,"\nST %s,R2",res);
		}
		if(strcmp(op,"*")==0){
			fprintf(fp2,"\n\nLD R0,%s",arg1);
			fprintf(fp2,"\nLD R1,%s",arg2);
			fprintf(fp2,"\nMUL R2,R0,R1");
			fprintf(fp2,"\nST %s,R2",res);
		}
		if(strcmp(op,"/")==0){
			fprintf(fp2,"\n\nLD R0,%s",arg1);
			fprintf(fp2,"\nLD R1,%s",arg2);
			fprintf(fp2,"\nDIV R2,R0,R1");
			fprintf(fp2,"\nST %s,R2",res);
		}
		if(strcmp(op,"=")==0){
			fprintf(fp2,"\n\nLD R0,%s",arg1);
			fprintf(fp2,"\nST %s,R0",res);
		}
	}
}

