%{
# define ID 257
# define INT 259
# define DOUBLE 260
# define COMMA 261



%}

/* lex definitions */
   
digits [0-9]+
decimal [0-9]+\.[0-9]*
   


%%
[ \r\t] {continue;}

   /* reserved words */

if       {return IF;}
then     {return THEN;}
else     {return ELSE;}
while    {ECHO; return WHILE;}
for  	   {return FOR;}
function {return FUNCTION;}
var      {return VAR;}



 /* punctuations */
":" {return COLON;}
"(" {return LPAREN;}
")" {return RPAREN;}
"." {return DOT;}

 /* Operaciones aritmeticas */
"+" {return PLUS;}
"-" {return MINUS;}
"*" {return TIMES;}
"/" {return DIVIDE;}
"%" {return MODULO;}


 /* Operaciones  relacionales*/
"=" {return EQ;}
"<>" {return NEQ;}
"<" {return LT;}
">" {return MN;}
"<=" {return LE;}
":=" {return ASSIGN;}
"!" {return NEGATION;}
"||" {return OR}
"&&" {return AND}






   /* Identifiers. */

[_a-zA-Z][a-zA-Z0-9]* {yylval.sval=Cadena(yytext); return ID;}
   

   /* integers */

{digits}	 {yylval.ival=atoi(yytext); return INT;}
{decimal}    {yylval.ival=atof(yytext); return DOUBLE;}


   /* Cualquier otra cosa */
.	 { printf("\nToken desconocido: '%s'.\n", yytext); }



%%