/*
 * Título    	  : Minicompilador con JavaCC	Pila Abstracta
 * Descripción	: Programa en Bison para obtener un compilador que traduzca un lenguaje
 *		  de alto nivel a código de máquina de pila abstracta.
 * Autor    	  : Victor Gonzalez del Campo
 * Fecha      	: 28-11-2023
 * Versión    	: v 1.0
 * Asignatura 	: Procesadores del Lenguaje
 * Entrega    	: Práctica 2 Javacc
 *
 */


%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//FUNCIÓN OBTENERSIGUIENTENUMERO
int obtenerSiguienteLBL(){
	static int siguienteNumero = 0;
	return siguienteNumero++;
}
	


int yylex (void);

void yyerror(const char *s) {
    fprintf(stderr, "Error: %s\n", s);
}






%}

%union {
    int num; // Para números
    char* str; // Para cadenas/identificadores
    int lbl;
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
    DO 
    { $<lbl>$ = obtenerSiguienteLBL();  printf("LBL%d:\n", $<lbl>$); }
    { $<lbl>$ = obtenerSiguienteLBL(); }
    stmts WHILE IPAREN expr DPAREN
    { printf("\tsifalsovea LBL%d\n", $<lbl>3); printf("\tvea LBL%d\n", $<lbl>2); printf("LBL%d:\n", $<lbl>3); }
    | FOR IPAREN ID FROM 
    {printf("\tvalori %s\n", $3);}
    expr TO NUM 
    { $<lbl>$ = obtenerSiguienteLBL(); } 
    { $<lbl>$ = obtenerSiguienteLBL();} 
    { printf("\tasigna\nLBL%d:\n", $<lbl>9); }
    for2
    ;
    
for2:

    DPAREN ICOR stmts DCOR

    { printf("\tvalorid %s\n\tvalord %s\n\tmete 1\n\tadd\n\tasigna\n\tmete %d\n\tvalord %s\n\tsub\n\tsifalsovea LBL%d\n\tvea LBL%d\nLBL%d:\n", $<str>-8,$<str>-8,$<num>-3,$<str>-8,$<lbl>-1, $<lbl>-2,$<lbl>-1); }
    |
    BY NUM DPAREN ICOR stmts DCOR
        { printf("\tvalori %s\n\tvalord %s\n\tmete %d\n\tadd\n\tasigna\n\tmete %d\n\tvalord %s\n\tsub\n\tsifalsovea LBL%d\n\tvea LBL%d\nLBL%d:\n", $<str>-8,$<str>-8,$2,$<num>-3,$<str>-8,$<lbl>-1, $<lbl>-2,$<lbl>-1); }
    ;
    
cond:

    IF IPAREN 
    { $<lbl>$ = obtenerSiguienteLBL(); }
    { $<lbl>$ = obtenerSiguienteLBL(); }
    expr DPAREN 
    { printf("\tsifalsovea LBL%d\n", $<lbl>3); } 
    ICOR stmts DCOR cond2
    ;
    
    
cond2:
    { printf("LBL%d:\n", $<lbl>-7); }
    | 
    ELSE ICOR
    { printf("\tvea LBL%d\n",$<lbl>-6); } 
    { printf("LBL%d:\n", $<lbl>-7); } 
    stmts 
    { printf("LBL%d:\n", $<lbl>-6); } 
    DCOR


io:
    PRINT expr {printf("\tprint\n");}
    | READ ID {printf("\tread %s\n", $2);}
    ;

assig:
    ID ASIG { printf("\tvalori %s\n", $1); } expr { printf("\tasigna\n"); }
    | ID ADD_ASIG { printf("\tvalori %s\n\tvalord %s\n", $1, $1); } expr { printf("\tadd\n\tasigna\n"); }
    | ID SUB_ASIG { printf("\tvalori %s\n\tvalord %s\n", $1, $1); } expr { printf("\tsub\n\tasigna\n"); }
    | ID MUL_ASIG { printf("\tvalori %s\n\tvalord %s\n", $1, $1); } expr { printf("\tmul\n\tasigna\n"); }
    | ID DIV_ASIG { printf("\tvalori %s\n\tvalord %s\n", $1, $1); } expr { printf("\tdiv\n\tasigna\n"); }
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
     MUL val { printf("\tmul\n"); } mult1
    |  DIV val { printf("\tdiv\n"); } mult1
    | 
    ;

val:
    NUM		{printf("\tmete %d\n", $1);}
    | ID	{printf("\tvalord %s\n", $1);}
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

