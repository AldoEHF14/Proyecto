/* EQUIPO: */
/*LUIS ALBERTO SOTO ZARATE - 2193035819*/
/*ALDO ENRIQUE HERNANDEZ FLORES - 2193035908*/
/*JORGE INFANTE FRAGOSO- 2203025256*/
/*JORGE OCTAVIO NICOLAS DIAZ - 2193076847*/


%{
#include <string.h>

# define ID 100
# define INT 101
# define DOUBLE 102
# define COMMA 103
/* control structures (selectives & iterative)  */
# define IF 104
# define ELSE 105
# define WHILE 106
# define FOR 107

# define TWOp 108
# define PYC 109
# define LPAREN 110
# define RPAREN 111
# define DOT 112
# define LKEY 113
# define RKEY 114

# define SUM 115
# define REST 116
# define PRODC 117
# define DIVIDE 118
# define MODULO 119

# define ASSIGN 120
# define EQ 121
# define MN 122
# define MY 123
# define MNQ 124
# define MYQ 125
# define DISTN 126


# define AND 127
# define OR 128
# define NOT 129



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
digits 	[0-9]+
signs 	[\- | \+]
special_symbol	 \[ | \] | \( | \) | \"| \+ | \- | ,
string 	[a-zA-Z0-9 ]*
comment /*[_a-zA-Z0-9 ]*/
float {signs}[0-9]*\.[0-9]*

%%

[ \r\t] {continue;}

	/* reserved words */

if    {ECHO; return IF;}
else  {ECHO; return ELSE;}
while {ECHO; return WHILE;}
for  	{ECHO; return FOR;}

 /* punctuations */
":" {ECHO;return TWOp;}
";" {ECHO;return PYC;}
"(" {ECHO;return LPAREN;}
")" {ECHO;return RPAREN;}
"." {ECHO;return DOT;}
"{" {ECHO;return LKEY;}
"}" {ECHO;return RKEY;}

 /* Operaciones aritmeticas */
"+" {ECHO;return SUM;}
"-" {ECHO;return REST;}
"*" {ECHO;return PRODC;}
"/" {ECHO;return DIVIDE;}
"%" {ECHO;return MODULO;}

 /* Operaciones  relacionales*/
"=" {ECHO;return ASSIGN;}
"==" {ECHO;return EQ;}
"<" {ECHO;return MN;}
">" {ECHO;return MY;}
"<=" {ECHO;return MNQ;}
">=" {ECHO;return MYQ;}
"!=" {ECHO;return DISTN;}

 /* Operaciones Logicos*/

"||" {ECHO;return OR;}
"&&" {ECHO;return AND;}
"!" {ECHO;return NOT;}

	/* Identifiers. */
[_a-zA-Z][a-zA-Z0-9]* { yylval.sval=Cadena(yytext); return ID;}
	/* integers */
{digits}	{ECHO; yylval.ival=atoi(yytext); return INT;}
{float}		{ECHO;  yylval.ival=atof(yytext); return DOUBLE;}
	/* Cualquier otra cosa */
. { printf("\nToken desconocido: '%s'.\n", yytext); }



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
