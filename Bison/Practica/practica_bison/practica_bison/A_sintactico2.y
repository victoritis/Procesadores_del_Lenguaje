/*
 * Título    	  : Analizador lexico	Pila Abstracta
 * Descripción	: Programa en Flex para obtener un compilador que traduzca un lenguaje
 *		  de alto nivel a código de máquina de pila abstracta. Esta parte en concreto
 *		  se usa para analizar el texto y generar tokens mediante este.
 * Autor    	  : Victor Gonzalez del Campo
 * Fecha      	: 28-11-2023
 * Versión    	: v 1.0
 * Asignatura 	: Procesadores del Lenguaje
 * Entrega    	: Práctica 3 Bison(flex)
 *
 */


%{
//Librerías
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//FUNCIÓN OBTENERSIGUIENTENUMERO
int obtenerSiguienteLBL(){
	static int siguienteNumero = 0;
	return siguienteNumero++;
}
	

//Variables de bison
int yylex (void);

void yyerror(const char *s) {
    fprintf(stderr, "Error: %s\n", s);
}






%}
//Definición de los tipos de las variables
%union {
    int num; // Para números
    char* str; // Para cadenas/identificadores
    int lbl;
}


//Definicion de tokenes y no terminales
%token WHILE IF ELSE PRINT READ DO FOR FROM TO BY
%token ASIG ADD_ASIG SUB_ASIG MUL_ASIG DIV_ASIG
%token ADD SUB MUL DIV
%token IPAREN DPAREN PUNTO_COMA ICOR DCOR
%token <num>NUM <str>ID

%%

// Definiciones de la gramática

/* No terminales: stmts, stmt
 * Producciones: stmts -> stmt ';' stmts | stmt
 */
stmts:
    stmt PUNTO_COMA stmts
    | stmt
    ;
/* No terminales: loop, cond, assig, io
 * Producciones: stmt -> loop | cond | assig | io
 */
stmt:
    loop
    | cond
    | assig
    | io
    ;
    
/* No terminales: stmts, expr
 * Terminales: DO, WHILE, IPAREN, DPAREN
 * Producciones: loop -> DO stmts WHILE '(' expr ')' | FOR '(' ID FROM expr TO NUM [BY NUM]? ')' '{' stmts '}'
 * Funciones: obtenerSiguienteLBL()
 */
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
    
 /* No terminales: stmts, expr
 * Terminales: DPAREN, ICOR, DCOR, BY, NUM
 * Producciones: for2 -> ')' '{' stmts '}' | BY NUM ')' '{' stmts '}'
 * Funciones: obtenerSiguienteLBL()
 */   
for2:
    DPAREN ICOR stmts DCOR
    { printf("\tvalorid %s\n\tvalord %s\n\tmete 1\n\tadd\n\tasigna\n\tmete %d\n\tvalord %s\n\tsub\n\tsifalsovea LBL%d\n\tvea LBL%d\nLBL%d:\n", $<str>-8,$<str>-8,$<num>-3,$<str>-8,$<lbl>-1, $<lbl>-2,$<lbl>-1); }
    |
    BY NUM DPAREN ICOR stmts DCOR
        { printf("\tvalori %s\n\tvalord %s\n\tmete %d\n\tadd\n\tasigna\n\tmete %d\n\tvalord %s\n\tsub\n\tsifalsovea LBL%d\n\tvea LBL%d\nLBL%d:\n", $<str>-8,$<str>-8,$2,$<num>-3,$<str>-8,$<lbl>-1, $<lbl>-2,$<lbl>-1); }
    ;
    
    
 /* No terminales: stmts, expr
 * Terminales: IF, IPAREN, DPAREN, ICOR, DCOR, ELSE
 * Producciones: cond -> IF '(' expr ')' '{' stmts '}' cond2
 * Funciones: obtenerSiguienteLBL()
 */   
cond:

    IF IPAREN 
    { $<lbl>$ = obtenerSiguienteLBL(); }
    { $<lbl>$ = obtenerSiguienteLBL(); }
    expr DPAREN 
    { printf("\tsifalsovea LBL%d\n", $<lbl>3); } 
    ICOR stmts DCOR cond2
    ;
    
 /* No terminales: stmts
 * Terminales: ELSE, ICOR, DCOR
 * Producciones: cond2 -> ε | ELSE '{' stmts '}'
 * Funciones: obtenerSiguienteLBL()
 */   
cond2:
    { printf("LBL%d:\n", $<lbl>-7); }
    | 
    ELSE ICOR
    { printf("\tvea LBL%d\n",$<lbl>-6); } 
    { printf("LBL%d:\n", $<lbl>-7); } 
    stmts 
    { printf("LBL%d:\n", $<lbl>-6); } 
    DCOR
    ;

/* No terminales: stmts, expr
 * Terminales: PRINT, READ, ID, ASIG, ADD_ASIG, SUB_ASIG, MUL_ASIG, DIV_ASIG
 * Producciones: io -> PRINT expr | READ ID
 * assig -> ID '=' expr | ID '+=' expr | ID '-=' expr | ID '*=' expr | ID '/=' expr
 */
io:
    PRINT expr {printf("\tprint\n");}
    | READ ID {printf("\tread %s\n", $2);}
    ;
    
/* No terminales: expr
 * Terminales: ID, ASIG, ADD_ASIG, SUB_ASIG, MUL_ASIG, DIV_ASIG
 * Producciones: assig -> ID '=' expr | ID '+=' expr | ID '-=' expr | ID '*=' expr | ID '/=' expr
 * Descripción: Define una asignación o una operación de asignación compuesta (como adición o sustracción) sobre una variable.
 */
assig:
    ID ASIG { printf("\tvalori %s\n", $1); } expr { printf("\tasigna\n"); }
    | ID ADD_ASIG { printf("\tvalori %s\n\tvalord %s\n", $1, $1); } expr { printf("\tadd\n\tasigna\n"); }
    | ID SUB_ASIG { printf("\tvalori %s\n\tvalord %s\n", $1, $1); } expr { printf("\tsub\n\tasigna\n"); }
    | ID MUL_ASIG { printf("\tvalori %s\n\tvalord %s\n", $1, $1); } expr { printf("\tmul\n\tasigna\n"); }
    | ID DIV_ASIG { printf("\tvalori %s\n\tvalord %s\n", $1, $1); } expr { printf("\tdiv\n\tasigna\n"); }
    ;

    

/* No terminales: mult, expr1
 * Producciones: expr -> mult expr1
 * Descripción: Define una expresión, la cual puede ser una multiplicación o división seguida opcionalmente de una suma o resta.
 */
expr:
    mult expr1
    ;
/* No terminales: mult, expr1
 * Terminales: ADD, SUB
 * Producciones: expr1 -> '+' mult expr1 | '-' mult expr1 | ε
 * Descripción: Define la continuación de una expresión, permitiendo la suma o resta de múltiples términos.
 */
expr1:
    ADD mult { printf("\tadd\n"); } expr1 
    | SUB mult { printf("\tsub\n"); } expr1
    | 
    ;


/* No terminales: val, mult1
 * Producciones: mult -> val mult1
 * Descripción: Define una expresión de multiplicación o división, comenzando con un valor y siguiendo opcionalmente con más operaciones de multiplicación o división.
 */
mult:
    val mult1
    ;


/* No terminales: val, mult1
 * Terminales: MUL, DIV
 * Producciones: mult1 -> '*' val mult1 | '/' val mult1 | ε
 * Descripción: Continuación de una expresión de multiplicación o división, permitiendo múltiples operaciones sucesivas.
 */
mult1:
     MUL val { printf("\tmul\n"); } mult1
    |  DIV val { printf("\tdiv\n"); } mult1
    | 
    ;
    
    
/* No terminales: expr
 * Terminales: NUM, ID, IPAREN, DPAREN
 * Producciones: val -> NUM | ID | '(' expr ')'
 * Descripción: Define un valor, que puede ser un número, un identificador o una expresión entre paréntesis.
 */
val:
    NUM		{printf("\tmete %d\n", $1);}
    | ID	{printf("\tvalord %s\n", $1);}
    | IPAREN expr DPAREN
    ;

%%

/* Separador de sección */

/* FUNCIÓN MAIN
 * Descripción: Punto de entrada principal del programa.
 * Comportamiento: Evalúa si se abre un fichero o se lee desde el terminal.
 *                Si hay un fichero, lo abre y lo procesa; de lo contrario, lee desde el terminal.
 */
int main( int argc, char *argv[] ){
        
	if (argc > 1){ //Condición if que evalua si se abre un fichero o por el terminal
		extern FILE *yyin;
		++argv;
		yyin = fopen( argv[0], "r" ); //Abre el fichero en modo lectura
		if(!yyin) { //Condición if que evalua si se abre correctamente el fichero
			fprintf(stderr, "Ha ocurrido un error al intentar abrir el fichero. %s\n", argv[1]);
			exit(1);
		}
		yyparse();
		printf("\n");
	}else{
	        yyparse ();
	        printf("\n");
	        return 0;
        }
}


