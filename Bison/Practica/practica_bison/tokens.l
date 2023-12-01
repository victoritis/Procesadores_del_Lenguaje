/*
 * Título    	  : Minicompilador con Flex	Pila Abstracta
 * Descripción	: Programa en BISON para obtener un compilador que traduzca un lenguaje
 *		  de alto nivel a código de máquina de pila abstracta. Esta parte en concreto
 *	 	  se encarga de generar tokens mediante el texto que analiza
 * Autor    	  : Victor Gonzalez del Campo
 * Fecha      	: 28-11-2023
 * Versión    	: v 1.0
 * Asignatura 	: Procesadores del Lenguaje
 * Entrega    	: Práctica 3 Bison(flex)
 *
 */



%{
//Incluimos cabeceras
#include "y.tab.h"
%}

%%


[ \t\n\r]+             { /* Ignorar espacios en blanco y saltos de li­nea */ }


/* Estos seran los tokens que ira devolviendo flex para pasarselos a Bison */

"while"                { return WHILE; }
"if"                   { return IF; }
"else"                 { return ELSE; }
"print"                { return PRINT; }
"read"                 { return READ; }
"do"                   { return DO; }
"for"                  { return FOR; }
"from"                 { return FROM; }
"to"                   { return TO; }
"by"                   { return BY; }
"<:"                   { return ASIG; }
"+="                   { return ADD_ASIG; }
"-="                   { return SUB_ASIG; }
"*="                   { return MUL_ASIG; }
"/="                   { return DIV_ASIG; }

"+"                    { return ADD; }
"-"                    { return SUB; }
"*"                    { return MUL; }
"/"                    { return DIV; }

"("                    { return IPAREN; }
")"                    { return DPAREN; }
";"                    { return PUNTO_COMA; }
"{"                    { return ICOR; }
"}"                    { return DCOR; }

[0-9]+                 { yylval.num = atoi(yytext); return NUM; }

[a-zA-Z_][a-zA-Z0-9_]*  { yylval.str = strdup(yytext); return ID; }

"#"[^\n]*             { /* Ignorar comentarios */ }

.                      { /* Caracteres no reconocidos */ }

%%
//iniciamos el analizador lexico
int yywrap() {
    return 1;
}
