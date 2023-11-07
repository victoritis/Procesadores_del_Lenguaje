%{
#include <stdio.h>
#include <string.h>

char titulo[100] = "";      // Almacena el título
char form_larga[100] = "";  // Almacena la fórmula más larga
double cord_min;            // Almacena la coordenada mínima
double cord_max;            // Almacena la coordenada máxima
int num_graficas = 0;       // Contador de gráficas/series
char max_formula[100] = ""; // Almacena la fórmula máxima
char formula[100] = "";     // Almacena la fórmula actual
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
    BEGIN TIKZ;		// Cambio al estado TIKZ
}

<TIKZ>"\\end{tikzpicture}" {
    BEGIN INITIAL;	// Cambio al estado INITIAL
}

<TIKZ>"\\begin{axis}" {
    BEGIN AXIS;		// Cambio al estado AXIS
}

<AXIS>title=\{([^\n]+)\n {
    /* Captura el contenido entre '{' y '}' en yytext */
    strncpy(titulo, yytext + 7 , yyleng - 10);
}

<AXIS>title=([^\n]+)\n {
    /* Captura el contenido del titulo en yytext en caso de no venir dado entre {} */
    strncpy(titulo, yytext + 6 , yyleng - 8);
}

<AXIS>"\\end{axis}" {
    BEGIN TIKZ;		// Cambio al estado TIKZ
}

<AXIS>"\\addplot" {
    BEGIN PLOT;		// Cambio al estado PLOT
    num_graficas++;	// Incrementa el contador de gráficas/series
}

<AXIS>xmin= { 
    BEGIN MIN_3D;	// Cambio al estado MIN_3D, capturara la cordenada minima
}

<MIN_3D>[^,]+, {
    char Scordenada[100] = "";
    strncpy(Scordenada, yytext , yyleng - 1);	//Capturamos las coordenadas como string
    double cordenada = atof(Scordenada);  // Convierte la cadena a un entero
    if( cordenada < cord_min ) {	//En caso de que se encuentre una nueva cordenada minima
    	cord_min = cordenada;
    }
    BEGIN AXIS;		//Vuelve al estado AXIS para buscar algun xmax en caso de haberlo
}

<AXIS>xmax= { 	
    BEGIN MAX_3D;	//En caso de encontrar un xmax pasamos al estado MAX_3D para capturar la cordenada
}

<MAX_3D>[^,]+, {
    char Scordenada[100] = "";
    strncpy(Scordenada, yytext , yyleng - 1);	//Capturamos las coordenadas como string
    double cordenada = atof(Scordenada);  // Convierte la cadena a un entero
    if( cordenada > cord_max ) {
    	cord_max = cordenada;	//En caso de que se encuentre una nueva cordenada maxima
    }
    BEGIN AXIS;	//volvemos al estado AXIS
}


<PLOT2D_MAX>[^,]+, {
    char Scordenada[100] = "";
    strncpy(Scordenada, yytext , yyleng - 1);	//Capturamos las coordenadas como string
    double cordenada = atof(Scordenada);  // Convierte la cadena a un entero
    if( cordenada > cord_max ) {	//En caso de que se encuentre una nueva cordenada maxima
    	cord_max = cordenada;
    }
    BEGIN PLOT;	//volvemos al estado PLOT tras analizar las cordenadas de domain
}


<PLOT2D_MIN>[^:]+: {
    char Scordenada[100] = "";
    strncpy(Scordenada, yytext , yyleng - 1);	//Capturamos las coordenadas como string
    double cordenada = atof(Scordenada);  // Convierte la cadena a un entero
    if( cordenada < cord_min ) {	//En caso de que se encuentre una nueva cordenada minima
    	cord_min = cordenada;
    }
    BEGIN PLOT2D_MAX;	//Cambiamos al estado que captura la cordenada maxima
}

<PLOT>domain= { 
    BEGIN(PLOT2D_MIN);  // Cambio al estado PLOT2D_MIN para empezar a capturar las cordenadas minimas
}

<PLOT>\{([^\n]+)\n {

    /* Captura el contenido entre '{' y '}' en yytext */
    yytext = yytext + 1;	//capturamos el contedio sin el primer corchete
    int length = yyleng - 4;	//calculamos la longitud para pasarle a strncp
    strncpy(formula, yytext , length );	//copiamos en formula 
    if (strlen(formula) > strlen(max_formula)) {	//en caso de encontarr una formula mas grande
    	// Copiar el valor de formula en max_formula
    	strcpy(max_formula, formula);
    }
    BEGIN AXIS;	//salimos del estado addplot
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
