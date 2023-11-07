%{
#include <stdio.h>
#include <string.h>

char titulo[100] = "";
char form_larga[100] = "";
int cord_min = 0;
int cord_max = 0;
int cordenada = 0;
int num_graficas_2d = 0;
int num_graficas_3d = 0;
int max_num_coordenadas = 0;
char max_formula[100] = "";
%}

%x TIKZ
%x AXIS
%x PLOT

%%

"\begin" {BEGIN(TIKZ);}

<TIKZ>"\\end{tikzpicture}" {
    BEGIN INITIAL;
    printf("Fin de entorno tikzpicture\n");
}

<TIKZ>"\\begin{axis}" {
    BEGIN AXIS;
    printf("Inicio entorno Axis\n");
}

<AXIS>"\\end{axis}" {
    BEGIN TIKZ;
    printf("Fin entorno Axis\n");
}

<AXIS>"\\addplot" {
    BEGIN PLOT;
    printf("Inicio entorno Plot\n");
}

<PLOT>; {
    /* Captura el contenido hasta encontrar un punto y coma dentro de plot */
    BEGIN AXIS;
    printf("%s\n", yytext);
    printf("Fin entorno Plot\n");
    
    // Analizar la fórmula y contar coordenadas
    char* formula = yytext;
    int num_coordenadas = 0;
    while (strchr(formula, '(') && strchr(formula, ')')) {
        formula = strchr(formula, '(') + 1;
        num_coordenadas++;
    }
    
    // Actualizar estadísticas
    cordenada += num_coordenadas;
    if (num_coordenadas > max_num_coordenadas) {
        max_num_coordenadas = num_coordenadas;
        strncpy(max_formula, yytext, sizeof(max_formula));
    }
}

<PLOT>. {
    /* Captura el contenido dentro de axis */
    printf("%s", yytext);
    
    // Contar gráficas/series 2D y 3D
    if (strstr(yytext, "3d")) {
        num_graficas_3d++;
    } else {
        num_graficas_2d++;
    }
}

<*>. {
    /* Ignorar otros caracteres fuera de tikzpicture */
}

%%

int main() {
    yylex();
    
    printf("Título: %s\n", titulo);
    printf("Coordenada mínima: %d y máxima: %d\n", cord_min, cord_max);
    printf("El gráfico contiene %d gráficas/series 2D y %d gráficas/series 3D\n", num_graficas_2d, num_graficas_3d);
    printf("La fórmula más larga es \"%s\"\n", max_formula);
    
    return 0;
}
