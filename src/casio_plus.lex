%{
#include <stdlib.h>
#include "y.tab.h"
#include <string.h>

extern "C" int yylex();
extern "C" int yywrap();
extern "C" int yyerror(const char *s);

char yylval_name[50];

%}

/* lex definitions */
digit 	[0-9]+
sign 	[-+]?

%%

[-()<>=+:*/,;{}.] { return *yytext; }

">="        return GE;
"<="        return LE;
"=="        return EQ;
"!="        return NE;
"&&"        return AND;
"||"        return OR;
"!"	    return NOT;

"while"     return WHILE;
"if"        return IF;
"print"     return PRINT;
"for"       return FOR;
"do"        return DO;



[a-zA-Z][a-zA-Z0-9]*    { 
                            strcpy(yylval.name, yytext);
                            return VARIABLE;
                        }

{sign}{digit}*"."{digit}*   { yylval.fValue = atof(yytext); return FLOAT;}


[0-9]+  {
            yylval.iValue = atoi(yytext);
            return INTEGER;
        }

[ \t\n]     ;

.           { 
                fprintf(stderr, "Unrecognized character: %s\n", yytext);
                yyerror("Unrecognized character.");
            }

%%

extern "C" int yywrap(void) {
   return 1;
}

int yyerror(const char *s) {
    fprintf(stderr, "%s\n", s);
    return 0;
}
