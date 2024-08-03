%{
#include <string.h>

# define ID 100
# define INT 101
# define DOUBLE 102
# define COMMA 103

# define IF 104
# define THEN 105
# define ELSE 106
# define WHILE 107
# define FOR 108

# define TWOp 109
# define PYC 110
# define LPAREN 111
# define RPAREN 112
# define DOT 113

# define SUM 114
# define REST 115
# define PRODC 116
# define DIVIDE 117
# define MODULO 118

# define ASSIGN 119
# define EQ 120
# define MN 121
# define MY 122
# define MNQ 123
# define MYQ 124
# define DISTN 125


# define AND 126
# define OR 127
# define NOT 128

# define LKEY 129
# define RKEY 130

typedef union  {
        int pos;
        int ival;
        char* sval;
} YYSTYPE;

YYSTYPE yylval;


char* Cadena(char *s)
{
   char* p = (char*) malloc(strlen(s)+1);
   strcpy(p,s);
   return p;
}



%}

/* lex definitions */
   
digits [0-9]+
/*float [0-9]+\.[0-9]**/
signs_numbers [\- | \+]
simbolos_especiales \[ | \] | \( | \) | \"| \+ | \- | ,
cadena [a-zA-Z0-9 ]*
comentario /*[_a-zA-Z0-9 ]*/
  
float {signs_numbers}[0-9]*\.[0-9]*



%%
[ \r\t] {continue;}

   /* reserved words -*/

if       {ECHO; return IF;}
then     {ECHO; return THEN;}
else     {ECHO; return ELSE;}
while    {ECHO; return WHILE;}
for  	   {ECHO; return FOR;}



 /* punctuations */
":" {ECHO;return TWOp;}
";" {ECHO;return PYC;}
"(" {return LPAREN;}
")" {return RPAREN;}
"." {return DOT;}
"{" {return LKEY;}
"}" {return RKEY;}

 /* Operaciones aritmeticas */
"+" {  return SUM;}
"-" {return REST;}
"*" {return PRODC;}
"/" {return DIVIDE;}
"%" {return MODULO;}


 /* Operaciones  relacionales*/
"=" {return ASSIGN;}
"==" {return EQ;}
"<" {return MN;}
">" {return MY;}
"<=" {return MNQ;}
">=" {return MYQ;}
"!=" {return DISTN;}


 /* Operaciones Logicos*/

"||" {return OR;}
"&&" {return AND;}
"!" {return NOT;}


   /* Identifiers. */

[_a-zA-Z][a-zA-Z0-9]* {yylval.sval=Cadena(yytext); return ID;}
   

   /* integers */

{digits}	 {ECHO; yylval.ival=atoi(yytext); return INT;}
{float}    {ECHO;  yylval.ival=atof(yytext); return DOUBLE;}


   /* Cualquier otra cosa */
.	 { printf("\nToken desconocido: '%s'.\n", yytext); }



%%



/* Este main es solamente de prueba.*/

int main(int argc, char *argv[]) {
   if (argc < 2) {
      printf("\n%s <archivo fuente>\n", argv[0]);
      return 0;
   }
   yyin = fopen(argv[1], "r");

   while(yylex());

   fclose(yyin);
}
