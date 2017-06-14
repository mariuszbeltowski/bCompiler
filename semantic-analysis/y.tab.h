/* A Bison parser, made by GNU Bison 3.0.2.  */

/* Bison interface for Yacc-like parsers in C

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
#line 69 "kotek.y" /* yacc.c:1909  */

  int ival;
  ATTRIBUTES aval;
  char *sval;
  double dval;
  char cval;

#line 172 "y.tab.h" /* yacc.c:1909  */
};
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
