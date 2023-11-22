%{
#include "y.tab.h"
%}

%%

[ \t\n\r]+             { /* Ignorar espacios en blanco y saltos de línea */ }

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

int yywrap() {
    return 1;
}
