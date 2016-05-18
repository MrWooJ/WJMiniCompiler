%{
#include "yystype.h"
#include "yygrammar.h"
%}
%%
"+"    { return '+'; }
"-"    { return '-'; }
"*"    { return '*'; }
"/"    { return '/'; }
[0-9]+ { yylval = atoi(yytext); return NUMBER; }
" "    { /* skip blank */ }
\n     { yypos++; }
.      { yyerror("illegal token"); }
