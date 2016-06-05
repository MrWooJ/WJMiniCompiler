%{
#include <string.h>
#include "yystype.h"
#include "yygrammar.h"
%}

DIGIT [0-9]
VARIABLE [a-zA-Z]+[0-9]*

ID1 _?{VARIABLE}_?*{VARIABLE}*
ID (([a-zA-Z]+[0-9]*)(_{0,2}([a-zA-Z]|[0-9])+)*)|(_{1,2}([a-zA-Z]|[0-9])+(_{0,2}([a-zA-Z]|[0-9])+)*)

BOOLKEY bool
BREAKKEY break
CASEKEY case
CHARKEY char
CONSTKEY const
CONTINUEKEY continue
DEFAULTKEY default
DOUBLEKEY double
ELSEKEY else
EXTERNKEY extern
FUNCTIONKEY function
FLOATKEY float
FORKEY for
GOTOKEY goto
IFKEY if
INPUTKEY input
INTKEY int
LONGKEY long
OUTPUTKEY output
RETURNKEY return
SZIEOFKEY sizeof
STATICKEY static
STRINGKEY string
SWITChKEY switch
VOIDKEY void
UNTILKEY until
RECORDKEY record
REPEATKEY repeat 
PROCEDUREKEY procedure
FOREACHKEY foreach
AUTOKEY auto
OFKEY of
INKEY in

%%

<<EOF>> {
	printf("EORF");
	return 0;
}

{AUTOKEY} {
	return AUTO;
}

{BOOLKEY} {
	return BOOLEAN;
}

{BREAKKEY} {
	return BREAK;
}

{CASEKEY} {
	return CASE;
}

{CHARKEY} {
	return CHARKEYWORD;
}

{CONSTKEY} {
	return CONST;
}

{CONTINUEKEY} {
	return CONTINUE;
}

{DEFAULTKEY} {
	return DEFAULT;
}

{DOUBLEKEY} {
	return DOUBLE;
}

{ELSEKEY} {
	return ELSE;
}

{EXTERNKEY} {
	return EXTERN;
}

{FUNCTIONKEY} {
	return FUNCTION;
}

{FLOATKEY} {
	return FLOAT;
}

{FOREACHKEY} {
	return FOREACH;
}

{FORKEY} {
	return FOR;
}

{GOTOKEY} {
	return GOTO;
}

{IFKEY} {
	return IF;
}

{INPUTKEY} {
	return INPUT;
}

{INTKEY} {
	printf("INT\n");
	return INT;
}

{INKEY} {
	return IN;
}

{LONGKEY} {
	return LONG;
}

{OFKEY} {
	return OF;
}

{OUTPUTKEY} {
	return OUTPUT;
}

{PROCEDUREKEY} {
	return PROCEDURE;
}

{RECORDKEY} {
	return RECORD;
}

{REPEATKEY} {
	return REPEAT;
}

{RETURNKEY} {
	return RETURN;
}

{SZIEOFKEY} {
	return SIZEOF;
}

{STATICKEY} {
	return STATIC;
}

{STRINGKEY} {
	return STRINGKEYWORD;
}

{SWITChKEY} {
	return SWITCH;
}

{UNTILKEY} {
	return UNTIL;
}

{VOIDKEY} {
	return VOID;
}

"\'"."\'" {
	yylval.str = yytext;
	return CHAR;
}

"\"".*"\"" {
	yylval.str = yytext;
	return STRING;
}

SINGLELINECOMMENT {
	/* IGNORING COMMENTS */
}

MULTILINECOMMENT {
	/* IGNORING COMMENTS */
}

"true" {
	yylval.num = 1;
	return TRUEV;
}

"false" {
	yylval.num = 0;
	return FALSEV;
}

[ \t] {
	/* IGNORE WHITESPACE */
}

\n {
	printf("NL\n");
	yypos = yypos + 1;
}

"!=" {
	return NOTEQUAL;
}

"!" {
	return NOT;
}

"<=" {
	return LESSOREQUAL;
}

"<" {
	return LESSTHAN;
}

"=>" {
	return BIGGEROREQUAL;
}

">" {
	return BIGGERTHAN;
}

"==" {
	return EQUAL;
}

"="	{
	return ASSIGNMENT;
}

"--" {
	return DECREMENT;
}

"-" {
	return SUBUNARYMINUS;
}

"++" {
	return INCREMENT;
}

"+" {
	return ADDUNARYPLUS;
}

"/" {
	return DIV;
}

"*" {
	return PRODUCTION;
}

"%" {
	return MOD;
}

"&&" {
	return LOGICALAND;
}

"&" {
	return ARITHMETICAND;
}

"||" {
	return LOGICALOR;
}

"|" {
	return ARITHMETICOR;
}

"^" {
	return XOR;
}

"{" {
	printf("{{{\n");
	return OPENCURLYBRACE;
}

"}" {
	printf("}}}\n");
	return CLOSECURLYBRACE;
}

"[" {
	return OPENINGBRACE;
}

"]" {
	return CLOSINGBRACE;
}

"(" {
	return OPENINGPAREBTHESIS;
}

")" {
	return CLOSINGPAREBTHESIS;
}

"," {
	return COMMA;
}

":" {
	return COLON;
}

";" {
	printf(";;;\n");
	return SEMICOLON;
}

{ID1} {
	printf("%s\n", yytext);
	yylval.str = yytext;
	return ID_CODE;
}

[-+]?{DIGIT}+ {
	yylval.str = yytext;
	yylval.num = atoi(yytext);
	return INTNUMBER;
}

[-+]?0[xX][0-9a-fA-F]+ {
	yylval.str = yytext;
	yylval.num = atoi(yytext);
	return INTNUMBER;
}

[-+]?[0-9]*\.?[0-9]+([eE][-+]?[0-9]+)? {
	yylval.str = yytext;
	yylval.numf = atof(yytext);
	yylval.num = atoi(yytext);
	return REALNUMBER;
}
