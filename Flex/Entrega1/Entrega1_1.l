%{
#include <stdio.h>
#include <string.h>

char titulo[100] = "";
char form_larga[100] = "";
double cord_min;
double cord_max;
int num_graficas = 0;
char max_formula[100] = "";
char formula[100] = "";

%}

%x TIKZ
%x AXIS
%x PLOT
%x PLOT2D_MAX
%x PLOT2D_MIN
%x MIN_3D
%x MAX_3D

%%

"\\begin{tikzpicture}"	{
    BEGIN TIKZ;
}

<TIKZ>"\\end{tikzpicture}" {
    BEGIN INITIAL;
}

<TIKZ>"\\begin{axis}" {
    BEGIN AXIS;
}

<AXIS>title=\{([^\n]+)\n {
    /* Captura el contenido entre '{' y '}' en yytext */
    strncpy(titulo, yytext + 7 , yyleng - 10);
}

<AXIS>title=([^\n]+)\n {
    /* Captura el contenido del titulo en yytext */
    strncpy(titulo, yytext + 6 , yyleng - 8);
}

<AXIS>"\\end{axis}" {
    BEGIN TIKZ;
}

<AXIS>"\\addplot" {
    BEGIN PLOT;
    num_graficas++;
}

<AXIS>xmin= { 
    BEGIN MIN_3D;
}

<MIN_3D>[^,]+, {
    char Scordenada[100] = "";
    strncpy(Scordenada, yytext , yyleng - 1);
    double cordenada = atof(Scordenada);  // Convierte la cadena a un entero
    if( cordenada < cord_min ) {
    	cord_min = cordenada;
    }
    BEGIN AXIS;
}

<AXIS>xmax= { 
    BEGIN MAX_3D;
}

<MAX_3D>[^,]+, {
    char Scordenada[100] = "";
    strncpy(Scordenada, yytext , yyleng - 1);
    double cordenada = atof(Scordenada);  // Convierte la cadena a un entero
    if( cordenada > cord_max ) {
    	cord_max = cordenada;
    }
    BEGIN AXIS;
}


<PLOT2D_MAX>[^,]+, {
    char Scordenada[100] = "";
    strncpy(Scordenada, yytext , yyleng - 1);
    double cordenada = atof(Scordenada);  // Convierte la cadena a un entero
    if( cordenada > cord_max ) {
    	cord_max = cordenada;
    }
    BEGIN PLOT;
}


<PLOT2D_MIN>[^:]+: {
    char Scordenada[100] = "";
    strncpy(Scordenada, yytext , yyleng - 1);
    double cordenada = atof(Scordenada);  // Convierte la cadena a un entero
    if( cordenada < cord_min ) {
    	cord_min = cordenada;
    }
    BEGIN PLOT2D_MAX;
}

<PLOT>domain= { 
    BEGIN(PLOT2D_MIN);  // Cambio al estado PLOT2D
}

<PLOT>\{([^\n]+)\n {

    /* Captura el contenido entre '{' y '}' en yytext */
    yytext = yytext + 1;
    int length = yyleng - 4;
    strncpy(formula, yytext , length );
    if (strlen(formula) > strlen(max_formula)) {
    	// Copiar el valor de formula en max_formula
    	strcpy(max_formula, formula);
    }
    BEGIN AXIS;
}




<*>. {
    /* Ignorar otros caracteres fuera de tikzpicture */
}

%%

int main() {
    yylex();
    
    printf("El título es \"%s\" \n", titulo);
    printf("Coordenada mínima: %g y máxima: %g\n", cord_min, cord_max);
    printf("El gráfico contiene %d gráficas/series \n", num_graficas);
    printf("La fórmula más larga es \"%s\"\n", max_formula);
    
    return 0;
}
