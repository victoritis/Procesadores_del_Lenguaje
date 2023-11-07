%{

int contador = 0;
int cuenta = 0;

%}


%%

hola	{
	yymore();
	//printf("%s", yytext);
}


adios	{
	printf("%s\n", yytext);
	printf("SI");
}

.|\n	{

		printf("%s\n", yytext);
		printf("SI");
}	


%%

int main(){
	yylex();
}
