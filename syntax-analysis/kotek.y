%{
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

#define  YYDEBUG  0  /* 1 for debugging */

FILE *out;
int  base;
%}

%start prog
%token DIGIT LETTER ARRAY CLASS DELETE DO DONE ELSE ENDIF EXTENDS FUNCTION IF INT NEW NULL_ OF PROGRAM READ RETURN STRING SUPER THEN THIS TYPE VAR VOID WHILE WRITE OPER_UMINUS OPER_UPLUS OPER_ASSIGN OPER_EQUAL OPER_NEQUAL OPER_AND OPER_OR OPER_ELESSER OPER_EGREATER ID INT_VAL REAL_VAL STRING_VAL

%left '+' '-'
%left '*' '/' '%'
%left OPER_UMINUS  /* priorytet dla unarnego minusa */
%left OPER_UPLUS  /* priorytet dla unarnego plusa */

%%
prog :
  PROGRAM ';' Cialo
    { printf("prog -> program ; Cialo \n");}
;

Cialo :
  ListaDeklaracji Blok { printf("Cialo -> ListaDeklaracji Blok \n");}
;

Blok :
  '{' ListaInstrukcji '}' { printf("Blok -> { ListaInstrukcji } \n");}
;

ListaDeklaracji :
  { printf("ListaDeklaracji -> slowo puste \n");}
  | Deklaracja ListaDeklaracji { printf("ListaDeklaracji -> Deklaracja ListaDeklaracji \n");}
;

Deklaracja :
  DeklaracjaTypu { printf("Deklaracja -> DeklaracjaTypu \n");}
  | DeklaracjaZmiennej { printf("Deklaracja -> DeklaracjaZmiennej \n");}
	| DeklaracjaFunkcji { printf("Deklaracja -> DeklaracjaFunkcji \n");}
	| DeklaracjaKlasy { printf("Deklaracja -> DeklaracjaKlasy \n");}
;

DeklaracjaTypu :
  TYPE Ident '=' OpisTypu
    { printf("DeklaracjaTypu -> Type Ident = OpisTypu \n");}
;

OpisTypu :
  Ident { printf("OpisTypu-> Ident \n");}
  | '{' ListaDeklaracjiZmiennej '}'  { printf("OpisTypu -> { ListaDeklaracjiZmiennej } \n");}
	|  ARRAY OF Typ { printf("OpisTypu -> array of Typ \n");}
;

ListaDeklaracjiZmiennej :
  DeklaracjaZmiennej
    { printf("ListaDeklaracjiZmiennej -> DeklaracjaZmiennej \n");}
  | DeklaracjaZmiennej ',' ListaDeklaracjiZmiennej
    { printf("ListaDeklaracjiZmiennej -> DeklaracjaZmiennej , ListaDeklaracjiZmiennej \n");}
;

Typ :
  Ident { printf("Typ -> Ident \n");}
  | STRING { printf("Typ -> string \n");}
	| INT { printf("Typ -> int \n");}
	| VOID { printf("Typ -> void \n");}
;

DeklaracjaZmiennej :
  VAR Ident ':' Typ
    { printf("DeklaracjaZmiennej -> var Ident : Typ \n");}
;

DeklaracjaFunkcji :
  FUNCTION Ident '(' DeklaracjaArgumentow ')' ':' Typ Cialo
    { printf("DeklaracjaFunkcji -> function Ident ( DeklaracjaArgumentow ) : Typ Cialo \n");}
;

DeklaracjaArgumentow :
  ListaDeklaracjiZmiennej { printf("DeklaracjaArgumentow -> ListaDeklaracjiZmiennej \n");}
  | { printf("DeklaracjaArgumentow -> Slowo puste \n");}
;

ListaInstrukcji :
  { printf("ListaInstrukcji -> Slowo puste \n");}
  | Instrukcja ListaInstrukcji { printf("ListaInstrukcji -> Instrukcja ListaInstrukcji \n");}
;

Instrukcja :
  Wyrazenie ';' { printf("Instrukcja ->  Wyrazenie ; \n");}
  | ZlozonaInstrukcja ';' { printf("Instrukcja -> ZlozonaInstrukcja ; \n");}
  | WyrazeniePostfiksowe OPER_ASSIGN Wyrazenie ';'{ printf("Instrukcja -> WyrazeniePostfiksowe := Wyrazenie ; \n");}
  | Blok { printf("Instrukcja -> Blok \n");}
	| DELETE Wyrazenie ';'  { printf("Instrukcja -> delete Wyrazenie ; \n");}
	| ';'  { printf("Instrukcja -> ; \n");}
	| READ Ident ';'  { printf("Instrukcja -> read Ident  ; \n");}
	| WRITE Wyrazenie ';' { printf("Instrukcja -> write Wyrazenie ; \n");}
	| RETURN Wyrazenie ';' { printf("Instrukcja -> return Wyrazenie ; \n");}
	| RETURN ';' { printf("Instrukcja -> return ; \n");}
;

WyrazeniePodstawowe :
  Ident { printf("WyrazeniePodstawowe -> Ident \n");}
	| STRING_VAL { printf("WyrazeniePodstawowe -> STRING_VAL \n");}
	| INT_VAL { printf("WyrazeniePodstawowe -> INT_VAL \n");}
  | REAL_VAL { printf("WyrazeniePodstawowe -> REAL_VAL \n");}
	| '(' Wyrazenie ')' { printf("WyrazeniePodstawowe -> (Wyrazenie) \n");}
	| THIS { printf("WyrazeniePodstawowe -> this \n");}
	| SUPER  { printf("WyrazeniePodstawowe -> super \n");}
	| NULL_  { printf("WyrazeniePodstawowe -> null \n");}
;

WyrazeniePostfiksowe :
  WyrazeniePostfiksowe '[' Wyrazenie ']'
    { printf("WyrazeniePostfiksowe -> WyrazeniePostfiksowe [Wyrazenie] \n");}
  | WyrazeniePostfiksowe '(' Parametry ')'
    { printf("WyrazeniePostfiksowe -> WyrazeniePostfiksowe (Parametry) \n");}
  | WyrazeniePostfiksowe '.' Ident
    { printf("WyrazeniePostfiksowe -> WyrazeniePostfiksowe . Ident \n");}
  | WyrazeniePodstawowe
    { printf("WyrazeniePostfiksowe -> WyrazeniePodstawowe \n");}
;

Parametry :
		  |  ListaWyrazen { printf("Parametry -> ListaWyrazen \n");}
;

ListaWyrazen :
  Wyrazenie { printf("ListaWyrazen -> Wyrazenie \n");}
  | Wyrazenie ',' ListaWyrazen { printf("ListaWyrazen -> Wyrazenie , ListaWyrazen \n");}
;

WyrazenieUnarne :
  OperatorUnarny WyrazenieUnarne
    { printf("WyrazenieUnarne -> OperatorUnarny WyrazenieUnarne \n");}
	| WyrazeniePostfiksowe
    { printf("WyrazenieUnarne -> WyrazeniePostfiksowe \n");}
;

OperatorUnarny :
  OPER_UMINUS { printf("OperatorUnarny -> - \n");}
  | OPER_UPLUS { printf("OperatorUnarny -> + \n");}
  | '!' { printf("OperatorUnarny -> ! \n");}
;

WyrazenieMultiplikatywne :
  WyrazenieMultiplikatywne OperatorMultiplikatywny WyrazenieUnarne
    { printf("WyrazenieMultiplikatywne -> WyrazenieMultiplikatywne OperatorMultiplikatywny WyrazenieUnarne \n");}
  | WyrazenieUnarne
    { printf(" WyrazenieMultiplikatywne -> WyrazenieUnarne \n");}
;

WyrazenieAddytywne :
  WyrazenieAddytywne OperatorAddytywny WyrazenieMultiplikatywne
    { printf("WyrazenieAddytywne -> WyrazenieAddytywne OperatorAddytywny WyrazenieMultiplikatywne \n");}
  | WyrazenieMultiplikatywne
    { printf("WyrazenieAddytywne -> WyrazenieMultiplikatywne \n");}
;

OperatorMultiplikatywny :
  '*' { printf("OperatorMultiplikatywny -> * \n");}
  | '/' { printf("OperatorMultiplikatywny -> '\' \n");}
;

OperatorAddytywny :
  '+' { printf("OperatorAddytywny -> + \n");}
  | '-' { printf("OperatorAddytywny -> - \n");}
;

WyrazeniePorownania :
  WyrazenieAddytywne OperatorPorownania WyrazenieAddytywne
    { printf("WyrazeniePorownania -> Wyrazenieaddytywne OperatorPorownania WyrazenieAddytywne \n");}
  | WyrazenieAddytywne
    { printf("WyrazeniePorownania -> WyrazenieAddytywne \n");}
;

OperatorPorownania :
  '<' { printf("OperatorPorownania -> < \n");}
  | '>' { printf("OperatorPorownania -> > \n");}
	| OPER_ELESSER { printf("OperatorPorownania -> <= \n");}
	| OPER_EGREATER    { printf("OperatorPorownania -> >= \n");}
	| OPER_EQUAL { printf("OperatorPorownania -> == \n");}
	| OPER_NEQUAL { printf("OperatorPorownania -> != \n");}
;

WyrazenieLogiczne :
  WyrazeniePorownania OperatorLogiczny WyrazeniePorownania
    { printf("Wyrazenielogiczne -> WyrazeniePorownania OperatorLogiczny WyrazeniePorownania \n");}
  | WyrazeniePorownania
    { printf("Wyrazenielogiczne -> WyrazeniePorownania \n");}
;

OperatorLogiczny :
  OPER_OR
    { printf("OperatorLogiczny -> || \n");}
  | OPER_AND
    { printf("OperatorLogiczny -> && \n");}
;

Wyrazenie :
  WyrazenieLogiczne
    { printf("Wyrazenie -> Wyrazenielogiczne \n");}
	| NEW Typ
    { printf("Wyrazenie -> new Typ \n");}
	| NEW Typ '[' Wyrazenie ']'
    { printf("Wyrazenie -> new Typ [Wyrazenie] \n");}
;

ZlozonaInstrukcja :
  IF Wyrazenie THEN ListaInstrukcji ELSE ListaInstrukcji ENDIF
    { printf("ZlozonaInstrukcja -> if Wyrazenie then ListaInstrukcji else ListaInstrukcji endif \n");}
  | IF Wyrazenie THEN ListaInstrukcji ENDIF
    { printf("ZlozonaInstrukcja -> if Wyrazenie then ListaInstrukcji endif \n");}
  | WHILE Wyrazenie DO ListaInstrukcji DONE
    { printf("ZlozonaInstrukcja -> while Wyrazenie do ListaInstrukcji done \n");}
;

DeklaracjaKlasy : CLASS Ident EXTENDS Ident '{' ListaDeklaracji '}'
{ printf("DeklaracjaKlasy -> class Ident extends Ident { ListaDeklaracji } \n");}
;

Ident : ID { printf("Ident -> Identyfikator \n");}
;

%%
int yyerror(char *p)
{
	fprintf(stderr,"yyerror: %s yychar: %d \n", p, yychar);
	return 1;
}

int endofcomp(void)
{
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
