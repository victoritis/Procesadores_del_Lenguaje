 #include<ctype.h>
mayusculas	[A-Z]
%%
{mayusculas}	{printf("%c", tolower(yytext[0]));}
