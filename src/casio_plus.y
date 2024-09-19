%{
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string>
#include <map>
#include "casio_plus.h"
#include "lex.yy.c"

static int lbl;
/* prototypes */
nodeType *opr(int oper, int nops, ...);
nodeType *id(const char* name);
nodeType *con(int value);
//nodeType *conf(float value);
void freeNode(nodeType *p);
int ex(nodeType *p);
int yyerror(const char *s); 

std::map<std::string, int> sym;
%}

%union {
    int iValue;
    float fValue;			 /* Valor entero */
    int sIndex;                /* Índice de la tabla de símbolos */
    char name[50];               
    nodeType *nPtr;             /* Apuntador a nodo */
};

%token <iValue> INTEGER
%token <fValue> FLOAT
%token <name> VARIABLE
%token WHILE IF PRINT
%nonassoc IFX
%nonassoc ELSE
%token AND
%token OR
%token FOR TO
%token DO 

%left AND
%left OR
%left GE LE EQ NE '>' '<'
%left '+' '-'
%left '*' '/' ':'
%nonassoc UMINUS
%nonassoc NOT
%type <nPtr> stmt expr stmt_list

%%

program:
         function '.'      { exit(0); }
         ;

function:
         function stmt     { ex($2); freeNode($2); }
         | /* NULL */
         ;

stmt:
         ';'                                                { $$ = opr(';', 2, NULL, NULL); }
         | expr ';'                                         { $$ = $1; }
         | PRINT  expr ';'                                  { $$ = opr(PRINT, 1, $2); }
         | VARIABLE '=' expr ';'                            { $$ = opr('=', 2, id($1), $3); }
         | WHILE '(' expr ')' stmt                          { $$ = opr(WHILE, 2, $3, $5); }
         | IF '(' expr ')' stmt %prec IFX                   { $$ = opr(IF, 2, $3, $5); }
         | IF '(' expr ')' stmt ELSE stmt                   { $$ = opr(IF, 3, $3, $5, $7); }
         | FOR VARIABLE '=' expr TO expr '{' stmt_list '}'  { $$ = opr(FOR, 4, id($2), $4, $6, $8); }
         | DO stmt WHILE '(' expr ')' ';'                   { $$ = opr(DO, 2, $2, $5); }
         | '{' stmt_list '}'                   { $$ = $2; }
         ;

stmt_list:
         stmt                    { $$ = $1; }
         | stmt_list stmt        { $$ = opr(';', 2, $1, $2); }
         ;

expr:
         INTEGER                 { $$ = con($1); 	     }
	 | FLOAT	 	 { $$ = con($1);  	     }
         | VARIABLE              { $$ = id($1); 	     }
         | '-' expr %prec UMINUS { $$ = opr(UMINUS, 1, $2);  }
         | expr '+' expr         { $$ = opr('+', 2, $1, $3); }
         | expr '-' expr         { $$ = opr('-', 2, $1, $3); }
         | expr '*' expr         { $$ = opr('*', 2, $1, $3); }
         | expr '/' expr         { $$ = opr('/', 2, $1, $3); }
         | expr '<' expr         { $$ = opr('<', 2, $1, $3); }
         | expr '>' expr         { $$ = opr('>', 2, $1, $3); }
         | expr ':' expr	 { $$ = opr(':', 2, $1, $3); }
	 | expr GE expr          { $$ = opr(GE, 2, $1, $3);  }
	 | expr LE expr          { $$ = opr(LE, 2, $1, $3);  }
         | expr NE expr          { $$ = opr(NE, 2, $1, $3);  }
         | expr EQ expr          { $$ = opr(EQ, 2, $1, $3);  }
         | expr AND expr         { $$ = opr(AND, 2, $1, $3); }
         | expr OR expr          { $$ = opr(OR, 2, $1, $3);  }
	 | NOT expr		 { $$ = opr(NOT, 1, $2);     }
         | '(' expr ')'          { $$ = $2; 		     }
         ;

%%

/*
nodeType *conf(float value) {
   nodeType *p;

   
   if((p = (nodeType*) malloc(sizeof(conNodeType))) == NULL)
      yyerror("out of memory");

  
   p->type = typeCon;
   p->con.valuef = value;

   return p;
}*/



nodeType *con(int value) {
   nodeType *p;

   
   if((p = (nodeType*) malloc(sizeof(conNodeType))) == NULL)
      yyerror("out of memory");

  
   p->type = typeCon;
   p->con.value = value;

   return p;
}


nodeType *id(const char* name) {
    nodeType *p;

    /* allocate node */
    if ((p = (nodeType*)malloc(sizeof(idNodeType))) == NULL)
        yyerror("out of memory");

    p->type = typeId;
    p->id.name[sizeof(p->id.name) - 1] = '\0';
    strncpy(p->id.name, name, sizeof(p->id.name) - 1);

    if (sym.find(p->id.name) == sym.end()) {
        sym[p->id.name] = 0;
    }

    return p;
}


nodeType *opr(int oper, int nops, ...) {
   va_list ap;
   nodeType *p;
   size_t size;
   int i;

   /* allocate node */
   size = sizeof(oprNodeType) + (nops-1) * sizeof(nodeType*);
   if ((p = (nodeType*)malloc(size)) == NULL)
      yyerror("out of memory");

   p->type = typeOpr;
   p->opr.oper = oper;
   p->opr.nops = nops;
   va_start(ap, nops);
   for (i = 0; i < nops; i++)
      p->opr.op[i] = va_arg(ap, nodeType*);
   va_end(ap);
   return p;
}

void freeNode(nodeType *p) {
   int i;

   if (!p) return;
   if (p->type == typeOpr) {
      for (i = 0; i < p->opr.nops; i++)
         freeNode(p->opr.op[i]);
   }
   free (p);
}

/*
int ex(nodeType *p) {

   if (!p) return 0;

   switch(p->type) {
      case typeCon: 
         return p->con.value;

      case typeId: 
         return sym[p->id.name];

      case typeOpr: 

         switch(p->opr.oper) {

            case WHILE: 
               while(ex(p->opr.op[0]))
                  ex(p->opr.op[1]);
               return 0;

            case DO:
               do {
                  ex(p->opr.op[0]);
               }while(ex(p->opr.op[1]));
               return 0;
            case IF:
               if (ex(p->opr.op[0]))
                  ex(p->opr.op[1]);
               else if (p->opr.nops > 2)
                  ex(p->opr.op[2]);
               return 0;

            case PRINT: 
               printf("%d\n", ex(p->opr.op[0]));
               return 0;

            case ';':
               ex(p->opr.op[0]);
               return ex(p->opr.op[1]);

            case '=':
               return sym[p->opr.op[0]->id.name] = ex(p->opr.op[1]);

            case UMINUS:
               return -ex(p->opr.op[0]);

            case '+':
               return ex(p->opr.op[0]) + ex(p->opr.op[1]);

            case '-': 
               return ex(p->opr.op[0]) - ex(p->opr.op[1]);

            case '*': 
               return ex(p->opr.op[0]) * ex(p->opr.op[1]);

            case '/': 
               return ex(p->opr.op[0]) / ex(p->opr.op[1]);

            case '<': 
               return ex(p->opr.op[0]) < ex(p->opr.op[1]);

            case '>': 
               return ex(p->opr.op[0]) > ex(p->opr.op[1]);

            case GE: 
               return ex(p->opr.op[0]) >= ex(p->opr.op[1]);

            case LE: 
               return ex(p->opr.op[0]) <= ex(p->opr.op[1]);

            case EQ:
               return ex(p->opr.op[0]) == ex(p->opr.op[1]);

            case AND: 
               return ex(p->opr.op[0]) && ex(p->opr.op[1]);
               
            case OR: 
               return ex(p->opr.op[0]) || ex(p->opr.op[1]);

            case FOR:
               sym[p->opr.op[0]->id.name] = ex(p->opr.op[1]);
               while (sym[p->opr.op[0]->id.name] <= ex(p->opr.op[2])) {
                  ex(p->opr.op[3]);
                  sym[p->opr.op[0]->id.name]++;
               }
               return 0;
         }
   }
   return 0;
}*/

int ex(nodeType* p) {
    int lbl1, lbl2;
    static int tempCount = 0;  // Para generar temporales
    char temp[10];  // Almacena el nombre del temporal
    if (!p)
        return 0; 
    switch (p->type) {
    case typeCon:
        sprintf(temp, "t%d", tempCount++);
        printf("\t%s = %d\n", temp, p->con.value);
        break;
    case typeId:
        sprintf(temp, "t%d", tempCount++);
        printf("\t%s = %s\n", temp, p->id.name );
        break;
    case typeOpr:
        switch (p->opr.oper) {
        case WHILE:
            lbl1 = lbl++;
            lbl2 = lbl++;
            printf("L%03d:\n", lbl1);
            ex(p->opr.op[0]);  // Condición del while
            printf("\tif_false t%d goto L%03d\n", tempCount - 1, lbl2);
            ex(p->opr.op[1]);  // Cuerpo del while
            printf("\tgoto L%03d\n", lbl1);
            printf("L%03d:\n", lbl2);
            break;
        case FOR:
            // FOR loop: p->opr.op[0] -> init; p->opr.op[1] -> condition; p->opr.op[2] -> increment; p->opr.op[3] -> body
            ex(p->opr.op[0]);  // Inicialización (i = 0)
            lbl1 = lbl++;      // Etiqueta de inicio del bucle
            lbl2 = lbl++;      // Etiqueta de salida del bucle
            printf("L%03d:\n", lbl1);
            ex(p->opr.op[1]);  // Condición (i < 10)
            printf("\tif_false t%d goto L%03d\n", tempCount - 1, lbl2);
            ex(p->opr.op[3]);  // Cuerpo del bucle (a = a + i)
            ex(p->opr.op[2]);  // Incremento (i = i + 1)
            printf("\tgoto L%03d\n", lbl1);
            printf("L%03d:\n", lbl2);  // Salida del bucle
            break;
        case IF:
            ex(p->opr.op[0]);  // Condición del if
            lbl1 = lbl++;
            if (p->opr.nops > 2) {
                // if-else
                lbl2 = lbl++;
                printf("\tif_false t%d goto L%03d\n", tempCount - 1, lbl1);
                ex(p->opr.op[1]);  // Bloque if
                printf("\tgoto L%03d\n", lbl2);
                printf("L%03d:\n", lbl1);
                ex(p->opr.op[2]);  // Bloque else
                printf("L%03d:\n", lbl2);
            } else {
                // Solo if
                printf("\tif_false t%d goto L%03d\n", tempCount - 1, lbl1);
                ex(p->opr.op[1]);  // Bloque if
                printf("L%03d:\n", lbl1);
            }
            break;
	case NOT:
		ex(p->opr.op[0]);  // Evaluar la expresión
		sprintf(temp, "t%d", tempCount++);
                printf("\t%s = !t%d\n",temp, tempCount-2);
	    break;	
        case PRINT:
            ex(p->opr.op[0]);
            printf("\tprint t%d\n", tempCount - 2);
            break;

        case '=':
            ex(p->opr.op[1]);  // Evaluar la expresión de la derecha
            printf("\t%s = t%d\n", p->opr.op[0]->id.name , tempCount - 1);
            break;

        case UMINUS:
            ex(p->opr.op[0]);  // Evaluar la expresión
            sprintf(temp, "t%d", tempCount++);
            printf("\t%s = -t%d\n", temp, tempCount - 2);
            break;

        default:
            ex(p->opr.op[0]);  // Lado izquierdo
            ex(p->opr.op[1]);  // Lado derecho
            sprintf(temp, "t%d", tempCount++);
            switch (p->opr.oper) {
            case '+':
                printf("\t%s = t%d + t%d\n", temp, tempCount - 3, tempCount - 2);
                break;
            case '-':
                printf("\t%s = t%d - t%d\n", temp, tempCount - 3, tempCount - 2);
                break;
            case '*':
                printf("\t%s = t%d * t%d\n", temp, tempCount - 3, tempCount - 2);
                break;
            case '/':
                printf("\t%s = t%d / t%d\n", temp, tempCount - 3, tempCount - 2);
                break;
            case '<':
                printf("\t%s = t%d < t%d\n", temp, tempCount - 3, tempCount - 2);
                break;
            case '>':
                printf("\t%s = t%d > t%d\n", temp, tempCount - 3, tempCount - 2);
                break;
	    case ':':
                printf("\t%s = t%d : t%d\n", temp, tempCount - 3, tempCount - 2);
                break;
            case GE:
                printf("\t%s = t%d >= t%d\n", temp, tempCount - 3, tempCount - 2);
                break;
            case LE:
                printf("\t%s = t%d <= t%d\n", temp, tempCount - 3, tempCount - 2);
                break;
            case NE:
                printf("\t%s = t%d != t%d\n", temp, tempCount - 3, tempCount - 2);
                break;
            case EQ:
                printf("\t%s = t%d == t%d\n", temp, tempCount - 3, tempCount - 2);
                break;
            case AND:
                printf("\t%s = t%d && t%d\n", temp, tempCount - 3, tempCount - 2);
                break;
            case OR:
                printf("\t%s = t%d || t%d\n", temp, tempCount - 3, tempCount - 2);
                break;
	    	
            }
            return 0;
        }
    }
    return 0 ;
}

int main(int argc, char **argv) {
   extern FILE* yyin;

   yyin = fopen(argv[1], "r");
   yyparse();

   return 0;
}
