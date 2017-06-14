/* A Bison parser, made by GNU Bison 3.0.2.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2013 Free Software Foundation, Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

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

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.0.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 1 "kotek.y" /* yacc.c:339  */

#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

#define  YYDEBUG  0  /* 1 for debugging */
#define  ONPSIZE  1024 /**/
#define  TABSIZE  200

extern char *yytext;

struct {
  char txt[20];
  int ival;
} ONP[ONPSIZE] = {0};

int p = 0; // indeks do ONP
int symbolsCount = 0; // indeks do tablicy symboli

typedef enum {
  TypeOwn,
  TypeString,
  TypeInt,
  TypeVoid,
  TypeReal,
  TypeBoolean
} types;

struct {
  char txt[20]; //nazwa
  int addr;
  int p; //poziom zadeklarowania
  types type;
} TSym[TABSIZE]={"0"};

typedef struct attributes {
	int at1; //add
  int at2;
  int at3;
  int at4;
  int at5; //other
  int at6; //type wyr
} ATTRIBUTES;

typedef enum {
  ASS,
  NEG,
  NOT,
  Jump,
  JFalse,
  JTrue
} codes;

int genStr(char txt[]);
int genAddr(int addr);
void update(int adr, int newAddr);
void updateList(int startAddr, int newAddr);
void checkTypeBoolean(types sourceType);
void checkTypeNumeric(types sourceType);
types getType(int tSymAddr);
void checkTypes(types type1, types type2);

FILE *out;

#line 132 "y.tab.c" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "y.tab.h".  */
#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    DIGIT = 258,
    LETTER = 259,
    ARRAY = 260,
    CLASS = 261,
    DELETE = 262,
    DO = 263,
    DONE = 264,
    ELSE = 265,
    ENDIF = 266,
    EXTENDS = 267,
    FUNCTION = 268,
    IF = 269,
    INT = 270,
    NEW = 271,
    NULL_ = 272,
    OF = 273,
    PROGRAM = 274,
    READ = 275,
    RETURN = 276,
    STRING = 277,
    SUPER = 278,
    THEN = 279,
    THIS = 280,
    TYPE = 281,
    VAR = 282,
    VOID = 283,
    WHILE = 284,
    WRITE = 285,
    OPER_UMINUS = 286,
    OPER_UPLUS = 287,
    OPER_ASSIGN = 288,
    OPER_EQUAL = 289,
    OPER_NEQUAL = 290,
    OPER_GREATER = 291,
    OPER_LESSER = 292,
    OPER_AND = 293,
    OPER_OR = 294,
    OPER_ELESSER = 295,
    OPER_EGREATER = 296,
    ID = 297,
    INT_VAL = 298,
    REAL_VAL = 299,
    STRING_VAL = 300,
    REAL = 301,
    BOOLEAN = 302,
    TRUE = 303,
    FALSE = 304,
    REPEAT = 305,
    UNTIL = 306,
    FOR = 307,
    TO = 308,
    DOWNTO = 309,
    CASE = 310
  };
#endif
/* Tokens.  */
#define DIGIT 258
#define LETTER 259
#define ARRAY 260
#define CLASS 261
#define DELETE 262
#define DO 263
#define DONE 264
#define ELSE 265
#define ENDIF 266
#define EXTENDS 267
#define FUNCTION 268
#define IF 269
#define INT 270
#define NEW 271
#define NULL_ 272
#define OF 273
#define PROGRAM 274
#define READ 275
#define RETURN 276
#define STRING 277
#define SUPER 278
#define THEN 279
#define THIS 280
#define TYPE 281
#define VAR 282
#define VOID 283
#define WHILE 284
#define WRITE 285
#define OPER_UMINUS 286
#define OPER_UPLUS 287
#define OPER_ASSIGN 288
#define OPER_EQUAL 289
#define OPER_NEQUAL 290
#define OPER_GREATER 291
#define OPER_LESSER 292
#define OPER_AND 293
#define OPER_OR 294
#define OPER_ELESSER 295
#define OPER_EGREATER 296
#define ID 297
#define INT_VAL 298
#define REAL_VAL 299
#define STRING_VAL 300
#define REAL 301
#define BOOLEAN 302
#define TRUE 303
#define FALSE 304
#define REPEAT 305
#define UNTIL 306
#define FOR 307
#define TO 308
#define DOWNTO 309
#define CASE 310

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE YYSTYPE;
union YYSTYPE
{
#line 69 "kotek.y" /* yacc.c:355  */

  int ival;
  ATTRIBUTES aval;
  char *sval;
  double dval;
  char cval;

#line 290 "y.tab.c" /* yacc.c:355  */
};
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 305 "y.tab.c" /* yacc.c:358  */

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

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

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
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


#if ! defined yyoverflow || YYERROR_VERBOSE

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
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
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
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  4
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   426

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  73
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  48
/* YYNRULES -- Number of rules.  */
#define YYNRULES  110
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  196

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   310

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    72,     2,     2,     2,    60,     2,     2,
      67,    68,    58,    56,    65,    57,    71,    59,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    66,    61,
       2,    64,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    69,     2,    70,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    62,     2,    63,     2,     2,     2,     2,
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
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   105,   105,   110,   114,   118,   119,   123,   124,   125,
     126,   130,   135,   136,   137,   141,   143,   148,   149,   150,
     151,   152,   153,   157,   165,   170,   171,   175,   176,   180,
     181,   182,   187,   188,   192,   193,   198,   202,   206,   213,
     225,   231,   237,   243,   249,   255,   259,   260,   261,   265,
     267,   269,   271,   280,   281,   285,   286,   290,   312,   321,
     322,   323,   327,   342,   349,   364,   371,   372,   376,   377,
     381,   420,   428,   429,   430,   431,   432,   433,   437,   443,
     449,   454,   458,   460,   465,   466,   467,   468,   469,   475,
     482,   492,   493,   497,   511,   528,   532,   541,   550,   562,
     575,   584,   593,   603,   613,   622,   627,   635,   644,   652,
     656
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "DIGIT", "LETTER", "ARRAY", "CLASS",
  "DELETE", "DO", "DONE", "ELSE", "ENDIF", "EXTENDS", "FUNCTION", "IF",
  "INT", "NEW", "NULL_", "OF", "PROGRAM", "READ", "RETURN", "STRING",
  "SUPER", "THEN", "THIS", "TYPE", "VAR", "VOID", "WHILE", "WRITE",
  "OPER_UMINUS", "OPER_UPLUS", "OPER_ASSIGN", "OPER_EQUAL", "OPER_NEQUAL",
  "OPER_GREATER", "OPER_LESSER", "OPER_AND", "OPER_OR", "OPER_ELESSER",
  "OPER_EGREATER", "ID", "INT_VAL", "REAL_VAL", "STRING_VAL", "REAL",
  "BOOLEAN", "TRUE", "FALSE", "REPEAT", "UNTIL", "FOR", "TO", "DOWNTO",
  "CASE", "'+'", "'-'", "'*'", "'/'", "'%'", "';'", "'{'", "'}'", "'='",
  "','", "':'", "'('", "')'", "'['", "']'", "'.'", "'!'", "$accept",
  "prog", "Cialo", "Blok", "ListaDeklaracji", "Deklaracja",
  "DeklaracjaTypu", "OpisTypu", "ListaDeklaracjiZmiennej", "Typ",
  "DeklaracjaZmiennej", "DeklaracjaFunkcji", "DeklaracjaArgumentow",
  "ListaInstrukcji", "Instrukcja", "WyrazeniePodstawowe",
  "WyrazeniePostfiksowe", "Parametry", "ListaWyrazen", "WyrazenieUnarne",
  "OperatorUnarny", "WyrazenieMultiplikatywne", "WyrazenieAddytywne",
  "OperatorMultiplikatywny", "OperatorAddytywny", "WyrazeniePorownania",
  "OperatorPorownania", "WyrazenieLogiczne", "Wyrazenie",
  "ZlozonaInstrukcja", "InstrukcjaForId", "InstrukcjaForAss", "TO_DOWNTO",
  "InstrukcjaForStart", "InstrukcjaFor", "InstrukcjaCase",
  "InstrukcjaCaseStart", "InstrukcjaCaseStartInstrukcja",
  "InstrukcjaRepeat", "InstrukcjaRepeatStart", "InstrukcjaWhile",
  "InstrukcjaWhileWyrazenie", "InstrukcjaWhileStart", "InstrukcjaIf",
  "IfWyrazenieInstrukcja", "IfWyrazenie", "DeklaracjaKlasy", "Ident", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,    43,    45,    42,    47,
      37,    59,   123,   125,    61,    44,    58,    40,    41,    91,
      93,    46,    33
};
# endif

#define YYPACT_NINF -78

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-78)))

#define YYTABLE_NINF -108

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
       9,   -31,    34,    26,   -78,    -2,    -2,    -2,    -2,   -78,
      -3,    26,   -78,   -78,   -78,   -78,   -78,    49,     0,     5,
       4,   210,   -78,   -78,    -2,    36,    15,     1,   321,   321,
       1,   -78,    -2,   287,   -78,   -78,   -78,   321,   -78,   -78,
     -78,   -78,   -78,   -78,   -78,   -78,    -2,    -2,   -78,   321,
     -78,   -78,     3,   210,   -78,    -9,   -78,   354,   -41,    54,
      -1,   -78,    10,    17,     2,    56,   -78,   -78,    14,   253,
     -78,   210,   -78,    57,   321,   -78,    73,    60,   -78,    30,
     -78,    28,    29,    78,    36,   -78,   -78,   -78,   -78,   -78,
     -78,   -78,   -78,   -78,   -36,    37,   -78,    31,    38,   -78,
      40,    41,    70,   -78,    86,    39,   -78,   -78,   321,   321,
     321,    -2,   -78,   -78,   -78,   354,   -78,   -78,   -78,   -78,
     -78,   -78,   -78,   -78,   354,   354,   354,   354,   -78,   -78,
     -78,   -78,   321,   210,   210,   210,   -78,    61,   210,   -78,
     210,   210,    26,    36,    42,     1,    50,   -78,   321,   -78,
     -78,   -78,   321,   321,   -78,    44,    46,   -78,    55,    45,
     -78,   -78,   -41,   -12,   -78,   -78,   -78,   -78,   -78,   -78,
     321,   110,   111,   120,   153,    69,   -78,     1,   -78,   -78,
      63,   -78,   -78,   -78,   -78,   321,   -78,   -78,   -78,   -78,
     -78,   -78,    26,   -78,   -78,   -78
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     5,     1,     0,     0,     0,     0,     2,
       0,     5,     7,     8,     9,    10,   110,     0,     0,     0,
       0,    27,     3,     6,     0,    26,     0,     0,     0,     0,
       0,    48,     0,     0,    47,    46,   104,     0,    59,    60,
      41,    42,    40,    43,    44,   101,     0,     0,    34,     0,
      61,    32,     0,    27,    52,    58,    63,     0,    65,    71,
      80,    81,     0,     0,     0,     0,    88,    87,     0,    96,
      86,     0,    85,     0,     0,    84,     0,     0,    39,     0,
      25,    15,     0,     0,     0,    11,    12,    19,    18,    20,
      21,    22,    23,    17,    58,     0,   108,    82,     0,    38,
       0,     0,     0,    89,     0,     0,     4,    28,     0,    53,
       0,     0,    57,    66,    67,     0,    76,    77,    73,    72,
      74,    75,    68,    69,     0,     0,     0,     0,    29,    30,
      91,    92,     0,     0,     0,     0,    98,     0,     0,   103,
       0,    27,     5,     0,     0,     0,     0,    33,     0,    35,
      37,    36,     0,     0,    45,     0,     0,    54,    55,     0,
      51,    62,    64,    70,    79,    78,    93,    94,    99,    95,
       0,     0,     0,     0,    27,     0,    16,     0,    14,    13,
       0,    90,    97,    31,    50,     0,    49,   100,   102,   105,
     106,   109,     5,    83,    56,    24
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -78,   -78,   -58,   125,    -4,   -78,   -78,   -78,   -71,   -19,
     -16,   -78,   -78,   -13,   -59,   -78,   -17,   -78,   -49,   -42,
     -78,    13,    16,   -78,   -78,   -77,   -78,   -78,   -23,   -78,
     -78,   -78,   -78,   -78,   -78,   -78,   -78,   -78,   -78,   -78,
     -78,   -78,   -78,   -78,   -78,   -78,   -78,    -5
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     9,    51,    10,    11,    12,    85,    80,    92,
      13,    14,    82,   107,    53,    54,    94,   156,   157,    56,
      57,    58,    59,   115,   124,    60,   125,    61,    62,    63,
     102,    64,   132,    65,    66,    67,    68,    69,    70,    71,
      72,    73,    74,    75,    76,    77,    15,    78
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      17,    18,    19,    20,    55,    95,    96,    23,    52,    81,
     100,    97,   137,   146,   101,   112,    87,   113,   114,    79,
      83,    86,    93,    88,   108,    93,   105,    98,     1,    89,
       3,   109,     5,   110,     4,   111,    55,   126,   127,     6,
      16,   103,   104,    16,   122,   123,   136,    90,    91,   164,
     165,   139,     7,     8,    55,   130,   131,    16,   109,    21,
     110,    24,   111,     8,   133,   138,   106,    25,    81,    26,
      27,   128,   176,   161,   167,   168,   169,    84,   129,   171,
     134,   172,   174,   140,   141,   155,   158,   159,   116,   117,
     118,   119,   142,   143,   120,   121,   145,   144,   147,   149,
     148,   150,   151,   152,   153,   183,   160,   154,   177,   166,
     122,   123,   170,   179,   184,   186,    55,    55,    55,   188,
     185,    55,   189,    55,    55,   180,   178,    81,   173,   181,
     182,   190,   191,   193,   195,    22,   194,   162,   175,     0,
      93,   163,     0,     0,     0,     0,     0,   187,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    55,   192,     0,
      28,     0,   158,  -107,     0,     0,     0,    29,     0,    30,
      31,     0,    93,    32,    33,     0,    34,     0,    35,     0,
       0,     0,    36,    37,    38,    39,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    16,    40,    41,    42,     0,
       0,    43,    44,    45,     0,    46,     0,     0,    47,     0,
       0,     0,     0,     0,    48,    21,     0,    28,     0,     0,
      49,     0,     0,     0,    29,    50,    30,    31,     0,     0,
      32,    33,     0,    34,     0,    35,     0,     0,     0,    36,
      37,    38,    39,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    16,    40,    41,    42,     0,     0,    43,    44,
      45,     0,    46,   135,     0,    47,     0,     0,     0,    30,
      31,    48,    21,     0,     0,     0,    34,    49,    35,     0,
       0,     0,    50,     0,    38,    39,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    16,    40,    41,    42,     0,
       0,    43,    44,    30,    31,     0,     0,     0,     0,     0,
      34,     0,    35,     0,     0,     0,     0,     0,    38,    39,
      49,     0,     0,     0,     0,    50,     0,     0,     0,    16,
      40,    41,    42,     0,     0,    43,    44,    30,    31,     0,
       0,     0,     0,     0,    34,     0,    35,     0,    99,     0,
       0,     0,    38,    39,    49,     0,     0,     0,     0,    50,
       0,     0,     0,    16,    40,    41,    42,     0,     0,    43,
      44,    31,     0,     0,     0,     0,     0,    34,     0,    35,
       0,     0,     0,     0,     0,    38,    39,     0,    49,     0,
       0,     0,     0,    50,     0,     0,    16,    40,    41,    42,
       0,     0,    43,    44,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    49,     0,     0,     0,     0,    50
};

static const yytype_int16 yycheck[] =
{
       5,     6,     7,     8,    21,    28,    29,    11,    21,    25,
      33,    30,    71,    84,    37,    57,    15,    58,    59,    24,
       5,    26,    27,    22,    33,    30,    49,    32,    19,    28,
      61,    67,     6,    69,     0,    71,    53,    38,    39,    13,
      42,    46,    47,    42,    56,    57,    69,    46,    47,   126,
     127,    74,    26,    27,    71,    53,    54,    42,    67,    62,
      69,    12,    71,    27,     8,     8,    63,    67,    84,    64,
      66,    61,   143,   115,   133,   134,   135,    62,    61,   138,
      66,   140,   141,    10,    24,   108,   109,   110,    34,    35,
      36,    37,    62,    65,    40,    41,    18,    68,    61,    61,
      69,    61,    61,    33,    18,    61,   111,    68,    66,   132,
      56,    57,    51,    63,    68,    70,   133,   134,   135,     9,
      65,   138,    11,   140,   141,   148,   145,   143,   141,   152,
     153,    11,    63,    70,   192,    10,   185,   124,   142,    -1,
     145,   125,    -1,    -1,    -1,    -1,    -1,   170,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   174,   177,    -1,
       7,    -1,   185,    10,    -1,    -1,    -1,    14,    -1,    16,
      17,    -1,   177,    20,    21,    -1,    23,    -1,    25,    -1,
      -1,    -1,    29,    30,    31,    32,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    42,    43,    44,    45,    -1,
      -1,    48,    49,    50,    -1,    52,    -1,    -1,    55,    -1,
      -1,    -1,    -1,    -1,    61,    62,    -1,     7,    -1,    -1,
      67,    -1,    -1,    -1,    14,    72,    16,    17,    -1,    -1,
      20,    21,    -1,    23,    -1,    25,    -1,    -1,    -1,    29,
      30,    31,    32,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    42,    43,    44,    45,    -1,    -1,    48,    49,
      50,    -1,    52,    10,    -1,    55,    -1,    -1,    -1,    16,
      17,    61,    62,    -1,    -1,    -1,    23,    67,    25,    -1,
      -1,    -1,    72,    -1,    31,    32,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    42,    43,    44,    45,    -1,
      -1,    48,    49,    16,    17,    -1,    -1,    -1,    -1,    -1,
      23,    -1,    25,    -1,    -1,    -1,    -1,    -1,    31,    32,
      67,    -1,    -1,    -1,    -1,    72,    -1,    -1,    -1,    42,
      43,    44,    45,    -1,    -1,    48,    49,    16,    17,    -1,
      -1,    -1,    -1,    -1,    23,    -1,    25,    -1,    61,    -1,
      -1,    -1,    31,    32,    67,    -1,    -1,    -1,    -1,    72,
      -1,    -1,    -1,    42,    43,    44,    45,    -1,    -1,    48,
      49,    17,    -1,    -1,    -1,    -1,    -1,    23,    -1,    25,
      -1,    -1,    -1,    -1,    -1,    31,    32,    -1,    67,    -1,
      -1,    -1,    -1,    72,    -1,    -1,    42,    43,    44,    45,
      -1,    -1,    48,    49,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    67,    -1,    -1,    -1,    -1,    72
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    19,    74,    61,     0,     6,    13,    26,    27,    75,
      77,    78,    79,    83,    84,   119,    42,   120,   120,   120,
     120,    62,    76,    77,    12,    67,    64,    66,     7,    14,
      16,    17,    20,    21,    23,    25,    29,    30,    31,    32,
      43,    44,    45,    48,    49,    50,    52,    55,    61,    67,
      72,    76,    86,    87,    88,    89,    92,    93,    94,    95,
      98,   100,   101,   102,   104,   106,   107,   108,   109,   110,
     111,   112,   113,   114,   115,   116,   117,   118,   120,   120,
      81,    83,    85,     5,    62,    80,   120,    15,    22,    28,
      46,    47,    82,   120,    89,   101,   101,    82,   120,    61,
     101,   101,   103,   120,   120,   101,    63,    86,    33,    67,
      69,    71,    92,    58,    59,    96,    34,    35,    36,    37,
      40,    41,    56,    57,    97,    99,    38,    39,    61,    61,
      53,    54,   105,     8,    66,    10,   101,    87,     8,   101,
      10,    24,    62,    65,    68,    18,    81,    61,    69,    61,
      61,    61,    33,    18,    68,   101,    90,    91,   101,   101,
     120,    92,    94,    95,    98,    98,   101,    87,    87,    87,
      51,    87,    87,    86,    87,    77,    81,    66,    82,    63,
     101,   101,   101,    61,    68,    65,    70,   101,     9,    11,
      11,    63,    82,    70,    91,    75
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    73,    74,    75,    76,    77,    77,    78,    78,    78,
      78,    79,    80,    80,    80,    81,    81,    82,    82,    82,
      82,    82,    82,    83,    84,    85,    85,    86,    86,    87,
      87,    87,    87,    87,    87,    87,    87,    87,    87,    88,
      88,    88,    88,    88,    88,    88,    88,    88,    88,    89,
      89,    89,    89,    90,    90,    91,    91,    92,    92,    93,
      93,    93,    94,    94,    95,    95,    96,    96,    97,    97,
      98,    98,    99,    99,    99,    99,    99,    99,   100,   100,
     100,   101,   101,   101,   102,   102,   102,   102,   102,   103,
     104,   105,   105,   106,   107,   108,   108,   109,   109,   110,
     111,   112,   113,   114,   115,   116,   116,   117,   118,   119,
     120
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     3,     2,     3,     0,     2,     1,     1,     1,
       1,     4,     1,     3,     3,     1,     3,     1,     1,     1,
       1,     1,     1,     4,     8,     1,     0,     0,     2,     2,
       2,     4,     1,     3,     1,     3,     3,     3,     2,     1,
       1,     1,     1,     1,     1,     3,     1,     1,     1,     4,
       4,     3,     1,     0,     1,     1,     3,     2,     1,     1,
       1,     1,     3,     1,     3,     1,     1,     1,     1,     1,
       3,     1,     1,     1,     1,     1,     1,     1,     3,     3,
       1,     1,     2,     5,     1,     1,     1,     1,     1,     1,
       4,     1,     1,     3,     3,     3,     1,     4,     2,     3,
       4,     1,     4,     2,     1,     4,     4,     3,     2,     7,
       1
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
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

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



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

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
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
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
                                              );
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
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
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


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
yystrlen (const char *yystr)
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            /* Fall through.  */
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
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
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        YYSTYPE *yyvs1 = yyvs;
        yytype_int16 *yyss1 = yyss;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * sizeof (*yyssp),
                    &yyvs1, yysize * sizeof (*yyvsp),
                    &yystacksize);

        yyss = yyss1;
        yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yytype_int16 *yyss1 = yyss;
        union yyalloc *yyptr =
          (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
                  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

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

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
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

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

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
| yyreduce -- Do a reduction.  |
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
        case 2:
#line 106 "kotek.y" /* yacc.c:1646  */
    { printf("prog -> program ; Cialo \n");}
#line 1587 "y.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 110 "kotek.y" /* yacc.c:1646  */
    { printf("Cialo -> ListaDeklaracji Blok \n");}
#line 1593 "y.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 114 "kotek.y" /* yacc.c:1646  */
    { printf("Blok -> { ListaInstrukcji } \n");}
#line 1599 "y.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 118 "kotek.y" /* yacc.c:1646  */
    { printf("ListaDeklaracji -> slowo puste \n");}
#line 1605 "y.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 119 "kotek.y" /* yacc.c:1646  */
    { printf("ListaDeklaracji -> Deklaracja ListaDeklaracji \n");}
#line 1611 "y.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 123 "kotek.y" /* yacc.c:1646  */
    { printf("Deklaracja -> DeklaracjaTypu \n");}
#line 1617 "y.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 124 "kotek.y" /* yacc.c:1646  */
    { printf("Deklaracja -> DeklaracjaZmiennej \n");}
#line 1623 "y.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 125 "kotek.y" /* yacc.c:1646  */
    { printf("Deklaracja -> DeklaracjaFunkcji \n");}
#line 1629 "y.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 126 "kotek.y" /* yacc.c:1646  */
    { printf("Deklaracja -> DeklaracjaKlasy \n");}
#line 1635 "y.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 131 "kotek.y" /* yacc.c:1646  */
    { printf("DeklaracjaTypu -> Type Ident = OpisTypu \n");}
#line 1641 "y.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 135 "kotek.y" /* yacc.c:1646  */
    { printf("OpisTypu-> Ident \n");}
#line 1647 "y.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 136 "kotek.y" /* yacc.c:1646  */
    { printf("OpisTypu -> { ListaDeklaracjiZmiennej } \n");}
#line 1653 "y.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 137 "kotek.y" /* yacc.c:1646  */
    { printf("OpisTypu -> array of Typ \n");}
#line 1659 "y.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 142 "kotek.y" /* yacc.c:1646  */
    { printf("ListaDeklaracjiZmiennej -> DeklaracjaZmiennej \n");}
#line 1665 "y.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 144 "kotek.y" /* yacc.c:1646  */
    { printf("ListaDeklaracjiZmiennej -> DeklaracjaZmiennej , ListaDeklaracjiZmiennej \n");}
#line 1671 "y.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 148 "kotek.y" /* yacc.c:1646  */
    { printf("Typ -> Ident \n"); (yyval.ival) = TypeOwn; }
#line 1677 "y.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 149 "kotek.y" /* yacc.c:1646  */
    { printf("Typ -> string \n"); (yyval.ival) = TypeString; }
#line 1683 "y.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 150 "kotek.y" /* yacc.c:1646  */
    { printf("Typ -> int \n"); (yyval.ival) = TypeInt; }
#line 1689 "y.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 151 "kotek.y" /* yacc.c:1646  */
    { printf("Typ -> void \n"); (yyval.ival) = TypeVoid; }
#line 1695 "y.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 152 "kotek.y" /* yacc.c:1646  */
    { printf("Typ -> real \n"); (yyval.ival) = TypeReal; }
#line 1701 "y.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 153 "kotek.y" /* yacc.c:1646  */
    { printf("Typ -> boolean \n"); (yyval.ival) = TypeBoolean; }
#line 1707 "y.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 158 "kotek.y" /* yacc.c:1646  */
    {
      printf("DeklaracjaZmiennej -> var Ident : Typ \n");
      declareSymbol((yyvsp[-2].sval), (yyvsp[0].ival));
    }
#line 1716 "y.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 166 "kotek.y" /* yacc.c:1646  */
    { printf("DeklaracjaFunkcji -> function Ident ( DeklaracjaArgumentow ) : Typ Cialo \n");}
#line 1722 "y.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 170 "kotek.y" /* yacc.c:1646  */
    { printf("DeklaracjaArgumentow -> ListaDeklaracjiZmiennej \n");}
#line 1728 "y.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 171 "kotek.y" /* yacc.c:1646  */
    { printf("DeklaracjaArgumentow -> Slowo puste \n");}
#line 1734 "y.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 175 "kotek.y" /* yacc.c:1646  */
    { printf("ListaInstrukcji -> Slowo puste \n");}
#line 1740 "y.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 176 "kotek.y" /* yacc.c:1646  */
    { printf("ListaInstrukcji -> Instrukcja ListaInstrukcji \n");}
#line 1746 "y.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 180 "kotek.y" /* yacc.c:1646  */
    { printf("Instrukcja ->  Wyrazenie ; \n");}
#line 1752 "y.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 181 "kotek.y" /* yacc.c:1646  */
    { printf("Instrukcja -> ZlozonaInstrukcja ; \n");}
#line 1758 "y.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 183 "kotek.y" /* yacc.c:1646  */
    {
      printf("Instrukcja -> WyrazeniePostfiksowe := Wyrazenie ; \n");
      genStr(":=");
    }
#line 1767 "y.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 187 "kotek.y" /* yacc.c:1646  */
    { printf("Instrukcja -> Blok \n");}
#line 1773 "y.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 188 "kotek.y" /* yacc.c:1646  */
    {
    printf("Instrukcja -> delete Wyrazenie ; \n");
    genStr("delete");
  }
#line 1782 "y.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 192 "kotek.y" /* yacc.c:1646  */
    { printf("Instrukcja -> ; \n");}
#line 1788 "y.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 193 "kotek.y" /* yacc.c:1646  */
    {
    printf("Instrukcja -> read Ident  ; \n");
    genStr((yyvsp[-1].sval));
    genStr("read");
  }
#line 1798 "y.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 198 "kotek.y" /* yacc.c:1646  */
    {
    printf("Instrukcja -> write Wyrazenie ; \n");
    genStr("write");
  }
#line 1807 "y.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 202 "kotek.y" /* yacc.c:1646  */
    {
    printf("Instrukcja -> return Wyrazenie ; \n");
    genStr("return");
  }
#line 1816 "y.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 206 "kotek.y" /* yacc.c:1646  */
    {
    printf("Instrukcja -> return ; \n");
    genStr("return");
  }
#line 1825 "y.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 214 "kotek.y" /* yacc.c:1646  */
    {
      printf("WyrazeniePodstawowe -> Ident \n");
      (yyval.aval).at1 = TypeOwn;
      int i = findSymbol((yyvsp[0].sval));
      (yyval.aval).at2 = i;
      if(i != -1)
      {
        (yyval.aval).at3 = TSym[i].type;
        (yyval.aval).at6 = TSym[i].type;
      }
    }
#line 1841 "y.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 225 "kotek.y" /* yacc.c:1646  */
    {
    printf("WyrazeniePodstawowe -> STRING_VAL \n");
    (yyval.aval).at1 = TypeString;
    (yyval.aval).at2 = addSymbol(yytext, TypeString);
    (yyval.aval).at6 = TypeString;
  }
#line 1852 "y.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 231 "kotek.y" /* yacc.c:1646  */
    {
    printf("WyrazeniePodstawowe -> INT_VAL %d\n", (yyvsp[0].ival));
    (yyval.aval).at1 = TypeInt;
    (yyval.aval).at2 = addSymbol(yytext, TypeInt);
    (yyval.aval).at6 = TypeInt;
  }
#line 1863 "y.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 237 "kotek.y" /* yacc.c:1646  */
    {
    printf("WyrazeniePodstawowe -> REAL_VAL \n");
    (yyval.aval).at1 = TypeReal;
    (yyval.aval).at2 = addSymbol(yytext, TypeReal);
    (yyval.aval).at6 = TypeReal;
  }
#line 1874 "y.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 243 "kotek.y" /* yacc.c:1646  */
    {
    printf("WyrazeniePodstawowe -> TRUE \n");
    (yyval.aval).at1 = TypeBoolean;
    (yyval.aval).at2 = addSymbol(yytext, TypeBoolean);
    (yyval.aval).at6 = TypeBoolean;
  }
#line 1885 "y.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 249 "kotek.y" /* yacc.c:1646  */
    {
    printf("WyrazeniePodstawowe -> FALSE \n");
    (yyval.aval).at1 = TypeBoolean;
    (yyval.aval).at2 = addSymbol(yytext, TypeBoolean);
    (yyval.aval).at6 = TypeBoolean;
  }
#line 1896 "y.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 255 "kotek.y" /* yacc.c:1646  */
    {
    printf("WyrazeniePodstawowe -> (Wyrazenie) \n");
    (yyval.aval) = (yyvsp[-1].aval);
  }
#line 1905 "y.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 259 "kotek.y" /* yacc.c:1646  */
    { printf("WyrazeniePodstawowe -> this \n");}
#line 1911 "y.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 260 "kotek.y" /* yacc.c:1646  */
    { printf("WyrazeniePodstawowe -> super \n");}
#line 1917 "y.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 261 "kotek.y" /* yacc.c:1646  */
    { printf("WyrazeniePodstawowe -> null \n");}
#line 1923 "y.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 266 "kotek.y" /* yacc.c:1646  */
    { printf("WyrazeniePostfiksowe -> WyrazeniePostfiksowe [Wyrazenie] \n");}
#line 1929 "y.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 268 "kotek.y" /* yacc.c:1646  */
    { printf("WyrazeniePostfiksowe -> WyrazeniePostfiksowe (Parametry) \n");}
#line 1935 "y.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 270 "kotek.y" /* yacc.c:1646  */
    { printf("WyrazeniePostfiksowe -> WyrazeniePostfiksowe . Ident \n");}
#line 1941 "y.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 271 "kotek.y" /* yacc.c:1646  */
    {
    printf("WyrazeniePostfiksowe -> WyrazeniePodstawowe \n");
    printf("Podstawowe typ: %d, %d, %d\n", (yyvsp[0].aval).at1, TypeInt, TypeReal);
    printf("Typ: %s, %d\n", TSym[(yyvsp[0].aval).at2].txt, getType((yyvsp[0].aval).at2));
    (yyval.aval) = (yyvsp[0].aval);
    genStr(TSym[(yyvsp[0].aval).at2].txt);
  }
#line 1953 "y.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 281 "kotek.y" /* yacc.c:1646  */
    { printf("Parametry -> ListaWyrazen \n");}
#line 1959 "y.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 285 "kotek.y" /* yacc.c:1646  */
    { printf("ListaWyrazen -> Wyrazenie \n");}
#line 1965 "y.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 286 "kotek.y" /* yacc.c:1646  */
    { printf("ListaWyrazen -> Wyrazenie , ListaWyrazen \n");}
#line 1971 "y.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 291 "kotek.y" /* yacc.c:1646  */
    {
      printf("WyrazenieUnarne -> OperatorUnarny WyrazenieUnarne \n");
      printf("typ unarny: %d, %d, %d", (yyvsp[0].aval).at1, TypeInt, TypeReal);
      (yyval.aval).at1 = (yyvsp[0].aval).at1;
      (yyval.aval).at6 = (yyvsp[0].aval).at6;
      genStr(TSym[(yyvsp[0].aval).at2].txt);
      switch((yyvsp[-1].cval)) {
        case '!':
          checkTypeBoolean(getType((yyvsp[0].aval).at2));
          genStr("!");
          break;
        case '-':
          checkTypeNumeric(getType((yyvsp[0].aval).at2));
          genStr("u-");
          break;
        case '+':
          checkTypeNumeric(getType((yyvsp[0].aval).at2));
          genStr("u+");
          break;
      }
    }
#line 1997 "y.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 312 "kotek.y" /* yacc.c:1646  */
    {
    printf("WyrazenieUnarne -> WyrazeniePostfiksowe\n");
    (yyval.aval).at1 = (yyvsp[0].aval).at1;
    (yyval.aval).at2 = (yyvsp[0].aval).at2;
    (yyval.aval).at6 = (yyvsp[0].aval).at6;
  }
#line 2008 "y.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 321 "kotek.y" /* yacc.c:1646  */
    { printf("OperatorUnarny -> - \n"); (yyval.cval) = '-'; }
#line 2014 "y.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 322 "kotek.y" /* yacc.c:1646  */
    { printf("OperatorUnarny -> + \n"); (yyval.cval) = '+'; }
#line 2020 "y.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 323 "kotek.y" /* yacc.c:1646  */
    { printf("OperatorUnarny -> ! \n"); (yyval.cval) = '!'; }
#line 2026 "y.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 328 "kotek.y" /* yacc.c:1646  */
    {
      printf("WyrazenieMultiplikatywne -> WyrazenieMultiplikatywne OperatorMultiplikatywny WyrazenieUnarne \n");
      printf("tpyyy %d, %d, real%d, int%d", getType((yyvsp[-2].aval).at2), getType((yyvsp[0].aval).at2), TypeInt, TypeReal);
      checkTypeNumeric(getType((yyvsp[-2].aval).at2));
      checkTypeNumeric(getType((yyvsp[0].aval).at2));
      switch((yyvsp[-1].cval)) {
        case '*':
          genStr("*");
          break;
        case '/':
          genStr("/");
          break;
      }
    }
#line 2045 "y.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 342 "kotek.y" /* yacc.c:1646  */
    {
    printf(" WyrazenieMultiplikatywne -> WyrazenieUnarne \n");
    (yyval.aval) = (yyvsp[0].aval);
  }
#line 2054 "y.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 350 "kotek.y" /* yacc.c:1646  */
    {
      printf("WyrazenieAddytywne -> WyrazenieAddytywne OperatorAddytywny WyrazenieMultiplikatywne \n");
      (yyval.aval) = (yyvsp[-2].aval);
      checkTypeNumeric(getType((yyvsp[-2].aval).at2));
      checkTypeNumeric(getType((yyvsp[0].aval).at2));
      switch((yyvsp[-1].cval)) {
        case '+':
          genStr("+");
          break;
        case '-':
          genStr("-");
          break;
      }
    }
#line 2073 "y.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 364 "kotek.y" /* yacc.c:1646  */
    {
    printf("WyrazenieAddytywne -> WyrazenieMultiplikatywne \n");
    (yyval.aval) = (yyvsp[0].aval);
  }
#line 2082 "y.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 371 "kotek.y" /* yacc.c:1646  */
    { printf("OperatorMultiplikatywny -> * \n"); (yyval.cval) = '*'; }
#line 2088 "y.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 372 "kotek.y" /* yacc.c:1646  */
    { printf("OperatorMultiplikatywny -> '\' \n"); (yyval.cval) = '/'; }
#line 2094 "y.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 376 "kotek.y" /* yacc.c:1646  */
    { printf("OperatorAddytywny -> + \n"); (yyval.cval) = '+'; }
#line 2100 "y.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 377 "kotek.y" /* yacc.c:1646  */
    { printf("OperatorAddytywny -> - \n"); (yyval.cval) = '-'; }
#line 2106 "y.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 382 "kotek.y" /* yacc.c:1646  */
    {
      printf("WyrazeniePorownania -> Wyrazenieaddytywne OperatorPorownania WyrazenieAddytywne \n");
      (yyval.aval).at1 = TypeBoolean;
      (yyval.aval).at6 = TypeBoolean;
      int type1 = getType((yyvsp[-2].aval).at2);
      int type2 = getType((yyvsp[0].aval).at2);
      if (type1 == TypeInt || type1 == TypeReal) {
        if (type2 != TypeInt && type2 != TypeReal)
          yyerror("Typ porownania nie poprawny\n");
      }
      if (type1 == TypeBoolean && type2 != TypeBoolean)
        yyerror("Typ porownania nie poprawny\n");
      if (type1 == TypeString && type2 != TypeString)
        yyerror("Typ porownania nie poprawny\n");

      switch ((yyvsp[-1].ival)) {
          case OPER_LESSER:
            genStr("<");
            break;
          case OPER_GREATER:
            genStr(">");
            break;
          case OPER_ELESSER:
            genStr("<=");
            break;
          case OPER_EGREATER:
            genStr(">=");
            break;
          case OPER_EQUAL:
            genStr("==");
            break;
          case OPER_NEQUAL:
            genStr("!=");
            break;
          default:
            yyerror("Operator nie rozpoznany\n");
      }
    }
#line 2149 "y.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 420 "kotek.y" /* yacc.c:1646  */
    {
    (yyval.aval).at1 = getType((yyvsp[0].aval).at1);
    (yyval.aval).at6 = (yyvsp[0].aval).at6;
    printf("WyrazeniePorownania -> WyrazenieAddytywne \n");
  }
#line 2159 "y.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 428 "kotek.y" /* yacc.c:1646  */
    { printf("OperatorPorownania -> < \n"); (yyval.ival) = OPER_LESSER; }
#line 2165 "y.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 429 "kotek.y" /* yacc.c:1646  */
    { printf("OperatorPorownania -> > \n"); (yyval.ival) = OPER_GREATER; }
#line 2171 "y.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 430 "kotek.y" /* yacc.c:1646  */
    { printf("OperatorPorownania -> <= \n"); (yyval.ival) = OPER_ELESSER; }
#line 2177 "y.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 431 "kotek.y" /* yacc.c:1646  */
    { printf("OperatorPorownania -> >= \n"); (yyval.ival) = OPER_EGREATER; }
#line 2183 "y.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 432 "kotek.y" /* yacc.c:1646  */
    { printf("OperatorPorownania -> == \n"); (yyval.ival) = OPER_EQUAL; }
#line 2189 "y.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 433 "kotek.y" /* yacc.c:1646  */
    { printf("OperatorPorownania -> != \n"); (yyval.ival) = OPER_NEQUAL; }
#line 2195 "y.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 438 "kotek.y" /* yacc.c:1646  */
    {
      (yyval.aval) = (yyvsp[-2].aval);
      printf("Wyrazenielogiczne -> WyrazeniePorownania || WyrazeniePorownania \n");
      genStr("||");
    }
#line 2205 "y.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 444 "kotek.y" /* yacc.c:1646  */
    {
      (yyval.aval) = (yyvsp[-2].aval);
      printf("Wyrazenielogiczne -> WyrazeniePorownania && WyrazeniePorownania \n");
      genStr("&&");
    }
#line 2215 "y.tab.c" /* yacc.c:1646  */
    break;

  case 80:
#line 449 "kotek.y" /* yacc.c:1646  */
    {
    (yyval.aval) = (yyvsp[0].aval); printf("Wyrazenielogiczne -> WyrazeniePorownania \n");}
#line 2222 "y.tab.c" /* yacc.c:1646  */
    break;

  case 81:
#line 454 "kotek.y" /* yacc.c:1646  */
    {
    (yyval.aval) = (yyvsp[0].aval);
    printf("Wyrazenie -> Wyrazenielogiczne \n");
  }
#line 2231 "y.tab.c" /* yacc.c:1646  */
    break;

  case 82:
#line 459 "kotek.y" /* yacc.c:1646  */
    { printf("Wyrazenie -> new Typ \n");}
#line 2237 "y.tab.c" /* yacc.c:1646  */
    break;

  case 83:
#line 461 "kotek.y" /* yacc.c:1646  */
    { printf("Wyrazenie -> new Typ [Wyrazenie] \n");}
#line 2243 "y.tab.c" /* yacc.c:1646  */
    break;

  case 89:
#line 475 "kotek.y" /* yacc.c:1646  */
    {
    (yyval.aval).at3 = findSymbol(yytext);
    genStr(yytext);
  }
#line 2252 "y.tab.c" /* yacc.c:1646  */
    break;

  case 90:
#line 482 "kotek.y" /* yacc.c:1646  */
    {
    printf("InstrukcjaForAss -> for Ident := Wyrazenie \n");
    checkTypes(getType((yyvsp[-2].aval).at3), (yyvsp[0].aval).at6);
    genStr(":=");
    (yyval.aval).at3 = (yyvsp[-2].aval).at3; //zm
    (yyval.aval).at1 = p;
  }
#line 2264 "y.tab.c" /* yacc.c:1646  */
    break;

  case 91:
#line 492 "kotek.y" /* yacc.c:1646  */
    { (yyval.cval) = '+'; }
#line 2270 "y.tab.c" /* yacc.c:1646  */
    break;

  case 92:
#line 493 "kotek.y" /* yacc.c:1646  */
    {(yyval.cval) = '-'; }
#line 2276 "y.tab.c" /* yacc.c:1646  */
    break;

  case 93:
#line 497 "kotek.y" /* yacc.c:1646  */
    {
    (yyval.aval).at1 = (yyvsp[-2].aval).at1; // begin of for iteration
    (yyval.aval).at4 = (yyvsp[-1].cval); // + or -
    checkTypes(getType((yyvsp[-2].aval).at3), (yyvsp[0].aval).at6);
    printf("type: %d, %d\n", getType((yyvsp[-2].aval).at3), (yyvsp[0].aval).at6);

    genStr(TSym[(yyvsp[-2].aval).at3].txt); //zm
    (yyval.aval).at2 = genAddr(0); // end of for address
    genStr("JEq");
    printf("InstrukcjaForStart -> InstrukcjaForAss to Wyrazenie \n");
  }
#line 2292 "y.tab.c" /* yacc.c:1646  */
    break;

  case 94:
#line 511 "kotek.y" /* yacc.c:1646  */
    {
    printf("InstrukcjaFor -> InstrukcjaForStart do Instrukcja \n");
    genStr(TSym[(yyvsp[-2].aval).at3].txt);
    genStr(TSym[(yyvsp[-2].aval).at3].txt);
    genStr("1");
    char t[2] = {(char)(yyvsp[-2].aval).at4, '\0'};
    genStr(t);
    genStr(":=");
    genAddr((yyvsp[-2].aval).at1);
    genStr("Jump");
    update((yyvsp[-2].aval).at2, p);
  }
#line 2309 "y.tab.c" /* yacc.c:1646  */
    break;

  case 95:
#line 528 "kotek.y" /* yacc.c:1646  */
    {
    printf("InstrukcjaCase -> InstrukcjaCaseStartInstrukcja else ListaInstrukcji \n");
    updateList((yyvsp[-2].aval).at1, p);
  }
#line 2318 "y.tab.c" /* yacc.c:1646  */
    break;

  case 96:
#line 532 "kotek.y" /* yacc.c:1646  */
    {
    printf("InstrukcjaCase -> InstrukcjaCaseStartInstrukcja \n");
    p -= 2; // remove last jump
    update((yyvsp[0].aval).at3, p);
    updateList((yyvsp[0].aval).at1, p);
  }
#line 2329 "y.tab.c" /* yacc.c:1646  */
    break;

  case 97:
#line 541 "kotek.y" /* yacc.c:1646  */
    {
    printf("InstrukcjaCaseStart -> case Ident of Wyrazenie\n");
    (yyval.aval).at1 = 0; //init jump
    (yyval.aval).at2 = findSymbol((yyvsp[-2].sval));
    checkTypes(TSym[(yyval.aval).at2].type, (yyvsp[0].aval).at6);
    genStr(TSym[(yyval.aval).at2].txt);
    (yyval.aval).at3 = genAddr(0);
    genStr("JNEq");
  }
#line 2343 "y.tab.c" /* yacc.c:1646  */
    break;

  case 98:
#line 550 "kotek.y" /* yacc.c:1646  */
    {
    printf("InstrukcjaCaseStart -> InstrukcjaCaseStartInstrukcja Wyrazenie\n");
    checkTypes(TSym[(yyvsp[-1].aval).at2].type, (yyvsp[0].aval).at6);
    genStr(TSym[(yyvsp[-1].aval).at2].txt);
    (yyval.aval).at3 = genAddr(0);
    genStr("JNEq");
    (yyval.aval).at1 = (yyvsp[-1].aval).at1;
    (yyval.aval).at2 = (yyvsp[-1].aval).at2;
  }
#line 2357 "y.tab.c" /* yacc.c:1646  */
    break;

  case 99:
#line 562 "kotek.y" /* yacc.c:1646  */
    {
    printf("InstrukcjaCaseStartInstrukcja -> InstrukcjaCaseStart : Instrukcja\n");
    (yyval.aval).at1 = genAddr((yyvsp[-2].aval).at1); // link jumps
    genStr("Jump");
    update((yyvsp[-2].aval).at3, p);
    (yyval.aval).at3 = (yyvsp[-2].aval).at3; // remmember if there is no `else`
    (yyval.aval).at2 = (yyvsp[-2].aval).at2;
  }
#line 2370 "y.tab.c" /* yacc.c:1646  */
    break;

  case 100:
#line 575 "kotek.y" /* yacc.c:1646  */
    {
    checkTypeBoolean((yyvsp[0].aval).at6);
    printf("InstrukcjaRepeat -> InstrukcjaRepeatStart Instrukcja until Wyrazenie\n");
    genAddr((yyvsp[-3].aval).at1);
    genStr("JTrue");
  }
#line 2381 "y.tab.c" /* yacc.c:1646  */
    break;

  case 101:
#line 584 "kotek.y" /* yacc.c:1646  */
    {
    printf("InstrukcjaRepeatStart -> repeat\n");
    (yyval.aval).at1 = p;
  }
#line 2390 "y.tab.c" /* yacc.c:1646  */
    break;

  case 102:
#line 594 "kotek.y" /* yacc.c:1646  */
    {
    printf("InstrukcjaWhile -> InstrukcjaWhileWyrazenie do Instrukcja done \n");
    genAddr((yyvsp[-3].aval).at1);
    genStr("JUMP");
    update((yyvsp[-3].aval).at2, p);
  }
#line 2401 "y.tab.c" /* yacc.c:1646  */
    break;

  case 103:
#line 603 "kotek.y" /* yacc.c:1646  */
    {
    checkTypeBoolean((yyvsp[0].aval).at6);
    printf("InstrukcjaWhileWyrazenie -> InstrukcjaWhileStart Wyrazenie \n");
    (yyval.aval).at1 = (yyvsp[-1].aval).at1;
    (yyval.aval).at2 = genAddr(0);
    genStr("JFalse");
  }
#line 2413 "y.tab.c" /* yacc.c:1646  */
    break;

  case 104:
#line 613 "kotek.y" /* yacc.c:1646  */
    {
    printf("InstrukcjaWhileStart -> while \n");
    (yyval.aval).at1 = p;
  }
#line 2422 "y.tab.c" /* yacc.c:1646  */
    break;

  case 105:
#line 623 "kotek.y" /* yacc.c:1646  */
    {
      printf("InstrukcjaIf -> IfWyrazenieInstrukcja ELSE Instrukcja ENDIF \n");
      update((yyvsp[-3].aval).at1, p);
    }
#line 2431 "y.tab.c" /* yacc.c:1646  */
    break;

  case 106:
#line 628 "kotek.y" /* yacc.c:1646  */
    {
      printf("InstrukcjaIf -> IfWyrazenie ELSE Instrukcja ENDIF \n");
      update((yyvsp[-3].aval).at2, p);
    }
#line 2440 "y.tab.c" /* yacc.c:1646  */
    break;

  case 107:
#line 635 "kotek.y" /* yacc.c:1646  */
    {
    printf("IfWyrazenieInstrukcja -> IfWyrazenie then Instrukcja \n");
    (yyval.aval).at1 = genAddr(0);
    genStr("JUMP");
    update((yyvsp[-2].aval).at2, p); // Update(M1.Jfalse, Current);
  }
#line 2451 "y.tab.c" /* yacc.c:1646  */
    break;

  case 108:
#line 644 "kotek.y" /* yacc.c:1646  */
    {
    checkTypeBoolean((yyvsp[0].aval).at6);
    printf("IfWyrazenie -> if Wyrazenie \n");
    (yyval.aval).at2 = genAddr(0);
    genStr("JFalse");
  }
#line 2462 "y.tab.c" /* yacc.c:1646  */
    break;

  case 109:
#line 653 "kotek.y" /* yacc.c:1646  */
    { printf("DeklaracjaKlasy -> class Ident extends Ident { ListaDeklaracji } \n");}
#line 2468 "y.tab.c" /* yacc.c:1646  */
    break;

  case 110:
#line 656 "kotek.y" /* yacc.c:1646  */
    {
  printf("Ident -> Identyfikator \n");
  char * copy = malloc(strlen(yytext) + 1);
  strcpy(copy, yytext); //because we want copy
  (yyval.sval) = copy;
}
#line 2479 "y.tab.c" /* yacc.c:1646  */
    break;


#line 2483 "y.tab.c" /* yacc.c:1646  */
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
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
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

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

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

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYTERROR;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
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
                  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
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
                  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  return yyresult;
}
#line 664 "kotek.y" /* yacc.c:1906  */

int genStr(char txt[]) {
  strcpy(ONP[p].txt, txt);
  return p++;
}

int genAddr(int addr) {
  ONP[p].ival = addr;
  return p++;
}

void updateList(int startAddr, int newAddr) {
  int address = startAddr;
  do {
    int tmp = ONP[address].ival;
    ONP[address].ival = newAddr;
    address = tmp;
  } while (address);
}

void update(int addr, int newAddr) {
  if(addr >=0  && addr <= p && newAddr >=0 && newAddr <= p) {
    ONP[addr].ival = newAddr;
  }
  else {
    yyerror("Niepoprawny adres do aktualizacji\n");
  }
}

int addSymbol(char symbol[], types type)
{
  int i = 0;

  while (i < symbolsCount)
  {
    if(strcmp(TSym[i].txt, symbol) == 0)
    {
        return i;
    }
    ++i;
  }

  strcpy(TSym[symbolsCount].txt, symbol);
  TSym[symbolsCount].type = type;
  return symbolsCount++;
}

int declareSymbol(char symbol[], types type)
{
  int i = 0;
  while (i < symbolsCount)
  {
      if(strcmp(TSym[i].txt, symbol) == 0)
      {
          yyerror("Ponowna deklaracja symbolu\n");
          return -1;
      }
      ++i;
  }
  strcpy(TSym[symbolsCount].txt, symbol);
  TSym[symbolsCount].type = type;
  return symbolsCount++;
}

int findSymbol(char symbol[])
{
    int i = 0;
    while (i < symbolsCount) {
      if(strcmp(TSym[i].txt, symbol) == 0)
          return i;
      ++i;
    }

    yyerror("Uzycie niezadeklarowanej zmiennej \n");
    return -1;
}

void checkTypeBoolean(types sourceType) {
    if (sourceType != TypeBoolean)
      yyerror("Konfilikt typow - wymagany typ boolean\n");
}

void checkTypeNumeric(types sourceType) {
  if (sourceType != TypeInt && sourceType != TypeReal)
    yyerror("Konfilikt typow - wymagany typ numeryczny\n");
}

types getType(int tSymAddr) {
  return TSym[tSymAddr].type;
}

void checkTypes(types type1, types type2) {
  switch (type1) {
    case TypeReal:
    case TypeInt:
      if (type2 != TypeReal && type2 != TypeInt)
        yyerror("Konfilikt typow - wymagany typ numeryczny\n");
      break;
    case TypeString:
      if (type2 != TypeString) yyerror("Konfilikt typow - wymagany typ string\n");
      break;
    case TypeBoolean:
      if (type2 != TypeBoolean) yyerror("Konfilikt typow - wymagany typ boolean\n");
      break;
  }
}

int yyerror(char *p)
{
	fprintf(stderr,"yyerror: %s yychar: %d txt: %s\n", p, yychar, yytext);
	return 1;
}

int endofcomp(void)
{
  int i = 0;
  fprintf(out,"--     End Of Compilation        --\n");
  fprintf(out,"-----------------------------------\n" );
  fprintf(out,"            ONP              \n ");
  fprintf(out,"-----------------------------------\n" );
  for(i=0; i<p; ++i) {
    if (i % 10 == 0)
      fprintf(out, "\n%d-%d: ", i, i+9);

    if (ONP[i].ival)
      fprintf(out, "addr(%d), ", ONP[i].ival);
    else
      fprintf(out, "%s, ", ONP[i].txt);
  }
  fprintf(out,"\n-----------------------------------\n" );
  fprintf(out,"            Symbols              \n ");
  fprintf(out,"-----------------------------------\n" );
  for(i=0; i<symbolsCount; i++) {

    fprintf(out, "%s: ", TSym[i].txt);

    switch(TSym[i].type) {
      case TypeOwn:
        fprintf(out, "own\n");
        break;
      case TypeInt:
        fprintf(out, "int\n");
        break;
      case TypeReal:
        fprintf(out, "real\n");
        break;
      case TypeVoid:
        fprintf(out, "void\n");
        break;
      case TypeString:
        fprintf(out, "string\n");
        break;
      case TypeBoolean:
        fprintf(out, "boolean\n");
        break;
      default:
        fprintf(stderr, "type %d unrecognized\n", TSym[i].type);
    }
  }
  fprintf(out,"-----------------------------------\n" );
  return (1);
}

#include "lex.yy.c"

int yywrap(void)
{
  printf("***EOF\n");
  return (1);
}

int main(int argc, char *argv[])
{
	if( argc != 2 )
	{
	 printf("usage: Kotek code< input > output \n");
	 exit (1);
	}

        out=fopen(argv[1],"w");
	yyparse();

        endofcomp();
	fclose(out);
	return 1;
}
