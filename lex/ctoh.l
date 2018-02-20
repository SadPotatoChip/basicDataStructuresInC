%option noyywrap

%{
	#include <stdlib.h>
	#include <string.h>

	FILE *outFile;
%}

%%
[a-zA-Z\*]+[ ]+[a-zA-z0-9]+[ ]*\([a-zA-Z0-9,*\. ]*\)\{	{
	char *replaced;
	replaced=strdup(yytext);
	int l=strlen(replaced);
	replaced[l-1]=';';
	fprintf(outFile,"%s\n",replaced);
}

[ \n\t]												{}
.													{}


%%


int main(int argc, char** argv){
	if(argc>=2){
		yyin=fopen(argv[1],"r");
		if(yyin==NULL){
			printf("cant open main file\n");
			exit(1);
		}
	}else{
		printf("wrong number of arguments\n");
		exit(1);
	}
	
	char *outName;
	outName=strdup(argv[1]);
	int outLen=strlen(outName);
	outName[outLen-1]='h';
	outFile=fopen(outName,"w");
	fclose(outFile);
	outFile=fopen(outName,"a");
	
	int i;
	for(int i=2;i<argc;i++){
		FILE *tmp;
		tmp=fopen(argv[i],"r");
		if(tmp==NULL){
			printf("cant open file (%s)\n",argv[i]);
			exit(1);
		}
		
		char buffer;
		while(EOF!=(buffer=fgetc(tmp))){
			fputc(buffer,outFile);
		}
		fprintf(outFile,"\n");
		
	}
	
	
	
	yylex();
	fclose(outFile);
	fclose(yyin);

	return 0;	
}
