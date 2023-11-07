

%%
hola[a-zA-Z]*	{ printf("SI"); }
[0-9]+	{ printf("|%s|",yytext); }
