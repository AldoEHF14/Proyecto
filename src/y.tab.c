/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "casio_plus.y"

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
nodeType *conf(float value);
void freeNode(nodeType *p);
int ex(nodeType *p);
int yyerror(const char *s); 

std::map<std::string, int> sym;

#line 93 "y.tab.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

/* Use api.header.include to #include this header
   instead of duplicating it here.  */
#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    INTEGER = 258,                 /* INTEGER  */
    FLOAT = 259,                   /* FLOAT  */
    VARIABLE = 260,                /* VARIABLE  */
    WHILE = 261,                   /* WHILE  */
    IF = 262,                      /* IF  */
    PRINT = 263,                   /* PRINT  */
    IFX = 264,                     /* IFX  */
    ELSE = 265,                    /* ELSE  */
    AND = 266,                     /* AND  */
    OR = 267,                      /* OR  */
    FOR = 268,                     /* FOR  */
    DO = 269,                      /* DO  */
    GE = 270,                      /* GE  */
    LE = 271,                      /* LE  */
    EQ = 272,                      /* EQ  */
    NE = 273,                      /* NE  */
    UMINUS = 274,                  /* UMINUS  */
    NOT = 275                      /* NOT  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif
/* Token kinds.  */
#define YYEMPTY -2
#define YYEOF 0
#define YYerror 256
#define YYUNDEF 257
#define INTEGER 258
#define FLOAT 259
#define VARIABLE 260
#define WHILE 261
#define IF 262
#define PRINT 263
#define IFX 264
#define ELSE 265
#define AND 266
#define OR 267
#define FOR 268
#define DO 269
#define GE 270
#define LE 271
#define EQ 272
#define NE 273
#define UMINUS 274
#define NOT 275

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 23 "casio_plus.y"

    int iValue;
    float fValue;			 /* Valor entero */
    int sIndex;                /* Índice de la tabla de símbolos */
    char name[50];               
    nodeType *nPtr;             /* Apuntador a nodo */

#line 194 "y.tab.c"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_INTEGER = 3,                    /* INTEGER  */
  YYSYMBOL_FLOAT = 4,                      /* FLOAT  */
  YYSYMBOL_VARIABLE = 5,                   /* VARIABLE  */
  YYSYMBOL_WHILE = 6,                      /* WHILE  */
  YYSYMBOL_IF = 7,                         /* IF  */
  YYSYMBOL_PRINT = 8,                      /* PRINT  */
  YYSYMBOL_IFX = 9,                        /* IFX  */
  YYSYMBOL_ELSE = 10,                      /* ELSE  */
  YYSYMBOL_AND = 11,                       /* AND  */
  YYSYMBOL_OR = 12,                        /* OR  */
  YYSYMBOL_FOR = 13,                       /* FOR  */
  YYSYMBOL_DO = 14,                        /* DO  */
  YYSYMBOL_GE = 15,                        /* GE  */
  YYSYMBOL_LE = 16,                        /* LE  */
  YYSYMBOL_EQ = 17,                        /* EQ  */
  YYSYMBOL_NE = 18,                        /* NE  */
  YYSYMBOL_19_ = 19,                       /* '>'  */
  YYSYMBOL_20_ = 20,                       /* '<'  */
  YYSYMBOL_21_ = 21,                       /* '+'  */
  YYSYMBOL_22_ = 22,                       /* '-'  */
  YYSYMBOL_23_ = 23,                       /* '*'  */
  YYSYMBOL_24_ = 24,                       /* '/'  */
  YYSYMBOL_25_ = 25,                       /* ':'  */
  YYSYMBOL_26_ = 26,                       /* ';'  */
  YYSYMBOL_UMINUS = 27,                    /* UMINUS  */
  YYSYMBOL_NOT = 28,                       /* NOT  */
  YYSYMBOL_29_ = 29,                       /* '.'  */
  YYSYMBOL_30_ = 30,                       /* '='  */
  YYSYMBOL_31_ = 31,                       /* '('  */
  YYSYMBOL_32_ = 32,                       /* ')'  */
  YYSYMBOL_33_ = 33,                       /* '{'  */
  YYSYMBOL_34_ = 34,                       /* '}'  */
  YYSYMBOL_YYACCEPT = 35,                  /* $accept  */
  YYSYMBOL_program = 36,                   /* program  */
  YYSYMBOL_function = 37,                  /* function  */
  YYSYMBOL_stmt = 38,                      /* stmt  */
  YYSYMBOL_expr_init = 39,                 /* expr_init  */
  YYSYMBOL_expr_cond = 40,                 /* expr_cond  */
  YYSYMBOL_expr_cnt = 41,                  /* expr_cnt  */
  YYSYMBOL_stmt_list = 42,                 /* stmt_list  */
  YYSYMBOL_expr = 43                       /* expr  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_int8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if !defined yyoverflow

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* !defined yyoverflow */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  3
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   309

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  35
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  9
/* YYNRULES -- Number of rules.  */
#define YYNRULES  40
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  94

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   275


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      31,    32,    23,    21,     2,    22,    29,    24,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    25,    26,
      20,    30,    19,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    33,     2,    34,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    27,    28
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int8 yyrline[] =
{
       0,    54,    54,    58,    59,    63,    64,    65,    66,    67,
      68,    69,    70,    71,    72,    76,    77,    81,    85,    86,
      91,    92,    96,    97,    98,    99,   100,   101,   102,   103,
     104,   105,   106,   107,   108,   109,   110,   111,   112,   113,
     114
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "INTEGER", "FLOAT",
  "VARIABLE", "WHILE", "IF", "PRINT", "IFX", "ELSE", "AND", "OR", "FOR",
  "DO", "GE", "LE", "EQ", "NE", "'>'", "'<'", "'+'", "'-'", "'*'", "'/'",
  "':'", "';'", "UMINUS", "NOT", "'.'", "'='", "'('", "')'", "'{'", "'}'",
  "$accept", "program", "function", "stmt", "expr_init", "expr_cond",
  "expr_cnt", "stmt_list", "expr", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-25)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     -25,     1,    85,   -25,   -25,   -25,   -24,   -17,   -16,    49,
       6,   116,    49,   -25,    49,   -25,    49,   116,   -25,   211,
      49,    49,    49,   -25,   227,    39,    40,   -25,   -25,   139,
     -25,    35,    49,    49,    49,    49,    49,    49,    49,    49,
      49,    49,    49,    49,    49,   -25,   243,   157,   175,   -25,
      15,    21,    19,   -25,   -25,   -25,   273,   284,    -4,    -4,
      -4,    -4,    -4,    -4,   -15,   -15,   -25,   -25,   -25,   -25,
     116,   116,    -1,    49,    49,   -25,    41,   -25,   -25,    29,
     259,   193,   116,    81,    30,   -25,    28,    27,   259,   -25,
      49,   116,   259,   -25
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       4,     0,     0,     1,    22,    23,    24,     0,     0,     0,
       0,     0,     0,     5,     0,     2,     0,     0,     3,     0,
       0,     0,     0,    24,     0,     0,     0,    25,    39,     0,
      20,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     6,     0,     0,     0,     7,
       0,     0,     0,    40,    14,    21,    37,    38,    33,    34,
      36,    35,    31,    30,    26,    27,    28,    29,    32,     8,
       0,     0,     0,     0,     0,     9,    10,    16,    15,     0,
      17,     0,     0,     0,     0,    11,    24,     0,    19,    13,
       0,     0,    18,    12
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -25,   -25,   -25,     5,   -25,   -25,   -25,   -25,    -9
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,     1,     2,    18,    51,    79,    87,    31,    19
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int8 yytable[] =
{
      24,     3,    77,    27,    78,    28,    20,    29,    42,    43,
      44,    46,    47,    48,    21,    22,    26,    40,    41,    42,
      43,    44,    30,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,    68,    55,    25,     4,     5,
       6,     7,     8,     9,    50,    72,    52,    73,    10,    11,
      74,    82,     4,     5,    23,    83,    89,    12,    90,    91,
       0,    13,     0,    14,    80,    81,    16,     0,    17,    54,
       0,    12,     0,     0,    88,    75,    76,    14,     0,     0,
      16,    92,     0,     0,     4,     5,    86,    85,     4,     5,
       6,     7,     8,     9,     0,     0,    93,     0,    10,    11,
       0,     0,     0,    12,     0,     0,     0,    12,     0,    14,
       0,    13,    16,    14,    15,     0,    16,     0,    17,     4,
       5,     6,     7,     8,     9,     0,     0,     0,     0,    10,
      11,     0,     0,     0,     0,     0,     0,     0,    12,     0,
       0,     0,    13,     0,    14,     0,     0,    16,     0,    17,
      32,    33,     0,     0,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,     0,     0,     0,    32,    33,
       0,    53,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,     0,     0,     0,    32,    33,     0,    70,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,     0,     0,     0,    32,    33,     0,    71,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,     0,
       0,     0,    32,    33,     0,    84,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    32,    33,
       0,     0,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    49,    32,    33,     0,     0,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    69,
      32,    33,     0,     0,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    33,     0,     0,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44
};

static const yytype_int8 yycheck[] =
{
       9,     0,     3,    12,     5,    14,    30,    16,    23,    24,
      25,    20,    21,    22,    31,    31,    11,    21,    22,    23,
      24,    25,    17,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    31,    31,     3,     4,
       5,     6,     7,     8,     5,    30,     6,    26,    13,    14,
      31,    10,     3,     4,     5,    26,    26,    22,    30,    32,
      -1,    26,    -1,    28,    73,    74,    31,    -1,    33,    34,
      -1,    22,    -1,    -1,    83,    70,    71,    28,    -1,    -1,
      31,    90,    -1,    -1,     3,     4,     5,    82,     3,     4,
       5,     6,     7,     8,    -1,    -1,    91,    -1,    13,    14,
      -1,    -1,    -1,    22,    -1,    -1,    -1,    22,    -1,    28,
      -1,    26,    31,    28,    29,    -1,    31,    -1,    33,     3,
       4,     5,     6,     7,     8,    -1,    -1,    -1,    -1,    13,
      14,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    22,    -1,
      -1,    -1,    26,    -1,    28,    -1,    -1,    31,    -1,    33,
      11,    12,    -1,    -1,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    -1,    -1,    -1,    11,    12,
      -1,    32,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    -1,    -1,    -1,    11,    12,    -1,    32,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    -1,    -1,    -1,    11,    12,    -1,    32,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    -1,
      -1,    -1,    11,    12,    -1,    32,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    11,    12,
      -1,    -1,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    11,    12,    -1,    -1,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      11,    12,    -1,    -1,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    12,    -1,    -1,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    36,    37,     0,     3,     4,     5,     6,     7,     8,
      13,    14,    22,    26,    28,    29,    31,    33,    38,    43,
      30,    31,    31,     5,    43,    31,    38,    43,    43,    43,
      38,    42,    11,    12,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    43,    43,    43,    26,
       5,    39,     6,    32,    34,    38,    43,    43,    43,    43,
      43,    43,    43,    43,    43,    43,    43,    43,    43,    26,
      32,    32,    30,    26,    31,    38,    38,     3,     5,    40,
      43,    43,    10,    26,    32,    38,     5,    41,    43,    26,
      30,    32,    43,    38
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    35,    36,    37,    37,    38,    38,    38,    38,    38,
      38,    38,    38,    38,    38,    39,    39,    40,    41,    41,
      42,    42,    43,    43,    43,    43,    43,    43,    43,    43,
      43,    43,    43,    43,    43,    43,    43,    43,    43,    43,
      43
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     2,     2,     0,     1,     2,     3,     4,     5,
       5,     7,     9,     7,     3,     3,     3,     1,     3,     1,
       1,     2,     1,     1,     1,     2,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     2,
       3
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;




/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */

  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */


  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 2: /* program: function '.'  */
#line 54 "casio_plus.y"
                           { exit(0); }
#line 1307 "y.tab.c"
    break;

  case 3: /* function: function stmt  */
#line 58 "casio_plus.y"
                           { ex((yyvsp[0].nPtr)); freeNode((yyvsp[0].nPtr)); }
#line 1313 "y.tab.c"
    break;

  case 5: /* stmt: ';'  */
#line 63 "casio_plus.y"
                                                                                { (yyval.nPtr) = opr(';', 2, NULL, NULL); }
#line 1319 "y.tab.c"
    break;

  case 6: /* stmt: expr ';'  */
#line 64 "casio_plus.y"
                                                                                { (yyval.nPtr) = (yyvsp[-1].nPtr); }
#line 1325 "y.tab.c"
    break;

  case 7: /* stmt: PRINT expr ';'  */
#line 65 "casio_plus.y"
                                                                                { (yyval.nPtr) = opr(PRINT, 1, (yyvsp[-1].nPtr)); }
#line 1331 "y.tab.c"
    break;

  case 8: /* stmt: VARIABLE '=' expr ';'  */
#line 66 "casio_plus.y"
                                                                                { (yyval.nPtr) = opr('=', 2, id((yyvsp[-3].name)), (yyvsp[-1].nPtr)); }
#line 1337 "y.tab.c"
    break;

  case 9: /* stmt: WHILE '(' expr ')' stmt  */
#line 67 "casio_plus.y"
                                                                                { (yyval.nPtr) = opr(WHILE, 2, (yyvsp[-2].nPtr), (yyvsp[0].nPtr)); }
#line 1343 "y.tab.c"
    break;

  case 10: /* stmt: IF '(' expr ')' stmt  */
#line 68 "casio_plus.y"
                                                                                { (yyval.nPtr) = opr(IF, 2, (yyvsp[-2].nPtr), (yyvsp[0].nPtr)); }
#line 1349 "y.tab.c"
    break;

  case 11: /* stmt: IF '(' expr ')' stmt ELSE stmt  */
#line 69 "casio_plus.y"
                                                                                { (yyval.nPtr) = opr(IF, 3, (yyvsp[-4].nPtr), (yyvsp[-2].nPtr), (yyvsp[0].nPtr)); }
#line 1355 "y.tab.c"
    break;

  case 12: /* stmt: FOR '(' expr_init ';' expr_cond ';' expr_cnt ')' stmt  */
#line 70 "casio_plus.y"
                                                                                { (yyval.nPtr) = opr(FOR, 4, (yyvsp[-6].nPtr), (yyvsp[-4].nPtr), (yyvsp[-2].nPtr), (yyvsp[0].nPtr)); }
#line 1361 "y.tab.c"
    break;

  case 13: /* stmt: DO stmt WHILE '(' expr ')' ';'  */
#line 71 "casio_plus.y"
                                                                                { (yyval.nPtr) = opr(DO, 2, (yyvsp[-5].nPtr), (yyvsp[-2].nPtr)); }
#line 1367 "y.tab.c"
    break;

  case 14: /* stmt: '{' stmt_list '}'  */
#line 72 "casio_plus.y"
                                                                                { (yyval.nPtr) = (yyvsp[-1].nPtr); }
#line 1373 "y.tab.c"
    break;

  case 15: /* expr_init: VARIABLE '=' VARIABLE  */
#line 76 "casio_plus.y"
                                        { (yyval.nPtr) = opr('=', 2, id((yyvsp[-2].name)), id((yyvsp[0].name))); }
#line 1379 "y.tab.c"
    break;

  case 16: /* expr_init: VARIABLE '=' INTEGER  */
#line 77 "casio_plus.y"
                                        { (yyval.nPtr) = opr('=', 2, id((yyvsp[-2].name)), con((yyvsp[0].iValue)));}
#line 1385 "y.tab.c"
    break;

  case 17: /* expr_cond: expr  */
#line 81 "casio_plus.y"
                                        { (yyval.nPtr) = (yyvsp[0].nPtr); }
#line 1391 "y.tab.c"
    break;

  case 18: /* expr_cnt: VARIABLE '=' expr  */
#line 85 "casio_plus.y"
                                        { (yyval.nPtr) = opr('=', 2, id((yyvsp[-2].name)), (yyvsp[0].nPtr)); }
#line 1397 "y.tab.c"
    break;

  case 19: /* expr_cnt: expr  */
#line 86 "casio_plus.y"
                                        { (yyval.nPtr) = (yyvsp[0].nPtr); }
#line 1403 "y.tab.c"
    break;

  case 20: /* stmt_list: stmt  */
#line 91 "casio_plus.y"
                                 { (yyval.nPtr) = (yyvsp[0].nPtr); }
#line 1409 "y.tab.c"
    break;

  case 21: /* stmt_list: stmt_list stmt  */
#line 92 "casio_plus.y"
                                 { (yyval.nPtr) = opr(';', 2, (yyvsp[-1].nPtr), (yyvsp[0].nPtr)); }
#line 1415 "y.tab.c"
    break;

  case 22: /* expr: INTEGER  */
#line 96 "casio_plus.y"
                                 { (yyval.nPtr) = con((yyvsp[0].iValue)); 	     }
#line 1421 "y.tab.c"
    break;

  case 23: /* expr: FLOAT  */
#line 97 "casio_plus.y"
                                 { (yyval.nPtr) = conf((yyvsp[0].fValue));  	     }
#line 1427 "y.tab.c"
    break;

  case 24: /* expr: VARIABLE  */
#line 98 "casio_plus.y"
                                 { (yyval.nPtr) = id((yyvsp[0].name)); 	     }
#line 1433 "y.tab.c"
    break;

  case 25: /* expr: '-' expr  */
#line 99 "casio_plus.y"
                                 { (yyval.nPtr) = opr(UMINUS, 1, (yyvsp[0].nPtr));  }
#line 1439 "y.tab.c"
    break;

  case 26: /* expr: expr '+' expr  */
#line 100 "casio_plus.y"
                                 { (yyval.nPtr) = opr('+', 2, (yyvsp[-2].nPtr), (yyvsp[0].nPtr)); }
#line 1445 "y.tab.c"
    break;

  case 27: /* expr: expr '-' expr  */
#line 101 "casio_plus.y"
                                 { (yyval.nPtr) = opr('-', 2, (yyvsp[-2].nPtr), (yyvsp[0].nPtr)); }
#line 1451 "y.tab.c"
    break;

  case 28: /* expr: expr '*' expr  */
#line 102 "casio_plus.y"
                                 { (yyval.nPtr) = opr('*', 2, (yyvsp[-2].nPtr), (yyvsp[0].nPtr)); }
#line 1457 "y.tab.c"
    break;

  case 29: /* expr: expr '/' expr  */
#line 103 "casio_plus.y"
                                 { (yyval.nPtr) = opr('/', 2, (yyvsp[-2].nPtr), (yyvsp[0].nPtr)); }
#line 1463 "y.tab.c"
    break;

  case 30: /* expr: expr '<' expr  */
#line 104 "casio_plus.y"
                                 { (yyval.nPtr) = opr('<', 2, (yyvsp[-2].nPtr), (yyvsp[0].nPtr)); }
#line 1469 "y.tab.c"
    break;

  case 31: /* expr: expr '>' expr  */
#line 105 "casio_plus.y"
                                 { (yyval.nPtr) = opr('>', 2, (yyvsp[-2].nPtr), (yyvsp[0].nPtr)); }
#line 1475 "y.tab.c"
    break;

  case 32: /* expr: expr ':' expr  */
#line 106 "casio_plus.y"
                                 { (yyval.nPtr) = opr(':', 2, (yyvsp[-2].nPtr), (yyvsp[0].nPtr)); }
#line 1481 "y.tab.c"
    break;

  case 33: /* expr: expr GE expr  */
#line 107 "casio_plus.y"
                                 { (yyval.nPtr) = opr(GE, 2, (yyvsp[-2].nPtr), (yyvsp[0].nPtr));  }
#line 1487 "y.tab.c"
    break;

  case 34: /* expr: expr LE expr  */
#line 108 "casio_plus.y"
                                 { (yyval.nPtr) = opr(LE, 2, (yyvsp[-2].nPtr), (yyvsp[0].nPtr));  }
#line 1493 "y.tab.c"
    break;

  case 35: /* expr: expr NE expr  */
#line 109 "casio_plus.y"
                                 { (yyval.nPtr) = opr(NE, 2, (yyvsp[-2].nPtr), (yyvsp[0].nPtr));  }
#line 1499 "y.tab.c"
    break;

  case 36: /* expr: expr EQ expr  */
#line 110 "casio_plus.y"
                                 { (yyval.nPtr) = opr(EQ, 2, (yyvsp[-2].nPtr), (yyvsp[0].nPtr));  }
#line 1505 "y.tab.c"
    break;

  case 37: /* expr: expr AND expr  */
#line 111 "casio_plus.y"
                                 { (yyval.nPtr) = opr(AND, 2, (yyvsp[-2].nPtr), (yyvsp[0].nPtr)); }
#line 1511 "y.tab.c"
    break;

  case 38: /* expr: expr OR expr  */
#line 112 "casio_plus.y"
                                 { (yyval.nPtr) = opr(OR, 2, (yyvsp[-2].nPtr), (yyvsp[0].nPtr));  }
#line 1517 "y.tab.c"
    break;

  case 39: /* expr: NOT expr  */
#line 113 "casio_plus.y"
                                 { (yyval.nPtr) = opr(NOT, 1, (yyvsp[0].nPtr));     }
#line 1523 "y.tab.c"
    break;

  case 40: /* expr: '(' expr ')'  */
#line 114 "casio_plus.y"
                                 { (yyval.nPtr) = (yyvsp[-1].nPtr); 		     }
#line 1529 "y.tab.c"
    break;


#line 1533 "y.tab.c"

      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (YY_("syntax error"));
    }

  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;
  ++yynerrs;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 117 "casio_plus.y"



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
    char temp[10];  // Almacena el nombre del temporal
    if (!p)
        return 0;

    switch (p->type) {
    case typeCon:
        // Para constantes, imprimir el valor directamente
        //printf("\t%d\n", p->con.value);
        //printf("entro aqui");
        break;

    case typeId:
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
            ex(p->opr.op[0]);  // Condición del while
            printf("\tif_false t%d goto L%03d\n", tempCount - 1,lbl2);
            ex(p->opr.op[1]);  // Cuerpo del while
            printf("\tgoto L%03d\n", lbl1);
            printf("L%03d:\n", lbl2);
            break;

        case FOR:
            ex(p->opr.op[0]);  // Inicialización (i = 0)
            lbl1 = lbl++;      // Etiqueta de inicio del bucle
            lbl2 = lbl++;      // Etiqueta de salida del bucle
            printf("L%03d:\n", lbl1);

            ex(p->opr.op[1]);  // Condición (i < 10)
            if (p->opr.op[1]->type == typeId) {
        // Si la condición involucra una variable, usar el nombre de la variable
                 //printf("\tif_false %s goto L%03d\n", p->opr.op[0]->id.name, lbl2);
                 printf("\tif_false %s goto L%03d\n", p->opr.op[0]->id.name, lbl2);
            	  
	    } else {
            // Si es una operación con temporales
                 printf("\tif_false t%d goto L%03d\n", tempCount - 1, lbl2);
             }
            //printf("\tif_false t%d goto L%03d\n",  tempCount - 1,lbl2);
            ex(p->opr.op[3]);  // Cuerpo del bucle (a = a + i)
            ex(p->opr.op[2]);  // Incremento (i = i + 1)
            printf("\tgoto L%03d\n", lbl1);
            printf("L%03d:\n", lbl2);  // Salida del bucle
            break;

        case IF:
            ex(p->opr.op[0]);  // Condición del if
            lbl1 = lbl++;
            if (p->opr.nops > 2) {
                lbl2 = lbl++;
                printf("\tif_false t%d goto L%03d\n", tempCount - 1, lbl1);
                ex(p->opr.op[1]);  // Bloque if
                printf("\tgoto L%03d\n", lbl2);
                printf("L%03d:\n", lbl1);
                ex(p->opr.op[2]);  // Bloque else
                printf("L%03d:\n", lbl2);
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

   yyin = fopen(argv[1], "r");
   yyparse();

   return 0;
}