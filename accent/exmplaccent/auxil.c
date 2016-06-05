main()
{
   yyparse();
   return 0;
}

yyerror(msg)
   char *msg;
{
   extern long yypos;
   extern char* yylval;

   printf("line %d %s: %s\n", yypos, yylval, msg);
}

yywrap()
{
   return 0;
}
