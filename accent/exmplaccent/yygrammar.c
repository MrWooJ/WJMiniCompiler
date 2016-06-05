#line 1 "spec.acc"

#include <stdio.h>
#include "SymbolTableHandler.h"
#include "OutputHandler.h"
#include "Utility.h"
#include "yystype.h"

int arrDecNumber = 0;
int arrDecProduction = 1;

int arrCmptProduction = 1;

Array parametersArray;

char* variableType;

int useOfArrayVar = 0;

int useOfResVar = 0;

char* VariableName;


# line 26 "yygrammar.c"
#include "yygrammar.h"

YYSTART ()
{
   switch(yyselect()) {
   case 109: {
      program();
      get_lexval();
      } break;
   }
}

program ()
{
#line 28 "spec.acc"
 PrepareST(); 
# line 43 "yygrammar.c"
   switch(yyselect()) {
   case 1: {
#line 29 "spec.acc"
 printf("Find"); 
# line 48 "yygrammar.c"
      program_parts();
      } break;
   case 2: {
#line 30 "spec.acc"
 printf("Find"); 
# line 54 "yygrammar.c"
      program_parts();
      program();
      } break;
   }
}

program_parts ()
{
   switch(yyselect()) {
   case 3: {
      var_dcl();
      } break;
   case 4: {
      func_proc();
      } break;
   case 5: {
      struct_dec();
      } break;
   }
}

func_proc ()
{
   YYSTYPE x;
   switch(yyselect()) {
   case 6: {
      func_dcl(&x);
#line 40 "spec.acc"
 HandleCodeGenerator("END", x.str, "", ""); 
# line 84 "yygrammar.c"
      } break;
   case 7: {
      proc_dcl();
      } break;
   case 8: {
      extern_dcl();
      } break;
   }
}

arguments ()
{
   switch(yyselect()) {
   case 9: {
      argument();
      } break;
   case 10: {
      argument();
      get_lexval();
      arguments();
      } break;
   }
}

array_dcl (n)
   YYSTYPE *n;
{
   YYSTYPE m;
   YYSTYPE x;
#line 52 "spec.acc"
 int simpleArray = 1; 
# line 116 "yygrammar.c"
   switch(yyselect()) {
   case 11: {
      null_point();
#line 53 "spec.acc"
 if (arrDecNumber == 0) { n->num = 0; } else { if (simpleArray == 1) { n->num = 1; } else { n->num = arrDecProduction; arrDecProduction = 1; } } arrDecNumber = 0; 
# line 122 "yygrammar.c"
      } break;
   case 12: {
      get_lexval();
      get_lexval();
#line 54 "spec.acc"
 arrDecNumber++; simpleArray = 1; 
# line 129 "yygrammar.c"
      array_dcl(&m);
      } break;
   case 13: {
      get_lexval();
      get_lexval();
      x = yylval;
      get_lexval();
#line 55 "spec.acc"
 arrDecNumber++; simpleArray = 0; arrDecProduction = arrDecProduction * x.num; 
# line 139 "yygrammar.c"
      array_dcl(&m);
      } break;
   }
}

argument ()
{
   YYSTYPE x;
   YYSTYPE y;
   YYSTYPE z;
#line 59 "spec.acc"
 int check = 0; char *arrSize1; 
# line 152 "yygrammar.c"
   switch(yyselect()) {
   case 14: {
      type(&x);
      get_lexval();
      y = yylval;
#line 60 "spec.acc"
 char* str6 = Lookup(y.str); if ((str6 != NULL) && (str6[0] != '\0')) { AddId(y.str,x.str); } else { ErrorPrump_IdDuplicated(1,y.str); } 
# line 160 "yygrammar.c"
      array_dcl(&z);
#line 60 "spec.acc"
 char* sizex; if (z.num == 0) { sizex = GetSizeOf(x.str); HandleCodeGenerator("ARG", sizex, y.str, ""); } else { sizex = GetSizeOf(x.str); arrSize1 = Int2String(z.num); HandleCodeGenerator("ARG", sizex, arrSize1, y.str); } 
# line 164 "yygrammar.c"
      } break;
   }
}

func_dcl (n)
   YYSTYPE *n;
{
   YYSTYPE x;
   YYSTYPE y;
   YYSTYPE m;
   switch(yyselect()) {
   case 15: {
      type(&x);
      get_lexval();
      y = yylval;
#line 64 "spec.acc"
 printf("FUNDCL"); char* str = Lookup(y.str); if ((str != NULL) && (str[0] != '\0')) { AddId(y.str,x.str); char* size = GetSizeOf(x.str); HandleCodeGenerator("FUN", y.str, size, ""); } else { ErrorPrump_IdDuplicated(1,y.str); } printf("DD"); 
# line 182 "yygrammar.c"
      get_lexval();
      switch (yyselect()) {
      case 110: {
         arguments();
         } break;
      default: ;
      }
      get_lexval();
      get_lexval();
#line 64 "spec.acc"
 n->str = y.str; 
# line 194 "yygrammar.c"
      } break;
   case 16: {
      type(&x);
      get_lexval();
      y = yylval;
#line 65 "spec.acc"
 char* str = Lookup(y.str); if ((str != NULL) && (str[0] != '\0')) { AddId(y.str,x.str); char* size = GetSizeOf(x.str); HandleCodeGenerator("FUN", y.str, size, ""); } else { ErrorPrump_IdDuplicated(1,y.str); } 
# line 202 "yygrammar.c"
      get_lexval();
      switch (yyselect()) {
      case 111: {
         arguments();
         } break;
      default: ;
      }
      get_lexval();
      block(&m);
#line 65 "spec.acc"
 n->str = y.str; 
# line 214 "yygrammar.c"
      } break;
   }
}

extern_dcl ()
{
   YYSTYPE x;
   YYSTYPE y;
   switch(yyselect()) {
   case 17: {
      get_lexval();
      type(&x);
      get_lexval();
      y = yylval;
#line 69 "spec.acc"
 char* str = Lookup(y.str); if ((str != NULL) && (str[0] != '\0')) { AddId(y.str,x.str); } else { ErrorPrump_IdDuplicated(1,y.str); } 
# line 231 "yygrammar.c"
      get_lexval();
      } break;
   }
}

proc_dcl ()
{
   YYSTYPE m;
   switch(yyselect()) {
   case 18: {
      get_lexval();
      get_lexval();
      get_lexval();
      switch (yyselect()) {
      case 112: {
         arguments();
         } break;
      default: ;
      }
      get_lexval();
      get_lexval();
      } break;
   case 19: {
      get_lexval();
      get_lexval();
      get_lexval();
      switch (yyselect()) {
      case 113: {
         arguments();
         } break;
      default: ;
      }
      get_lexval();
      block(&m);
      } break;
   }
}

type (n)
   YYSTYPE *n;
{
   YYSTYPE m;
   switch(yyselect()) {
   case 20: {
      get_lexval();
#line 78 "spec.acc"
 n->str = "int"; 
# line 279 "yygrammar.c"
      } break;
   case 21: {
      get_lexval();
#line 79 "spec.acc"
 n->str = "bool"; 
# line 285 "yygrammar.c"
      } break;
   case 22: {
      get_lexval();
#line 80 "spec.acc"
 printf("FLOATFIND"); n->str = "float"; 
# line 291 "yygrammar.c"
      } break;
   case 23: {
      get_lexval();
#line 81 "spec.acc"
 n->str = "long"; 
# line 297 "yygrammar.c"
      } break;
   case 24: {
      get_lexval();
#line 82 "spec.acc"
 n->str = "char"; 
# line 303 "yygrammar.c"
      } break;
   case 25: {
      get_lexval();
#line 83 "spec.acc"
 n->str = "double"; 
# line 309 "yygrammar.c"
      } break;
   case 26: {
      get_lexval();
      m = yylval;
#line 84 "spec.acc"
 n->str = m.str; 
# line 316 "yygrammar.c"
      } break;
   case 27: {
      get_lexval();
#line 85 "spec.acc"
 n->str = "char *"; 
# line 322 "yygrammar.c"
      } break;
   case 28: {
      get_lexval();
#line 86 "spec.acc"
 n->str = "void"; 
# line 328 "yygrammar.c"
      } break;
   case 29: {
      get_lexval();
#line 87 "spec.acc"
 n->str = "auto"; 
# line 334 "yygrammar.c"
      } break;
   }
}

var_dcl ()
{
   YYSTYPE x;
#line 91 "spec.acc"
 int i = 0; 
# line 344 "yygrammar.c"
   switch(yyselect()) {
   case 30: {
      switch (yyselect()) {
      case 114: {
         get_lexval();
#line 92 "spec.acc"
 i = 1; 
# line 352 "yygrammar.c"
         } break;
      default: ;
      }
      type(&x);
#line 92 "spec.acc"
 variableType = x.str; 
# line 359 "yygrammar.c"
      var_dcl_cnts();
      get_lexval();
      } break;
   }
}

var_dcl_cnts ()
{
   switch(yyselect()) {
   case 31: {
      var_dcl_cnt();
      } break;
   case 32: {
      var_dcl_cnt();
      get_lexval();
      var_dcl_cnts();
      } break;
   }
}

var_dcl_cnt ()
{
   YYSTYPE m;
   YYSTYPE x;
   switch(yyselect()) {
   case 33: {
      assignment_expr(&m);
      } break;
   case 34: {
      variable(&x);
#line 102 "spec.acc"
 char* str4 = Lookup(x.str); if ((str4 != NULL) && (str4[0] != '\0')) { AddId(x.str,variableType); char* size = GetSizeOf(variableType); if (useOfArrayVar == 0) { HandleCodeGenerator("VAR", size, x.str, ""); } else { HandleCodeGenerator("ARR", size, Int2String(arrCmptProduction), x.str); arrCmptProduction = 1; useOfArrayVar = 0; } } else { ErrorPrump_IdDuplicated(1,x.str); } 
# line 392 "yygrammar.c"
      } break;
   }
}

struct_dec ()
{
   YYSTYPE x;
   switch(yyselect()) {
   case 35: {
      get_lexval();
      get_lexval();
      x = yylval;
#line 106 "spec.acc"
 char* str = Lookup(x.str); if ((str != NULL) && (str[0] != '\0')) { AddId(x.str,"REC"); } else { ErrorPrump_IdDuplicated(1,x.str); } 
# line 407 "yygrammar.c"
      get_lexval();
      var_dcl();
      get_lexval();
      get_lexval();
      } break;
   }
}

block (n)
   YYSTYPE *n;
{
   switch(yyselect()) {
   case 36: {
      get_lexval();
#line 110 "spec.acc"
 EnterScope(); 
# line 424 "yygrammar.c"
      while (1) {
         switch (yyselect()) {
         case 117: {
            switch (yyselect()) {
            case 115: {
               var_dcl();
               } break;
            case 116: {
               statement_expr();
               } break;
            default: printf("???\n"); exit(1);
            }
            } break;
         default: goto yy1;
         }
      }
      yy1: ;
      get_lexval();
#line 110 "spec.acc"
 ExitScope(); n->str = ProduceBlockLabel(); 
# line 445 "yygrammar.c"
      } break;
   }
}

arithmatic_low_level (n)
   YYSTYPE *n;
{
   YYSTYPE x;
   switch(yyselect()) {
   case 37: {
      get_lexval();
      x = yylval;
#line 114 "spec.acc"
 n->str = x.str; 
# line 460 "yygrammar.c"
      } break;
   case 38: {
      get_lexval();
      x = yylval;
#line 115 "spec.acc"
 n->str = x.str; 
# line 467 "yygrammar.c"
      } break;
   }
}

arithmatic_high_level (n)
   YYSTYPE *n;
{
   YYSTYPE x;
   switch(yyselect()) {
   case 39: {
      get_lexval();
      x = yylval;
#line 119 "spec.acc"
 n->str = x.str; 
# line 482 "yygrammar.c"
      } break;
   case 40: {
      get_lexval();
      x = yylval;
#line 120 "spec.acc"
 n->str = x.str; 
# line 489 "yygrammar.c"
      } break;
   case 41: {
      get_lexval();
      x = yylval;
#line 121 "spec.acc"
 n->str = x.str; 
# line 496 "yygrammar.c"
      } break;
   case 42: {
      get_lexval();
      x = yylval;
#line 122 "spec.acc"
 n->str = x.str; 
# line 503 "yygrammar.c"
      } break;
   case 43: {
      get_lexval();
      x = yylval;
#line 123 "spec.acc"
 n->str = x.str; 
# line 510 "yygrammar.c"
      } break;
   case 44: {
      get_lexval();
      x = yylval;
#line 124 "spec.acc"
 n->str = x.str; 
# line 517 "yygrammar.c"
      } break;
   case 45: {
      get_lexval();
      x = yylval;
#line 125 "spec.acc"
 n->str = x.str; 
# line 524 "yygrammar.c"
      } break;
   case 46: {
      get_lexval();
      x = yylval;
#line 126 "spec.acc"
 n->str = x.str; 
# line 531 "yygrammar.c"
      } break;
   }
}

arithmatic (n)
   YYSTYPE *n;
{
   YYSTYPE x;
   switch(yyselect()) {
   case 47: {
      get_lexval();
      x = yylval;
#line 130 "spec.acc"
 n->str = x.str; 
# line 546 "yygrammar.c"
      } break;
   case 48: {
      get_lexval();
      x = yylval;
#line 131 "spec.acc"
 n->str = x.str; 
# line 553 "yygrammar.c"
      } break;
   case 49: {
      get_lexval();
      x = yylval;
#line 132 "spec.acc"
 n->str = x.str; 
# line 560 "yygrammar.c"
      } break;
   case 50: {
      get_lexval();
      x = yylval;
#line 133 "spec.acc"
 n->str = x.str; 
# line 567 "yygrammar.c"
      } break;
   case 51: {
      get_lexval();
      x = yylval;
#line 134 "spec.acc"
 n->str = x.str; 
# line 574 "yygrammar.c"
      } break;
   case 52: {
      get_lexval();
      x = yylval;
#line 135 "spec.acc"
 n->str = x.str; 
# line 581 "yygrammar.c"
      } break;
   case 53: {
      get_lexval();
      x = yylval;
#line 136 "spec.acc"
 n->str = x.str; 
# line 588 "yygrammar.c"
      } break;
   case 54: {
      get_lexval();
      x = yylval;
#line 137 "spec.acc"
 n->str = x.str; 
# line 595 "yygrammar.c"
      } break;
   case 55: {
      get_lexval();
      x = yylval;
#line 138 "spec.acc"
 n->str = x.str; 
# line 602 "yygrammar.c"
      } break;
   case 56: {
      get_lexval();
      x = yylval;
#line 139 "spec.acc"
 n->str = x.str; 
# line 609 "yygrammar.c"
      } break;
   }
}

conditional (n)
   YYSTYPE *n;
{
   YYSTYPE x;
   switch(yyselect()) {
   case 57: {
      get_lexval();
      x = yylval;
#line 143 "spec.acc"
 n->str = x.str; 
# line 624 "yygrammar.c"
      } break;
   case 58: {
      get_lexval();
      x = yylval;
#line 144 "spec.acc"
 n->str = x.str; 
# line 631 "yygrammar.c"
      } break;
   case 59: {
      get_lexval();
      x = yylval;
#line 145 "spec.acc"
 n->str = x.str; 
# line 638 "yygrammar.c"
      } break;
   case 60: {
      get_lexval();
      x = yylval;
#line 146 "spec.acc"
 n->str = x.str; 
# line 645 "yygrammar.c"
      } break;
   case 61: {
      get_lexval();
      x = yylval;
#line 147 "spec.acc"
 n->str = x.str; 
# line 652 "yygrammar.c"
      } break;
   case 62: {
      get_lexval();
      x = yylval;
#line 148 "spec.acc"
 n->str = x.str; 
# line 659 "yygrammar.c"
      } break;
   }
}

binary_op (n)
   YYSTYPE *n;
{
   YYSTYPE x;
   switch(yyselect()) {
   case 63: {
      arithmatic(&x);
#line 152 "spec.acc"
 n->str = x.str; 
# line 673 "yygrammar.c"
      } break;
   case 64: {
      conditional(&x);
#line 153 "spec.acc"
 n->str = x.str; 
# line 679 "yygrammar.c"
      } break;
   }
}

parameters (n)
   YYSTYPE *n;
{
   YYSTYPE x;
   YYSTYPE m;
   switch(yyselect()) {
   case 65: {
      expr(&x);
#line 157 "spec.acc"
 insertArray(&parametersArray, x.str); n->str = ProduceParameters(&parametersArray); freeArray(&parametersArray); 
# line 694 "yygrammar.c"
      } break;
   case 66: {
      expr(&x);
#line 158 "spec.acc"
 insertArray(&parametersArray, x.str); 
# line 700 "yygrammar.c"
      get_lexval();
      parameters(&m);
      } break;
   }
}

method_call_expr ()
{
   YYSTYPE x;
   YYSTYPE y;
#line 162 "spec.acc"
 int hasParameters = 0; 
# line 713 "yygrammar.c"
   switch(yyselect()) {
   case 67: {
      get_lexval();
      x = yylval;
      get_lexval();
      switch (yyselect()) {
      case 118: {
#line 163 "spec.acc"
 initArray(&parametersArray, 5); 
# line 723 "yygrammar.c"
         parameters(&y);
#line 163 "spec.acc"
 hasParameters = 1; 
# line 727 "yygrammar.c"
         } break;
      default: ;
      }
      get_lexval();
#line 163 "spec.acc"
 if(hasParameters == 0) { HandleCodeGenerator("CALL",x.str,"",""); } else { HandleCodeGenerator("CALL",x.str,y.str,""); } 
# line 734 "yygrammar.c"
      } break;
   }
}

array_complete_dcl (n)
   YYSTYPE *n;
{
   YYSTYPE x;
   YYSTYPE y;
   switch(yyselect()) {
   case 68: {
      get_lexval();
      expr(&x);
      get_lexval();
#line 167 "spec.acc"
 n->num = arrCmptProduction * x.num; 
# line 751 "yygrammar.c"
      } break;
   case 69: {
      get_lexval();
      expr(&x);
      get_lexval();
#line 168 "spec.acc"
 arrCmptProduction = arrCmptProduction * x.num; 
# line 759 "yygrammar.c"
      array_complete_dcl(&y);
      } break;
   }
}

variable (n)
   YYSTYPE *n;
{
   YYSTYPE x;
   YYSTYPE y;
   YYSTYPE m;
   switch(yyselect()) {
   case 70: {
      get_lexval();
      x = yylval;
#line 172 "spec.acc"
 char * str = Lookup(x.str); if ((str != NULL) && (str[0] != '\0')) { ErrorPrump_IdNotFound(1,x.str); } else { n->str = x.str; } 
# line 777 "yygrammar.c"
      } break;
   case 71: {
      get_lexval();
      x = yylval;
#line 173 "spec.acc"
 char * str = Lookup(x.str); if ((str != NULL) && (str[0] != '\0')) { ErrorPrump_IdNotFound(1,x.str); } else { n->str = x.str; } 
# line 784 "yygrammar.c"
      array_complete_dcl(&y);
#line 173 "spec.acc"
 useOfArrayVar = 1; n->str = x.str; 
# line 788 "yygrammar.c"
      } break;
   case 72: {
      get_lexval();
      variable(&m);
      } break;
   case 73: {
      get_lexval();
      variable(&m);
      } break;
   case 74: {
      variable(&m);
      get_lexval();
      } break;
   case 75: {
      variable(&m);
      get_lexval();
      } break;
   }
}

const_val (n)
   YYSTYPE *n;
{
   YYSTYPE x;
   switch(yyselect()) {
   case 76: {
      get_lexval();
      x = yylval;
#line 181 "spec.acc"
 n->num = x.num; 
# line 819 "yygrammar.c"
      } break;
   case 77: {
      get_lexval();
      x = yylval;
#line 182 "spec.acc"
 n->numf = x.numf; n->num = x.num; 
# line 826 "yygrammar.c"
      } break;
   case 78: {
      get_lexval();
      x = yylval;
#line 183 "spec.acc"
 n->num = x.num; 
# line 833 "yygrammar.c"
      } break;
   case 79: {
      get_lexval();
      x = yylval;
#line 184 "spec.acc"
 n->num = x.num; 
# line 840 "yygrammar.c"
      } break;
   case 80: {
      get_lexval();
      x = yylval;
#line 185 "spec.acc"
 n->num = x.num; 
# line 847 "yygrammar.c"
      } break;
   }
}

assignment_expr (n)
   YYSTYPE *n;
{
   YYSTYPE x;
   YYSTYPE y;
   switch(yyselect()) {
   case 81: {
      variable(&x);
#line 189 "spec.acc"
 printf("AE"); useOfResVar = 1; VariableName = x.str; 
# line 862 "yygrammar.c"
      get_lexval();
      expr(&y);
#line 189 "spec.acc"
 HandleCodeGenerator("=",x.str,y.str,""); useOfResVar = 0; 
# line 867 "yygrammar.c"
      } break;
   }
}

expr_assign ()
{
   YYSTYPE m;
   switch(yyselect()) {
   case 82: {
      expr(&m);
      } break;
   case 83: {
      assignment_expr(&m);
      } break;
   }
}

loop_stmt ()
{
   YYSTYPE k;
   YYSTYPE l;
   YYSTYPE m;
   YYSTYPE y;
   YYSTYPE z;
   YYSTYPE f;
   switch(yyselect()) {
   case 84: {
      get_lexval();
      get_lexval();
      switch (yyselect()) {
      case 119: {
         var_dcl();
         } break;
      default: ;
      }
      get_lexval();
      expr(&k);
      get_lexval();
      switch (yyselect()) {
      case 120: {
         expr_assign();
         } break;
      default: ;
      }
      get_lexval();
      block(&l);
      } break;
   case 85: {
      get_lexval();
      block(&m);
      get_lexval();
      get_lexval();
      expr(&l);
      get_lexval();
      get_lexval();
      } break;
   case 86: {
      get_lexval();
      get_lexval();
      get_lexval();
      y = yylval;
#line 200 "spec.acc"
 char* str2 = Lookup(y.str); if ((str2 != NULL) && (str2[0] != '\0')) { AddId(y.str,"VAR"); } else { ErrorPrump_IdDuplicated(1,y.str); } 
# line 931 "yygrammar.c"
      get_lexval();
      get_lexval();
      z = yylval;
#line 200 "spec.acc"
 char * str1 = Lookup(z.str); if ((str1 != NULL) && (str1[0] != '\0')) { ErrorPrump_IdNotFound(1,z.str); } 
# line 937 "yygrammar.c"
      get_lexval();
      block(&f);
      } break;
   }
}

expr (n)
   YYSTYPE *n;
{
   YYSTYPE x;
   YYSTYPE m;
   YYSTYPE y;
   switch(yyselect()) {
   case 87: {
      expr(&x);
      conditional(&m);
      expr(&y);
      } break;
   case 88: {
      get_lexval();
      expr(&y);
      get_lexval();
      } break;
   case 89: {
      method_call_expr();
      } break;
   case 90: {
      variable(&x);
#line 207 "spec.acc"
 n->str = x.str; 
# line 968 "yygrammar.c"
      } break;
   case 91: {
      const_val(&m);
      } break;
   case 92: {
      get_lexval();
      expr(&m);
      } break;
   case 93: {
      get_lexval();
      expr(&m);
      } break;
   }
}

cond_statement ()
{
   YYSTYPE x;
   YYSTYPE y;
   YYSTYPE z;
   YYSTYPE m;
   switch(yyselect()) {
   case 94: {
      get_lexval();
      get_lexval();
      expr(&x);
      get_lexval();
      block(&y);
#line 214 "spec.acc"
 char* blockLabel = UseOfBlockLabel(); HandleCodeGenerator("JNZ",blockLabel,x.str,""); 
# line 999 "yygrammar.c"
      switch (yyselect()) {
      case 121: {
         get_lexval();
         block(&z);
#line 214 "spec.acc"
 char* blockLabel = UseOfBlockLabel(); HandleCodeGenerator("JZ",blockLabel,z.str,""); 
# line 1006 "yygrammar.c"
         } break;
      default: ;
      }
      } break;
   case 95: {
      get_lexval();
      get_lexval();
      get_lexval();
      x = yylval;
      get_lexval();
      get_lexval();
      get_lexval();
      get_lexval();
#line 215 "spec.acc"
 EnterScope(); 
# line 1022 "yygrammar.c"
      while (1) {
         switch (yyselect()) {
         case 122: {
            get_lexval();
            get_lexval();
            y = yylval;
            get_lexval();
            block(&z);
            } break;
         default: goto yy2;
         }
      }
      yy2: ;
      get_lexval();
      get_lexval();
      block(&m);
      get_lexval();
#line 215 "spec.acc"
 ExitScope(); 
# line 1042 "yygrammar.c"
      } break;
   }
}

gotofunc ()
{
   YYSTYPE x;
   switch(yyselect()) {
   case 96: {
      get_lexval();
      get_lexval();
      x = yylval;
#line 219 "spec.acc"
 HandleCodeGenerator("JMP",x.str,"",""); 
# line 1057 "yygrammar.c"
      } break;
   }
}

labeltoken ()
{
   YYSTYPE x;
   switch(yyselect()) {
   case 97: {
      get_lexval();
      x = yylval;
      get_lexval();
#line 223 "spec.acc"
 HandleCodeGenerator("LB",x.str,"",""); 
# line 1072 "yygrammar.c"
      } break;
   }
}

statement_expr ()
{
   YYSTYPE m;
   YYSTYPE x;
   switch(yyselect()) {
   case 98: {
      assignment_expr(&m);
      get_lexval();
      } break;
   case 99: {
      cond_statement();
      } break;
   case 100: {
      loop_stmt();
      } break;
   case 101: {
      method_call_expr();
      get_lexval();
      } break;
   case 102: {
      get_lexval();
#line 231 "spec.acc"
 int i = 0; 
# line 1100 "yygrammar.c"
      switch (yyselect()) {
      case 123: {
         expr(&x);
#line 231 "spec.acc"
 i = 1; 
# line 1106 "yygrammar.c"
         } break;
      default: ;
      }
      get_lexval();
#line 231 "spec.acc"
 if(i == 0) { HandleCodeGenerator("RET",x.str,"",""); } else { HandleCodeGenerator("RET","","",""); } 
# line 1113 "yygrammar.c"
      } break;
   case 103: {
      gotofunc();
      get_lexval();
      } break;
   case 104: {
      labeltoken();
      } break;
   case 105: {
      get_lexval();
      get_lexval();
      } break;
   case 106: {
      get_lexval();
      get_lexval();
      } break;
   case 107: {
      get_lexval();
      get_lexval();
      type(&m);
      get_lexval();
      get_lexval();
      } break;
   }
}

null_point ()
{
   switch(yyselect()) {
   case 108: {
      } break;
   }
}

extern YYSTYPE yylval;
YYSTYPE yylval;
extern long yypos;
long yypos = 1;
/* GentleFlag = no */

typedef struct LEXELEMSTRUCT {
   YYSTYPE val;
   long pos;
   long sym;
   char * text;
   struct LEXELEMSTRUCT *next;
} LEXELEM;
   
LEXELEM *first_lexelem, *cur_lexelem;

init_lexelem()
{
   cur_lexelem = first_lexelem;
}

first_lexval () {
   LEXELEM *p;
   p = (LEXELEM *)malloc(sizeof(LEXELEM));
   if (! p) yymallocerror();
   p->val = yylval;
   p->pos = yypos;
   p->next = 0;
   cur_lexelem = p;
   first_lexelem = p;
}

next_lexval() {
   LEXELEM *p;
   p = (LEXELEM *)malloc(sizeof(LEXELEM));
   if (! p) yymallocerror();
   cur_lexelem-> next = p;
   p->val = yylval;
   p->pos = yypos;
   p->next = 0;
   cur_lexelem = p;
}

get_lexval() {
   extern int FREE_LEXELEMS;
   LEXELEM *p;
   yylval = cur_lexelem->val;
   yypos = cur_lexelem->pos;
   p = cur_lexelem;
   cur_lexelem = cur_lexelem->next;
   free(p);
}

extern int c_length;
int c_length = 651;
extern int yygrammar[];
int yygrammar[] = {
0,
/* 1 */ 0,
/* 2 */ 6,
/* 3 */ 50000,
/* 4 */ -1,
/* 5 */ 109,
/* 6 */ 10,
/* 7 */ 15,
/* 8 */ -6,
/* 9 */ 1,
/* 10 */ 0,
/* 11 */ 15,
/* 12 */ 6,
/* 13 */ -6,
/* 14 */ 2,
/* 15 */ 19,
/* 16 */ 183,
/* 17 */ -15,
/* 18 */ 3,
/* 19 */ 23,
/* 20 */ 27,
/* 21 */ -15,
/* 22 */ 4,
/* 23 */ 0,
/* 24 */ 215,
/* 25 */ -15,
/* 26 */ 5,
/* 27 */ 31,
/* 28 */ 72,
/* 29 */ -27,
/* 30 */ 6,
/* 31 */ 35,
/* 32 */ 111,
/* 33 */ -27,
/* 34 */ 7,
/* 35 */ 0,
/* 36 */ 104,
/* 37 */ -27,
/* 38 */ 8,
/* 39 */ 43,
/* 40 */ 66,
/* 41 */ -39,
/* 42 */ 9,
/* 43 */ 0,
/* 44 */ 66,
/* 45 */ 50289,
/* 46 */ 39,
/* 47 */ -39,
/* 48 */ 10,
/* 49 */ 53,
/* 50 */ 649,
/* 51 */ -49,
/* 52 */ 11,
/* 53 */ 59,
/* 54 */ 50285,
/* 55 */ 50286,
/* 56 */ 49,
/* 57 */ -49,
/* 58 */ 12,
/* 59 */ 0,
/* 60 */ 50285,
/* 61 */ 50261,
/* 62 */ 50286,
/* 63 */ 49,
/* 64 */ -49,
/* 65 */ 13,
/* 66 */ 0,
/* 67 */ 143,
/* 68 */ 50260,
/* 69 */ 49,
/* 70 */ -66,
/* 71 */ 14,
/* 72 */ 81,
/* 73 */ 143,
/* 74 */ 50260,
/* 75 */ 50287,
/* 76 */ 90,
/* 77 */ 50288,
/* 78 */ 50290,
/* 79 */ -72,
/* 80 */ 15,
/* 81 */ 0,
/* 82 */ 143,
/* 83 */ 50260,
/* 84 */ 50287,
/* 85 */ 97,
/* 86 */ 50288,
/* 87 */ 224,
/* 88 */ -72,
/* 89 */ 16,
/* 90 */ 94,
/* 91 */ 39,
/* 92 */ -90,
/* 93 */ 110,
/* 94 */ 0,
/* 95 */ -90,
/* 96 */ 124,
/* 97 */ 101,
/* 98 */ 39,
/* 99 */ -97,
/* 100 */ 111,
/* 101 */ 0,
/* 102 */ -97,
/* 103 */ 125,
/* 104 */ 0,
/* 105 */ 50301,
/* 106 */ 143,
/* 107 */ 50260,
/* 108 */ 50290,
/* 109 */ -104,
/* 110 */ 17,
/* 111 */ 120,
/* 112 */ 50320,
/* 113 */ 50260,
/* 114 */ 50287,
/* 115 */ 129,
/* 116 */ 50288,
/* 117 */ 50290,
/* 118 */ -111,
/* 119 */ 18,
/* 120 */ 0,
/* 121 */ 50320,
/* 122 */ 50260,
/* 123 */ 50287,
/* 124 */ 136,
/* 125 */ 50288,
/* 126 */ 224,
/* 127 */ -111,
/* 128 */ 19,
/* 129 */ 133,
/* 130 */ 39,
/* 131 */ -129,
/* 132 */ 112,
/* 133 */ 0,
/* 134 */ -129,
/* 135 */ 126,
/* 136 */ 140,
/* 137 */ 39,
/* 138 */ -136,
/* 139 */ 113,
/* 140 */ 0,
/* 141 */ -136,
/* 142 */ 127,
/* 143 */ 147,
/* 144 */ 50308,
/* 145 */ -143,
/* 146 */ 20,
/* 147 */ 151,
/* 148 */ 50292,
/* 149 */ -143,
/* 150 */ 21,
/* 151 */ 155,
/* 152 */ 50303,
/* 153 */ -143,
/* 154 */ 22,
/* 155 */ 159,
/* 156 */ 50309,
/* 157 */ -143,
/* 158 */ 23,
/* 159 */ 163,
/* 160 */ 50295,
/* 161 */ -143,
/* 162 */ 24,
/* 163 */ 167,
/* 164 */ 50299,
/* 165 */ -143,
/* 166 */ 25,
/* 167 */ 171,
/* 168 */ 50260,
/* 169 */ -143,
/* 170 */ 26,
/* 171 */ 175,
/* 172 */ 50314,
/* 173 */ -143,
/* 174 */ 27,
/* 175 */ 179,
/* 176 */ 50316,
/* 177 */ -143,
/* 178 */ 28,
/* 179 */ 0,
/* 180 */ 50317,
/* 181 */ -143,
/* 182 */ 29,
/* 183 */ 0,
/* 184 */ 190,
/* 185 */ 143,
/* 186 */ 197,
/* 187 */ 50290,
/* 188 */ -183,
/* 189 */ 30,
/* 190 */ 194,
/* 191 */ 50296,
/* 192 */ -190,
/* 193 */ 114,
/* 194 */ 0,
/* 195 */ -190,
/* 196 */ 128,
/* 197 */ 201,
/* 198 */ 207,
/* 199 */ -197,
/* 200 */ 31,
/* 201 */ 0,
/* 202 */ 207,
/* 203 */ 50289,
/* 204 */ 197,
/* 205 */ -197,
/* 206 */ 32,
/* 207 */ 211,
/* 208 */ 444,
/* 209 */ -207,
/* 210 */ 33,
/* 211 */ 0,
/* 212 */ 395,
/* 213 */ -207,
/* 214 */ 34,
/* 215 */ 0,
/* 216 */ 50318,
/* 217 */ 50260,
/* 218 */ 50283,
/* 219 */ 183,
/* 220 */ 50284,
/* 221 */ 50290,
/* 222 */ -215,
/* 223 */ 35,
/* 224 */ 0,
/* 225 */ 50283,
/* 226 */ 230,
/* 227 */ 50284,
/* 228 */ -224,
/* 229 */ 36,
/* 230 */ 235,
/* 231 */ 238,
/* 232 */ 230,
/* 233 */ -230,
/* 234 */ 117,
/* 235 */ 0,
/* 236 */ -230,
/* 237 */ 129,
/* 238 */ 242,
/* 239 */ 183,
/* 240 */ -238,
/* 241 */ 115,
/* 242 */ 0,
/* 243 */ 591,
/* 244 */ -238,
/* 245 */ 116,
/* 246 */ 250,
/* 247 */ 50274,
/* 248 */ -246,
/* 249 */ 37,
/* 250 */ 0,
/* 251 */ 50272,
/* 252 */ -246,
/* 253 */ 38,
/* 254 */ 258,
/* 255 */ 50276,
/* 256 */ -254,
/* 257 */ 39,
/* 258 */ 262,
/* 259 */ 50275,
/* 260 */ -254,
/* 261 */ 40,
/* 262 */ 266,
/* 263 */ 50277,
/* 264 */ -254,
/* 265 */ 41,
/* 266 */ 270,
/* 267 */ 50279,
/* 268 */ -254,
/* 269 */ 42,
/* 270 */ 274,
/* 271 */ 50281,
/* 272 */ -254,
/* 273 */ 43,
/* 274 */ 278,
/* 275 */ 50282,
/* 276 */ -254,
/* 277 */ 44,
/* 278 */ 282,
/* 279 */ 50280,
/* 280 */ -254,
/* 281 */ 45,
/* 282 */ 0,
/* 283 */ 50278,
/* 284 */ -254,
/* 285 */ 46,
/* 286 */ 290,
/* 287 */ 50274,
/* 288 */ -286,
/* 289 */ 47,
/* 290 */ 294,
/* 291 */ 50272,
/* 292 */ -286,
/* 293 */ 48,
/* 294 */ 298,
/* 295 */ 50276,
/* 296 */ -286,
/* 297 */ 49,
/* 298 */ 302,
/* 299 */ 50275,
/* 300 */ -286,
/* 301 */ 50,
/* 302 */ 306,
/* 303 */ 50277,
/* 304 */ -286,
/* 305 */ 51,
/* 306 */ 310,
/* 307 */ 50279,
/* 308 */ -286,
/* 309 */ 52,
/* 310 */ 314,
/* 311 */ 50281,
/* 312 */ -286,
/* 313 */ 53,
/* 314 */ 318,
/* 315 */ 50282,
/* 316 */ -286,
/* 317 */ 54,
/* 318 */ 322,
/* 319 */ 50280,
/* 320 */ -286,
/* 321 */ 55,
/* 322 */ 0,
/* 323 */ 50278,
/* 324 */ -286,
/* 325 */ 56,
/* 326 */ 330,
/* 327 */ 50269,
/* 328 */ -326,
/* 329 */ 57,
/* 330 */ 334,
/* 331 */ 50263,
/* 332 */ -326,
/* 333 */ 58,
/* 334 */ 338,
/* 335 */ 50267,
/* 336 */ -326,
/* 337 */ 59,
/* 338 */ 342,
/* 339 */ 50265,
/* 340 */ -326,
/* 341 */ 60,
/* 342 */ 346,
/* 343 */ 50266,
/* 344 */ -326,
/* 345 */ 61,
/* 346 */ 0,
/* 347 */ 50268,
/* 348 */ -326,
/* 349 */ 62,
/* 350 */ 354,
/* 351 */ 286,
/* 352 */ -350,
/* 353 */ 63,
/* 354 */ 0,
/* 355 */ 326,
/* 356 */ -350,
/* 357 */ 64,
/* 358 */ 362,
/* 359 */ 504,
/* 360 */ -358,
/* 361 */ 65,
/* 362 */ 0,
/* 363 */ 504,
/* 364 */ 50289,
/* 365 */ 358,
/* 366 */ -358,
/* 367 */ 66,
/* 368 */ 0,
/* 369 */ 50260,
/* 370 */ 50287,
/* 371 */ 375,
/* 372 */ 50288,
/* 373 */ -368,
/* 374 */ 67,
/* 375 */ 379,
/* 376 */ 358,
/* 377 */ -375,
/* 378 */ 118,
/* 379 */ 0,
/* 380 */ -375,
/* 381 */ 130,
/* 382 */ 388,
/* 383 */ 50285,
/* 384 */ 504,
/* 385 */ 50286,
/* 386 */ -382,
/* 387 */ 68,
/* 388 */ 0,
/* 389 */ 50285,
/* 390 */ 504,
/* 391 */ 50286,
/* 392 */ 382,
/* 393 */ -382,
/* 394 */ 69,
/* 395 */ 399,
/* 396 */ 50260,
/* 397 */ -395,
/* 398 */ 70,
/* 399 */ 404,
/* 400 */ 50260,
/* 401 */ 382,
/* 402 */ -395,
/* 403 */ 71,
/* 404 */ 409,
/* 405 */ 50271,
/* 406 */ 395,
/* 407 */ -395,
/* 408 */ 72,
/* 409 */ 414,
/* 410 */ 50273,
/* 411 */ 395,
/* 412 */ -395,
/* 413 */ 73,
/* 414 */ 419,
/* 415 */ 395,
/* 416 */ 50271,
/* 417 */ -395,
/* 418 */ 74,
/* 419 */ 0,
/* 420 */ 395,
/* 421 */ 50273,
/* 422 */ -395,
/* 423 */ 75,
/* 424 */ 428,
/* 425 */ 50261,
/* 426 */ -424,
/* 427 */ 76,
/* 428 */ 432,
/* 429 */ 50262,
/* 430 */ -424,
/* 431 */ 77,
/* 432 */ 436,
/* 433 */ 50256,
/* 434 */ -424,
/* 435 */ 78,
/* 436 */ 440,
/* 437 */ 50292,
/* 438 */ -424,
/* 439 */ 79,
/* 440 */ 0,
/* 441 */ 50257,
/* 442 */ -424,
/* 443 */ 80,
/* 444 */ 0,
/* 445 */ 395,
/* 446 */ 50270,
/* 447 */ 504,
/* 448 */ -444,
/* 449 */ 81,
/* 450 */ 454,
/* 451 */ 504,
/* 452 */ -450,
/* 453 */ 82,
/* 454 */ 0,
/* 455 */ 444,
/* 456 */ -450,
/* 457 */ 83,
/* 458 */ 470,
/* 459 */ 50304,
/* 460 */ 50287,
/* 461 */ 490,
/* 462 */ 50290,
/* 463 */ 504,
/* 464 */ 50290,
/* 465 */ 497,
/* 466 */ 50288,
/* 467 */ 224,
/* 468 */ -458,
/* 469 */ 84,
/* 470 */ 480,
/* 471 */ 50319,
/* 472 */ 224,
/* 473 */ 50324,
/* 474 */ 50287,
/* 475 */ 504,
/* 476 */ 50288,
/* 477 */ 50290,
/* 478 */ -458,
/* 479 */ 85,
/* 480 */ 0,
/* 481 */ 50321,
/* 482 */ 50287,
/* 483 */ 50260,
/* 484 */ 50323,
/* 485 */ 50260,
/* 486 */ 50288,
/* 487 */ 224,
/* 488 */ -458,
/* 489 */ 86,
/* 490 */ 494,
/* 491 */ 183,
/* 492 */ -490,
/* 493 */ 119,
/* 494 */ 0,
/* 495 */ -490,
/* 496 */ 131,
/* 497 */ 501,
/* 498 */ 450,
/* 499 */ -497,
/* 500 */ 120,
/* 501 */ 0,
/* 502 */ -497,
/* 503 */ 132,
/* 504 */ 510,
/* 505 */ 504,
/* 506 */ 326,
/* 507 */ 504,
/* 508 */ -504,
/* 509 */ 87,
/* 510 */ 516,
/* 511 */ 50287,
/* 512 */ 504,
/* 513 */ 50288,
/* 514 */ -504,
/* 515 */ 88,
/* 516 */ 520,
/* 517 */ 368,
/* 518 */ -504,
/* 519 */ 89,
/* 520 */ 524,
/* 521 */ 395,
/* 522 */ -504,
/* 523 */ 90,
/* 524 */ 528,
/* 525 */ 424,
/* 526 */ -504,
/* 527 */ 91,
/* 528 */ 533,
/* 529 */ 50272,
/* 530 */ 504,
/* 531 */ -504,
/* 532 */ 92,
/* 533 */ 0,
/* 534 */ 50264,
/* 535 */ 504,
/* 536 */ -504,
/* 537 */ 93,
/* 538 */ 547,
/* 539 */ 50306,
/* 540 */ 50287,
/* 541 */ 504,
/* 542 */ 50288,
/* 543 */ 224,
/* 544 */ 562,
/* 545 */ -538,
/* 546 */ 94,
/* 547 */ 0,
/* 548 */ 50315,
/* 549 */ 50287,
/* 550 */ 50260,
/* 551 */ 50288,
/* 552 */ 50322,
/* 553 */ 50291,
/* 554 */ 50283,
/* 555 */ 570,
/* 556 */ 50298,
/* 557 */ 50291,
/* 558 */ 224,
/* 559 */ 50284,
/* 560 */ -538,
/* 561 */ 95,
/* 562 */ 567,
/* 563 */ 50300,
/* 564 */ 224,
/* 565 */ -562,
/* 566 */ 121,
/* 567 */ 0,
/* 568 */ -562,
/* 569 */ 133,
/* 570 */ 578,
/* 571 */ 50294,
/* 572 */ 50261,
/* 573 */ 50291,
/* 574 */ 224,
/* 575 */ 570,
/* 576 */ -570,
/* 577 */ 122,
/* 578 */ 0,
/* 579 */ -570,
/* 580 */ 134,
/* 581 */ 0,
/* 582 */ 50305,
/* 583 */ 50260,
/* 584 */ -581,
/* 585 */ 96,
/* 586 */ 0,
/* 587 */ 50260,
/* 588 */ 50291,
/* 589 */ -586,
/* 590 */ 97,
/* 591 */ 596,
/* 592 */ 444,
/* 593 */ 50290,
/* 594 */ -591,
/* 595 */ 98,
/* 596 */ 600,
/* 597 */ 538,
/* 598 */ -591,
/* 599 */ 99,
/* 600 */ 604,
/* 601 */ 458,
/* 602 */ -591,
/* 603 */ 100,
/* 604 */ 609,
/* 605 */ 368,
/* 606 */ 50290,
/* 607 */ -591,
/* 608 */ 101,
/* 609 */ 615,
/* 610 */ 50311,
/* 611 */ 642,
/* 612 */ 50290,
/* 613 */ -591,
/* 614 */ 102,
/* 615 */ 620,
/* 616 */ 581,
/* 617 */ 50290,
/* 618 */ -591,
/* 619 */ 103,
/* 620 */ 624,
/* 621 */ 586,
/* 622 */ -591,
/* 623 */ 104,
/* 624 */ 629,
/* 625 */ 50293,
/* 626 */ 50290,
/* 627 */ -591,
/* 628 */ 105,
/* 629 */ 634,
/* 630 */ 50297,
/* 631 */ 50290,
/* 632 */ -591,
/* 633 */ 106,
/* 634 */ 0,
/* 635 */ 50312,
/* 636 */ 50287,
/* 637 */ 143,
/* 638 */ 50288,
/* 639 */ 50290,
/* 640 */ -591,
/* 641 */ 107,
/* 642 */ 646,
/* 643 */ 504,
/* 644 */ -642,
/* 645 */ 123,
/* 646 */ 0,
/* 647 */ -642,
/* 648 */ 135,
/* 649 */ 0,
/* 650 */ -649,
/* 651 */ 108,
0
};
extern int yyannotation[];
int yyannotation[] = {
0,
/* 1 */ 0,
/* 2 */ 0,
/* 3 */ 50000,
/* 4 */ -1,
/* 5 */ 0,
/* 6 */ 10,
/* 7 */ 1,
/* 8 */ -6,
/* 9 */ 1,
/* 10 */ 0,
/* 11 */ 1,
/* 12 */ 1,
/* 13 */ -6,
/* 14 */ 2,
/* 15 */ 19,
/* 16 */ 1,
/* 17 */ -15,
/* 18 */ 1,
/* 19 */ 23,
/* 20 */ 1,
/* 21 */ -15,
/* 22 */ 2,
/* 23 */ 0,
/* 24 */ 1,
/* 25 */ -15,
/* 26 */ 3,
/* 27 */ 31,
/* 28 */ 1,
/* 29 */ -27,
/* 30 */ 1,
/* 31 */ 35,
/* 32 */ 1,
/* 33 */ -27,
/* 34 */ 2,
/* 35 */ 0,
/* 36 */ 1,
/* 37 */ -27,
/* 38 */ 3,
/* 39 */ 43,
/* 40 */ 1,
/* 41 */ -39,
/* 42 */ 1,
/* 43 */ 0,
/* 44 */ 1,
/* 45 */ 50289,
/* 46 */ 1,
/* 47 */ -39,
/* 48 */ 2,
/* 49 */ 53,
/* 50 */ 1,
/* 51 */ -49,
/* 52 */ 1,
/* 53 */ 59,
/* 54 */ 50285,
/* 55 */ 50286,
/* 56 */ 1,
/* 57 */ -49,
/* 58 */ 2,
/* 59 */ 0,
/* 60 */ 50285,
/* 61 */ 50261,
/* 62 */ 50286,
/* 63 */ 1,
/* 64 */ -49,
/* 65 */ 3,
/* 66 */ 0,
/* 67 */ 1,
/* 68 */ 50260,
/* 69 */ 1,
/* 70 */ -66,
/* 71 */ 1,
/* 72 */ 81,
/* 73 */ 1,
/* 74 */ 50260,
/* 75 */ 50287,
/* 76 */ 1,
/* 77 */ 50288,
/* 78 */ 50290,
/* 79 */ -72,
/* 80 */ 1,
/* 81 */ 0,
/* 82 */ 1,
/* 83 */ 50260,
/* 84 */ 50287,
/* 85 */ 1,
/* 86 */ 50288,
/* 87 */ 1,
/* 88 */ -72,
/* 89 */ 2,
/* 90 */ 94,
/* 91 */ 1,
/* 92 */ -90,
/* 93 */ 1,
/* 94 */ 0,
/* 95 */ -90,
/* 96 */ 2,
/* 97 */ 101,
/* 98 */ 1,
/* 99 */ -97,
/* 100 */ 1,
/* 101 */ 0,
/* 102 */ -97,
/* 103 */ 2,
/* 104 */ 0,
/* 105 */ 50301,
/* 106 */ 1,
/* 107 */ 50260,
/* 108 */ 50290,
/* 109 */ -104,
/* 110 */ 1,
/* 111 */ 120,
/* 112 */ 50320,
/* 113 */ 50260,
/* 114 */ 50287,
/* 115 */ 1,
/* 116 */ 50288,
/* 117 */ 50290,
/* 118 */ -111,
/* 119 */ 1,
/* 120 */ 0,
/* 121 */ 50320,
/* 122 */ 50260,
/* 123 */ 50287,
/* 124 */ 1,
/* 125 */ 50288,
/* 126 */ 1,
/* 127 */ -111,
/* 128 */ 2,
/* 129 */ 133,
/* 130 */ 1,
/* 131 */ -129,
/* 132 */ 1,
/* 133 */ 0,
/* 134 */ -129,
/* 135 */ 2,
/* 136 */ 140,
/* 137 */ 1,
/* 138 */ -136,
/* 139 */ 1,
/* 140 */ 0,
/* 141 */ -136,
/* 142 */ 2,
/* 143 */ 147,
/* 144 */ 50308,
/* 145 */ -143,
/* 146 */ 1,
/* 147 */ 151,
/* 148 */ 50292,
/* 149 */ -143,
/* 150 */ 2,
/* 151 */ 155,
/* 152 */ 50303,
/* 153 */ -143,
/* 154 */ 3,
/* 155 */ 159,
/* 156 */ 50309,
/* 157 */ -143,
/* 158 */ 4,
/* 159 */ 163,
/* 160 */ 50295,
/* 161 */ -143,
/* 162 */ 5,
/* 163 */ 167,
/* 164 */ 50299,
/* 165 */ -143,
/* 166 */ 6,
/* 167 */ 171,
/* 168 */ 50260,
/* 169 */ -143,
/* 170 */ 7,
/* 171 */ 175,
/* 172 */ 50314,
/* 173 */ -143,
/* 174 */ 8,
/* 175 */ 179,
/* 176 */ 50316,
/* 177 */ -143,
/* 178 */ 9,
/* 179 */ 0,
/* 180 */ 50317,
/* 181 */ -143,
/* 182 */ 10,
/* 183 */ 0,
/* 184 */ 1,
/* 185 */ 1,
/* 186 */ 1,
/* 187 */ 50290,
/* 188 */ -183,
/* 189 */ 1,
/* 190 */ 194,
/* 191 */ 50296,
/* 192 */ -190,
/* 193 */ 1,
/* 194 */ 0,
/* 195 */ -190,
/* 196 */ 2,
/* 197 */ 201,
/* 198 */ 1,
/* 199 */ -197,
/* 200 */ 1,
/* 201 */ 0,
/* 202 */ 1,
/* 203 */ 50289,
/* 204 */ 1,
/* 205 */ -197,
/* 206 */ 2,
/* 207 */ 211,
/* 208 */ 1,
/* 209 */ -207,
/* 210 */ 1,
/* 211 */ 0,
/* 212 */ 1,
/* 213 */ -207,
/* 214 */ 2,
/* 215 */ 0,
/* 216 */ 50318,
/* 217 */ 50260,
/* 218 */ 50283,
/* 219 */ 1,
/* 220 */ 50284,
/* 221 */ 50290,
/* 222 */ -215,
/* 223 */ 1,
/* 224 */ 0,
/* 225 */ 50283,
/* 226 */ 1,
/* 227 */ 50284,
/* 228 */ -224,
/* 229 */ 1,
/* 230 */ 235,
/* 231 */ 1,
/* 232 */ 1,
/* 233 */ -230,
/* 234 */ 1,
/* 235 */ 0,
/* 236 */ -230,
/* 237 */ 2,
/* 238 */ 242,
/* 239 */ 1,
/* 240 */ -238,
/* 241 */ 1,
/* 242 */ 0,
/* 243 */ 1,
/* 244 */ -238,
/* 245 */ 2,
/* 246 */ 250,
/* 247 */ 50274,
/* 248 */ -246,
/* 249 */ 1,
/* 250 */ 0,
/* 251 */ 50272,
/* 252 */ -246,
/* 253 */ 2,
/* 254 */ 258,
/* 255 */ 50276,
/* 256 */ -254,
/* 257 */ 1,
/* 258 */ 262,
/* 259 */ 50275,
/* 260 */ -254,
/* 261 */ 2,
/* 262 */ 266,
/* 263 */ 50277,
/* 264 */ -254,
/* 265 */ 3,
/* 266 */ 270,
/* 267 */ 50279,
/* 268 */ -254,
/* 269 */ 4,
/* 270 */ 274,
/* 271 */ 50281,
/* 272 */ -254,
/* 273 */ 5,
/* 274 */ 278,
/* 275 */ 50282,
/* 276 */ -254,
/* 277 */ 6,
/* 278 */ 282,
/* 279 */ 50280,
/* 280 */ -254,
/* 281 */ 7,
/* 282 */ 0,
/* 283 */ 50278,
/* 284 */ -254,
/* 285 */ 8,
/* 286 */ 290,
/* 287 */ 50274,
/* 288 */ -286,
/* 289 */ 1,
/* 290 */ 294,
/* 291 */ 50272,
/* 292 */ -286,
/* 293 */ 2,
/* 294 */ 298,
/* 295 */ 50276,
/* 296 */ -286,
/* 297 */ 3,
/* 298 */ 302,
/* 299 */ 50275,
/* 300 */ -286,
/* 301 */ 4,
/* 302 */ 306,
/* 303 */ 50277,
/* 304 */ -286,
/* 305 */ 5,
/* 306 */ 310,
/* 307 */ 50279,
/* 308 */ -286,
/* 309 */ 6,
/* 310 */ 314,
/* 311 */ 50281,
/* 312 */ -286,
/* 313 */ 7,
/* 314 */ 318,
/* 315 */ 50282,
/* 316 */ -286,
/* 317 */ 8,
/* 318 */ 322,
/* 319 */ 50280,
/* 320 */ -286,
/* 321 */ 9,
/* 322 */ 0,
/* 323 */ 50278,
/* 324 */ -286,
/* 325 */ 10,
/* 326 */ 330,
/* 327 */ 50269,
/* 328 */ -326,
/* 329 */ 1,
/* 330 */ 334,
/* 331 */ 50263,
/* 332 */ -326,
/* 333 */ 2,
/* 334 */ 338,
/* 335 */ 50267,
/* 336 */ -326,
/* 337 */ 3,
/* 338 */ 342,
/* 339 */ 50265,
/* 340 */ -326,
/* 341 */ 4,
/* 342 */ 346,
/* 343 */ 50266,
/* 344 */ -326,
/* 345 */ 5,
/* 346 */ 0,
/* 347 */ 50268,
/* 348 */ -326,
/* 349 */ 6,
/* 350 */ 354,
/* 351 */ 1,
/* 352 */ -350,
/* 353 */ 1,
/* 354 */ 0,
/* 355 */ 1,
/* 356 */ -350,
/* 357 */ 2,
/* 358 */ 362,
/* 359 */ 1,
/* 360 */ -358,
/* 361 */ 1,
/* 362 */ 0,
/* 363 */ 1,
/* 364 */ 50289,
/* 365 */ 1,
/* 366 */ -358,
/* 367 */ 2,
/* 368 */ 0,
/* 369 */ 50260,
/* 370 */ 50287,
/* 371 */ 1,
/* 372 */ 50288,
/* 373 */ -368,
/* 374 */ 1,
/* 375 */ 379,
/* 376 */ 1,
/* 377 */ -375,
/* 378 */ 1,
/* 379 */ 0,
/* 380 */ -375,
/* 381 */ 2,
/* 382 */ 388,
/* 383 */ 50285,
/* 384 */ 1,
/* 385 */ 50286,
/* 386 */ -382,
/* 387 */ 1,
/* 388 */ 0,
/* 389 */ 50285,
/* 390 */ 1,
/* 391 */ 50286,
/* 392 */ 1,
/* 393 */ -382,
/* 394 */ 2,
/* 395 */ 399,
/* 396 */ 50260,
/* 397 */ -395,
/* 398 */ 1,
/* 399 */ 404,
/* 400 */ 50260,
/* 401 */ 1,
/* 402 */ -395,
/* 403 */ 2,
/* 404 */ 409,
/* 405 */ 50271,
/* 406 */ 1,
/* 407 */ -395,
/* 408 */ 3,
/* 409 */ 414,
/* 410 */ 50273,
/* 411 */ 1,
/* 412 */ -395,
/* 413 */ 4,
/* 414 */ 419,
/* 415 */ 1,
/* 416 */ 50271,
/* 417 */ -395,
/* 418 */ 5,
/* 419 */ 0,
/* 420 */ 1,
/* 421 */ 50273,
/* 422 */ -395,
/* 423 */ 6,
/* 424 */ 428,
/* 425 */ 50261,
/* 426 */ -424,
/* 427 */ 1,
/* 428 */ 432,
/* 429 */ 50262,
/* 430 */ -424,
/* 431 */ 2,
/* 432 */ 436,
/* 433 */ 50256,
/* 434 */ -424,
/* 435 */ 3,
/* 436 */ 440,
/* 437 */ 50292,
/* 438 */ -424,
/* 439 */ 4,
/* 440 */ 0,
/* 441 */ 50257,
/* 442 */ -424,
/* 443 */ 5,
/* 444 */ 0,
/* 445 */ 1,
/* 446 */ 50270,
/* 447 */ 1,
/* 448 */ -444,
/* 449 */ 1,
/* 450 */ 454,
/* 451 */ 1,
/* 452 */ -450,
/* 453 */ 1,
/* 454 */ 0,
/* 455 */ 1,
/* 456 */ -450,
/* 457 */ 2,
/* 458 */ 470,
/* 459 */ 50304,
/* 460 */ 50287,
/* 461 */ 1,
/* 462 */ 50290,
/* 463 */ 1,
/* 464 */ 50290,
/* 465 */ 1,
/* 466 */ 50288,
/* 467 */ 1,
/* 468 */ -458,
/* 469 */ 1,
/* 470 */ 480,
/* 471 */ 50319,
/* 472 */ 1,
/* 473 */ 50324,
/* 474 */ 50287,
/* 475 */ 1,
/* 476 */ 50288,
/* 477 */ 50290,
/* 478 */ -458,
/* 479 */ 2,
/* 480 */ 0,
/* 481 */ 50321,
/* 482 */ 50287,
/* 483 */ 50260,
/* 484 */ 50323,
/* 485 */ 50260,
/* 486 */ 50288,
/* 487 */ 1,
/* 488 */ -458,
/* 489 */ 3,
/* 490 */ 494,
/* 491 */ 1,
/* 492 */ -490,
/* 493 */ 1,
/* 494 */ 0,
/* 495 */ -490,
/* 496 */ 2,
/* 497 */ 501,
/* 498 */ 1,
/* 499 */ -497,
/* 500 */ 1,
/* 501 */ 0,
/* 502 */ -497,
/* 503 */ 2,
/* 504 */ 510,
/* 505 */ 1,
/* 506 */ 1,
/* 507 */ 1,
/* 508 */ -504,
/* 509 */ 1,
/* 510 */ 516,
/* 511 */ 50287,
/* 512 */ 1,
/* 513 */ 50288,
/* 514 */ -504,
/* 515 */ 2,
/* 516 */ 520,
/* 517 */ 1,
/* 518 */ -504,
/* 519 */ 3,
/* 520 */ 524,
/* 521 */ 1,
/* 522 */ -504,
/* 523 */ 4,
/* 524 */ 528,
/* 525 */ 1,
/* 526 */ -504,
/* 527 */ 5,
/* 528 */ 533,
/* 529 */ 50272,
/* 530 */ 1,
/* 531 */ -504,
/* 532 */ 6,
/* 533 */ 0,
/* 534 */ 50264,
/* 535 */ 1,
/* 536 */ -504,
/* 537 */ 7,
/* 538 */ 547,
/* 539 */ 50306,
/* 540 */ 50287,
/* 541 */ 1,
/* 542 */ 50288,
/* 543 */ 1,
/* 544 */ 1,
/* 545 */ -538,
/* 546 */ 1,
/* 547 */ 0,
/* 548 */ 50315,
/* 549 */ 50287,
/* 550 */ 50260,
/* 551 */ 50288,
/* 552 */ 50322,
/* 553 */ 50291,
/* 554 */ 50283,
/* 555 */ 1,
/* 556 */ 50298,
/* 557 */ 50291,
/* 558 */ 1,
/* 559 */ 50284,
/* 560 */ -538,
/* 561 */ 2,
/* 562 */ 567,
/* 563 */ 50300,
/* 564 */ 1,
/* 565 */ -562,
/* 566 */ 1,
/* 567 */ 0,
/* 568 */ -562,
/* 569 */ 2,
/* 570 */ 578,
/* 571 */ 50294,
/* 572 */ 50261,
/* 573 */ 50291,
/* 574 */ 1,
/* 575 */ 1,
/* 576 */ -570,
/* 577 */ 1,
/* 578 */ 0,
/* 579 */ -570,
/* 580 */ 2,
/* 581 */ 0,
/* 582 */ 50305,
/* 583 */ 50260,
/* 584 */ -581,
/* 585 */ 1,
/* 586 */ 0,
/* 587 */ 50260,
/* 588 */ 50291,
/* 589 */ -586,
/* 590 */ 1,
/* 591 */ 596,
/* 592 */ 1,
/* 593 */ 50290,
/* 594 */ -591,
/* 595 */ 1,
/* 596 */ 600,
/* 597 */ 1,
/* 598 */ -591,
/* 599 */ 2,
/* 600 */ 604,
/* 601 */ 1,
/* 602 */ -591,
/* 603 */ 3,
/* 604 */ 609,
/* 605 */ 1,
/* 606 */ 50290,
/* 607 */ -591,
/* 608 */ 4,
/* 609 */ 615,
/* 610 */ 50311,
/* 611 */ 1,
/* 612 */ 50290,
/* 613 */ -591,
/* 614 */ 5,
/* 615 */ 620,
/* 616 */ 1,
/* 617 */ 50290,
/* 618 */ -591,
/* 619 */ 6,
/* 620 */ 624,
/* 621 */ 1,
/* 622 */ -591,
/* 623 */ 7,
/* 624 */ 629,
/* 625 */ 50293,
/* 626 */ 50290,
/* 627 */ -591,
/* 628 */ 8,
/* 629 */ 634,
/* 630 */ 50297,
/* 631 */ 50290,
/* 632 */ -591,
/* 633 */ 9,
/* 634 */ 0,
/* 635 */ 50312,
/* 636 */ 50287,
/* 637 */ 1,
/* 638 */ 50288,
/* 639 */ 50290,
/* 640 */ -591,
/* 641 */ 10,
/* 642 */ 646,
/* 643 */ 1,
/* 644 */ -642,
/* 645 */ 1,
/* 646 */ 0,
/* 647 */ -642,
/* 648 */ 2,
/* 649 */ 0,
/* 650 */ -649,
/* 651 */ 1,
0
};
extern int yycoordinate[];
int yycoordinate[] = {
0,
/* 1 */ 9999,
/* 2 */ 27009,
/* 3 */ 9999,
/* 4 */ 9999,
/* 5 */ 27009,
/* 6 */ 9999,
/* 7 */ 29023,
/* 8 */ 9999,
/* 9 */ 29003,
/* 10 */ 9999,
/* 11 */ 30023,
/* 12 */ 30037,
/* 13 */ 9999,
/* 14 */ 30003,
/* 15 */ 9999,
/* 16 */ 34003,
/* 17 */ 9999,
/* 18 */ 34009,
/* 19 */ 9999,
/* 20 */ 35003,
/* 21 */ 9999,
/* 22 */ 35011,
/* 23 */ 9999,
/* 24 */ 36003,
/* 25 */ 9999,
/* 26 */ 36012,
/* 27 */ 9999,
/* 28 */ 40003,
/* 29 */ 9999,
/* 30 */ 40010,
/* 31 */ 9999,
/* 32 */ 41003,
/* 33 */ 9999,
/* 34 */ 41010,
/* 35 */ 9999,
/* 36 */ 42003,
/* 37 */ 9999,
/* 38 */ 42012,
/* 39 */ 9999,
/* 40 */ 46003,
/* 41 */ 9999,
/* 42 */ 46010,
/* 43 */ 9999,
/* 44 */ 47003,
/* 45 */ 9999,
/* 46 */ 47018,
/* 47 */ 9999,
/* 48 */ 47010,
/* 49 */ 9999,
/* 50 */ 53003,
/* 51 */ 9999,
/* 52 */ 53012,
/* 53 */ 9999,
/* 54 */ 9999,
/* 55 */ 9999,
/* 56 */ 54066,
/* 57 */ 9999,
/* 58 */ 54014,
/* 59 */ 9999,
/* 60 */ 9999,
/* 61 */ 9999,
/* 62 */ 9999,
/* 63 */ 55124,
/* 64 */ 9999,
/* 65 */ 55014,
/* 66 */ 9999,
/* 67 */ 60003,
/* 68 */ 9999,
/* 69 */ 60162,
/* 70 */ 9999,
/* 71 */ 60006,
/* 72 */ 9999,
/* 73 */ 64003,
/* 74 */ 9999,
/* 75 */ 9999,
/* 76 */ 64286,
/* 77 */ 9999,
/* 78 */ 9999,
/* 79 */ 9999,
/* 80 */ 64006,
/* 81 */ 9999,
/* 82 */ 65003,
/* 83 */ 9999,
/* 84 */ 9999,
/* 85 */ 65254,
/* 86 */ 9999,
/* 87 */ 65288,
/* 88 */ 9999,
/* 89 */ 65006,
/* 90 */ 9999,
/* 91 */ 64288,
/* 92 */ 9999,
/* 93 */ 64296,
/* 94 */ 9999,
/* 95 */ 9999,
/* 96 */ 64296,
/* 97 */ 9999,
/* 98 */ 65256,
/* 99 */ 9999,
/* 100 */ 65264,
/* 101 */ 9999,
/* 102 */ 9999,
/* 103 */ 65264,
/* 104 */ 9999,
/* 105 */ 9999,
/* 106 */ 69010,
/* 107 */ 9999,
/* 108 */ 9999,
/* 109 */ 9999,
/* 110 */ 69008,
/* 111 */ 9999,
/* 112 */ 9999,
/* 113 */ 9999,
/* 114 */ 9999,
/* 115 */ 73040,
/* 116 */ 9999,
/* 117 */ 9999,
/* 118 */ 9999,
/* 119 */ 73011,
/* 120 */ 9999,
/* 121 */ 9999,
/* 122 */ 9999,
/* 123 */ 9999,
/* 124 */ 74040,
/* 125 */ 9999,
/* 126 */ 74074,
/* 127 */ 9999,
/* 128 */ 74011,
/* 129 */ 9999,
/* 130 */ 73042,
/* 131 */ 9999,
/* 132 */ 73050,
/* 133 */ 9999,
/* 134 */ 9999,
/* 135 */ 73050,
/* 136 */ 9999,
/* 137 */ 74042,
/* 138 */ 9999,
/* 139 */ 74050,
/* 140 */ 9999,
/* 141 */ 9999,
/* 142 */ 74050,
/* 143 */ 9999,
/* 144 */ 9999,
/* 145 */ 9999,
/* 146 */ 78005,
/* 147 */ 9999,
/* 148 */ 9999,
/* 149 */ 9999,
/* 150 */ 79009,
/* 151 */ 9999,
/* 152 */ 9999,
/* 153 */ 9999,
/* 154 */ 80007,
/* 155 */ 9999,
/* 156 */ 9999,
/* 157 */ 9999,
/* 158 */ 81006,
/* 159 */ 9999,
/* 160 */ 9999,
/* 161 */ 9999,
/* 162 */ 82013,
/* 163 */ 9999,
/* 164 */ 9999,
/* 165 */ 9999,
/* 166 */ 83008,
/* 167 */ 9999,
/* 168 */ 9999,
/* 169 */ 9999,
/* 170 */ 84009,
/* 171 */ 9999,
/* 172 */ 9999,
/* 173 */ 9999,
/* 174 */ 85015,
/* 175 */ 9999,
/* 176 */ 9999,
/* 177 */ 9999,
/* 178 */ 86006,
/* 179 */ 9999,
/* 180 */ 9999,
/* 181 */ 9999,
/* 182 */ 87006,
/* 183 */ 9999,
/* 184 */ 92003,
/* 185 */ 92025,
/* 186 */ 92059,
/* 187 */ 9999,
/* 188 */ 9999,
/* 189 */ 92003,
/* 190 */ 9999,
/* 191 */ 9999,
/* 192 */ 9999,
/* 193 */ 92009,
/* 194 */ 9999,
/* 195 */ 9999,
/* 196 */ 92009,
/* 197 */ 9999,
/* 198 */ 96003,
/* 199 */ 9999,
/* 200 */ 96013,
/* 201 */ 9999,
/* 202 */ 97003,
/* 203 */ 9999,
/* 204 */ 97021,
/* 205 */ 9999,
/* 206 */ 97013,
/* 207 */ 9999,
/* 208 */ 101003,
/* 209 */ 9999,
/* 210 */ 101017,
/* 211 */ 9999,
/* 212 */ 102003,
/* 213 */ 9999,
/* 214 */ 102010,
/* 215 */ 9999,
/* 216 */ 9999,
/* 217 */ 9999,
/* 218 */ 9999,
/* 219 */ 106173,
/* 220 */ 9999,
/* 221 */ 9999,
/* 222 */ 9999,
/* 223 */ 106008,
/* 224 */ 9999,
/* 225 */ 9999,
/* 226 */ 110036,
/* 227 */ 9999,
/* 228 */ 9999,
/* 229 */ 110016,
/* 230 */ 9999,
/* 231 */ 110038,
/* 232 */ 110038,
/* 233 */ 9999,
/* 234 */ 110038,
/* 235 */ 9999,
/* 236 */ 9999,
/* 237 */ 110038,
/* 238 */ 9999,
/* 239 */ 110040,
/* 240 */ 9999,
/* 241 */ 110046,
/* 242 */ 9999,
/* 243 */ 110050,
/* 244 */ 9999,
/* 245 */ 110063,
/* 246 */ 9999,
/* 247 */ 9999,
/* 248 */ 9999,
/* 249 */ 114014,
/* 250 */ 9999,
/* 251 */ 9999,
/* 252 */ 9999,
/* 253 */ 115015,
/* 254 */ 9999,
/* 255 */ 9999,
/* 256 */ 9999,
/* 257 */ 119012,
/* 258 */ 9999,
/* 259 */ 9999,
/* 260 */ 9999,
/* 261 */ 120005,
/* 262 */ 9999,
/* 263 */ 9999,
/* 264 */ 9999,
/* 265 */ 121005,
/* 266 */ 9999,
/* 267 */ 9999,
/* 268 */ 9999,
/* 269 */ 122015,
/* 270 */ 9999,
/* 271 */ 9999,
/* 272 */ 9999,
/* 273 */ 123014,
/* 274 */ 9999,
/* 275 */ 9999,
/* 276 */ 9999,
/* 277 */ 124005,
/* 278 */ 9999,
/* 279 */ 9999,
/* 280 */ 9999,
/* 281 */ 125011,
/* 282 */ 9999,
/* 283 */ 9999,
/* 284 */ 9999,
/* 285 */ 126012,
/* 286 */ 9999,
/* 287 */ 9999,
/* 288 */ 9999,
/* 289 */ 130014,
/* 290 */ 9999,
/* 291 */ 9999,
/* 292 */ 9999,
/* 293 */ 131015,
/* 294 */ 9999,
/* 295 */ 9999,
/* 296 */ 9999,
/* 297 */ 132012,
/* 298 */ 9999,
/* 299 */ 9999,
/* 300 */ 9999,
/* 301 */ 133005,
/* 302 */ 9999,
/* 303 */ 9999,
/* 304 */ 9999,
/* 305 */ 134005,
/* 306 */ 9999,
/* 307 */ 9999,
/* 308 */ 9999,
/* 309 */ 135015,
/* 310 */ 9999,
/* 311 */ 9999,
/* 312 */ 9999,
/* 313 */ 136014,
/* 314 */ 9999,
/* 315 */ 9999,
/* 316 */ 9999,
/* 317 */ 137005,
/* 318 */ 9999,
/* 319 */ 9999,
/* 320 */ 9999,
/* 321 */ 138011,
/* 322 */ 9999,
/* 323 */ 9999,
/* 324 */ 9999,
/* 325 */ 139012,
/* 326 */ 9999,
/* 327 */ 9999,
/* 328 */ 9999,
/* 329 */ 143007,
/* 330 */ 9999,
/* 331 */ 9999,
/* 332 */ 9999,
/* 333 */ 144010,
/* 334 */ 9999,
/* 335 */ 9999,
/* 336 */ 9999,
/* 337 */ 145015,
/* 338 */ 9999,
/* 339 */ 9999,
/* 340 */ 9999,
/* 341 */ 146013,
/* 342 */ 9999,
/* 343 */ 9999,
/* 344 */ 9999,
/* 345 */ 147010,
/* 346 */ 9999,
/* 347 */ 9999,
/* 348 */ 9999,
/* 349 */ 148012,
/* 350 */ 9999,
/* 351 */ 152003,
/* 352 */ 9999,
/* 353 */ 152012,
/* 354 */ 9999,
/* 355 */ 153003,
/* 356 */ 9999,
/* 357 */ 153013,
/* 358 */ 9999,
/* 359 */ 157003,
/* 360 */ 9999,
/* 361 */ 157006,
/* 362 */ 9999,
/* 363 */ 158003,
/* 364 */ 9999,
/* 365 */ 158059,
/* 366 */ 9999,
/* 367 */ 158006,
/* 368 */ 9999,
/* 369 */ 9999,
/* 370 */ 9999,
/* 371 */ 163033,
/* 372 */ 9999,
/* 373 */ 9999,
/* 374 */ 163009,
/* 375 */ 9999,
/* 376 */ 163071,
/* 377 */ 9999,
/* 378 */ 163035,
/* 379 */ 9999,
/* 380 */ 9999,
/* 381 */ 163035,
/* 382 */ 9999,
/* 383 */ 9999,
/* 384 */ 167016,
/* 385 */ 9999,
/* 386 */ 9999,
/* 387 */ 167014,
/* 388 */ 9999,
/* 389 */ 9999,
/* 390 */ 168016,
/* 391 */ 9999,
/* 392 */ 168088,
/* 393 */ 9999,
/* 394 */ 168014,
/* 395 */ 9999,
/* 396 */ 9999,
/* 397 */ 9999,
/* 398 */ 172009,
/* 399 */ 9999,
/* 400 */ 9999,
/* 401 */ 173146,
/* 402 */ 9999,
/* 403 */ 173009,
/* 404 */ 9999,
/* 405 */ 9999,
/* 406 */ 174013,
/* 407 */ 9999,
/* 408 */ 174011,
/* 409 */ 9999,
/* 410 */ 9999,
/* 411 */ 175013,
/* 412 */ 9999,
/* 413 */ 175011,
/* 414 */ 9999,
/* 415 */ 176003,
/* 416 */ 9999,
/* 417 */ 9999,
/* 418 */ 176010,
/* 419 */ 9999,
/* 420 */ 177003,
/* 421 */ 9999,
/* 422 */ 9999,
/* 423 */ 177010,
/* 424 */ 9999,
/* 425 */ 9999,
/* 426 */ 9999,
/* 427 */ 181011,
/* 428 */ 9999,
/* 429 */ 9999,
/* 430 */ 9999,
/* 431 */ 182012,
/* 432 */ 9999,
/* 433 */ 9999,
/* 434 */ 9999,
/* 435 */ 183006,
/* 436 */ 9999,
/* 437 */ 9999,
/* 438 */ 9999,
/* 439 */ 184009,
/* 440 */ 9999,
/* 441 */ 9999,
/* 442 */ 9999,
/* 443 */ 185008,
/* 444 */ 9999,
/* 445 */ 189003,
/* 446 */ 9999,
/* 447 */ 189083,
/* 448 */ 9999,
/* 449 */ 189010,
/* 450 */ 9999,
/* 451 */ 193003,
/* 452 */ 9999,
/* 453 */ 193006,
/* 454 */ 9999,
/* 455 */ 194003,
/* 456 */ 9999,
/* 457 */ 194017,
/* 458 */ 9999,
/* 459 */ 9999,
/* 460 */ 9999,
/* 461 */ 198026,
/* 462 */ 9999,
/* 463 */ 198049,
/* 464 */ 9999,
/* 465 */ 198067,
/* 466 */ 9999,
/* 467 */ 198103,
/* 468 */ 9999,
/* 469 */ 198005,
/* 470 */ 9999,
/* 471 */ 9999,
/* 472 */ 199010,
/* 473 */ 9999,
/* 474 */ 9999,
/* 475 */ 199044,
/* 476 */ 9999,
/* 477 */ 9999,
/* 478 */ 9999,
/* 479 */ 199008,
/* 480 */ 9999,
/* 481 */ 9999,
/* 482 */ 9999,
/* 483 */ 9999,
/* 484 */ 9999,
/* 485 */ 9999,
/* 486 */ 9999,
/* 487 */ 200324,
/* 488 */ 9999,
/* 489 */ 200009,
/* 490 */ 9999,
/* 491 */ 198028,
/* 492 */ 9999,
/* 493 */ 198034,
/* 494 */ 9999,
/* 495 */ 9999,
/* 496 */ 198034,
/* 497 */ 9999,
/* 498 */ 198069,
/* 499 */ 9999,
/* 500 */ 198079,
/* 501 */ 9999,
/* 502 */ 9999,
/* 503 */ 198079,
/* 504 */ 9999,
/* 505 */ 204003,
/* 506 */ 204011,
/* 507 */ 204026,
/* 508 */ 9999,
/* 509 */ 204006,
/* 510 */ 9999,
/* 511 */ 9999,
/* 512 */ 205022,
/* 513 */ 9999,
/* 514 */ 9999,
/* 515 */ 205020,
/* 516 */ 9999,
/* 517 */ 206003,
/* 518 */ 9999,
/* 519 */ 206018,
/* 520 */ 9999,
/* 521 */ 207003,
/* 522 */ 9999,
/* 523 */ 207010,
/* 524 */ 9999,
/* 525 */ 208003,
/* 526 */ 9999,
/* 527 */ 208011,
/* 528 */ 9999,
/* 529 */ 9999,
/* 530 */ 209017,
/* 531 */ 9999,
/* 532 */ 209015,
/* 533 */ 9999,
/* 534 */ 9999,
/* 535 */ 210007,
/* 536 */ 9999,
/* 537 */ 210005,
/* 538 */ 9999,
/* 539 */ 9999,
/* 540 */ 9999,
/* 541 */ 214025,
/* 542 */ 9999,
/* 543 */ 214052,
/* 544 */ 214151,
/* 545 */ 9999,
/* 546 */ 214004,
/* 547 */ 9999,
/* 548 */ 9999,
/* 549 */ 9999,
/* 550 */ 9999,
/* 551 */ 9999,
/* 552 */ 9999,
/* 553 */ 9999,
/* 554 */ 9999,
/* 555 */ 215101,
/* 556 */ 9999,
/* 557 */ 9999,
/* 558 */ 215153,
/* 559 */ 9999,
/* 560 */ 9999,
/* 561 */ 215008,
/* 562 */ 9999,
/* 563 */ 9999,
/* 564 */ 214158,
/* 565 */ 9999,
/* 566 */ 214156,
/* 567 */ 9999,
/* 568 */ 9999,
/* 569 */ 214156,
/* 570 */ 9999,
/* 571 */ 9999,
/* 572 */ 9999,
/* 573 */ 9999,
/* 574 */ 215127,
/* 575 */ 215106,
/* 576 */ 9999,
/* 577 */ 215106,
/* 578 */ 9999,
/* 579 */ 9999,
/* 580 */ 215106,
/* 581 */ 9999,
/* 582 */ 9999,
/* 583 */ 9999,
/* 584 */ 9999,
/* 585 */ 219006,
/* 586 */ 9999,
/* 587 */ 9999,
/* 588 */ 9999,
/* 589 */ 9999,
/* 590 */ 223009,
/* 591 */ 9999,
/* 592 */ 227003,
/* 593 */ 9999,
/* 594 */ 9999,
/* 595 */ 227017,
/* 596 */ 9999,
/* 597 */ 228003,
/* 598 */ 9999,
/* 599 */ 228016,
/* 600 */ 9999,
/* 601 */ 229003,
/* 602 */ 9999,
/* 603 */ 229011,
/* 604 */ 9999,
/* 605 */ 230003,
/* 606 */ 9999,
/* 607 */ 9999,
/* 608 */ 230018,
/* 609 */ 9999,
/* 610 */ 9999,
/* 611 */ 231025,
/* 612 */ 9999,
/* 613 */ 9999,
/* 614 */ 231008,
/* 615 */ 9999,
/* 616 */ 232003,
/* 617 */ 9999,
/* 618 */ 9999,
/* 619 */ 232010,
/* 620 */ 9999,
/* 621 */ 233003,
/* 622 */ 9999,
/* 623 */ 233012,
/* 624 */ 9999,
/* 625 */ 9999,
/* 626 */ 9999,
/* 627 */ 9999,
/* 628 */ 234007,
/* 629 */ 9999,
/* 630 */ 9999,
/* 631 */ 9999,
/* 632 */ 9999,
/* 633 */ 235010,
/* 634 */ 9999,
/* 635 */ 9999,
/* 636 */ 9999,
/* 637 */ 236029,
/* 638 */ 9999,
/* 639 */ 9999,
/* 640 */ 9999,
/* 641 */ 236008,
/* 642 */ 9999,
/* 643 */ 231027,
/* 644 */ 9999,
/* 645 */ 231030,
/* 646 */ 9999,
/* 647 */ 9999,
/* 648 */ 231030,
/* 649 */ 9999,
/* 650 */ 9999,
/* 651 */ 241001,
0
};
/* only for BIGHASH (see art.c)
extern int DHITS[];
int DHITS[653];
*/
int TABLE[136][256];
init_dirsets() {
TABLE[109][0] = 1;
TABLE[109][318] = 1;
TABLE[109][317] = 1;
TABLE[109][316] = 1;
TABLE[109][314] = 1;
TABLE[109][260] = 1;
TABLE[109][299] = 1;
TABLE[109][295] = 1;
TABLE[109][309] = 1;
TABLE[109][303] = 1;
TABLE[109][292] = 1;
TABLE[109][308] = 1;
TABLE[109][320] = 1;
TABLE[109][301] = 1;
TABLE[109][296] = 1;
TABLE[1][0] = 1;
TABLE[1][308] = 1;
TABLE[1][292] = 1;
TABLE[1][303] = 1;
TABLE[1][309] = 1;
TABLE[1][295] = 1;
TABLE[1][299] = 1;
TABLE[1][260] = 1;
TABLE[1][314] = 1;
TABLE[1][316] = 1;
TABLE[1][317] = 1;
TABLE[1][318] = 1;
TABLE[1][296] = 1;
TABLE[1][301] = 1;
TABLE[1][320] = 1;
TABLE[2][0] = 1;
TABLE[2][308] = 1;
TABLE[2][292] = 1;
TABLE[2][303] = 1;
TABLE[2][309] = 1;
TABLE[2][295] = 1;
TABLE[2][299] = 1;
TABLE[2][260] = 1;
TABLE[2][314] = 1;
TABLE[2][316] = 1;
TABLE[2][317] = 1;
TABLE[2][318] = 1;
TABLE[2][296] = 1;
TABLE[2][301] = 1;
TABLE[2][320] = 1;
TABLE[3][0] = 1;
TABLE[3][318] = 1;
TABLE[3][320] = 1;
TABLE[3][301] = 1;
TABLE[3][317] = 1;
TABLE[3][316] = 1;
TABLE[3][314] = 1;
TABLE[3][260] = 1;
TABLE[3][299] = 1;
TABLE[3][295] = 1;
TABLE[3][309] = 1;
TABLE[3][303] = 1;
TABLE[3][292] = 1;
TABLE[3][308] = 1;
TABLE[3][296] = 1;
TABLE[4][320] = 1;
TABLE[4][301] = 1;
TABLE[4][308] = 1;
TABLE[4][292] = 1;
TABLE[4][303] = 1;
TABLE[4][309] = 1;
TABLE[4][295] = 1;
TABLE[4][299] = 1;
TABLE[4][260] = 1;
TABLE[4][314] = 1;
TABLE[4][316] = 1;
TABLE[4][317] = 1;
TABLE[5][318] = 1;
TABLE[6][317] = 1;
TABLE[6][316] = 1;
TABLE[6][314] = 1;
TABLE[6][260] = 1;
TABLE[6][299] = 1;
TABLE[6][295] = 1;
TABLE[6][309] = 1;
TABLE[6][303] = 1;
TABLE[6][292] = 1;
TABLE[6][308] = 1;
TABLE[7][320] = 1;
TABLE[8][301] = 1;
TABLE[9][317] = 1;
TABLE[9][316] = 1;
TABLE[9][314] = 1;
TABLE[9][260] = 1;
TABLE[9][299] = 1;
TABLE[9][295] = 1;
TABLE[9][309] = 1;
TABLE[9][303] = 1;
TABLE[9][292] = 1;
TABLE[9][308] = 1;
TABLE[10][317] = 1;
TABLE[10][316] = 1;
TABLE[10][314] = 1;
TABLE[10][260] = 1;
TABLE[10][299] = 1;
TABLE[10][295] = 1;
TABLE[10][309] = 1;
TABLE[10][303] = 1;
TABLE[10][292] = 1;
TABLE[10][308] = 1;
TABLE[11][289] = 1;
TABLE[11][288] = 1;
TABLE[12][285] = 1;
TABLE[13][285] = 1;
TABLE[14][308] = 1;
TABLE[14][292] = 1;
TABLE[14][303] = 1;
TABLE[14][309] = 1;
TABLE[14][295] = 1;
TABLE[14][299] = 1;
TABLE[14][260] = 1;
TABLE[14][314] = 1;
TABLE[14][316] = 1;
TABLE[14][317] = 1;
TABLE[15][308] = 1;
TABLE[15][292] = 1;
TABLE[15][303] = 1;
TABLE[15][309] = 1;
TABLE[15][295] = 1;
TABLE[15][299] = 1;
TABLE[15][260] = 1;
TABLE[15][314] = 1;
TABLE[15][316] = 1;
TABLE[15][317] = 1;
TABLE[16][308] = 1;
TABLE[16][292] = 1;
TABLE[16][303] = 1;
TABLE[16][309] = 1;
TABLE[16][295] = 1;
TABLE[16][299] = 1;
TABLE[16][260] = 1;
TABLE[16][314] = 1;
TABLE[16][316] = 1;
TABLE[16][317] = 1;
TABLE[110][308] = 1;
TABLE[110][292] = 1;
TABLE[110][303] = 1;
TABLE[110][309] = 1;
TABLE[110][295] = 1;
TABLE[110][299] = 1;
TABLE[110][260] = 1;
TABLE[110][314] = 1;
TABLE[110][316] = 1;
TABLE[110][317] = 1;
TABLE[124][288] = 1;
TABLE[111][308] = 1;
TABLE[111][292] = 1;
TABLE[111][303] = 1;
TABLE[111][309] = 1;
TABLE[111][295] = 1;
TABLE[111][299] = 1;
TABLE[111][260] = 1;
TABLE[111][314] = 1;
TABLE[111][316] = 1;
TABLE[111][317] = 1;
TABLE[125][288] = 1;
TABLE[17][301] = 1;
TABLE[18][320] = 1;
TABLE[19][320] = 1;
TABLE[112][308] = 1;
TABLE[112][292] = 1;
TABLE[112][303] = 1;
TABLE[112][309] = 1;
TABLE[112][295] = 1;
TABLE[112][299] = 1;
TABLE[112][260] = 1;
TABLE[112][314] = 1;
TABLE[112][316] = 1;
TABLE[112][317] = 1;
TABLE[126][288] = 1;
TABLE[113][308] = 1;
TABLE[113][292] = 1;
TABLE[113][303] = 1;
TABLE[113][309] = 1;
TABLE[113][295] = 1;
TABLE[113][299] = 1;
TABLE[113][260] = 1;
TABLE[113][314] = 1;
TABLE[113][316] = 1;
TABLE[113][317] = 1;
TABLE[127][288] = 1;
TABLE[20][308] = 1;
TABLE[21][292] = 1;
TABLE[22][303] = 1;
TABLE[23][309] = 1;
TABLE[24][295] = 1;
TABLE[25][299] = 1;
TABLE[26][260] = 1;
TABLE[27][314] = 1;
TABLE[28][316] = 1;
TABLE[29][317] = 1;
TABLE[30][308] = 1;
TABLE[30][292] = 1;
TABLE[30][303] = 1;
TABLE[30][309] = 1;
TABLE[30][295] = 1;
TABLE[30][299] = 1;
TABLE[30][260] = 1;
TABLE[30][314] = 1;
TABLE[30][316] = 1;
TABLE[30][317] = 1;
TABLE[30][296] = 1;
TABLE[114][296] = 1;
TABLE[128][308] = 1;
TABLE[128][292] = 1;
TABLE[128][303] = 1;
TABLE[128][309] = 1;
TABLE[128][295] = 1;
TABLE[128][299] = 1;
TABLE[128][260] = 1;
TABLE[128][314] = 1;
TABLE[128][316] = 1;
TABLE[128][317] = 1;
TABLE[31][260] = 1;
TABLE[31][271] = 1;
TABLE[31][273] = 1;
TABLE[32][260] = 1;
TABLE[32][271] = 1;
TABLE[32][273] = 1;
TABLE[33][273] = 1;
TABLE[33][271] = 1;
TABLE[33][260] = 1;
TABLE[34][260] = 1;
TABLE[34][271] = 1;
TABLE[34][273] = 1;
TABLE[35][318] = 1;
TABLE[36][283] = 1;
TABLE[117][284] = 1;
TABLE[117][308] = 1;
TABLE[117][292] = 1;
TABLE[117][303] = 1;
TABLE[117][309] = 1;
TABLE[117][295] = 1;
TABLE[117][299] = 1;
TABLE[117][260] = 1;
TABLE[117][314] = 1;
TABLE[117][316] = 1;
TABLE[117][317] = 1;
TABLE[117][296] = 1;
TABLE[117][312] = 1;
TABLE[117][297] = 1;
TABLE[117][293] = 1;
TABLE[117][305] = 1;
TABLE[117][311] = 1;
TABLE[117][304] = 1;
TABLE[117][319] = 1;
TABLE[117][321] = 1;
TABLE[117][306] = 1;
TABLE[117][315] = 1;
TABLE[117][273] = 1;
TABLE[117][271] = 1;
TABLE[129][284] = 1;
TABLE[115][271] = 1;
TABLE[115][273] = 1;
TABLE[115][315] = 1;
TABLE[115][306] = 1;
TABLE[115][321] = 1;
TABLE[115][319] = 1;
TABLE[115][304] = 1;
TABLE[115][311] = 1;
TABLE[115][305] = 1;
TABLE[115][293] = 1;
TABLE[115][297] = 1;
TABLE[115][312] = 1;
TABLE[115][284] = 1;
TABLE[115][317] = 1;
TABLE[115][316] = 1;
TABLE[115][314] = 1;
TABLE[115][260] = 1;
TABLE[115][299] = 1;
TABLE[115][295] = 1;
TABLE[115][309] = 1;
TABLE[115][303] = 1;
TABLE[115][292] = 1;
TABLE[115][308] = 1;
TABLE[115][296] = 1;
TABLE[116][260] = 1;
TABLE[116][271] = 1;
TABLE[116][273] = 1;
TABLE[116][315] = 1;
TABLE[116][306] = 1;
TABLE[116][321] = 1;
TABLE[116][319] = 1;
TABLE[116][304] = 1;
TABLE[116][311] = 1;
TABLE[116][305] = 1;
TABLE[116][293] = 1;
TABLE[116][297] = 1;
TABLE[116][312] = 1;
TABLE[37][274] = 1;
TABLE[38][272] = 1;
TABLE[39][276] = 1;
TABLE[40][275] = 1;
TABLE[41][277] = 1;
TABLE[42][279] = 1;
TABLE[43][281] = 1;
TABLE[44][282] = 1;
TABLE[45][280] = 1;
TABLE[46][278] = 1;
TABLE[47][274] = 1;
TABLE[48][272] = 1;
TABLE[49][276] = 1;
TABLE[50][275] = 1;
TABLE[51][277] = 1;
TABLE[52][279] = 1;
TABLE[53][281] = 1;
TABLE[54][282] = 1;
TABLE[55][280] = 1;
TABLE[56][278] = 1;
TABLE[57][269] = 1;
TABLE[58][263] = 1;
TABLE[59][267] = 1;
TABLE[60][265] = 1;
TABLE[61][266] = 1;
TABLE[62][268] = 1;
TABLE[63][274] = 1;
TABLE[63][272] = 1;
TABLE[63][276] = 1;
TABLE[63][275] = 1;
TABLE[63][277] = 1;
TABLE[63][279] = 1;
TABLE[63][281] = 1;
TABLE[63][282] = 1;
TABLE[63][280] = 1;
TABLE[63][278] = 1;
TABLE[64][269] = 1;
TABLE[64][263] = 1;
TABLE[64][267] = 1;
TABLE[64][265] = 1;
TABLE[64][266] = 1;
TABLE[64][268] = 1;
TABLE[65][287] = 1;
TABLE[65][260] = 1;
TABLE[65][273] = 1;
TABLE[65][271] = 1;
TABLE[65][257] = 1;
TABLE[65][292] = 1;
TABLE[65][256] = 1;
TABLE[65][262] = 1;
TABLE[65][261] = 1;
TABLE[65][272] = 1;
TABLE[65][264] = 1;
TABLE[66][287] = 1;
TABLE[66][260] = 1;
TABLE[66][273] = 1;
TABLE[66][271] = 1;
TABLE[66][257] = 1;
TABLE[66][292] = 1;
TABLE[66][256] = 1;
TABLE[66][262] = 1;
TABLE[66][261] = 1;
TABLE[66][272] = 1;
TABLE[66][264] = 1;
TABLE[67][260] = 1;
TABLE[118][264] = 1;
TABLE[118][272] = 1;
TABLE[118][261] = 1;
TABLE[118][262] = 1;
TABLE[118][256] = 1;
TABLE[118][292] = 1;
TABLE[118][257] = 1;
TABLE[118][271] = 1;
TABLE[118][273] = 1;
TABLE[118][260] = 1;
TABLE[118][287] = 1;
TABLE[130][288] = 1;
TABLE[68][285] = 1;
TABLE[69][285] = 1;
TABLE[70][260] = 1;
TABLE[71][260] = 1;
TABLE[72][271] = 1;
TABLE[73][273] = 1;
TABLE[74][260] = 1;
TABLE[74][271] = 1;
TABLE[74][273] = 1;
TABLE[75][260] = 1;
TABLE[75][271] = 1;
TABLE[75][273] = 1;
TABLE[76][261] = 1;
TABLE[77][262] = 1;
TABLE[78][256] = 1;
TABLE[79][292] = 1;
TABLE[80][257] = 1;
TABLE[81][260] = 1;
TABLE[81][271] = 1;
TABLE[81][273] = 1;
TABLE[82][287] = 1;
TABLE[82][260] = 1;
TABLE[82][273] = 1;
TABLE[82][271] = 1;
TABLE[82][257] = 1;
TABLE[82][292] = 1;
TABLE[82][256] = 1;
TABLE[82][262] = 1;
TABLE[82][261] = 1;
TABLE[82][272] = 1;
TABLE[82][264] = 1;
TABLE[83][273] = 1;
TABLE[83][271] = 1;
TABLE[83][260] = 1;
TABLE[84][304] = 1;
TABLE[85][319] = 1;
TABLE[86][321] = 1;
TABLE[119][290] = 1;
TABLE[119][317] = 1;
TABLE[119][316] = 1;
TABLE[119][314] = 1;
TABLE[119][260] = 1;
TABLE[119][299] = 1;
TABLE[119][295] = 1;
TABLE[119][309] = 1;
TABLE[119][303] = 1;
TABLE[119][292] = 1;
TABLE[119][308] = 1;
TABLE[119][296] = 1;
TABLE[131][290] = 1;
TABLE[120][260] = 1;
TABLE[120][271] = 1;
TABLE[120][273] = 1;
TABLE[120][264] = 1;
TABLE[120][272] = 1;
TABLE[120][261] = 1;
TABLE[120][262] = 1;
TABLE[120][256] = 1;
TABLE[120][292] = 1;
TABLE[120][257] = 1;
TABLE[120][287] = 1;
TABLE[132][288] = 1;
TABLE[87][287] = 1;
TABLE[87][260] = 1;
TABLE[87][273] = 1;
TABLE[87][271] = 1;
TABLE[87][257] = 1;
TABLE[87][292] = 1;
TABLE[87][256] = 1;
TABLE[87][262] = 1;
TABLE[87][261] = 1;
TABLE[87][272] = 1;
TABLE[87][264] = 1;
TABLE[88][287] = 1;
TABLE[89][260] = 1;
TABLE[90][260] = 1;
TABLE[90][271] = 1;
TABLE[90][273] = 1;
TABLE[91][261] = 1;
TABLE[91][262] = 1;
TABLE[91][256] = 1;
TABLE[91][292] = 1;
TABLE[91][257] = 1;
TABLE[92][272] = 1;
TABLE[93][264] = 1;
TABLE[94][306] = 1;
TABLE[95][315] = 1;
TABLE[121][300] = 1;
TABLE[133][317] = 1;
TABLE[133][316] = 1;
TABLE[133][314] = 1;
TABLE[133][260] = 1;
TABLE[133][299] = 1;
TABLE[133][295] = 1;
TABLE[133][309] = 1;
TABLE[133][303] = 1;
TABLE[133][292] = 1;
TABLE[133][308] = 1;
TABLE[133][271] = 1;
TABLE[133][273] = 1;
TABLE[133][315] = 1;
TABLE[133][306] = 1;
TABLE[133][321] = 1;
TABLE[133][319] = 1;
TABLE[133][304] = 1;
TABLE[133][311] = 1;
TABLE[133][305] = 1;
TABLE[133][293] = 1;
TABLE[133][297] = 1;
TABLE[133][312] = 1;
TABLE[133][296] = 1;
TABLE[133][284] = 1;
TABLE[122][294] = 1;
TABLE[134][298] = 1;
TABLE[96][305] = 1;
TABLE[97][260] = 1;
TABLE[98][273] = 1;
TABLE[98][271] = 1;
TABLE[98][260] = 1;
TABLE[99][306] = 1;
TABLE[99][315] = 1;
TABLE[100][304] = 1;
TABLE[100][319] = 1;
TABLE[100][321] = 1;
TABLE[101][260] = 1;
TABLE[102][311] = 1;
TABLE[103][305] = 1;
TABLE[104][260] = 1;
TABLE[105][293] = 1;
TABLE[106][297] = 1;
TABLE[107][312] = 1;
TABLE[123][287] = 1;
TABLE[123][260] = 1;
TABLE[123][273] = 1;
TABLE[123][271] = 1;
TABLE[123][257] = 1;
TABLE[123][292] = 1;
TABLE[123][256] = 1;
TABLE[123][262] = 1;
TABLE[123][261] = 1;
TABLE[123][272] = 1;
TABLE[123][264] = 1;
TABLE[135][290] = 1;
TABLE[108][289] = 1;
TABLE[108][288] = 1;
}

extern int yydirset();
int yydirset(i,j)
   int i,j;
{
   return TABLE[i][j];
}
int yytransparent(n)
   int n;
{
   switch(n) {
      case 1: return 1; break;
      case 6: return 1; break;
      case 15: return 1; break;
      case 27: return 0; break;
      case 39: return 0; break;
      case 49: return 1; break;
      case 66: return 0; break;
      case 72: return 0; break;
      case 90: return 1; break;
      case 97: return 1; break;
      case 104: return 0; break;
      case 111: return 0; break;
      case 129: return 1; break;
      case 136: return 1; break;
      case 143: return 0; break;
      case 183: return 1; break;
      case 190: return 1; break;
      case 197: return 0; break;
      case 207: return 0; break;
      case 215: return 0; break;
      case 224: return 0; break;
      case 230: return 1; break;
      case 238: return 1; break;
      case 246: return 0; break;
      case 254: return 0; break;
      case 286: return 0; break;
      case 326: return 0; break;
      case 350: return 0; break;
      case 358: return 0; break;
      case 368: return 0; break;
      case 375: return 1; break;
      case 382: return 0; break;
      case 395: return 0; break;
      case 424: return 0; break;
      case 444: return 0; break;
      case 450: return 0; break;
      case 458: return 0; break;
      case 490: return 1; break;
      case 497: return 1; break;
      case 504: return 0; break;
      case 538: return 0; break;
      case 562: return 1; break;
      case 570: return 1; break;
      case 581: return 0; break;
      case 586: return 0; break;
      case 591: return 0; break;
      case 642: return 1; break;
      case 649: return 1; break;
   }
}
char * yyprintname(n)
   int n;
{
   if (n <= 50000)
      switch(n) {
         case 1: return "YYSTART"; break;
         case 6: return "program"; break;
         case 15: return "program_parts"; break;
         case 27: return "func_proc"; break;
         case 39: return "arguments"; break;
         case 49: return "array_dcl"; break;
         case 66: return "argument"; break;
         case 72: return "func_dcl"; break;
         case 90: return "Subphrase"; break;
         case 97: return "Subphrase"; break;
         case 104: return "extern_dcl"; break;
         case 111: return "proc_dcl"; break;
         case 129: return "Subphrase"; break;
         case 136: return "Subphrase"; break;
         case 143: return "type"; break;
         case 183: return "var_dcl"; break;
         case 190: return "Subphrase"; break;
         case 197: return "var_dcl_cnts"; break;
         case 207: return "var_dcl_cnt"; break;
         case 215: return "struct_dec"; break;
         case 224: return "block"; break;
         case 230: return "Subphrase"; break;
         case 238: return "Subphrase"; break;
         case 246: return "arithmatic_low_level"; break;
         case 254: return "arithmatic_high_level"; break;
         case 286: return "arithmatic"; break;
         case 326: return "conditional"; break;
         case 350: return "binary_op"; break;
         case 358: return "parameters"; break;
         case 368: return "method_call_expr"; break;
         case 375: return "Subphrase"; break;
         case 382: return "array_complete_dcl"; break;
         case 395: return "variable"; break;
         case 424: return "const_val"; break;
         case 444: return "assignment_expr"; break;
         case 450: return "expr_assign"; break;
         case 458: return "loop_stmt"; break;
         case 490: return "Subphrase"; break;
         case 497: return "Subphrase"; break;
         case 504: return "expr"; break;
         case 538: return "cond_statement"; break;
         case 562: return "Subphrase"; break;
         case 570: return "Subphrase"; break;
         case 581: return "gotofunc"; break;
         case 586: return "labeltoken"; break;
         case 591: return "statement_expr"; break;
         case 642: return "Subphrase"; break;
         case 649: return "null_point"; break;
   }
   else 
      switch(n-50000) {
         case 324: return "UNTIL"; break;
         case 323: return "IN"; break;
         case 322: return "OF"; break;
         case 321: return "FOREACH"; break;
         case 320: return "PROCEDURE"; break;
         case 319: return "REPEAT"; break;
         case 318: return "RECORD"; break;
         case 317: return "AUTO"; break;
         case 316: return "VOID"; break;
         case 315: return "SWITCH"; break;
         case 314: return "STRINGKEYWORD"; break;
         case 313: return "STATIC"; break;
         case 312: return "SIZEOF"; break;
         case 311: return "RETURN"; break;
         case 310: return "OUTPUT"; break;
         case 309: return "LONG"; break;
         case 308: return "INT"; break;
         case 307: return "INPUT"; break;
         case 306: return "IF"; break;
         case 305: return "GOTO"; break;
         case 304: return "FOR"; break;
         case 303: return "FLOAT"; break;
         case 302: return "FUNCTION"; break;
         case 301: return "EXTERN"; break;
         case 300: return "ELSE"; break;
         case 299: return "DOUBLE"; break;
         case 298: return "DEFAULT"; break;
         case 297: return "CONTINUE"; break;
         case 296: return "CONST"; break;
         case 295: return "CHARKEYWORD"; break;
         case 294: return "CASE"; break;
         case 293: return "BREAK"; break;
         case 292: return "BOOLEAN"; break;
         case 291: return "COLON"; break;
         case 290: return "SEMICOLON"; break;
         case 289: return "COMMA"; break;
         case 288: return "CLOSINGPAREBTHESIS"; break;
         case 287: return "OPENINGPAREBTHESIS"; break;
         case 286: return "CLOSINGBRACE"; break;
         case 285: return "OPENINGBRACE"; break;
         case 284: return "CLOSECURLYBRACE"; break;
         case 283: return "OPENCURLYBRACE"; break;
         case 282: return "XOR"; break;
         case 281: return "ARITHMETICOR"; break;
         case 280: return "LOGICALOR"; break;
         case 279: return "ARITHMETICAND"; break;
         case 278: return "LOGICALAND"; break;
         case 277: return "MOD"; break;
         case 276: return "PRODUCTION"; break;
         case 275: return "DIV"; break;
         case 274: return "ADDUNARYPLUS"; break;
         case 273: return "INCREMENT"; break;
         case 272: return "SUBUNARYMINUS"; break;
         case 271: return "DECREMENT"; break;
         case 270: return "ASSIGNMENT"; break;
         case 269: return "EQUAL"; break;
         case 268: return "BIGGERTHAN"; break;
         case 267: return "BIGGEROREQUAL"; break;
         case 266: return "LESSTHAN"; break;
         case 265: return "LESSOREQUAL"; break;
         case 264: return "NOT"; break;
         case 263: return "NOTEQUAL"; break;
         case 262: return "REALNUMBER"; break;
         case 261: return "INTNUMBER"; break;
         case 260: return "ID_CODE"; break;
         case 259: return "FALSEV"; break;
         case 258: return "TRUEV"; break;
         case 257: return "STRING"; break;
         case 256: return "CHAR"; break;
      }
   return "special_character";
}
