%{
#include <stdlib.h>
#include "y.tab.h"
#include <string.h>

extern "C" int yylex();
extern "C" int yywrap();
extern "C" int yyerror(const char *s);

char yylval_name[50];

%}

%%

[-()<>=+*/,;{}.] { return *yytext; }

">="        return GE;
"<="        return LE;
"=="        return EQ;
"!="        return NE;
"&&"        return AND;
"||"        return OR;

"while"     return WHILE;
"if"        return IF;
"print"     return PRINT;
"for"       return FOR;
"to"        return TO;


[a-zA-Z][a-zA-Z0-9]*    { 
                            strcpy(yylval.name, yytext);
                            return VARIABLE;
                        }
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
