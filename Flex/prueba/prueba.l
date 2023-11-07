%s TIKZ
%s CONDICION_B

%%
"inicioA"    { BEGIN(CONDICION_A); }
"inicioB"    { BEGIN(CONDICION_B); }

<CONDICION_A>"a"    { printf("Condición A: %s\n", yytext); }
<CONDICION_B>"b"    { printf("Condición B: %s\n", yytext); }
<CONDICION_A>"cambiar"	 { BEGIN(INITIAL); }


<CONDICION_A>.    { /* Ignorar otros caracteres en CONDICION_A */ }
<CONDICION_B>.    { /* Ignorar otros caracteres en CONDICION_B */ }



%%
