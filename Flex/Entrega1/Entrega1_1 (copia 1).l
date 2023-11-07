%{
#include <stdio.h>
#include <string.h>

char titulo[100] = "";
char form_larga[100] = "";
float cord_min;
float cord_max;
char Scord_min[100] = "0";
char Scord_max[100] = "0";
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

<AXIS>title=\{[^\}]+\} {
    /* Captura el contenido entre '{' y '}' en yytext */
    strncpy(titulo, yytext + 7 , yyleng - 8);
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
    char Scordenada[100];
    strncpy(Scordenada, yytext , yyleng - 1);
    float cordenada = atof(Scordenada);  // Convierte la cadena a un entero
    if( cordenada < cord_min ) {
    	cord_min = cordenada;
    	strncpy(Scord_min, yytext , yyleng - 1 );
    }
    BEGIN AXIS;
}

<AXIS>xmax= { 
    BEGIN MAX_3D;
}

<MAX_3D>[^,]+, {
    char Scordenada[100];
    strncpy(Scordenada, yytext , yyleng - 1);
    float cordenada = atof(Scordenada);  // Convierte la cadena a un entero
    if( cordenada > cord_max ) {
    	cord_max = cordenada;
    	strncpy(Scord_max, yytext , yyleng - 1 );
    }
    BEGIN AXIS;
}


<PLOT2D_MAX>[^,]+, {
    char Scordenada[100] = "";
    strncpy(Scordenada, yytext , yyleng - 1);
    float cordenada = atof(Scordenada);  // Convierte la cadena a un entero
    printf("%f\n", cordenada);
    printf("%f", cord_max);
    if( cordenada > cord_max ) {
    	cord_max = cordenada;
    	strncpy(Scord_max, yytext , yyleng - 1);
    }
    BEGIN PLOT;
}


<PLOT2D_MIN>[^:]+: {
    char Scordenada[100] = "";
    strncpy(Scordenada, yytext , yyleng - 1);
    float cordenada = atof(Scordenada);  // Convierte la cadena a un entero
    if( cordenada < cord_min ) {
    	cord_min = cordenada;
    	//strncpy(Scord_min, yytext , yyleng - 1);
    }
    BEGIN PLOT2D_MAX;
}

<PLOT>domain= { 
    BEGIN(PLOT2D_MIN);  // Cambio al estado PLOT2D
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
}

<*>. {
    /* Ignorar otros caracteres fuera de tikzpicture */
}

%%

int main() {
    yylex();
    
    printf("El título es \"%s\" \n", titulo);
    printf("Coordenada mínima: %f y máxima: %f\n", cord_min, cord_max);
    printf("El gráfico contiene %d gráficas/series \n", num_graficas);
    printf("La fórmula más larga es \"%s\"\n", max_formula);
    
    return 0;
}
