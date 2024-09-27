%{
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string>
#include <map>
#include "casio_plus.h"
#include "lex.yy.c"

static int lbl;
static FILE *file;
/* prototypes */
nodeType *opr(int oper, int nops, ...);
nodeType *id(const char* name);
nodeType *con(int value);
nodeType *conf(float value);
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
%token FOR
%token DO 

%left AND
%left OR
%left GE LE EQ NE '>' '<'
%left '+' '-'
%left '*' '/' ':' ';'
%nonassoc UMINUS
%nonassoc NOT
%type <nPtr> stmt expr stmt_list expr_init expr_cond expr_cnt

%%

program:
         function '.'      { exit(0); }
         ;

function:
         function stmt     { ex($2); freeNode($2); }
         | /* NULL */
         ;

stmt:
         ';'                                                			{ $$ = opr(';', 2, NULL, NULL); }
         | expr ';'                                         			{ $$ = $1; }
         | PRINT  expr ';'                                  			{ $$ = opr(PRINT, 1, $2); }
         | VARIABLE '=' expr ';'                            			{ $$ = opr('=', 2, id($1), $3); }
         | WHILE '(' expr ')' stmt                          			{ $$ = opr(WHILE, 2, $3, $5); }
         | IF '(' expr ')' stmt %prec IFX                   			{ $$ = opr(IF, 2, $3, $5); }
         | IF '(' expr ')' stmt ELSE stmt                   			{ $$ = opr(IF, 3, $3, $5, $7); }
         | FOR '(' expr_init  ';' expr_cond ';' expr_cnt ')' stmt 		{ $$ = opr(FOR, 4, $3, $5, $7, $9); }
	 | DO stmt WHILE '(' expr ')' ';'                   			{ $$ = opr(DO, 2, $2, $5); }
         | '{' stmt_list '}'                   					{ $$ = $2; }
         ;

expr_init:
	 VARIABLE '=' VARIABLE		{ $$ = opr('=', 2, id($1), id($3)); }
	 | VARIABLE '=' INTEGER		{ $$ = opr('=', 2, id($1), con($3));}
	 ;

expr_cond:
	 expr				{ $$ = $1; }
	 ;

expr_cnt:
	 VARIABLE '=' expr		{ $$ = opr('=', 2, id($1), $3); }
	 | expr 			{ $$ = $1; }
	 ; 


stmt_list:
         stmt                    { $$ = $1; }
         | stmt_list stmt        { $$ = opr(';', 2, $1, $2); }
         ;

expr:
         INTEGER                 { $$ = con($1); 	     }
	 | FLOAT	 	 { $$ = conf($1);  	     }
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


nodeType *conf(float value) {
   nodeType *p;

   
   if((p = (nodeType*) malloc(sizeof(conNodeType))) == NULL)
      yyerror("out of memory");

  
   p->type = typeCon;
   p->con.valuef = value;

   return p;
}



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








int ex(nodeType* p) {
    int lbl1, lbl2;
    static int tempCount = 0;  // Para generar temporales 
    static int regCount = 0;
    char temp[10];  // Almacena el nombre del temporal
    if (!p)
        return 0;

    switch (p->type) {
    case typeCon:
	
	
	//printf("\tMOV R%d, #%d\n", regCount++, p->con.value);
	//printf("\tMOV R%d, #%d\n", tempCount++, p->con.value);

        // Para constantes, imprimir el valor directamente
        //printf("\t%d\n", p->con.value);
        //printf("entro aqui");
        break;

    case typeId:
	
	//printf("\tMOV R%d, [R%d]\n", regCount++, tempCount);
	//printf("\tMOV R%d, [%s]\n", tempCount++, p->id.name);
        // Para variables, imprimir el nombre directamente
        //printf("\t%s\n", p->id.name);
        //printf("aquiiiiiii");
        break;

    case typeOpr:
        switch (p->opr.oper) {
        case WHILE:
            lbl1 = lbl++;

	    lbl2 = lbl++;
            
	    
	    printf("L%03d:\n", lbl1);
	     
            //fprintf(file, "L%03d:\n", lbl1);  // Escribe en el archivo	

            ex(p->opr.op[0]);  // Condición del while
            
	   // printf("\tCMP R%d, #0\n", regCount - 1);  // Comparar la condición con 0		

	    printf("\tif_false t%d goto L%03d\n", tempCount - 1,lbl2);
            
	    //fprintf(file, "\tif_false t%d goto L%03d\n", tempCount - 1, lbl2);

	    ex(p->opr.op[1]);  // Cuerpo del while
            printf("\tgoto L%03d\n", lbl1);

		//fprintf(file, "\tgoto L%03d\n", lbl1);
            printf("L%03d:\n", lbl2);

		//fprintf(file, "L%03d:\n", lbl2);
            break;

        case FOR:
            ex(p->opr.op[0]);  // Inicialización (i = 0)
            lbl1 = lbl++;      // Etiqueta de inicio del bucle
            lbl2 = lbl++;      // Etiqueta de salida del bucle
            printf("L%03d:\n", lbl1);
		//fprintf(file, "L%03d:\n", lbl1);            
		ex(p->opr.op[1]);  // Condición (i < 10)
            if (p->opr.op[1]->type == typeId) {
        // Si la condición involucra una variable, usar el nombre de la variable
                 //printf("\tif_false %s goto L%03d\n", p->opr.op[0]->id.name, lbl2);
                 printf("\tif_false %s goto L%03d\n", p->opr.op[0]->id.name, lbl2);

		//fprintf(file, "\tif_false %s goto L%03d\n", p->opr.op[0]->id.name, lbl2);
            	  
	    } else {
            // Si es una operación con temporales
                 printf("\tif_false t%d goto L%03d\n", tempCount - 1, lbl2);

		//fprintf(file, "\tif_false t%d goto L%03d\n", tempCount - 1, lbl2);
		
             }
            //printf("\tif_false t%d goto L%03d\n",  tempCount - 1,lbl2);
            ex(p->opr.op[3]);  // Cuerpo del bucle (a = a + i)
            ex(p->opr.op[2]);  // Incremento (i = i + 1)
            printf("\tgoto L%03d\n", lbl1);

		//fprintf(file, "\tgoto L%03d\n", lbl1);
            printf("L%03d:\n", lbl2);  // Salida del bucle

		//fprintf(file, "L%03d:\n", lbl2);
            break;

        case IF:
            ex(p->opr.op[0]);  // Condición del if
            lbl1 = lbl++;
            if (p->opr.nops > 2) {
                lbl2 = lbl++;
                printf("\tif_false t%d goto L%03d\n", tempCount - 1, lbl1);

		//fprintf(file, "\tif_false t%d goto L%03d\n", tempCount - 1, lbl1);


                ex(p->opr.op[1]);  // Bloque if
                printf("\tgoto L%03d\n", lbl2);

		//fprintf(file, "\tgoto L%03d\n", lbl2);	



                printf("L%03d:\n", lbl1);

		//fprintf(file, "L%03d:\n", lbl1);

                ex(p->opr.op[2]);  // Bloque else
                printf("L%03d:\n", lbl2);

		//fprintf(file, "L%03d:\n", lbl2);
            } else {
                printf("\tif_false t%d goto L%03d\n", tempCount - 1, lbl1);
                ex(p->opr.op[1]);  // Bloque if
                printf("L%03d:\n", lbl1);
            }
            break;

        case '=':
            // Evaluar el valor de la derecha y asignarlo a la variable de la izquierda
            ex(p->opr.op[1]);
            if (p->opr.op[1]->type == typeOpr) {
                printf("\t%s = t%d\n", p->opr.op[0]->id.name, tempCount - 1);
            } else if (p->opr.op[1]->type == typeCon) {
        // Si es una constante, asignar el valor directamente
                 printf("\t%s = %d\n", p->opr.op[0]->id.name, p->opr.op[1]->con.value);
            } else if (p->opr.op[1]->type == typeId) {
        // Si es una variable, asignar el valor de la variable
                 printf("\t%s = %s\n", p->opr.op[0]->id.name, p->opr.op[1]->id.name);
            }
            break;

        case '+':
            // Suma directa de los operandos sin temporales
            ex(p->opr.op[0]);
            ex(p->opr.op[1]);
            sprintf(temp, "t%d", tempCount++);
            if (p->opr.op[0]->type == typeId) {
                printf("\t%s = %s + %d\n", temp, p->opr.op[0]->id.name, p->opr.op[1]->con.value);
            } else {
                printf("\t%s = %d + %d\n", temp, p->opr.op[0]->con.value, p->opr.op[1]->con.value);
            }
            break;

        case PRINT:
            ex(p->opr.op[0]);
            if (p->opr.op[0]->type == typeId) {
                 printf("\tprint %s\n", p->opr.op[0]->id.name);
            } else if (p->opr.op[0]->type == typeCon) {
                printf("\tprint %d\n", p->opr.op[0]->con.value);
            } else if (p->opr.op[0]->type == typeOpr) {
                 printf("\tprint t%d\n", tempCount - 1);  
            }
            break;
        case UMINUS:
            ex(p->opr.op[0]);
            printf("\t-%d\n", p->opr.op[0]->con.value);
            break;

        default:
            ex(p->opr.op[0]);  // Lado izquierdo
            ex(p->opr.op[1]);  // Lado derecho
            sprintf(temp, "t%d", tempCount++);
            switch (p->opr.oper) {
            case '-':
                if (p->opr.op[0]->type == typeId && p->opr.op[1]->type == typeId) {
                    // Ambos operandos son variables>
                    printf("\t%s = %s - %s\n", temp, p->opr.op[0]->id.name, p->opr.op[1]->id.name);
                } else if (p->opr.op[0]->type == typeCon && p->opr.op[1]->type == typeCon) {
                    // Ambos operandos son constantes
                    printf("\t%s = %d - %d\n", temp, p->opr.op[0]->con.value, p->opr.op[1]->con.value);
                } else if (p->opr.op[0]->type == typeId && p->opr.op[1]->type == typeCon) {
                    // El primer operando es una variable y el segundo es una constante
                    printf("\t%s = %s - %d\n", temp, p->opr.op[0]->id.name, p->opr.op[1]->con.value);
                } else if (p->opr.op[0]->type == typeCon && p->opr.op[1]->type == typeId) {
                    // El primer operando es una constante y el segundo es una variable
                    printf("\t%s = %d - %s\n", temp, p->opr.op[0]->con.value, p->opr.op[1]->id.name);
                 } 
                break;
            case '*':
                if (p->opr.op[0]->type == typeId && p->opr.op[1]->type == typeId) {
                    // Ambos operandos son variables>
                    printf("\t%s = %s * %s\n", temp, p->opr.op[0]->id.name, p->opr.op[1]->id.name);
                } else if (p->opr.op[0]->type == typeCon && p->opr.op[1]->type == typeCon) {
                    // Ambos operandos son constantes
                    printf("\t%s = %d * %d\n", temp, p->opr.op[0]->con.value, p->opr.op[1]->con.value);
                } else if (p->opr.op[0]->type == typeId && p->opr.op[1]->type == typeCon) {
                    // El primer operando es una variable y el segundo es una constante
                    printf("\t%s = %s * %d\n", temp, p->opr.op[0]->id.name, p->opr.op[1]->con.value);
                } else if (p->opr.op[0]->type == typeCon && p->opr.op[1]->type == typeId) {
                    // El primer operando es una constante y el segundo es una variable
                    printf("\t%s = %d * %s\n", temp, p->opr.op[0]->con.value, p->opr.op[1]->id.name);
                 } 
                break;
            case '/':
                if (p->opr.op[0]->type == typeId && p->opr.op[1]->type == typeId) {
                    // Ambos operandos son variables>
                    printf("\t%s = %s / %s\n", temp, p->opr.op[0]->id.name, p->opr.op[1]->id.name);
                } else if (p->opr.op[0]->type == typeCon && p->opr.op[1]->type == typeCon) {
                    // Ambos operandos son constantes
                    printf("\t%s = %d / %d\n", temp, p->opr.op[0]->con.value, p->opr.op[1]->con.value);
                } else if (p->opr.op[0]->type == typeId && p->opr.op[1]->type == typeCon) {
                    // El primer operando es una variable y el segundo es una constante
                    printf("\t%s = %s / %d\n", temp, p->opr.op[0]->id.name, p->opr.op[1]->con.value);
                } else if (p->opr.op[0]->type == typeCon && p->opr.op[1]->type == typeId) {
                    // El primer operando es una constante y el segundo es una variable
                    printf("\t%s = %d / %s\n", temp, p->opr.op[0]->con.value, p->opr.op[1]->id.name);
                 } 
                break;
            case '<':
                if (p->opr.op[0]->type == typeId && p->opr.op[1]->type == typeId) {
                    // Ambos operandos son variables>
                    printf("\t%s = %s < %s\n", temp, p->opr.op[0]->id.name, p->opr.op[1]->id.name);
                } else if (p->opr.op[0]->type == typeCon && p->opr.op[1]->type == typeCon) {
                    // Ambos operandos son constantes
                    printf("\t%s = %d < %d\n", temp, p->opr.op[0]->con.value, p->opr.op[1]->con.value);
                } else if (p->opr.op[0]->type == typeId && p->opr.op[1]->type == typeCon) {
                    // El primer operando es una variable y el segundo es una constante
                    printf("\t%s = %s < %d\n", temp, p->opr.op[0]->id.name, p->opr.op[1]->con.value);
                } else if (p->opr.op[0]->type == typeCon && p->opr.op[1]->type == typeId) {
                    // El primer operando es una constante y el segundo es una variable
                    printf("\t%s = %d < %s\n", temp, p->opr.op[0]->con.value, p->opr.op[1]->id.name);
                 } 
                break;

            case '>':
                if (p->opr.op[0]->type == typeId && p->opr.op[1]->type == typeId) {
                    // Ambos operandos son variables>
                    printf("\t%s = %s > %s\n", temp, p->opr.op[0]->id.name, p->opr.op[1]->id.name);
                } else if (p->opr.op[0]->type == typeCon && p->opr.op[1]->type == typeCon) {
                    // Ambos operandos son constantes
                    printf("\t%s = %d > %d\n", temp, p->opr.op[0]->con.value, p->opr.op[1]->con.value);
                } else if (p->opr.op[0]->type == typeId && p->opr.op[1]->type == typeCon) {
                    // El primer operando es una variable y el segundo es una constante
                    printf("\t%s = %s > %d\n", temp, p->opr.op[0]->id.name, p->opr.op[1]->con.value);
                } else if (p->opr.op[0]->type == typeCon && p->opr.op[1]->type == typeId) {
                    // El primer operando es una constante y el segundo es una variable
                    printf("\t%s = %d > %s\n", temp, p->opr.op[0]->con.value, p->opr.op[1]->id.name);
                 } 
                break;

            case GE:
                if (p->opr.op[0]->type == typeId && p->opr.op[1]->type == typeId) {
                    // Ambos operandos son variables>
                    printf("\t%s = %s >= %s\n", temp, p->opr.op[0]->id.name, p->opr.op[1]->id.name);
                } else if (p->opr.op[0]->type == typeCon && p->opr.op[1]->type == typeCon) {
                    // Ambos operandos son constantes
                    printf("\t%s = %d >= %d\n", temp, p->opr.op[0]->con.value, p->opr.op[1]->con.value);
                } else if (p->opr.op[0]->type == typeId && p->opr.op[1]->type == typeCon) {
                    // El primer operando es una variable y el segundo es una constante
                    printf("\t%s = %s >= %d\n", temp, p->opr.op[0]->id.name, p->opr.op[1]->con.value);
                } else if (p->opr.op[0]->type == typeCon && p->opr.op[1]->type == typeId) {
                    // El primer operando es una constante y el segundo es una variable
                    printf("\t%s = %d >= %s\n", temp, p->opr.op[0]->con.value, p->opr.op[1]->id.name);
                 } 
                break;
            case LE:
                if (p->opr.op[0]->type == typeId && p->opr.op[1]->type == typeId) {
                    // Ambos operandos son variables>
                    printf("\t%s = %s <= %s\n", temp, p->opr.op[0]->id.name, p->opr.op[1]->id.name);
                } else if (p->opr.op[0]->type == typeCon && p->opr.op[1]->type == typeCon) {
                    // Ambos operandos son constantes
                    printf("\t%s = %d <= %d\n", temp, p->opr.op[0]->con.value, p->opr.op[1]->con.value);
                } else if (p->opr.op[0]->type == typeId && p->opr.op[1]->type == typeCon) {
                    // El primer operando es una variable y el segundo es una constante
                    printf("\t%s = %s <= %d\n", temp, p->opr.op[0]->id.name, p->opr.op[1]->con.value);
                } else if (p->opr.op[0]->type == typeCon && p->opr.op[1]->type == typeId) {
                    // El primer operando es una constante y el segundo es una variable
                    printf("\t%s = %d <= %s\n", temp, p->opr.op[0]->con.value, p->opr.op[1]->id.name);
                 }            
                break;
            case NE:
                if (p->opr.op[0]->type == typeId && p->opr.op[1]->type == typeId) {
                    // Ambos operandos son variables<
                    printf("\t%s = %s != %s\n", temp, p->opr.op[0]->id.name, p->opr.op[1]->id.name);
                } else if (p->opr.op[0]->type == typeCon && p->opr.op[1]->type == typeCon) {
                    // Ambos operandos son constantes
                    printf("\t%s = %d != %d\n", temp, p->opr.op[0]->con.value, p->opr.op[1]->con.value);
                } else if (p->opr.op[0]->type == typeId && p->opr.op[1]->type == typeCon) {
                    // El primer operando es una variable y el segundo es una constante
                    printf("\t%s = %s != %d\n", temp, p->opr.op[0]->id.name, p->opr.op[1]->con.value);
                } else if (p->opr.op[0]->type == typeCon && p->opr.op[1]->type == typeId) {
                    // El primer operando es una constante y el segundo es una variable
                    printf("\t%s = %d != %s\n", temp, p->opr.op[0]->con.value, p->opr.op[1]->id.name);
                 }
                break;
            case EQ:
                if (p->opr.op[0]->type == typeId && p->opr.op[1]->type == typeId) {
                    // Ambos operandos son variables
                    printf("\t%s = %s = %s\n", temp, p->opr.op[0]->id.name, p->opr.op[1]->id.name);
                } else if (p->opr.op[0]->type == typeCon && p->opr.op[1]->type == typeCon) {
                    // Ambos operandos son constantes
                    printf("\t%s = %d = %d\n", temp, p->opr.op[0]->con.value, p->opr.op[1]->con.value);
                } else if (p->opr.op[0]->type == typeId && p->opr.op[1]->type == typeCon) {
                    // El primer operando es una variable y el segundo es una constante
                    printf("\t%s = %s = %d\n", temp, p->opr.op[0]->id.name, p->opr.op[1]->con.value);
                } else if (p->opr.op[0]->type == typeCon && p->opr.op[1]->type == typeId) {
                    // El primer operando es una constante y el segundo es una variable
                    printf("\t%s = %d = %s\n", temp, p->opr.op[0]->con.value, p->opr.op[1]->id.name);
                 }
                break;
            case AND:
                if (p->opr.op[0]->type == typeId && p->opr.op[1]->type == typeId) {
                    // Ambos operandos son variables
                    printf("\t%s = %s && %s\n", temp, p->opr.op[0]->id.name, p->opr.op[1]->id.name);
                } else if (p->opr.op[0]->type == typeCon && p->opr.op[1]->type == typeCon) {
                    // Ambos operandos son constantes
                    printf("\t%s = %d && %d\n", temp, p->opr.op[0]->con.value, p->opr.op[1]->con.value);
                } else if (p->opr.op[0]->type == typeId && p->opr.op[1]->type == typeCon) {
                    // El primer operando es una variable y el segundo es una constante
                    printf("\t%s = %s && %d\n", temp, p->opr.op[0]->id.name, p->opr.op[1]->con.value);
                } else if (p->opr.op[0]->type == typeCon && p->opr.op[1]->type == typeId) {
                    // El primer operando es una constante y el segundo es una variable
                    printf("\t%s = %d && %s\n", temp, p->opr.op[0]->con.value, p->opr.op[1]->id.name);
                 }
                break;
            case OR:
                if (p->opr.op[0]->type == typeId && p->opr.op[1]->type == typeId) {
                    // Ambos operandos son variables
                    printf("\t%s = %s || %s\n", temp, p->opr.op[0]->id.name, p->opr.op[1]->id.name);
                } else if (p->opr.op[0]->type == typeCon && p->opr.op[1]->type == typeCon) {
                    // Ambos operandos son constantes
                    printf("\t%s = %d || %d\n", temp, p->opr.op[0]->con.value, p->opr.op[1]->con.value);
                } else if (p->opr.op[0]->type == typeId && p->opr.op[1]->type == typeCon) {
                    // El primer operando es una variable y el segundo es una constante
                    printf("\t%s = %s || %d\n", temp, p->opr.op[0]->id.name, p->opr.op[1]->con.value);
                } else if (p->opr.op[0]->type == typeCon && p->opr.op[1]->type == typeId) {
                    // El primer operando es una constante y el segundo es una variable
                    printf("\t%s = %d || %s\n", temp, p->opr.op[0]->con.value, p->opr.op[1]->id.name);
                 }
            }
            break;
        }
    }
    return 0;
}

int main(int argc, char **argv) {
   extern FILE* yyin;
   file = fopen("tac_file.txt", "w");
   if (file == NULL) {
   	printf("Error al abrir el archivo\n");
	return 1;
   }	
   yyin = fopen(argv[1], "r");
   yyparse();

   return 0;
}
