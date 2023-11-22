%{
#include <stdio.h>
#include <stdlib.h>

int yylex (void);

%}

%union {
    int num; // Para números
    char* str; // Para cadenas/identificadores
}

%token WHILE IF ELSE PRINT READ DO FOR FROM TO BY
%token ASIG ADD_ASIG SUB_ASIG MUL_ASIG DIV_ASIG
%token ADD SUB MUL DIV
%token IPAREN DPAREN PUNTO_COMA ICOR DCOR
%token <num>NUM <str>ID

%%

// Definiciones de la gramática

stmts:
    stmt PUNTO_COMA stmts
    | stmt
    ;

stmt:
    loop
    | cond
    | assig
    | io
    ;

loop:
    DO stmts WHILE IPAREN expr DPAREN
    | FOR IPAREN ID FROM expr TO NUM DPAREN ICOR stmts DCOR
    | FOR IPAREN ID FROM expr TO NUM BY NUM DPAREN ICOR stmts DCOR
    ;

cond:
    IF IPAREN expr DPAREN ICOR stmts DCOR
    | IF IPAREN expr DPAREN ICOR stmts DCOR ELSE ICOR stmts DCOR
    ;
    


io:
    PRINT expr
    | READ ID
    ;

assig:
    ID ASIG { printf("\tvalori %s\n", $1); } { printf("\t\n"); } expr
    | ID ADD_ASIG expr
    | ID SUB_ASIG expr
    | ID MUL_ASIG expr
    | ID DIV_ASIG expr
    ;
    


expr:
    mult expr1
    ;

expr1:
    ADD mult { printf("\tadd\n"); } expr1 
    | SUB mult { printf("\tsub\n"); } expr1
    | 
    ;



mult:
    val mult1
    ;



mult1:
     MUL { printf("\tmul\n"); } val
    |  DIV { printf("\tdiv\n"); } val
    | 
    ;

val:
    NUM		{printf("\n\tmete %d", $1);}
    | ID	{printf("\n\tvalord %d", $1);}
    | IPAREN expr DPAREN
    ;

%%

//FUNCIÓN MAIN
int main( int argc, char *argv[] ){
        
	if (argc > 1){ //Condición if que evalua si se abre un fichero o por el terminal
		extern FILE *yyin;
		++argv;
		yyin = fopen( argv[0], "r" ); //Abre el fichero en modo lectura
		if(!yyin) { //Condición if que evalua si se abre correctamente el fichero
			fprintf(stderr, "Ha ocurrido un error al intentar abrir el fichero. %s\n", argv[1]);
			exit(1);
		}
	}else{
	        yyparse ();
	        printf("\n");
	        return 0;
        }
}
