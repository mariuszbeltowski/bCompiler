%{
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
%}

%start prog

%union {
  int ival;
  ATTRIBUTES aval;
  char *sval;
  double dval;
  char cval;
}

%token DIGIT LETTER ARRAY CLASS DELETE DO DONE ELSE ENDIF EXTENDS FUNCTION IF
%token INT NEW NULL_ OF PROGRAM READ RETURN STRING SUPER THEN THIS TYPE VAR VOID
%token WHILE WRITE OPER_UMINUS OPER_UPLUS OPER_ASSIGN OPER_EQUAL OPER_NEQUAL
%token OPER_GREATER OPER_LESSER
%token OPER_AND OPER_OR OPER_ELESSER OPER_EGREATER ID INT_VAL REAL_VAL
%token STRING_VAL REAL BOOLEAN TRUE FALSE REPEAT UNTIL FOR TO DOWNTO CASE

%type <aval> IfWyrazenieInstrukcja IfWyrazenie
%type <aval> InstrukcjaWhile InstrukcjaWhileWyrazenie InstrukcjaWhileStart
%type <aval> InstrukcjaRepeatStart InstrukcjaRepeat
%type <aval> InstrukcjaCase InstrukcjaCaseStart InstrukcjaCaseStartInstrukcja
%type <aval> InstrukcjaForStart InstrukcjaFor InstrukcjaForAss InstrukcjaForId
%type <aval> Wyrazenie WyrazeniePodstawowe WyrazeniePostfiksowe WyrazenieUnarne
%type <aval> WyrazenieMultiplikatywne WyrazenieAddytywne WyrazeniePorownania
%type <aval> WyrazenieLogiczne

%type <ival> Typ INT_VAL OperatorPorownania
%type <sval> Ident STRING_VAL
%type <dval> REAL_VAL
%type <cval> OperatorUnarny OperatorMultiplikatywny OperatorAddytywny TO_DOWNTO

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
  Ident { printf("Typ -> Ident \n"); $$ = TypeOwn; }
  | STRING { printf("Typ -> string \n"); $$ = TypeString; }
	| INT { printf("Typ -> int \n"); $$ = TypeInt; }
	| VOID { printf("Typ -> void \n"); $$ = TypeVoid; }
  | REAL { printf("Typ -> real \n"); $$ = TypeReal; }
  | BOOLEAN { printf("Typ -> boolean \n"); $$ = TypeBoolean; }
;

DeklaracjaZmiennej :
  VAR Ident ':' Typ
    {
      printf("DeklaracjaZmiennej -> var Ident : Typ \n");
      declareSymbol($2, $4);
    }
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
  | WyrazeniePostfiksowe OPER_ASSIGN Wyrazenie ';'
    {
      printf("Instrukcja -> WyrazeniePostfiksowe := Wyrazenie ; \n");
      genStr(":=");
    }
  | Blok { printf("Instrukcja -> Blok \n");}
	| DELETE Wyrazenie ';'  {
    printf("Instrukcja -> delete Wyrazenie ; \n");
    genStr("delete");
  }
	| ';'  { printf("Instrukcja -> ; \n");}
	| READ Ident ';'  {
    printf("Instrukcja -> read Ident  ; \n");
    genStr($2);
    genStr("read");
  }
	| WRITE Wyrazenie ';' {
    printf("Instrukcja -> write Wyrazenie ; \n");
    genStr("write");
  }
	| RETURN Wyrazenie ';' {
    printf("Instrukcja -> return Wyrazenie ; \n");
    genStr("return");
  }
	| RETURN ';' {
    printf("Instrukcja -> return ; \n");
    genStr("return");
  }
;

WyrazeniePodstawowe :
  Ident
    {
      printf("WyrazeniePodstawowe -> Ident \n");
      $$.at1 = TypeOwn;
      int i = findSymbol($1);
      $$.at2 = i;
      if(i != -1)
      {
        $$.at3 = TSym[i].type;
        $$.at6 = TSym[i].type;
      }
    }
	| STRING_VAL {
    printf("WyrazeniePodstawowe -> STRING_VAL \n");
    $$.at1 = TypeString;
    $$.at2 = addSymbol(yytext, TypeString);
    $$.at6 = TypeString;
  }
	| INT_VAL {
    printf("WyrazeniePodstawowe -> INT_VAL %d\n", $1);
    $$.at1 = TypeInt;
    $$.at2 = addSymbol(yytext, TypeInt);
    $$.at6 = TypeInt;
  }
  | REAL_VAL {
    printf("WyrazeniePodstawowe -> REAL_VAL \n");
    $$.at1 = TypeReal;
    $$.at2 = addSymbol(yytext, TypeReal);
    $$.at6 = TypeReal;
  }
  | TRUE {
    printf("WyrazeniePodstawowe -> TRUE \n");
    $$.at1 = TypeBoolean;
    $$.at2 = addSymbol(yytext, TypeBoolean);
    $$.at6 = TypeBoolean;
  }
  | FALSE {
    printf("WyrazeniePodstawowe -> FALSE \n");
    $$.at1 = TypeBoolean;
    $$.at2 = addSymbol(yytext, TypeBoolean);
    $$.at6 = TypeBoolean;
  }
	| '(' Wyrazenie ')' {
    printf("WyrazeniePodstawowe -> (Wyrazenie) \n");
    $$ = $2;
  }
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
  | WyrazeniePodstawowe {
    printf("WyrazeniePostfiksowe -> WyrazeniePodstawowe \n");
    printf("Podstawowe typ: %d, %d, %d\n", $1.at1, TypeInt, TypeReal);
    printf("Typ: %s, %d\n", TSym[$1.at2].txt, getType($1.at2));
    $$ = $1;
    genStr(TSym[$1.at2].txt);
  }
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
    {
      printf("WyrazenieUnarne -> OperatorUnarny WyrazenieUnarne \n");
      printf("typ unarny: %d, %d, %d", $2.at1, TypeInt, TypeReal);
      $$.at1 = $2.at1;
      $$.at6 = $2.at6;
      genStr(TSym[$2.at2].txt);
      switch($1) {
        case '!':
          checkTypeBoolean(getType($2.at2));
          genStr("!");
          break;
        case '-':
          checkTypeNumeric(getType($2.at2));
          genStr("u-");
          break;
        case '+':
          checkTypeNumeric(getType($2.at2));
          genStr("u+");
          break;
      }
    }
	| WyrazeniePostfiksowe {
    printf("WyrazenieUnarne -> WyrazeniePostfiksowe\n");
    $$.at1 = $1.at1;
    $$.at2 = $1.at2;
    $$.at6 = $1.at6;
  }
;

OperatorUnarny :
  OPER_UMINUS { printf("OperatorUnarny -> - \n"); $$ = '-'; }
  | OPER_UPLUS { printf("OperatorUnarny -> + \n"); $$ = '+'; }
  | '!' { printf("OperatorUnarny -> ! \n"); $$ = '!'; }
;

WyrazenieMultiplikatywne :
  WyrazenieMultiplikatywne OperatorMultiplikatywny WyrazenieUnarne
    {
      printf("WyrazenieMultiplikatywne -> WyrazenieMultiplikatywne OperatorMultiplikatywny WyrazenieUnarne \n");
      printf("tpyyy %d, %d, real%d, int%d", getType($1.at2), getType($3.at2), TypeInt, TypeReal);
      checkTypeNumeric(getType($1.at2));
      checkTypeNumeric(getType($3.at2));
      switch($2) {
        case '*':
          genStr("*");
          break;
        case '/':
          genStr("/");
          break;
      }
    }
  | WyrazenieUnarne {
    printf(" WyrazenieMultiplikatywne -> WyrazenieUnarne \n");
    $$ = $1;
  }
;

WyrazenieAddytywne :
  WyrazenieAddytywne OperatorAddytywny WyrazenieMultiplikatywne
    {
      printf("WyrazenieAddytywne -> WyrazenieAddytywne OperatorAddytywny WyrazenieMultiplikatywne \n");
      $$ = $1;
      checkTypeNumeric(getType($1.at2));
      checkTypeNumeric(getType($3.at2));
      switch($2) {
        case '+':
          genStr("+");
          break;
        case '-':
          genStr("-");
          break;
      }
    }
  | WyrazenieMultiplikatywne {
    printf("WyrazenieAddytywne -> WyrazenieMultiplikatywne \n");
    $$ = $1;
  }
;

OperatorMultiplikatywny :
  '*' { printf("OperatorMultiplikatywny -> * \n"); $$ = '*'; }
  | '/' { printf("OperatorMultiplikatywny -> '\' \n"); $$ = '/'; }
;

OperatorAddytywny :
  '+' { printf("OperatorAddytywny -> + \n"); $$ = '+'; }
  | '-' { printf("OperatorAddytywny -> - \n"); $$ = '-'; }
;

WyrazeniePorownania :
  WyrazenieAddytywne OperatorPorownania WyrazenieAddytywne
    {
      printf("WyrazeniePorownania -> Wyrazenieaddytywne OperatorPorownania WyrazenieAddytywne \n");
      $$.at1 = TypeBoolean;
      $$.at6 = TypeBoolean;
      int type1 = getType($1.at2);
      int type2 = getType($3.at2);
      if (type1 == TypeInt || type1 == TypeReal) {
        if (type2 != TypeInt && type2 != TypeReal)
          yyerror("Typ porownania nie poprawny\n");
      }
      if (type1 == TypeBoolean && type2 != TypeBoolean)
        yyerror("Typ porownania nie poprawny\n");
      if (type1 == TypeString && type2 != TypeString)
        yyerror("Typ porownania nie poprawny\n");

      switch ($2) {
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
  | WyrazenieAddytywne {
    $$.at1 = getType($1.at1);
    $$.at6 = $1.at6;
    printf("WyrazeniePorownania -> WyrazenieAddytywne \n");
  }
;

OperatorPorownania :
  OPER_LESSER { printf("OperatorPorownania -> < \n"); $$ = OPER_LESSER; }
  | OPER_GREATER { printf("OperatorPorownania -> > \n"); $$ = OPER_GREATER; }
	| OPER_ELESSER { printf("OperatorPorownania -> <= \n"); $$ = OPER_ELESSER; }
	| OPER_EGREATER    { printf("OperatorPorownania -> >= \n"); $$ = OPER_EGREATER; }
	| OPER_EQUAL { printf("OperatorPorownania -> == \n"); $$ = OPER_EQUAL; }
	| OPER_NEQUAL { printf("OperatorPorownania -> != \n"); $$ = OPER_NEQUAL; }
;

WyrazenieLogiczne :
  WyrazeniePorownania OPER_OR WyrazeniePorownania
    {
      $$ = $1;
      printf("Wyrazenielogiczne -> WyrazeniePorownania || WyrazeniePorownania \n");
      genStr("||");
    }
  | WyrazeniePorownania OPER_AND WyrazeniePorownania
    {
      $$ = $1;
      printf("Wyrazenielogiczne -> WyrazeniePorownania && WyrazeniePorownania \n");
      genStr("&&");
    }
  | WyrazeniePorownania {
    $$ = $1; printf("Wyrazenielogiczne -> WyrazeniePorownania \n");}
;

Wyrazenie :
  WyrazenieLogiczne {
    $$ = $1;
    printf("Wyrazenie -> Wyrazenielogiczne \n");
  }
	| NEW Typ
    { printf("Wyrazenie -> new Typ \n");}
	| NEW Typ '[' Wyrazenie ']'
    { printf("Wyrazenie -> new Typ [Wyrazenie] \n");}
;

ZlozonaInstrukcja :
  InstrukcjaIf
  | InstrukcjaWhile
  | InstrukcjaRepeat
  | InstrukcjaCase
  | InstrukcjaFor
;

// FOR
// at1 - Jump, at2 - JEq, at3 - zm, at4 - todownto, at5 - wyr2
InstrukcjaForId :
  Ident {
    $$.at3 = findSymbol(yytext);
    genStr(yytext);
  }
;

InstrukcjaForAss :
  FOR InstrukcjaForId OPER_ASSIGN Wyrazenie {
    printf("InstrukcjaForAss -> for Ident := Wyrazenie \n");
    checkTypes(getType($2.at3), $4.at6);
    genStr(":=");
    $$.at3 = $2.at3; //zm
    $$.at1 = p;
  }
;

TO_DOWNTO :
  TO { $$ = '+'; }
  | DOWNTO {$$ = '-'; }
;

InstrukcjaForStart :
  InstrukcjaForAss TO_DOWNTO Wyrazenie {
    $$.at1 = $1.at1; // begin of for iteration
    $$.at4 = $2; // + or -
    checkTypes(getType($1.at3), $3.at6);
    printf("type: %d, %d\n", getType($1.at3), $3.at6);

    genStr(TSym[$1.at3].txt); //zm
    $$.at2 = genAddr(0); // end of for address
    genStr("JEq");
    printf("InstrukcjaForStart -> InstrukcjaForAss to Wyrazenie \n");
  }
;

InstrukcjaFor :
  InstrukcjaForStart DO Instrukcja {
    printf("InstrukcjaFor -> InstrukcjaForStart do Instrukcja \n");
    genStr(TSym[$1.at3].txt);
    genStr(TSym[$1.at3].txt);
    genStr("1");
    char t[2] = {(char)$1.at4, '\0'};
    genStr(t);
    genStr(":=");
    genAddr($1.at1);
    genStr("Jump");
    update($1.at2, p);
  }
;

// CASE OF
// at1 - Jump, at2 - zm, at3 - JNEq
InstrukcjaCase :
  InstrukcjaCaseStartInstrukcja ELSE Instrukcja {
    printf("InstrukcjaCase -> InstrukcjaCaseStartInstrukcja else ListaInstrukcji \n");
    updateList($1.at1, p);
  }
  | InstrukcjaCaseStartInstrukcja {
    printf("InstrukcjaCase -> InstrukcjaCaseStartInstrukcja \n");
    p -= 2; // remove last jump
    update($1.at3, p);
    updateList($1.at1, p);
  }
;

InstrukcjaCaseStart :
  CASE Ident OF Wyrazenie {
    printf("InstrukcjaCaseStart -> case Ident of Wyrazenie\n");
    $$.at1 = 0; //init jump
    $$.at2 = findSymbol($2);
    checkTypes(TSym[$$.at2].type, $4.at6);
    genStr(TSym[$$.at2].txt);
    $$.at3 = genAddr(0);
    genStr("JNEq");
  }
  | InstrukcjaCaseStartInstrukcja Wyrazenie {
    printf("InstrukcjaCaseStart -> InstrukcjaCaseStartInstrukcja Wyrazenie\n");
    checkTypes(TSym[$1.at2].type, $2.at6);
    genStr(TSym[$1.at2].txt);
    $$.at3 = genAddr(0);
    genStr("JNEq");
    $$.at1 = $1.at1;
    $$.at2 = $1.at2;
  }
;

InstrukcjaCaseStartInstrukcja :
  InstrukcjaCaseStart ':' Instrukcja {
    printf("InstrukcjaCaseStartInstrukcja -> InstrukcjaCaseStart : Instrukcja\n");
    $$.at1 = genAddr($1.at1); // link jumps
    genStr("Jump");
    update($1.at3, p);
    $$.at3 = $1.at3; // remmember if there is no `else`
    $$.at2 = $1.at2;
  }
;

// REPEAT UNTIL
// at1 - Jump
InstrukcjaRepeat :
  InstrukcjaRepeatStart Instrukcja UNTIL Wyrazenie {
    checkTypeBoolean($4.at6);
    printf("InstrukcjaRepeat -> InstrukcjaRepeatStart Instrukcja until Wyrazenie\n");
    genAddr($1.at1);
    genStr("JTrue");
  }
;

InstrukcjaRepeatStart :
  REPEAT {
    printf("InstrukcjaRepeatStart -> repeat\n");
    $$.at1 = p;
  }
;

// WHILE
// at1- Jump, at2 - JFalse
InstrukcjaWhile :
  InstrukcjaWhileWyrazenie DO Instrukcja DONE
  {
    printf("InstrukcjaWhile -> InstrukcjaWhileWyrazenie do Instrukcja done \n");
    genAddr($1.at1);
    genStr("JUMP");
    update($1.at2, p);
  }
;

InstrukcjaWhileWyrazenie :
  InstrukcjaWhileStart Wyrazenie {
    checkTypeBoolean($2.at6);
    printf("InstrukcjaWhileWyrazenie -> InstrukcjaWhileStart Wyrazenie \n");
    $$.at1 = $1.at1;
    $$.at2 = genAddr(0);
    genStr("JFalse");
  }
;

InstrukcjaWhileStart :
  WHILE {
    printf("InstrukcjaWhileStart -> while \n");
    $$.at1 = p;
  }
;

// IF ELSE
// at1 - jump , at2 - jfalse
InstrukcjaIf :
  IfWyrazenieInstrukcja ELSE Instrukcja ENDIF
    {
      printf("InstrukcjaIf -> IfWyrazenieInstrukcja ELSE Instrukcja ENDIF \n");
      update($1.at1, p);
    }
  | IfWyrazenie THEN ListaInstrukcji ENDIF
    {
      printf("InstrukcjaIf -> IfWyrazenie ELSE Instrukcja ENDIF \n");
      update($1.at2, p);
    }
;

IfWyrazenieInstrukcja :
  IfWyrazenie THEN Instrukcja {
    printf("IfWyrazenieInstrukcja -> IfWyrazenie then Instrukcja \n");
    $$.at1 = genAddr(0);
    genStr("JUMP");
    update($1.at2, p); // Update(M1.Jfalse, Current);
  }
;

IfWyrazenie :
  IF Wyrazenie {
    checkTypeBoolean($2.at6);
    printf("IfWyrazenie -> if Wyrazenie \n");
    $$.at2 = genAddr(0);
    genStr("JFalse");
  }
;

DeklaracjaKlasy : CLASS Ident EXTENDS Ident '{' ListaDeklaracji '}'
{ printf("DeklaracjaKlasy -> class Ident extends Ident { ListaDeklaracji } \n");}
;

Ident : ID {
  printf("Ident -> Identyfikator \n");
  char * copy = malloc(strlen(yytext) + 1);
  strcpy(copy, yytext); //because we want copy
  $$ = copy;
}
;

%%
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
