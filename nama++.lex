%{

%}

/* lex definitions */
   
digits [0-9]+
   


%%
[ \r\t] {continue;}

 /* punctuations */
":" {return COLON;}
"(" {return LPAREN;}
")" {return RPAREN;}
"." {return DOT;}
"+" {return PLUS;}
"-" {return MINUS;}
"*" {return TIMES;}
"/" {return DIVIDE;}
"=" {return EQ;}
"<>" {return NEQ;}
"<" {return LT;}
"<=" {return LE;}
":=" {return ASSIGN;}

   /* Identifiers. */

[_a-zA-Z][a-zA-Z0-9]* {yylval.sval=Cadena(yytext); return ID;}
   

   /* integers */

{digits}	 {yylval.ival=atoi(yytext); return INT;}


   /* Cualquier otra cosa */
.	 { printf("\nToken desconocido: '%s'.\n", yytext); }



%%