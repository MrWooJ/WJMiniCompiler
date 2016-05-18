%{
#include "yystype.h"
#include "yygrammar.h"
%}

DIGIT [0-9]
VARIABLE [a-zA-Z]+[0-9]*

%%

"\'"."\'" {
	yylval.charval = (char)(yytext);
	return CHAR;
}

"\"".*"\"" {
	yylval.stringval = yytext;
	return STRING;
}

"/@" {
			lineNumbers[j] = yylineno;
			j++;
			BEGIN (COMMENT);
}

<COMMENT>"@/" {
			outputFile << "line ";
			for (int k = 0; lineNumbers[k] != 0; k++)
			{
				outputFile << lineNumbers[k] << "-" ;
			}
			outputFile << yylineno;
			outputFile << ": " << "comment " << "\"";
			for (int k = 0; comments[k].compare("$") != 0 ; k++)
			{
				outputFile << comments[k];
			}
			outputFile << "\"" << endl;


			i = j = 0;
			for (int k = 0; k < 100 ; k++)
				lineNumbers[k] = 0;

			for (int k = 0; k < 100 ; k++)
				comments[k] = "$";

			BEGIN 0;
}

<COMMENT>. {
			const char *s = yytext;
			string str(s);
			comments[i] = s;
			i++;
}

<COMMENT>[\n] {
			const char *s = yytext;
			string str(s);
			comments[i] = s;
			lineNumbers[j] = yylineno;
			i++;
			j++;
}


"@@".* {
			const char *s = yytext;
			string str(s);
			outputFile << "line " << yylineno << ": " << "comment " << "\"" << yytext << "\"" << endl;
}

"bool" {
	return BOOL;
}

"true" {
	yylval.boolval = true;
	return TRUEV;
}

"false" {
	yylval.boolval = false;
	return FALSEV;
}

[-+]?{DIGIT}+ {
	yylval.intval = atoi(yytext);
	return NUMBER;
}

[-+]?0[xX][0-9a-fA-F]+ {
	yylval.intval = atoi(yytext);
	return NUMBER;
}

[-+]?[0-9]*\.?[0-9]+([eE][-+]?[0-9]+)? {
	yylval.floatval = atof(yytext);
	return NUMBER;
}

[ \t] {
	/* IGNORE WHITESPACE */
}

\n {
	yypos++;
}

_?{VARIABLE}_?*{VARIABLE}* {
			outputFile << "line " << yylineno << ": " << "id " << "\"" << yytext << "\"" << endl;
			return ID_CODE;
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