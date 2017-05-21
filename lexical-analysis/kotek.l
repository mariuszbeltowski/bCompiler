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
array|class|delete|do|done|else|endif|extends|function|if|int|new|null|of|program|read|return|string|super|then|this|type|var|void|while|write {
  printf("KEYWORD(\"%s\")\n", yytext);
  //return "KEYWORD";
}

<unary>"-"|"+" {
  BEGIN INITIAL;
  printf("OPER_UNARNY\n");
  //return "OPER_UNARNY";
}

"+"|"-" {
  BEGIN unary;
  printf("OPER_ADDITIVE\n");
  //return "OPER_ADDITIVE";
}

"="|":=" {
  BEGIN unary;
  printf("OPER_ASSIGN\n");
  //return "OPER_ASSIGN";
}

"*"|"/" {
  BEGIN unary;
  printf("OPER_MULTIPLICATIVE\n");
  //return "OPER_MULTIPLICATIVE";
}

"(" {
  BEGIN unary;
  printf("OPER_BRACKET\n");
  //return "OPER_BRACKET";
}
")" {
  BEGIN INITIAL;
  printf("OPER_BRACKET\n");
  //return "OPER_BRACKET";
}

"[" {
  BEGIN unary;
  printf("OPER_SQBRACKET\n");
  //return "OPER_SQBRACKET";
}
"]" {
  BEGIN INITIAL;
  printf("OPER_SQBRACKET\n");
  //return "OPER_SQBRACKET";
}

"{"|"}" {
  printf("OPER_BRACE\n");
  //return "OPER_BRACE";
}

";" {
  printf("OPER_SEMICOLON\n");
  //return "OPER_SEMICOLON";
}
":" {
  printf("OPER_COLON\n");
  //return "OPER_COLON";
}
"," {
  printf("OPER_COMMA\n");
  //return "OPER_COMMA";
}
"." {
  printf("OPER_DOT\n");
  //return "OPER_DOT";
}
"!" {
  printf("OPER_NEG\n");
  //return "OPER_NEG";
}

"&&"|"||" {
  BEGIN unary;
  printf("OPER_LOGIC\n");
  //return "OPER_LOGIC";
}

"<"|">"|"<="|">="|"=="|"!=" {
  BEGIN unary;
  printf("OPER_REL\n");
  //return "OPER_REL";
}

{ID} {
  BEGIN INITIAL;
  printf("ID(\"%s\")\n", yytext);
}

{INTEGER} {
  printf("INT(%s)\n", yytext);
}

{DIGIT}+"."{DIGIT}*({EXP})?  |
{DIGIT}*"."{DIGIT}+({EXP})?  |
{DIGIT}+{EXP} printf("REAL(%s) -> %g \n", yytext, atof(yytext));

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
             printf("STRING(\"%s\")\n", string_buffer);
             //return "STRING";
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
  printf("error(line:%d): illegal char: %c\n", line_number, yytext[0]);
}


%%

int yywrap()
{
  printf("EOF\n");
  return 1;
}

int main( int argc, char **argv )
{
   if ( argc > 1 )
             yyin = fopen( argv[1], "r" );
   else
             yyin = stdin;

   printf("Plik: %s\n", argv[0]);
   printf("----------------------------------------\n");
   yylex();
   return 0;
}
