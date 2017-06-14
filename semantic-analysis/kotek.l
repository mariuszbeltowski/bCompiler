/* Skaner dla jezyka C*/

%{

#include <stdio.h>

#define STRING_BUFFER 256
#define DEFINE_ARRAY 128

int line_number = 0;
char string_buffer[STRING_BUFFER],*p_string_buffer;

%}

DIGIT   [0-9]
ID      [[:alpha:]][[:alnum:][\_]*]*
INTEGER {DIGIT}+
EXP     [Ee][-+]?{DIGIT}+

%x string comment
%s unary

%%
"array" { printf("token: %s\n", yytext); return ARRAY; }
"boolean" { printf("token: %s\n", yytext); return BOOLEAN; }
"class" { printf("token: %s\n", yytext); return CLASS; }
"delete" { printf("token: %s\n", yytext); return DELETE; }
"do" { printf("token: %s\n", yytext); return DO; }
"done" { printf("token: %s\n", yytext); return DONE; }
"else" { printf("token: %s\n", yytext); return ELSE; }
"endif" { printf("token: %s\n", yytext); return ENDIF; }
"extends" { printf("token: %s\n", yytext); return EXTENDS; }
"function" { printf("token: %s\n", yytext); return FUNCTION; }
"if" { printf("token: %s\n", yytext); return IF; }
"int" { printf("token: %s\n", yytext); return INT; }
"new" { printf("token: %s\n", yytext); return NEW; }
"null" { printf("token: %s\n", yytext); return NULL_; }
"of" { printf("token: %s\n", yytext); return OF; }
"program" { printf("token: %s\n", yytext); return PROGRAM; }
"read" { printf("token: %s\n", yytext); return READ; }
"real" { printf("token: %s\n", yytext); return REAL; }
"return" { printf("token: %s\n", yytext); return RETURN; }
"string" { printf("token: %s\n", yytext); return STRING; }
"super" { printf("token: %s\n", yytext); return SUPER; }
"then" { printf("token: %s\n", yytext); return THEN; }
"this" { printf("token: %s\n", yytext); return THIS; }
"type" { printf("token: %s\n", yytext); return TYPE; }
"var" { printf("token: %s\n", yytext); return VAR; }
"void" { printf("token: %s\n", yytext); return VOID; }
"while" { printf("token: %s\n", yytext); return WHILE; }
"write" { printf("token: %s\n", yytext); return WRITE; }
"true" { printf("token: %s\n", yytext); return TRUE; }
"false" { printf("token: %s\n", yytext); return FALSE; }
"repeat" { printf("token: %s\n", yytext); return REPEAT; }
"until" { printf("token: %s\n", yytext); return UNTIL; }
"for" { printf("token: %s\n", yytext); return FOR; }
"to" { printf("token: %s\n", yytext); return TO; }
"downto" { printf("token: %s\n", yytext); return DOWNTO; }
"case" { printf("token: %s\n", yytext); return CASE; }

<unary>"-" {
  BEGIN INITIAL;
  printf("token: %s (unary)\n", yytext);
  return OPER_UMINUS;
}

<unary>"+" {
  BEGIN INITIAL;
  printf("token: %s (unary)\n", yytext);
  return OPER_UPLUS;
}

"+" { printf("token: %s\n", yytext); return '+'; }
"-" { printf("token: %s\n", yytext); return '-'; }

"=" { printf("token: %s\n", yytext); return '='; }
":=" {
  BEGIN unary;
  printf("token: %s\n", yytext);
  return OPER_ASSIGN;
}

"*" {
  BEGIN unary;
  printf("token: %s\n", yytext);
  return '*';
}
"/" {
  BEGIN unary;
  printf("token: %s\n", yytext);
  return '/';
}
"%" {
  BEGIN unary;
  printf("token: %s\n", yytext);
  return '%';
}

"==" {
  BEGIN unary;
  printf("token: %s\n", yytext);
  return OPER_EQUAL;
}
"!=" {
  BEGIN unary;
  printf("token: %s\n", yytext);
  return OPER_NEQUAL;
}

"(" {
  BEGIN unary;
  printf("token: %s\n", yytext);
  return '(';
}
")" {
  BEGIN INITIAL;
  printf("token: %s\n", yytext);
  return ')';
}

";" { printf("token: %s\n", yytext); return ';'; }
":" { printf("token: %s\n", yytext); return ':'; }

"," { printf("token: %s\n", yytext); return ','; }
"." { printf("token: %s\n", yytext); return '.'; }

"!" { printf("token: %s\n", yytext); return '!'; }

"&&" {
  BEGIN unary;
  printf("token: %s\n", yytext);
  return OPER_AND;
}
"||" {
  BEGIN unary;
  printf("token: %s\n", yytext);
  return OPER_OR;
}

"[" {
  BEGIN unary;
  printf("token: %s\n", yytext);
  return '[';
}
"]" {
  BEGIN INITIAL;
  printf("token: %s\n", yytext);
  return ']';
}

"{" { printf("token: %s\n", yytext); return '{'; }
"}" { printf("token: %s\n", yytext); return '}'; }

"<" {
  BEGIN unary;
  printf("token: %s\n", yytext);
  return OPER_LESSER;
}
">" {
  BEGIN unary;
  printf("token: %s\n", yytext);
  return OPER_GREATER;
}
"<=" {
  BEGIN unary;
  printf("token: %s\n", yytext);
  return OPER_ELESSER;
}
">=" {
  BEGIN unary;
  printf("token: %s\n", yytext);
  return OPER_EGREATER;
}

{ID} {
  BEGIN INITIAL;
  printf("token: ID (\"%s\")\n", yytext);
  return ID;
}

{INTEGER} {
  printf("token: INT_VAL (%s)\n", yytext);
  return INT_VAL;
}

{DIGIT}+"."{DIGIT}*({EXP})?  |
{DIGIT}*"."{DIGIT}+({EXP})?  |
{DIGIT}+{EXP} {
  printf("token: REAL_VAL (%s) -> %g \n", yytext, atof(yytext));
  return REAL_VAL;
}

\"     {
         p_string_buffer = string_buffer;
         BEGIN string;
       }

<string>[^\\\n\"]+ {
                     char *yptr = yytext;
                     while (*yptr)
                        *p_string_buffer++ = *yptr++;
                   }

<string>\n   line_number++;

<string>\\\" {yymore();}

<string>\" {
             BEGIN INITIAL;
             *p_string_buffer = '\0';
             printf("token: STRING_VAL (\"%s\")\n", string_buffer);
             return STRING_VAL;
           }

"//"[^\n]* line_number++;

"/*"                   { yymore(); BEGIN comment; }

<comment>[^*\n]+       { yymore();}
<comment>"*"+[^*/\n]*  { yymore();}
<comment>\n            { yymore(); line_number++; }

<comment>"*"+"/"  {
                    BEGIN INITIAL;
                    //printf("Komentarz: \n%s\n", yytext);
                  }

[ \t]+

"\n"     {
          printf("Line: %d\n\n", line_number++);
         }

.        {
  fprintf(stderr, "error(line:%d): illegal char: %c\n", line_number, yytext[0]);
  // printf("error(line:%d): illegal char: %c\n", line_number, yytext[0]);
}

%%
