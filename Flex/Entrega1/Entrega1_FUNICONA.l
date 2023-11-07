%{
#include <stdio.h>
#include <string.h>

char titulo[100] = "";
char form_larga[100] = "";
int cord_min = 0;
int cord_max = 0;
//int cordenada = 0;
int num_graficas = 0;
int max_num_coordenadas = 0;
char max_formula[100] = "";
char formula[100] = "";
char dominio[100] = "";
char cordenada[100];
%}

%x TIKZ
%x AXIS
%x PLOT
%x PLOT2D

%%

"\\begin{tikzpicture}"	{
    BEGIN TIKZ;
    printf("Comienzo de entorno tikzpicture\n");
}

<TIKZ>"\\end{tikzpicture}" {
    BEGIN INITIAL;
    printf("Fin de entorno tikzpicture\n");
}

<TIKZ>"\\begin{axis}" {
    BEGIN AXIS;
    printf("Inicio entorno Axis\n");
}

<AXIS>title=\{[^\}]+\} {
    /* Captura el contenido entre '{' y '}' en yytext */
    strncpy(titulo, yytext + 7 , yyleng - 8);
}

<AXIS>"\\end{axis}" {
    BEGIN TIKZ;
    printf("Fin entorno Axis\n");
}

<AXIS>"\\addplot" {
    BEGIN PLOT;
    printf("Inicio entorno Plot\n");
    num_graficas++;
}

<PLOT2D>domain[^:]+: {
    printf("%s\n", yytext);
    strncpy(cordenada, yytext + 7, yyleng - 8);
    int cord_min = atoi(cordenada);  // Convierte la cadena a un entero
    printf("%d\n", cord_min);
    BEGIN PLOT;
}

<PLOT>domain[^,]+, { 
    BEGIN(PLOT2D);  // Cambio al estado PLOT2D
    printf("INICIO PLOT 2D\n"); 
    char linea_actual[1024];
    strncpy(dominio, yytext + 7 , yyleng - 8);
    printf("%s\n", yytext);
    strcpy(linea_actual, yytext);
    yyless(strlen(linea_actual));
    
}

<PLOT>\{[^}]*\} {

    /* Captura el contenido entre '{' y '}' en yytext */
    yytext = yytext + 1;
    int length = yyleng - 2;
    strncpy(formula, yytext , length );
    if (strlen(formula) > strlen(max_formula)) {
    	// Copiar el valor de formula en max_formula
    	strcpy(max_formula, formula);
    }
}


<PLOT>; {
    /* Captura el contenido hasta encontrar un punto y coma dentro de plot */
    BEGIN AXIS;
    printf("Fin entorno Plot");
}

<PLOT>. {
    /* Captura el contenido dentro de axis */
    //printf("%s", yytext);
}



<*>. {
    /* Ignorar otros caracteres fuera de tikzpicture */
}

%%

int main() {
    yylex();
    
    printf("Título: %s\n", titulo);
    printf("Coordenada mínima: %d y máxima: %d\n", cord_min, cord_max);
    printf("El gráfico contiene %d gráficas/series \n", num_graficas);
    printf("La fórmula más larga es \"%s\"\n", max_formula);
    
    return 0;
}
