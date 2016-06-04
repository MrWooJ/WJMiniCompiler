%{
#include "yygrammar.h"
%}

DIGIT [0-9]
VARIABLE [a-zA-Z]+[0-9]*

ID = (([a-zA-Z]+[0-9]*)(_{0,2}([a-zA-Z]|[0-9])+)*)|(_{1,2}([a-zA-Z]|[0-9])+(_{0,2}([a-zA-Z]|[0-9])+)*)

BOOLKEY = bool
BREAKKEY = break
CASEKEY = case
CHARKEY = char
CONSTKEY = const
CONTINUEKEY = continue
DEFAULTKEY = default
DOUBLEKEY = double
ELSEKEY = else
EXTERNKEY = extern
FUNCTIONKEY = function
FLOATKEY = float
FORKEY = for
GOTOKEY = goto
IFKEY = if
INPUTKEY = input
INTKEY = int
LONGKEY = long
OUTPUTKEY = output
RETURNKEY = return
SZIEOFKEY = sizeof
STATICKEY = static
STRINGKEY = string
SWITChKEY = switch
VOIDKEY = void
UNTILKEY = until
RECORDKEY = record
REPEATKEY = repeat 
PROCEDUREKEY = procedure
FOREACHKEY = foreach
AUTOKEY = auto
OFKEY = of
INKEY = in

%%

AUTOKEY {
	return AUTO;
}

BOOLKEY {
	return BOOLEAN;
}

BREAKKEY {
	return BREAK;
}

CASEKEY {
	return CASE;
}

CHARKEY {
	return CHARKEYWORD;
}

CONSTKEY {
	return CONST;
}

CONTINUEKEY {
	return CONTINUE;
}

DEFAULTKEY {
	return DEFAULT;
}

DOUBLEKEY {
	return DOUBLE;
}

ELSEKEY {
	return ELSE;
}

EXTERNKEY {
	return EXTERN;
}

FUNCTIONKEY {
	return FUNCTION;
}

FLOATKEY {
	return FLOAT;
}

FOREACHKEY {
	return FOREACH;
}

FORKEY {
	return FOR;
}

GOTOKEY {
	return GOTO;
}

IFKEY {
	return IF;
}

INPUTKEY {
	return INPUT;
}

INTKEY {
	return INT;
}

INKEY {
	return IN;
}

LONGKEY {
	return LONG;
}

OFKEY {
	return OF;
}

OUTPUTKEY {
	return OUTPUT;
}

PROCEDUREKEY {
	return PROCEDURE;
}

RECORDKEY {
	return RECORD;
}

REPEATKEY {
	return REPEAT;
}

RETURNKEY {
	return RETURN;
}

SZIEOFKEY {
	return SIZEOF;
}

STATICKEY {
	return STATIC;
}

STRINGKEY {
	return STRINGKEYWORD;
}

SWITChKEY {
	return SWITCH;
}

UNTILKEY {
	return UNTIL;
}

VOIDKEY {
	return VOID;
}

"\'"."\'" {
	yylval = (char)(yytext);
	return CHAR;
}

"\"".*"\"" {
	yylval = yytext;
	return STRING;
}

SINGLELINECOMMENT {
	/* IGNORING COMMENTS */
}

MULTILINECOMMENT {
	/* IGNORING COMMENTS */
}

"true" {
	yylval = true;
	return TRUEV;
}

"false" {
	yylval = false;
	return FALSEV;
}

ID {
	yylval = yytext;
	return ID_CODE;
}

[-+]?{DIGIT}+ {
	yylval = atoi(yytext);
	return INTNUMBER;
}

[-+]?0[xX][0-9a-fA-F]+ {
	yylval = atoi(yytext);
	return INTNUMBER;
}

[-+]?[0-9]*\.?[0-9]+([eE][-+]?[0-9]+)? {
	yylval = atof(yytext);
	return REALNUMBER;
}

[ \t] {
	/* IGNORE WHITESPACE */
}

\n {
	yypos++;
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
	return OPENCURLYBRACE;
}

"}" {
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
	return SEMICOLON;
}

<<EOF>> {
	return EOF;
}

. {
	yyerror("illegal token");
}
