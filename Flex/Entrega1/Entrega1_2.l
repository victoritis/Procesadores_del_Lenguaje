%x TIKZ
%x AXIS
%x PLOT

%%

"\\begin{tikzpicture}"	{
    BEGIN TIKZ;
    printf("Comienzo de entorno tikzpicture\n");
}

<AXIS>"\\end{tikzpicture}" {
    BEGIN INITIAL;
    printf("Fin de entorno tikzpicture\n");
}

<PLOT>. {
    /* Captura el contenido dentro de axis */
    printf("%s", yytext);
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

<PLOT>[^;]+; {
    /* Captura el contenido hasta encontrar un punto y coma dentro de axis */
    BEGIN AXIS;
    printf("%s", yytext);
}

<*>. {
    /* Ignorar otros caracteres fuera de tikzpicture */
}

%%

