#line 1 "spec.acc"

#include "SymbolTableHandler.h"
#include "OutputHandler.h"
#include "Utility.h"

int arrDecNumber = 0;
int arrDecProduction = 1;

int arrCmptProduction = 1;

Array parametersArray;

char* variableType;

int useOfArrayVar = 0;

int useOfResVar = 0;

char* VariableName;


# line 24 "yygrammar.c"
#include "yygrammar.h"

YYSTART ()
{
   switch(yyselect()) {
   case 117: {
      null_point();
      get_lexval();
      } break;
   }
}

null_point ()
{
   switch(yyselect()) {
   case 1: {
      } break;
   }
}

program ()
{
#line 31 "spec.acc"
 PrepareST(); 
# line 49 "yygrammar.c"
   switch(yyselect()) {
   case 2: {
      program_parts();
      } break;
   case 3: {
      program_parts();
      program();
      } break;
   }
}

program_parts ()
{
   switch(yyselect()) {
   case 4: {
      var_dcl();
      } break;
   case 5: {
      func_proc();
      } break;
   case 6: {
      struct_dec();
      } break;
   }
}

func_proc ()
{
   YYSTYPE x;
   switch(yyselect()) {
   case 7: {
      func_dcl(&x);
#line 43 "spec.acc"
 HandleCodeGenerator("END", x, "", ""); 
# line 84 "yygrammar.c"
      } break;
   case 8: {
      proc_dcl();
      } break;
   case 9: {
      extern_dcl();
      } break;
   }
}

arguments ()
{
   switch(yyselect()) {
   case 10: {
      argument();
      } break;
   case 11: {
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
#line 54 "spec.acc"
 int simpleArray = 1; 
# line 116 "yygrammar.c"
   switch(yyselect()) {
   case 12: {
      null_point();
#line 55 "spec.acc"
 if (arrDecNumber == 0) { *n = 0; } else { if (simpleArray == 1) { *n = 1; } else { *n = arrDecProduction; arrDecProduction = 1; } } arrDecNumber = 0; 
# line 122 "yygrammar.c"
      } break;
   case 13: {
      get_lexval();
      get_lexval();
#line 56 "spec.acc"
 arrDecNumber++; simpleArray = 1; 
# line 129 "yygrammar.c"
      array_dcl(&m);
      } break;
   case 14: {
      get_lexval();
      get_lexval();
      x = yylval;
      get_lexval();
#line 57 "spec.acc"
 arrDecNumber++; simpleArray = 0; arrDecProduction = arrDecProduction * x; 
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
#line 61 "spec.acc"
 int check = 0; char *arrSize1; 
# line 152 "yygrammar.c"
   switch(yyselect()) {
   case 15: {
      type(&x);
      get_lexval();
      y = yylval;
#line 62 "spec.acc"
 char* str6 = Lookup(y); if ((str6 != NULL) && (str6[0] != '\0')) { AddId(y,x); } else { ErrorPrump_IdDuplicated(1,y); return; } 
# line 160 "yygrammar.c"
      array_dcl(&z);
#line 62 "spec.acc"
 char* sizex; if (z == 0) { sizex = GetSizeOf(x); HandleCodeGenerator("ARG", sizex, y, ""); } else { sizex = GetSizeOf(x); arrSize1 = Int2String(z); HandleCodeGenerator("ARG", sizex, arrSize1, y); } 
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
   case 16: {
      type(&x);
      get_lexval();
      y = yylval;
#line 66 "spec.acc"
 char* str = Lookup(y); if ((str != NULL) && (str[0] != '\0')) { AddId(y,x); } else { ErrorPrump_IdDuplicated(1,y); return; } char* size = GetSizeOf(x); HandleCodeGenerator("FUN", y, size, ""); 
# line 182 "yygrammar.c"
      get_lexval();
      switch (yyselect()) {
      case 118: {
         arguments();
         } break;
      default: ;
      }
      get_lexval();
      get_lexval();
#line 66 "spec.acc"
 *n = y; 
# line 194 "yygrammar.c"
      } break;
   case 17: {
      type(&x);
      get_lexval();
      y = yylval;
#line 67 "spec.acc"
 char* str = Lookup(y); if ((str != NULL) && (str[0] != '\0')) { AddId(y,x); } else { ErrorPrump_IdDuplicated(1,y); return; } char* size = GetSizeOf(x); HandleCodeGenerator("FUN", y, size, ""); 
# line 202 "yygrammar.c"
      get_lexval();
      switch (yyselect()) {
      case 119: {
         arguments();
         } break;
      default: ;
      }
      get_lexval();
      block(&m);
#line 67 "spec.acc"
 *n = y; 
# line 214 "yygrammar.c"
      } break;
   }
}

extern_dcl ()
{
   YYSTYPE x;
   YYSTYPE y;
   switch(yyselect()) {
   case 18: {
      get_lexval();
      type(&x);
      get_lexval();
      y = yylval;
#line 71 "spec.acc"
 char* str = Lookup(y); if ((str != NULL) && (str[0] != '\0')) { AddId(y,x); } else { ErrorPrump_IdDuplicated(1,y); return; } 
# line 231 "yygrammar.c"
      get_lexval();
      } break;
   }
}

proc_dcl ()
{
   YYSTYPE m;
   switch(yyselect()) {
   case 19: {
      get_lexval();
      get_lexval();
      get_lexval();
      switch (yyselect()) {
      case 120: {
         arguments();
         } break;
      default: ;
      }
      get_lexval();
      get_lexval();
      } break;
   case 20: {
      get_lexval();
      get_lexval();
      get_lexval();
      switch (yyselect()) {
      case 121: {
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
   case 21: {
      get_lexval();
#line 80 "spec.acc"
 *n = "int"; 
# line 279 "yygrammar.c"
      } break;
   case 22: {
      get_lexval();
#line 81 "spec.acc"
 *n = "bool"; 
# line 285 "yygrammar.c"
      } break;
   case 23: {
      get_lexval();
#line 82 "spec.acc"
 *n = "float"; 
# line 291 "yygrammar.c"
      } break;
   case 24: {
      get_lexval();
#line 83 "spec.acc"
 *n = "long"; 
# line 297 "yygrammar.c"
      } break;
   case 25: {
      get_lexval();
#line 84 "spec.acc"
 *n = "char"; 
# line 303 "yygrammar.c"
      } break;
   case 26: {
      get_lexval();
#line 85 "spec.acc"
 *n = "double"; 
# line 309 "yygrammar.c"
      } break;
   case 27: {
      get_lexval();
      m = yylval;
#line 86 "spec.acc"
 *n = m; 
# line 316 "yygrammar.c"
      } break;
   case 28: {
      get_lexval();
#line 87 "spec.acc"
 *n = "char *"; 
# line 322 "yygrammar.c"
      } break;
   case 29: {
      get_lexval();
#line 88 "spec.acc"
 *n = "void"; 
# line 328 "yygrammar.c"
      } break;
   case 30: {
      get_lexval();
#line 89 "spec.acc"
 *n = "auto"; 
# line 334 "yygrammar.c"
      } break;
   }
}

var_dcl ()
{
   YYSTYPE x;
#line 93 "spec.acc"
 int i = 0; 
# line 344 "yygrammar.c"
   switch(yyselect()) {
   case 31: {
      switch (yyselect()) {
      case 122: {
         get_lexval();
#line 94 "spec.acc"
 i = 1; 
# line 352 "yygrammar.c"
         } break;
      default: ;
      }
      type(&x);
#line 94 "spec.acc"
 variableType = x; 
# line 359 "yygrammar.c"
      var_dcl_cnts();
      get_lexval();
      } break;
   }
}

var_dcl_cnts ()
{
   switch(yyselect()) {
   case 32: {
      var_dcl_cnt();
      } break;
   case 33: {
      var_dcl_cnt();
      get_lexval();
      var_dcl_cnts();
      } break;
   }
}

var_dcl_cnt ()
{
   YYSTYPE x;
   YYSTYPE m;
   switch(yyselect()) {
   case 34: {
      variable(&x);
#line 103 "spec.acc"
 char* str4 = Lookup(x); if ((str4 != NULL) && (str4[0] != '\0')) { AddId(x,variableType); } else { ErrorPrump_IdDuplicated(1,x); return; } char* size = GetSizeOf(variableType); if (useOfArrayVar == 0) { HandleCodeGenerator("VAR", size, x, ""); } else { HandleCodeGenerator("ARR", size, arrCmptProduction, x); arrCmptProduction = 1; useOfArrayVar = 0; } 
# line 389 "yygrammar.c"
      } break;
   case 35: {
      assignment_expr(&m);
      } break;
   }
}

struct_dec ()
{
   YYSTYPE x;
   switch(yyselect()) {
   case 36: {
      get_lexval();
      get_lexval();
      x = yylval;
#line 108 "spec.acc"
 char* str = Lookup(x); if ((str != NULL) && (str[0] != '\0')) { AddId(x,"REC"); } else { ErrorPrump_IdDuplicated(1,x); return; } 
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
   case 37: {
      get_lexval();
#line 112 "spec.acc"
 EnterScope(); 
# line 424 "yygrammar.c"
      while (1) {
         switch (yyselect()) {
         case 125: {
            switch (yyselect()) {
            case 123: {
               var_dcl();
               } break;
            case 124: {
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
#line 112 "spec.acc"
 ExitScope(); 
# line 445 "yygrammar.c"
#line 112 "spec.acc"
 *n = ProduceBlockLabel(); 
# line 448 "yygrammar.c"
      } break;
   }
}

arithmatic_low_level (n)
   YYSTYPE *n;
{
   YYSTYPE x;
   switch(yyselect()) {
   case 38: {
      get_lexval();
      x = yylval;
#line 116 "spec.acc"
 *n = x; 
# line 463 "yygrammar.c"
      } break;
   case 39: {
      get_lexval();
      x = yylval;
#line 117 "spec.acc"
 *n = x; 
# line 470 "yygrammar.c"
      } break;
   }
}

arithmatic_high_level (n)
   YYSTYPE *n;
{
   YYSTYPE x;
   switch(yyselect()) {
   case 40: {
      get_lexval();
      x = yylval;
#line 121 "spec.acc"
 *n = x; 
# line 485 "yygrammar.c"
      } break;
   case 41: {
      get_lexval();
      x = yylval;
#line 122 "spec.acc"
 *n = x; 
# line 492 "yygrammar.c"
      } break;
   case 42: {
      get_lexval();
      x = yylval;
#line 123 "spec.acc"
 *n = x; 
# line 499 "yygrammar.c"
      } break;
   case 43: {
      get_lexval();
      x = yylval;
#line 124 "spec.acc"
 *n = x; 
# line 506 "yygrammar.c"
      } break;
   case 44: {
      get_lexval();
      x = yylval;
#line 125 "spec.acc"
 *n = x; 
# line 513 "yygrammar.c"
      } break;
   case 45: {
      get_lexval();
      x = yylval;
#line 126 "spec.acc"
 *n = x; 
# line 520 "yygrammar.c"
      } break;
   case 46: {
      get_lexval();
      x = yylval;
#line 127 "spec.acc"
 *n = x; 
# line 527 "yygrammar.c"
      } break;
   case 47: {
      get_lexval();
      x = yylval;
#line 128 "spec.acc"
 *n = x; 
# line 534 "yygrammar.c"
      } break;
   }
}

arithmatic (n)
   YYSTYPE *n;
{
   YYSTYPE x;
   switch(yyselect()) {
   case 48: {
      get_lexval();
      x = yylval;
#line 132 "spec.acc"
 *n = x; 
# line 549 "yygrammar.c"
      } break;
   case 49: {
      get_lexval();
      x = yylval;
#line 133 "spec.acc"
 *n = x; 
# line 556 "yygrammar.c"
      } break;
   case 50: {
      get_lexval();
      x = yylval;
#line 134 "spec.acc"
 *n = x; 
# line 563 "yygrammar.c"
      } break;
   case 51: {
      get_lexval();
      x = yylval;
#line 135 "spec.acc"
 *n = x; 
# line 570 "yygrammar.c"
      } break;
   case 52: {
      get_lexval();
      x = yylval;
#line 136 "spec.acc"
 *n = x; 
# line 577 "yygrammar.c"
      } break;
   case 53: {
      get_lexval();
      x = yylval;
#line 137 "spec.acc"
 *n = x; 
# line 584 "yygrammar.c"
      } break;
   case 54: {
      get_lexval();
      x = yylval;
#line 138 "spec.acc"
 *n = x; 
# line 591 "yygrammar.c"
      } break;
   case 55: {
      get_lexval();
      x = yylval;
#line 139 "spec.acc"
 *n = x; 
# line 598 "yygrammar.c"
      } break;
   case 56: {
      get_lexval();
      x = yylval;
#line 140 "spec.acc"
 *n = x; 
# line 605 "yygrammar.c"
      } break;
   case 57: {
      get_lexval();
      x = yylval;
#line 141 "spec.acc"
 *n = x; 
# line 612 "yygrammar.c"
      } break;
   }
}

conditional (n)
   YYSTYPE *n;
{
   YYSTYPE x;
   switch(yyselect()) {
   case 58: {
      get_lexval();
      x = yylval;
#line 145 "spec.acc"
 *n = x; 
# line 627 "yygrammar.c"
      } break;
   case 59: {
      get_lexval();
      x = yylval;
#line 146 "spec.acc"
 *n = x; 
# line 634 "yygrammar.c"
      } break;
   case 60: {
      get_lexval();
      x = yylval;
#line 147 "spec.acc"
 *n = x; 
# line 641 "yygrammar.c"
      } break;
   case 61: {
      get_lexval();
      x = yylval;
#line 148 "spec.acc"
 *n = x; 
# line 648 "yygrammar.c"
      } break;
   case 62: {
      get_lexval();
      x = yylval;
#line 149 "spec.acc"
 *n = x; 
# line 655 "yygrammar.c"
      } break;
   case 63: {
      get_lexval();
      x = yylval;
#line 150 "spec.acc"
 *n = x; 
# line 662 "yygrammar.c"
      } break;
   }
}

binary_op (n)
   YYSTYPE *n;
{
   YYSTYPE x;
   switch(yyselect()) {
   case 64: {
      arithmatic(&x);
#line 154 "spec.acc"
 *n = x; 
# line 676 "yygrammar.c"
      } break;
   case 65: {
      conditional(&x);
#line 155 "spec.acc"
 *n = x; 
# line 682 "yygrammar.c"
      } break;
   }
}

parameters (n)
   YYSTYPE *n;
{
   YYSTYPE x;
   YYSTYPE m;
   switch(yyselect()) {
   case 66: {
      expr(&x);
#line 159 "spec.acc"
 insertArray(&parametersArray, x); *n = ProduceParameters(&parametersArray); freeArray(&parametersArray); 
# line 697 "yygrammar.c"
      } break;
   case 67: {
      expr(&x);
#line 160 "spec.acc"
 insertArray(&parametersArray, x); 
# line 703 "yygrammar.c"
      get_lexval();
      parameters(&m);
      } break;
   }
}

method_call_expr ()
{
   YYSTYPE x;
   YYSTYPE y;
#line 164 "spec.acc"
 int hasParameters = 0; 
# line 716 "yygrammar.c"
   switch(yyselect()) {
   case 68: {
      get_lexval();
      x = yylval;
      get_lexval();
      switch (yyselect()) {
      case 126: {
#line 165 "spec.acc"
 initArray(&parametersArray, 5); 
# line 726 "yygrammar.c"
         parameters(&y);
#line 165 "spec.acc"
 hasParameters = 1; 
# line 730 "yygrammar.c"
         } break;
      default: ;
      }
      get_lexval();
#line 165 "spec.acc"
 if(hasParameters == 0) { HandleCodeGenerator("CALL",x,"",""); } else { HandleCodeGenerator("CALL",x,y,""); } 
# line 737 "yygrammar.c"
      } break;
   }
}

array_complete_dcl (n)
   YYSTYPE *n;
{
   YYSTYPE x;
   YYSTYPE y;
   switch(yyselect()) {
   case 69: {
      get_lexval();
      expr(&x);
      get_lexval();
#line 169 "spec.acc"
 *n = arrCmptProduction * x; 
# line 754 "yygrammar.c"
      } break;
   case 70: {
      get_lexval();
      expr(&x);
      get_lexval();
#line 170 "spec.acc"
 arrCmptProduction = arrCmptProduction * x; 
# line 762 "yygrammar.c"
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
   case 71: {
      get_lexval();
      x = yylval;
#line 174 "spec.acc"
 char * str = Lookup(x); if ((str != NULL) && (str[0] != '\0')) { ErrorPrump_IdNotFound(1,x); } else { *n = x; } 
# line 780 "yygrammar.c"
      } break;
   case 72: {
      get_lexval();
      x = yylval;
#line 175 "spec.acc"
 char * str = Lookup(x); if ((str != NULL) && (str[0] != '\0')) { ErrorPrump_IdNotFound(1,x); } else { *n = x; } 
# line 787 "yygrammar.c"
      array_complete_dcl(&y);
#line 175 "spec.acc"
 useOfArrayVar = 1; *n = x; 
# line 791 "yygrammar.c"
      } break;
   case 73: {
      get_lexval();
      variable(&m);
      } break;
   case 74: {
      get_lexval();
      variable(&m);
      } break;
   case 75: {
      variable(&m);
      get_lexval();
      } break;
   case 76: {
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
   case 77: {
      get_lexval();
      x = yylval;
#line 183 "spec.acc"
 *n = x; 
# line 822 "yygrammar.c"
      } break;
   case 78: {
      get_lexval();
      x = yylval;
#line 184 "spec.acc"
 *n = x; 
# line 829 "yygrammar.c"
      } break;
   case 79: {
      get_lexval();
      x = yylval;
#line 185 "spec.acc"
 *n = x; 
# line 836 "yygrammar.c"
      } break;
   case 80: {
      get_lexval();
      x = yylval;
#line 186 "spec.acc"
 *n = x; 
# line 843 "yygrammar.c"
      } break;
   case 81: {
      get_lexval();
      x = yylval;
#line 187 "spec.acc"
 *n = x; 
# line 850 "yygrammar.c"
      } break;
   }
}

assignment_expr (n)
   YYSTYPE *n;
{
   YYSTYPE x;
   YYSTYPE y;
   switch(yyselect()) {
   case 82: {
      variable(&x);
#line 191 "spec.acc"
 useOfResVar = 1; VariableName = x; 
# line 865 "yygrammar.c"
      get_lexval();
      expr(&y);
#line 191 "spec.acc"
 HandleCodeGenerator("=",x,y,""); useOfResVar = 0; 
# line 870 "yygrammar.c"
      } break;
   }
}

expr_assign ()
{
   YYSTYPE m;
   switch(yyselect()) {
   case 83: {
      expr(&m);
      } break;
   case 84: {
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
   case 85: {
      get_lexval();
      get_lexval();
      switch (yyselect()) {
      case 127: {
         var_dcl();
         } break;
      default: ;
      }
      get_lexval();
      expr(&k);
      get_lexval();
      switch (yyselect()) {
      case 128: {
         expr_assign();
         } break;
      default: ;
      }
      get_lexval();
      block(&l);
      } break;
   case 86: {
      get_lexval();
      block(&m);
      get_lexval();
      get_lexval();
      expr(&l);
      get_lexval();
      get_lexval();
      } break;
   case 87: {
      get_lexval();
      get_lexval();
      get_lexval();
      y = yylval;
#line 202 "spec.acc"
 char* str2 = Lookup(y); if ((str2 != NULL) && (str2[0] != '\0')) { AddId(y,"VAR"); } else { ErrorPrump_IdDuplicated(1,y); return; } 
# line 934 "yygrammar.c"
      get_lexval();
      get_lexval();
      z = yylval;
#line 202 "spec.acc"
 char * str1 = Lookup(z); if ((str1 != NULL) && (str1[0] != '\0')) { ErrorPrump_IdNotFound(1,z); } 
# line 940 "yygrammar.c"
      get_lexval();
      block(&f);
      } break;
   }
}

term (n)
   YYSTYPE *n;
{
   YYSTYPE x;
   YYSTYPE y;
   YYSTYPE z;
   switch(yyselect()) {
   case 88: {
      term(&x);
      arithmatic_low_level(&y);
      factor(&z);
#line 206 "spec.acc"
 char* temp = ProduceTempVar(); HandleCodeGenerator(y,temp,x,z); *n = temp; 
# line 960 "yygrammar.c"
      } break;
   case 89: {
      factor(&x);
      } break;
   }
}

factor (n)
   YYSTYPE *n;
{
   YYSTYPE x;
   YYSTYPE y;
   YYSTYPE z;
   switch(yyselect()) {
   case 90: {
      factor(&x);
      arithmatic_high_level(&y);
      primary(&z);
#line 211 "spec.acc"
 char* temp = ProduceTempVar(); HandleCodeGenerator(y,temp,x,z); *n = temp; 
# line 981 "yygrammar.c"
      } break;
   case 91: {
      primary(&x);
#line 212 "spec.acc"
 *n = x; 
# line 987 "yygrammar.c"
      } break;
   }
}

primary (n)
   YYSTYPE *n;
{
   YYSTYPE x;
   switch(yyselect()) {
   case 92: {
      get_lexval();
      x = yylval;
#line 216 "spec.acc"
 *n = x; 
# line 1002 "yygrammar.c"
      } break;
   case 93: {
      get_lexval();
      x = yylval;
#line 217 "spec.acc"
 *n = x; 
# line 1009 "yygrammar.c"
      } break;
   case 94: {
      get_lexval();
      term(&x);
      get_lexval();
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
   case 95: {
      term(&x);
      } break;
   case 96: {
      expr(&x);
      conditional(&m);
      expr(&y);
      } break;
   case 97: {
      get_lexval();
      expr(&y);
      get_lexval();
      } break;
   case 98: {
      method_call_expr();
      } break;
   case 99: {
      variable(&x);
#line 226 "spec.acc"
 *n = x; 
# line 1046 "yygrammar.c"
      } break;
   case 100: {
      const_val(&m);
      } break;
   case 101: {
      get_lexval();
      expr(&m);
      } break;
   case 102: {
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
   case 103: {
      get_lexval();
      get_lexval();
      expr(&x);
      get_lexval();
      block(&y);
#line 233 "spec.acc"
 char* blockLabel = UseOfBlockLabel(); HandleCodeGenerator("JNZ",blockLabel,x,""); 
# line 1077 "yygrammar.c"
      switch (yyselect()) {
      case 129: {
         get_lexval();
         block(&z);
#line 233 "spec.acc"
 char* blockLabel = UseOfBlockLabel(); HandleCodeGenerator("JZ",blockLabel,z,""); 
# line 1084 "yygrammar.c"
         } break;
      default: ;
      }
      } break;
   case 104: {
      get_lexval();
      get_lexval();
      get_lexval();
      x = yylval;
      get_lexval();
      get_lexval();
      get_lexval();
      get_lexval();
#line 234 "spec.acc"
 EnterScope(); 
# line 1100 "yygrammar.c"
      while (1) {
         switch (yyselect()) {
         case 130: {
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
#line 234 "spec.acc"
 ExitScope(); 
# line 1120 "yygrammar.c"
      } break;
   }
}

gotofunc ()
{
   YYSTYPE x;
   switch(yyselect()) {
   case 105: {
      get_lexval();
      get_lexval();
      x = yylval;
#line 238 "spec.acc"
 HandleCodeGenerator("JMP",x,"",""); 
# line 1135 "yygrammar.c"
      } break;
   }
}

labeltoken ()
{
   YYSTYPE x;
   switch(yyselect()) {
   case 106: {
      get_lexval();
      x = yylval;
      get_lexval();
#line 242 "spec.acc"
 HandleCodeGenerator("LB",x,"",""); 
# line 1150 "yygrammar.c"
      } break;
   }
}

statement_expr ()
{
   YYSTYPE m;
   YYSTYPE x;
   switch(yyselect()) {
   case 107: {
      assignment_expr(&m);
      get_lexval();
      } break;
   case 108: {
      cond_statement();
      } break;
   case 109: {
      loop_stmt();
      } break;
   case 110: {
      method_call_expr();
      get_lexval();
      } break;
   case 111: {
      get_lexval();
#line 250 "spec.acc"
 int i = 0; 
# line 1178 "yygrammar.c"
      switch (yyselect()) {
      case 131: {
         expr(&x);
#line 250 "spec.acc"
 i = 1; 
# line 1184 "yygrammar.c"
         } break;
      default: ;
      }
      get_lexval();
#line 250 "spec.acc"
 if(i == 0) { HandleCodeGenerator("RET",x,"",""); } else HandleCodeGenerator("RET","","",""); 
# line 1191 "yygrammar.c"
      } break;
   case 112: {
      gotofunc();
      get_lexval();
      } break;
   case 113: {
      labeltoken();
      } break;
   case 114: {
      get_lexval();
      get_lexval();
      } break;
   case 115: {
      get_lexval();
      get_lexval();
      } break;
   case 116: {
      get_lexval();
      get_lexval();
      type(&m);
      get_lexval();
      get_lexval();
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
int c_length = 689;
extern int yygrammar[];
int yygrammar[] = {
0,
/* 1 */ 0,
/* 2 */ 6,
/* 3 */ 50000,
/* 4 */ -1,
/* 5 */ 117,
/* 6 */ 0,
/* 7 */ -6,
/* 8 */ 1,
/* 9 */ 13,
/* 10 */ 18,
/* 11 */ -9,
/* 12 */ 2,
/* 13 */ 0,
/* 14 */ 18,
/* 15 */ 9,
/* 16 */ -9,
/* 17 */ 3,
/* 18 */ 22,
/* 19 */ 186,
/* 20 */ -18,
/* 21 */ 4,
/* 22 */ 26,
/* 23 */ 30,
/* 24 */ -18,
/* 25 */ 5,
/* 26 */ 0,
/* 27 */ 218,
/* 28 */ -18,
/* 29 */ 6,
/* 30 */ 34,
/* 31 */ 75,
/* 32 */ -30,
/* 33 */ 7,
/* 34 */ 38,
/* 35 */ 114,
/* 36 */ -30,
/* 37 */ 8,
/* 38 */ 0,
/* 39 */ 107,
/* 40 */ -30,
/* 41 */ 9,
/* 42 */ 46,
/* 43 */ 69,
/* 44 */ -42,
/* 45 */ 10,
/* 46 */ 0,
/* 47 */ 69,
/* 48 */ 50289,
/* 49 */ 42,
/* 50 */ -42,
/* 51 */ 11,
/* 52 */ 56,
/* 53 */ 6,
/* 54 */ -52,
/* 55 */ 12,
/* 56 */ 62,
/* 57 */ 50285,
/* 58 */ 50286,
/* 59 */ 52,
/* 60 */ -52,
/* 61 */ 13,
/* 62 */ 0,
/* 63 */ 50285,
/* 64 */ 50261,
/* 65 */ 50286,
/* 66 */ 52,
/* 67 */ -52,
/* 68 */ 14,
/* 69 */ 0,
/* 70 */ 146,
/* 71 */ 50260,
/* 72 */ 52,
/* 73 */ -69,
/* 74 */ 15,
/* 75 */ 84,
/* 76 */ 146,
/* 77 */ 50260,
/* 78 */ 50287,
/* 79 */ 93,
/* 80 */ 50288,
/* 81 */ 50290,
/* 82 */ -75,
/* 83 */ 16,
/* 84 */ 0,
/* 85 */ 146,
/* 86 */ 50260,
/* 87 */ 50287,
/* 88 */ 100,
/* 89 */ 50288,
/* 90 */ 227,
/* 91 */ -75,
/* 92 */ 17,
/* 93 */ 97,
/* 94 */ 42,
/* 95 */ -93,
/* 96 */ 118,
/* 97 */ 0,
/* 98 */ -93,
/* 99 */ 132,
/* 100 */ 104,
/* 101 */ 42,
/* 102 */ -100,
/* 103 */ 119,
/* 104 */ 0,
/* 105 */ -100,
/* 106 */ 133,
/* 107 */ 0,
/* 108 */ 50302,
/* 109 */ 146,
/* 110 */ 50260,
/* 111 */ 50290,
/* 112 */ -107,
/* 113 */ 18,
/* 114 */ 123,
/* 115 */ 50321,
/* 116 */ 50260,
/* 117 */ 50287,
/* 118 */ 132,
/* 119 */ 50288,
/* 120 */ 50290,
/* 121 */ -114,
/* 122 */ 19,
/* 123 */ 0,
/* 124 */ 50321,
/* 125 */ 50260,
/* 126 */ 50287,
/* 127 */ 139,
/* 128 */ 50288,
/* 129 */ 227,
/* 130 */ -114,
/* 131 */ 20,
/* 132 */ 136,
/* 133 */ 42,
/* 134 */ -132,
/* 135 */ 120,
/* 136 */ 0,
/* 137 */ -132,
/* 138 */ 134,
/* 139 */ 143,
/* 140 */ 42,
/* 141 */ -139,
/* 142 */ 121,
/* 143 */ 0,
/* 144 */ -139,
/* 145 */ 135,
/* 146 */ 150,
/* 147 */ 50309,
/* 148 */ -146,
/* 149 */ 21,
/* 150 */ 154,
/* 151 */ 50293,
/* 152 */ -146,
/* 153 */ 22,
/* 154 */ 158,
/* 155 */ 50304,
/* 156 */ -146,
/* 157 */ 23,
/* 158 */ 162,
/* 159 */ 50310,
/* 160 */ -146,
/* 161 */ 24,
/* 162 */ 166,
/* 163 */ 50296,
/* 164 */ -146,
/* 165 */ 25,
/* 166 */ 170,
/* 167 */ 50300,
/* 168 */ -146,
/* 169 */ 26,
/* 170 */ 174,
/* 171 */ 50260,
/* 172 */ -146,
/* 173 */ 27,
/* 174 */ 178,
/* 175 */ 50315,
/* 176 */ -146,
/* 177 */ 28,
/* 178 */ 182,
/* 179 */ 50317,
/* 180 */ -146,
/* 181 */ 29,
/* 182 */ 0,
/* 183 */ 50318,
/* 184 */ -146,
/* 185 */ 30,
/* 186 */ 0,
/* 187 */ 193,
/* 188 */ 146,
/* 189 */ 200,
/* 190 */ 50290,
/* 191 */ -186,
/* 192 */ 31,
/* 193 */ 197,
/* 194 */ 50297,
/* 195 */ -193,
/* 196 */ 122,
/* 197 */ 0,
/* 198 */ -193,
/* 199 */ 136,
/* 200 */ 204,
/* 201 */ 210,
/* 202 */ -200,
/* 203 */ 32,
/* 204 */ 0,
/* 205 */ 210,
/* 206 */ 50289,
/* 207 */ 200,
/* 208 */ -200,
/* 209 */ 33,
/* 210 */ 214,
/* 211 */ 398,
/* 212 */ -210,
/* 213 */ 34,
/* 214 */ 0,
/* 215 */ 447,
/* 216 */ -210,
/* 217 */ 35,
/* 218 */ 0,
/* 219 */ 50319,
/* 220 */ 50260,
/* 221 */ 50283,
/* 222 */ 186,
/* 223 */ 50284,
/* 224 */ 50290,
/* 225 */ -218,
/* 226 */ 36,
/* 227 */ 0,
/* 228 */ 50283,
/* 229 */ 233,
/* 230 */ 50284,
/* 231 */ -227,
/* 232 */ 37,
/* 233 */ 238,
/* 234 */ 241,
/* 235 */ 233,
/* 236 */ -233,
/* 237 */ 125,
/* 238 */ 0,
/* 239 */ -233,
/* 240 */ 137,
/* 241 */ 245,
/* 242 */ 186,
/* 243 */ -241,
/* 244 */ 123,
/* 245 */ 0,
/* 246 */ 632,
/* 247 */ -241,
/* 248 */ 124,
/* 249 */ 253,
/* 250 */ 50274,
/* 251 */ -249,
/* 252 */ 38,
/* 253 */ 0,
/* 254 */ 50272,
/* 255 */ -249,
/* 256 */ 39,
/* 257 */ 261,
/* 258 */ 50276,
/* 259 */ -257,
/* 260 */ 40,
/* 261 */ 265,
/* 262 */ 50275,
/* 263 */ -257,
/* 264 */ 41,
/* 265 */ 269,
/* 266 */ 50277,
/* 267 */ -257,
/* 268 */ 42,
/* 269 */ 273,
/* 270 */ 50279,
/* 271 */ -257,
/* 272 */ 43,
/* 273 */ 277,
/* 274 */ 50281,
/* 275 */ -257,
/* 276 */ 44,
/* 277 */ 281,
/* 278 */ 50282,
/* 279 */ -257,
/* 280 */ 45,
/* 281 */ 285,
/* 282 */ 50280,
/* 283 */ -257,
/* 284 */ 46,
/* 285 */ 0,
/* 286 */ 50278,
/* 287 */ -257,
/* 288 */ 47,
/* 289 */ 293,
/* 290 */ 50274,
/* 291 */ -289,
/* 292 */ 48,
/* 293 */ 297,
/* 294 */ 50272,
/* 295 */ -289,
/* 296 */ 49,
/* 297 */ 301,
/* 298 */ 50276,
/* 299 */ -289,
/* 300 */ 50,
/* 301 */ 305,
/* 302 */ 50275,
/* 303 */ -289,
/* 304 */ 51,
/* 305 */ 309,
/* 306 */ 50277,
/* 307 */ -289,
/* 308 */ 52,
/* 309 */ 313,
/* 310 */ 50279,
/* 311 */ -289,
/* 312 */ 53,
/* 313 */ 317,
/* 314 */ 50281,
/* 315 */ -289,
/* 316 */ 54,
/* 317 */ 321,
/* 318 */ 50282,
/* 319 */ -289,
/* 320 */ 55,
/* 321 */ 325,
/* 322 */ 50280,
/* 323 */ -289,
/* 324 */ 56,
/* 325 */ 0,
/* 326 */ 50278,
/* 327 */ -289,
/* 328 */ 57,
/* 329 */ 333,
/* 330 */ 50269,
/* 331 */ -329,
/* 332 */ 58,
/* 333 */ 337,
/* 334 */ 50263,
/* 335 */ -329,
/* 336 */ 59,
/* 337 */ 341,
/* 338 */ 50267,
/* 339 */ -329,
/* 340 */ 60,
/* 341 */ 345,
/* 342 */ 50265,
/* 343 */ -329,
/* 344 */ 61,
/* 345 */ 349,
/* 346 */ 50266,
/* 347 */ -329,
/* 348 */ 62,
/* 349 */ 0,
/* 350 */ 50268,
/* 351 */ -329,
/* 352 */ 63,
/* 353 */ 357,
/* 354 */ 289,
/* 355 */ -353,
/* 356 */ 64,
/* 357 */ 0,
/* 358 */ 329,
/* 359 */ -353,
/* 360 */ 65,
/* 361 */ 365,
/* 362 */ 541,
/* 363 */ -361,
/* 364 */ 66,
/* 365 */ 0,
/* 366 */ 541,
/* 367 */ 50289,
/* 368 */ 361,
/* 369 */ -361,
/* 370 */ 67,
/* 371 */ 0,
/* 372 */ 50260,
/* 373 */ 50287,
/* 374 */ 378,
/* 375 */ 50288,
/* 376 */ -371,
/* 377 */ 68,
/* 378 */ 382,
/* 379 */ 361,
/* 380 */ -378,
/* 381 */ 126,
/* 382 */ 0,
/* 383 */ -378,
/* 384 */ 138,
/* 385 */ 391,
/* 386 */ 50285,
/* 387 */ 541,
/* 388 */ 50286,
/* 389 */ -385,
/* 390 */ 69,
/* 391 */ 0,
/* 392 */ 50285,
/* 393 */ 541,
/* 394 */ 50286,
/* 395 */ 385,
/* 396 */ -385,
/* 397 */ 70,
/* 398 */ 402,
/* 399 */ 50260,
/* 400 */ -398,
/* 401 */ 71,
/* 402 */ 407,
/* 403 */ 50260,
/* 404 */ 385,
/* 405 */ -398,
/* 406 */ 72,
/* 407 */ 412,
/* 408 */ 50271,
/* 409 */ 398,
/* 410 */ -398,
/* 411 */ 73,
/* 412 */ 417,
/* 413 */ 50273,
/* 414 */ 398,
/* 415 */ -398,
/* 416 */ 74,
/* 417 */ 422,
/* 418 */ 398,
/* 419 */ 50271,
/* 420 */ -398,
/* 421 */ 75,
/* 422 */ 0,
/* 423 */ 398,
/* 424 */ 50273,
/* 425 */ -398,
/* 426 */ 76,
/* 427 */ 431,
/* 428 */ 50261,
/* 429 */ -427,
/* 430 */ 77,
/* 431 */ 435,
/* 432 */ 50262,
/* 433 */ -427,
/* 434 */ 78,
/* 435 */ 439,
/* 436 */ 50256,
/* 437 */ -427,
/* 438 */ 79,
/* 439 */ 443,
/* 440 */ 50293,
/* 441 */ -427,
/* 442 */ 80,
/* 443 */ 0,
/* 444 */ 50257,
/* 445 */ -427,
/* 446 */ 81,
/* 447 */ 0,
/* 448 */ 398,
/* 449 */ 50270,
/* 450 */ 541,
/* 451 */ -447,
/* 452 */ 82,
/* 453 */ 457,
/* 454 */ 541,
/* 455 */ -453,
/* 456 */ 83,
/* 457 */ 0,
/* 458 */ 447,
/* 459 */ -453,
/* 460 */ 84,
/* 461 */ 473,
/* 462 */ 50305,
/* 463 */ 50287,
/* 464 */ 493,
/* 465 */ 50290,
/* 466 */ 541,
/* 467 */ 50290,
/* 468 */ 500,
/* 469 */ 50288,
/* 470 */ 227,
/* 471 */ -461,
/* 472 */ 85,
/* 473 */ 483,
/* 474 */ 50320,
/* 475 */ 227,
/* 476 */ 50325,
/* 477 */ 50287,
/* 478 */ 541,
/* 479 */ 50288,
/* 480 */ 50290,
/* 481 */ -461,
/* 482 */ 86,
/* 483 */ 0,
/* 484 */ 50322,
/* 485 */ 50287,
/* 486 */ 50260,
/* 487 */ 50324,
/* 488 */ 50260,
/* 489 */ 50288,
/* 490 */ 227,
/* 491 */ -461,
/* 492 */ 87,
/* 493 */ 497,
/* 494 */ 186,
/* 495 */ -493,
/* 496 */ 127,
/* 497 */ 0,
/* 498 */ -493,
/* 499 */ 139,
/* 500 */ 504,
/* 501 */ 453,
/* 502 */ -500,
/* 503 */ 128,
/* 504 */ 0,
/* 505 */ -500,
/* 506 */ 140,
/* 507 */ 513,
/* 508 */ 507,
/* 509 */ 249,
/* 510 */ 517,
/* 511 */ -507,
/* 512 */ 88,
/* 513 */ 0,
/* 514 */ 517,
/* 515 */ -507,
/* 516 */ 89,
/* 517 */ 523,
/* 518 */ 517,
/* 519 */ 257,
/* 520 */ 527,
/* 521 */ -517,
/* 522 */ 90,
/* 523 */ 0,
/* 524 */ 527,
/* 525 */ -517,
/* 526 */ 91,
/* 527 */ 531,
/* 528 */ 50261,
/* 529 */ -527,
/* 530 */ 92,
/* 531 */ 535,
/* 532 */ 50262,
/* 533 */ -527,
/* 534 */ 93,
/* 535 */ 0,
/* 536 */ 50287,
/* 537 */ 507,
/* 538 */ 50288,
/* 539 */ -527,
/* 540 */ 94,
/* 541 */ 545,
/* 542 */ 507,
/* 543 */ -541,
/* 544 */ 95,
/* 545 */ 551,
/* 546 */ 541,
/* 547 */ 329,
/* 548 */ 541,
/* 549 */ -541,
/* 550 */ 96,
/* 551 */ 557,
/* 552 */ 50287,
/* 553 */ 541,
/* 554 */ 50288,
/* 555 */ -541,
/* 556 */ 97,
/* 557 */ 561,
/* 558 */ 371,
/* 559 */ -541,
/* 560 */ 98,
/* 561 */ 565,
/* 562 */ 398,
/* 563 */ -541,
/* 564 */ 99,
/* 565 */ 569,
/* 566 */ 427,
/* 567 */ -541,
/* 568 */ 100,
/* 569 */ 574,
/* 570 */ 50272,
/* 571 */ 541,
/* 572 */ -541,
/* 573 */ 101,
/* 574 */ 0,
/* 575 */ 50264,
/* 576 */ 541,
/* 577 */ -541,
/* 578 */ 102,
/* 579 */ 588,
/* 580 */ 50307,
/* 581 */ 50287,
/* 582 */ 541,
/* 583 */ 50288,
/* 584 */ 227,
/* 585 */ 603,
/* 586 */ -579,
/* 587 */ 103,
/* 588 */ 0,
/* 589 */ 50316,
/* 590 */ 50287,
/* 591 */ 50260,
/* 592 */ 50288,
/* 593 */ 50323,
/* 594 */ 50291,
/* 595 */ 50283,
/* 596 */ 611,
/* 597 */ 50299,
/* 598 */ 50291,
/* 599 */ 227,
/* 600 */ 50284,
/* 601 */ -579,
/* 602 */ 104,
/* 603 */ 608,
/* 604 */ 50301,
/* 605 */ 227,
/* 606 */ -603,
/* 607 */ 129,
/* 608 */ 0,
/* 609 */ -603,
/* 610 */ 141,
/* 611 */ 619,
/* 612 */ 50295,
/* 613 */ 50261,
/* 614 */ 50291,
/* 615 */ 227,
/* 616 */ 611,
/* 617 */ -611,
/* 618 */ 130,
/* 619 */ 0,
/* 620 */ -611,
/* 621 */ 142,
/* 622 */ 0,
/* 623 */ 50306,
/* 624 */ 50260,
/* 625 */ -622,
/* 626 */ 105,
/* 627 */ 0,
/* 628 */ 50260,
/* 629 */ 50291,
/* 630 */ -627,
/* 631 */ 106,
/* 632 */ 637,
/* 633 */ 447,
/* 634 */ 50290,
/* 635 */ -632,
/* 636 */ 107,
/* 637 */ 641,
/* 638 */ 579,
/* 639 */ -632,
/* 640 */ 108,
/* 641 */ 645,
/* 642 */ 461,
/* 643 */ -632,
/* 644 */ 109,
/* 645 */ 650,
/* 646 */ 371,
/* 647 */ 50290,
/* 648 */ -632,
/* 649 */ 110,
/* 650 */ 656,
/* 651 */ 50312,
/* 652 */ 683,
/* 653 */ 50290,
/* 654 */ -632,
/* 655 */ 111,
/* 656 */ 661,
/* 657 */ 622,
/* 658 */ 50290,
/* 659 */ -632,
/* 660 */ 112,
/* 661 */ 665,
/* 662 */ 627,
/* 663 */ -632,
/* 664 */ 113,
/* 665 */ 670,
/* 666 */ 50294,
/* 667 */ 50290,
/* 668 */ -632,
/* 669 */ 114,
/* 670 */ 675,
/* 671 */ 50298,
/* 672 */ 50290,
/* 673 */ -632,
/* 674 */ 115,
/* 675 */ 0,
/* 676 */ 50313,
/* 677 */ 50287,
/* 678 */ 146,
/* 679 */ 50288,
/* 680 */ 50290,
/* 681 */ -632,
/* 682 */ 116,
/* 683 */ 687,
/* 684 */ 541,
/* 685 */ -683,
/* 686 */ 131,
/* 687 */ 0,
/* 688 */ -683,
/* 689 */ 143,
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
/* 6 */ 0,
/* 7 */ -6,
/* 8 */ -1,
/* 9 */ 13,
/* 10 */ 0,
/* 11 */ -9,
/* 12 */ -1,
/* 13 */ 0,
/* 14 */ 0,
/* 15 */ 0,
/* 16 */ -9,
/* 17 */ -1,
/* 18 */ 22,
/* 19 */ 0,
/* 20 */ -18,
/* 21 */ -1,
/* 22 */ 26,
/* 23 */ 0,
/* 24 */ -18,
/* 25 */ -1,
/* 26 */ 0,
/* 27 */ 0,
/* 28 */ -18,
/* 29 */ -1,
/* 30 */ 34,
/* 31 */ 0,
/* 32 */ -30,
/* 33 */ -1,
/* 34 */ 38,
/* 35 */ 0,
/* 36 */ -30,
/* 37 */ -1,
/* 38 */ 0,
/* 39 */ 0,
/* 40 */ -30,
/* 41 */ -1,
/* 42 */ 46,
/* 43 */ 0,
/* 44 */ -42,
/* 45 */ -1,
/* 46 */ 0,
/* 47 */ 0,
/* 48 */ 50289,
/* 49 */ 0,
/* 50 */ -42,
/* 51 */ -1,
/* 52 */ 56,
/* 53 */ 0,
/* 54 */ -52,
/* 55 */ -1,
/* 56 */ 62,
/* 57 */ 50285,
/* 58 */ 50286,
/* 59 */ 0,
/* 60 */ -52,
/* 61 */ -1,
/* 62 */ 0,
/* 63 */ 50285,
/* 64 */ 50261,
/* 65 */ 50286,
/* 66 */ 0,
/* 67 */ -52,
/* 68 */ -1,
/* 69 */ 0,
/* 70 */ 0,
/* 71 */ 50260,
/* 72 */ 0,
/* 73 */ -69,
/* 74 */ -1,
/* 75 */ 84,
/* 76 */ 0,
/* 77 */ 50260,
/* 78 */ 50287,
/* 79 */ 0,
/* 80 */ 50288,
/* 81 */ 50290,
/* 82 */ -75,
/* 83 */ -1,
/* 84 */ 0,
/* 85 */ 0,
/* 86 */ 50260,
/* 87 */ 50287,
/* 88 */ 0,
/* 89 */ 50288,
/* 90 */ 0,
/* 91 */ -75,
/* 92 */ -1,
/* 93 */ 97,
/* 94 */ 0,
/* 95 */ -93,
/* 96 */ -1,
/* 97 */ 0,
/* 98 */ -93,
/* 99 */ -1,
/* 100 */ 104,
/* 101 */ 0,
/* 102 */ -100,
/* 103 */ -1,
/* 104 */ 0,
/* 105 */ -100,
/* 106 */ -1,
/* 107 */ 0,
/* 108 */ 50302,
/* 109 */ 0,
/* 110 */ 50260,
/* 111 */ 50290,
/* 112 */ -107,
/* 113 */ -1,
/* 114 */ 123,
/* 115 */ 50321,
/* 116 */ 50260,
/* 117 */ 50287,
/* 118 */ 0,
/* 119 */ 50288,
/* 120 */ 50290,
/* 121 */ -114,
/* 122 */ -1,
/* 123 */ 0,
/* 124 */ 50321,
/* 125 */ 50260,
/* 126 */ 50287,
/* 127 */ 0,
/* 128 */ 50288,
/* 129 */ 0,
/* 130 */ -114,
/* 131 */ -1,
/* 132 */ 136,
/* 133 */ 0,
/* 134 */ -132,
/* 135 */ -1,
/* 136 */ 0,
/* 137 */ -132,
/* 138 */ -1,
/* 139 */ 143,
/* 140 */ 0,
/* 141 */ -139,
/* 142 */ -1,
/* 143 */ 0,
/* 144 */ -139,
/* 145 */ -1,
/* 146 */ 150,
/* 147 */ 50309,
/* 148 */ -146,
/* 149 */ -1,
/* 150 */ 154,
/* 151 */ 50293,
/* 152 */ -146,
/* 153 */ -1,
/* 154 */ 158,
/* 155 */ 50304,
/* 156 */ -146,
/* 157 */ -1,
/* 158 */ 162,
/* 159 */ 50310,
/* 160 */ -146,
/* 161 */ -1,
/* 162 */ 166,
/* 163 */ 50296,
/* 164 */ -146,
/* 165 */ -1,
/* 166 */ 170,
/* 167 */ 50300,
/* 168 */ -146,
/* 169 */ -1,
/* 170 */ 174,
/* 171 */ 50260,
/* 172 */ -146,
/* 173 */ -1,
/* 174 */ 178,
/* 175 */ 50315,
/* 176 */ -146,
/* 177 */ -1,
/* 178 */ 182,
/* 179 */ 50317,
/* 180 */ -146,
/* 181 */ -1,
/* 182 */ 0,
/* 183 */ 50318,
/* 184 */ -146,
/* 185 */ -1,
/* 186 */ 0,
/* 187 */ 0,
/* 188 */ 0,
/* 189 */ 0,
/* 190 */ 50290,
/* 191 */ -186,
/* 192 */ -1,
/* 193 */ 197,
/* 194 */ 50297,
/* 195 */ -193,
/* 196 */ -1,
/* 197 */ 0,
/* 198 */ -193,
/* 199 */ -1,
/* 200 */ 204,
/* 201 */ 0,
/* 202 */ -200,
/* 203 */ -1,
/* 204 */ 0,
/* 205 */ 0,
/* 206 */ 50289,
/* 207 */ 0,
/* 208 */ -200,
/* 209 */ -1,
/* 210 */ 214,
/* 211 */ 0,
/* 212 */ -210,
/* 213 */ -1,
/* 214 */ 0,
/* 215 */ 0,
/* 216 */ -210,
/* 217 */ -1,
/* 218 */ 0,
/* 219 */ 50319,
/* 220 */ 50260,
/* 221 */ 50283,
/* 222 */ 0,
/* 223 */ 50284,
/* 224 */ 50290,
/* 225 */ -218,
/* 226 */ -1,
/* 227 */ 0,
/* 228 */ 50283,
/* 229 */ 0,
/* 230 */ 50284,
/* 231 */ -227,
/* 232 */ -1,
/* 233 */ 238,
/* 234 */ 0,
/* 235 */ 0,
/* 236 */ -233,
/* 237 */ -1,
/* 238 */ 0,
/* 239 */ -233,
/* 240 */ -1,
/* 241 */ 245,
/* 242 */ 0,
/* 243 */ -241,
/* 244 */ -1,
/* 245 */ 0,
/* 246 */ 0,
/* 247 */ -241,
/* 248 */ -1,
/* 249 */ 253,
/* 250 */ 50274,
/* 251 */ -249,
/* 252 */ -1,
/* 253 */ 0,
/* 254 */ 50272,
/* 255 */ -249,
/* 256 */ -1,
/* 257 */ 261,
/* 258 */ 50276,
/* 259 */ -257,
/* 260 */ -1,
/* 261 */ 265,
/* 262 */ 50275,
/* 263 */ -257,
/* 264 */ -1,
/* 265 */ 269,
/* 266 */ 50277,
/* 267 */ -257,
/* 268 */ -1,
/* 269 */ 273,
/* 270 */ 50279,
/* 271 */ -257,
/* 272 */ -1,
/* 273 */ 277,
/* 274 */ 50281,
/* 275 */ -257,
/* 276 */ -1,
/* 277 */ 281,
/* 278 */ 50282,
/* 279 */ -257,
/* 280 */ -1,
/* 281 */ 285,
/* 282 */ 50280,
/* 283 */ -257,
/* 284 */ -1,
/* 285 */ 0,
/* 286 */ 50278,
/* 287 */ -257,
/* 288 */ -1,
/* 289 */ 293,
/* 290 */ 50274,
/* 291 */ -289,
/* 292 */ -1,
/* 293 */ 297,
/* 294 */ 50272,
/* 295 */ -289,
/* 296 */ -1,
/* 297 */ 301,
/* 298 */ 50276,
/* 299 */ -289,
/* 300 */ -1,
/* 301 */ 305,
/* 302 */ 50275,
/* 303 */ -289,
/* 304 */ -1,
/* 305 */ 309,
/* 306 */ 50277,
/* 307 */ -289,
/* 308 */ -1,
/* 309 */ 313,
/* 310 */ 50279,
/* 311 */ -289,
/* 312 */ -1,
/* 313 */ 317,
/* 314 */ 50281,
/* 315 */ -289,
/* 316 */ -1,
/* 317 */ 321,
/* 318 */ 50282,
/* 319 */ -289,
/* 320 */ -1,
/* 321 */ 325,
/* 322 */ 50280,
/* 323 */ -289,
/* 324 */ -1,
/* 325 */ 0,
/* 326 */ 50278,
/* 327 */ -289,
/* 328 */ -1,
/* 329 */ 333,
/* 330 */ 50269,
/* 331 */ -329,
/* 332 */ -1,
/* 333 */ 337,
/* 334 */ 50263,
/* 335 */ -329,
/* 336 */ -1,
/* 337 */ 341,
/* 338 */ 50267,
/* 339 */ -329,
/* 340 */ -1,
/* 341 */ 345,
/* 342 */ 50265,
/* 343 */ -329,
/* 344 */ -1,
/* 345 */ 349,
/* 346 */ 50266,
/* 347 */ -329,
/* 348 */ -1,
/* 349 */ 0,
/* 350 */ 50268,
/* 351 */ -329,
/* 352 */ -1,
/* 353 */ 357,
/* 354 */ 0,
/* 355 */ -353,
/* 356 */ -1,
/* 357 */ 0,
/* 358 */ 0,
/* 359 */ -353,
/* 360 */ -1,
/* 361 */ 365,
/* 362 */ 0,
/* 363 */ -361,
/* 364 */ -1,
/* 365 */ 0,
/* 366 */ 0,
/* 367 */ 50289,
/* 368 */ 0,
/* 369 */ -361,
/* 370 */ -1,
/* 371 */ 0,
/* 372 */ 50260,
/* 373 */ 50287,
/* 374 */ 0,
/* 375 */ 50288,
/* 376 */ -371,
/* 377 */ -1,
/* 378 */ 382,
/* 379 */ 0,
/* 380 */ -378,
/* 381 */ -1,
/* 382 */ 0,
/* 383 */ -378,
/* 384 */ -1,
/* 385 */ 391,
/* 386 */ 50285,
/* 387 */ 0,
/* 388 */ 50286,
/* 389 */ -385,
/* 390 */ -1,
/* 391 */ 0,
/* 392 */ 50285,
/* 393 */ 0,
/* 394 */ 50286,
/* 395 */ 0,
/* 396 */ -385,
/* 397 */ -1,
/* 398 */ 402,
/* 399 */ 50260,
/* 400 */ -398,
/* 401 */ -1,
/* 402 */ 407,
/* 403 */ 50260,
/* 404 */ 0,
/* 405 */ -398,
/* 406 */ -1,
/* 407 */ 412,
/* 408 */ 50271,
/* 409 */ 0,
/* 410 */ -398,
/* 411 */ -1,
/* 412 */ 417,
/* 413 */ 50273,
/* 414 */ 0,
/* 415 */ -398,
/* 416 */ -1,
/* 417 */ 422,
/* 418 */ 0,
/* 419 */ 50271,
/* 420 */ -398,
/* 421 */ -1,
/* 422 */ 0,
/* 423 */ 0,
/* 424 */ 50273,
/* 425 */ -398,
/* 426 */ -1,
/* 427 */ 431,
/* 428 */ 50261,
/* 429 */ -427,
/* 430 */ -1,
/* 431 */ 435,
/* 432 */ 50262,
/* 433 */ -427,
/* 434 */ -1,
/* 435 */ 439,
/* 436 */ 50256,
/* 437 */ -427,
/* 438 */ -1,
/* 439 */ 443,
/* 440 */ 50293,
/* 441 */ -427,
/* 442 */ -1,
/* 443 */ 0,
/* 444 */ 50257,
/* 445 */ -427,
/* 446 */ -1,
/* 447 */ 0,
/* 448 */ 0,
/* 449 */ 50270,
/* 450 */ 0,
/* 451 */ -447,
/* 452 */ -1,
/* 453 */ 457,
/* 454 */ 0,
/* 455 */ -453,
/* 456 */ -1,
/* 457 */ 0,
/* 458 */ 0,
/* 459 */ -453,
/* 460 */ -1,
/* 461 */ 473,
/* 462 */ 50305,
/* 463 */ 50287,
/* 464 */ 0,
/* 465 */ 50290,
/* 466 */ 0,
/* 467 */ 50290,
/* 468 */ 0,
/* 469 */ 50288,
/* 470 */ 0,
/* 471 */ -461,
/* 472 */ -1,
/* 473 */ 483,
/* 474 */ 50320,
/* 475 */ 0,
/* 476 */ 50325,
/* 477 */ 50287,
/* 478 */ 0,
/* 479 */ 50288,
/* 480 */ 50290,
/* 481 */ -461,
/* 482 */ -1,
/* 483 */ 0,
/* 484 */ 50322,
/* 485 */ 50287,
/* 486 */ 50260,
/* 487 */ 50324,
/* 488 */ 50260,
/* 489 */ 50288,
/* 490 */ 0,
/* 491 */ -461,
/* 492 */ -1,
/* 493 */ 497,
/* 494 */ 0,
/* 495 */ -493,
/* 496 */ -1,
/* 497 */ 0,
/* 498 */ -493,
/* 499 */ -1,
/* 500 */ 504,
/* 501 */ 0,
/* 502 */ -500,
/* 503 */ -1,
/* 504 */ 0,
/* 505 */ -500,
/* 506 */ -1,
/* 507 */ 513,
/* 508 */ 0,
/* 509 */ 0,
/* 510 */ 0,
/* 511 */ -507,
/* 512 */ -1,
/* 513 */ 0,
/* 514 */ 0,
/* 515 */ -507,
/* 516 */ -1,
/* 517 */ 523,
/* 518 */ 0,
/* 519 */ 0,
/* 520 */ 0,
/* 521 */ -517,
/* 522 */ -1,
/* 523 */ 0,
/* 524 */ 0,
/* 525 */ -517,
/* 526 */ -1,
/* 527 */ 531,
/* 528 */ 50261,
/* 529 */ -527,
/* 530 */ -1,
/* 531 */ 535,
/* 532 */ 50262,
/* 533 */ -527,
/* 534 */ -1,
/* 535 */ 0,
/* 536 */ 50287,
/* 537 */ 0,
/* 538 */ 50288,
/* 539 */ -527,
/* 540 */ -1,
/* 541 */ 545,
/* 542 */ 0,
/* 543 */ -541,
/* 544 */ -1,
/* 545 */ 551,
/* 546 */ 0,
/* 547 */ 0,
/* 548 */ 0,
/* 549 */ -541,
/* 550 */ -1,
/* 551 */ 557,
/* 552 */ 50287,
/* 553 */ 0,
/* 554 */ 50288,
/* 555 */ -541,
/* 556 */ -1,
/* 557 */ 561,
/* 558 */ 0,
/* 559 */ -541,
/* 560 */ -1,
/* 561 */ 565,
/* 562 */ 0,
/* 563 */ -541,
/* 564 */ -1,
/* 565 */ 569,
/* 566 */ 0,
/* 567 */ -541,
/* 568 */ -1,
/* 569 */ 574,
/* 570 */ 50272,
/* 571 */ 0,
/* 572 */ -541,
/* 573 */ -1,
/* 574 */ 0,
/* 575 */ 50264,
/* 576 */ 0,
/* 577 */ -541,
/* 578 */ -1,
/* 579 */ 588,
/* 580 */ 50307,
/* 581 */ 50287,
/* 582 */ 0,
/* 583 */ 50288,
/* 584 */ 0,
/* 585 */ 0,
/* 586 */ -579,
/* 587 */ -1,
/* 588 */ 0,
/* 589 */ 50316,
/* 590 */ 50287,
/* 591 */ 50260,
/* 592 */ 50288,
/* 593 */ 50323,
/* 594 */ 50291,
/* 595 */ 50283,
/* 596 */ 0,
/* 597 */ 50299,
/* 598 */ 50291,
/* 599 */ 0,
/* 600 */ 50284,
/* 601 */ -579,
/* 602 */ -1,
/* 603 */ 608,
/* 604 */ 50301,
/* 605 */ 0,
/* 606 */ -603,
/* 607 */ -1,
/* 608 */ 0,
/* 609 */ -603,
/* 610 */ -1,
/* 611 */ 619,
/* 612 */ 50295,
/* 613 */ 50261,
/* 614 */ 50291,
/* 615 */ 0,
/* 616 */ 0,
/* 617 */ -611,
/* 618 */ -1,
/* 619 */ 0,
/* 620 */ -611,
/* 621 */ -1,
/* 622 */ 0,
/* 623 */ 50306,
/* 624 */ 50260,
/* 625 */ -622,
/* 626 */ -1,
/* 627 */ 0,
/* 628 */ 50260,
/* 629 */ 50291,
/* 630 */ -627,
/* 631 */ -1,
/* 632 */ 637,
/* 633 */ 0,
/* 634 */ 50290,
/* 635 */ -632,
/* 636 */ -1,
/* 637 */ 641,
/* 638 */ 0,
/* 639 */ -632,
/* 640 */ -1,
/* 641 */ 645,
/* 642 */ 0,
/* 643 */ -632,
/* 644 */ -1,
/* 645 */ 650,
/* 646 */ 0,
/* 647 */ 50290,
/* 648 */ -632,
/* 649 */ -1,
/* 650 */ 656,
/* 651 */ 50312,
/* 652 */ 0,
/* 653 */ 50290,
/* 654 */ -632,
/* 655 */ -1,
/* 656 */ 661,
/* 657 */ 0,
/* 658 */ 50290,
/* 659 */ -632,
/* 660 */ -1,
/* 661 */ 665,
/* 662 */ 0,
/* 663 */ -632,
/* 664 */ -1,
/* 665 */ 670,
/* 666 */ 50294,
/* 667 */ 50290,
/* 668 */ -632,
/* 669 */ -1,
/* 670 */ 675,
/* 671 */ 50298,
/* 672 */ 50290,
/* 673 */ -632,
/* 674 */ -1,
/* 675 */ 0,
/* 676 */ 50313,
/* 677 */ 50287,
/* 678 */ 0,
/* 679 */ 50288,
/* 680 */ 50290,
/* 681 */ -632,
/* 682 */ -1,
/* 683 */ 687,
/* 684 */ 0,
/* 685 */ -683,
/* 686 */ -1,
/* 687 */ 0,
/* 688 */ -683,
/* 689 */ -1,
0
};
extern int yycoordinate[];
int yycoordinate[] = {
0,
/* 1 */ 9999,
/* 2 */ 27012,
/* 3 */ 9999,
/* 4 */ 9999,
/* 5 */ 27012,
/* 6 */ 9999,
/* 7 */ 9999,
/* 8 */ 28001,
/* 9 */ 9999,
/* 10 */ 32003,
/* 11 */ 9999,
/* 12 */ 32015,
/* 13 */ 9999,
/* 14 */ 33003,
/* 15 */ 33017,
/* 16 */ 9999,
/* 17 */ 33015,
/* 18 */ 9999,
/* 19 */ 37003,
/* 20 */ 9999,
/* 21 */ 37009,
/* 22 */ 9999,
/* 23 */ 38003,
/* 24 */ 9999,
/* 25 */ 38011,
/* 26 */ 9999,
/* 27 */ 39003,
/* 28 */ 9999,
/* 29 */ 39012,
/* 30 */ 9999,
/* 31 */ 43003,
/* 32 */ 9999,
/* 33 */ 43010,
/* 34 */ 9999,
/* 35 */ 44003,
/* 36 */ 9999,
/* 37 */ 44010,
/* 38 */ 9999,
/* 39 */ 45003,
/* 40 */ 9999,
/* 41 */ 45012,
/* 42 */ 9999,
/* 43 */ 49003,
/* 44 */ 9999,
/* 45 */ 49010,
/* 46 */ 9999,
/* 47 */ 50003,
/* 48 */ 9999,
/* 49 */ 50018,
/* 50 */ 9999,
/* 51 */ 50010,
/* 52 */ 9999,
/* 53 */ 55003,
/* 54 */ 9999,
/* 55 */ 55012,
/* 56 */ 9999,
/* 57 */ 9999,
/* 58 */ 9999,
/* 59 */ 56066,
/* 60 */ 9999,
/* 61 */ 56014,
/* 62 */ 9999,
/* 63 */ 9999,
/* 64 */ 9999,
/* 65 */ 9999,
/* 66 */ 57120,
/* 67 */ 9999,
/* 68 */ 57014,
/* 69 */ 9999,
/* 70 */ 62003,
/* 71 */ 9999,
/* 72 */ 62154,
/* 73 */ 9999,
/* 74 */ 62006,
/* 75 */ 9999,
/* 76 */ 66003,
/* 77 */ 9999,
/* 78 */ 9999,
/* 79 */ 66238,
/* 80 */ 9999,
/* 81 */ 9999,
/* 82 */ 9999,
/* 83 */ 66006,
/* 84 */ 9999,
/* 85 */ 67003,
/* 86 */ 9999,
/* 87 */ 9999,
/* 88 */ 67238,
/* 89 */ 9999,
/* 90 */ 67272,
/* 91 */ 9999,
/* 92 */ 67006,
/* 93 */ 9999,
/* 94 */ 66240,
/* 95 */ 9999,
/* 96 */ 66248,
/* 97 */ 9999,
/* 98 */ 9999,
/* 99 */ 66248,
/* 100 */ 9999,
/* 101 */ 67240,
/* 102 */ 9999,
/* 103 */ 67248,
/* 104 */ 9999,
/* 105 */ 9999,
/* 106 */ 67248,
/* 107 */ 9999,
/* 108 */ 9999,
/* 109 */ 71010,
/* 110 */ 9999,
/* 111 */ 9999,
/* 112 */ 9999,
/* 113 */ 71008,
/* 114 */ 9999,
/* 115 */ 9999,
/* 116 */ 9999,
/* 117 */ 9999,
/* 118 */ 75040,
/* 119 */ 9999,
/* 120 */ 9999,
/* 121 */ 9999,
/* 122 */ 75011,
/* 123 */ 9999,
/* 124 */ 9999,
/* 125 */ 9999,
/* 126 */ 9999,
/* 127 */ 76040,
/* 128 */ 9999,
/* 129 */ 76074,
/* 130 */ 9999,
/* 131 */ 76011,
/* 132 */ 9999,
/* 133 */ 75042,
/* 134 */ 9999,
/* 135 */ 75050,
/* 136 */ 9999,
/* 137 */ 9999,
/* 138 */ 75050,
/* 139 */ 9999,
/* 140 */ 76042,
/* 141 */ 9999,
/* 142 */ 76050,
/* 143 */ 9999,
/* 144 */ 9999,
/* 145 */ 76050,
/* 146 */ 9999,
/* 147 */ 9999,
/* 148 */ 9999,
/* 149 */ 80005,
/* 150 */ 9999,
/* 151 */ 9999,
/* 152 */ 9999,
/* 153 */ 81009,
/* 154 */ 9999,
/* 155 */ 9999,
/* 156 */ 9999,
/* 157 */ 82007,
/* 158 */ 9999,
/* 159 */ 9999,
/* 160 */ 9999,
/* 161 */ 83006,
/* 162 */ 9999,
/* 163 */ 9999,
/* 164 */ 9999,
/* 165 */ 84013,
/* 166 */ 9999,
/* 167 */ 9999,
/* 168 */ 9999,
/* 169 */ 85008,
/* 170 */ 9999,
/* 171 */ 9999,
/* 172 */ 9999,
/* 173 */ 86009,
/* 174 */ 9999,
/* 175 */ 9999,
/* 176 */ 9999,
/* 177 */ 87015,
/* 178 */ 9999,
/* 179 */ 9999,
/* 180 */ 9999,
/* 181 */ 88006,
/* 182 */ 9999,
/* 183 */ 9999,
/* 184 */ 9999,
/* 185 */ 89006,
/* 186 */ 9999,
/* 187 */ 94003,
/* 188 */ 94025,
/* 189 */ 94055,
/* 190 */ 9999,
/* 191 */ 9999,
/* 192 */ 94003,
/* 193 */ 9999,
/* 194 */ 9999,
/* 195 */ 9999,
/* 196 */ 94009,
/* 197 */ 9999,
/* 198 */ 9999,
/* 199 */ 94009,
/* 200 */ 9999,
/* 201 */ 98003,
/* 202 */ 9999,
/* 203 */ 98013,
/* 204 */ 9999,
/* 205 */ 99003,
/* 206 */ 9999,
/* 207 */ 99021,
/* 208 */ 9999,
/* 209 */ 99013,
/* 210 */ 9999,
/* 211 */ 103003,
/* 212 */ 9999,
/* 213 */ 103010,
/* 214 */ 9999,
/* 215 */ 104003,
/* 216 */ 9999,
/* 217 */ 104017,
/* 218 */ 9999,
/* 219 */ 9999,
/* 220 */ 9999,
/* 221 */ 9999,
/* 222 */ 108169,
/* 223 */ 9999,
/* 224 */ 9999,
/* 225 */ 9999,
/* 226 */ 108008,
/* 227 */ 9999,
/* 228 */ 9999,
/* 229 */ 112036,
/* 230 */ 9999,
/* 231 */ 9999,
/* 232 */ 112016,
/* 233 */ 9999,
/* 234 */ 112038,
/* 235 */ 112038,
/* 236 */ 9999,
/* 237 */ 112038,
/* 238 */ 9999,
/* 239 */ 9999,
/* 240 */ 112038,
/* 241 */ 9999,
/* 242 */ 112040,
/* 243 */ 9999,
/* 244 */ 112046,
/* 245 */ 9999,
/* 246 */ 112050,
/* 247 */ 9999,
/* 248 */ 112063,
/* 249 */ 9999,
/* 250 */ 9999,
/* 251 */ 9999,
/* 252 */ 116014,
/* 253 */ 9999,
/* 254 */ 9999,
/* 255 */ 9999,
/* 256 */ 117015,
/* 257 */ 9999,
/* 258 */ 9999,
/* 259 */ 9999,
/* 260 */ 121012,
/* 261 */ 9999,
/* 262 */ 9999,
/* 263 */ 9999,
/* 264 */ 122005,
/* 265 */ 9999,
/* 266 */ 9999,
/* 267 */ 9999,
/* 268 */ 123005,
/* 269 */ 9999,
/* 270 */ 9999,
/* 271 */ 9999,
/* 272 */ 124015,
/* 273 */ 9999,
/* 274 */ 9999,
/* 275 */ 9999,
/* 276 */ 125014,
/* 277 */ 9999,
/* 278 */ 9999,
/* 279 */ 9999,
/* 280 */ 126005,
/* 281 */ 9999,
/* 282 */ 9999,
/* 283 */ 9999,
/* 284 */ 127011,
/* 285 */ 9999,
/* 286 */ 9999,
/* 287 */ 9999,
/* 288 */ 128012,
/* 289 */ 9999,
/* 290 */ 9999,
/* 291 */ 9999,
/* 292 */ 132014,
/* 293 */ 9999,
/* 294 */ 9999,
/* 295 */ 9999,
/* 296 */ 133015,
/* 297 */ 9999,
/* 298 */ 9999,
/* 299 */ 9999,
/* 300 */ 134012,
/* 301 */ 9999,
/* 302 */ 9999,
/* 303 */ 9999,
/* 304 */ 135005,
/* 305 */ 9999,
/* 306 */ 9999,
/* 307 */ 9999,
/* 308 */ 136005,
/* 309 */ 9999,
/* 310 */ 9999,
/* 311 */ 9999,
/* 312 */ 137015,
/* 313 */ 9999,
/* 314 */ 9999,
/* 315 */ 9999,
/* 316 */ 138014,
/* 317 */ 9999,
/* 318 */ 9999,
/* 319 */ 9999,
/* 320 */ 139005,
/* 321 */ 9999,
/* 322 */ 9999,
/* 323 */ 9999,
/* 324 */ 140011,
/* 325 */ 9999,
/* 326 */ 9999,
/* 327 */ 9999,
/* 328 */ 141012,
/* 329 */ 9999,
/* 330 */ 9999,
/* 331 */ 9999,
/* 332 */ 145007,
/* 333 */ 9999,
/* 334 */ 9999,
/* 335 */ 9999,
/* 336 */ 146010,
/* 337 */ 9999,
/* 338 */ 9999,
/* 339 */ 9999,
/* 340 */ 147015,
/* 341 */ 9999,
/* 342 */ 9999,
/* 343 */ 9999,
/* 344 */ 148013,
/* 345 */ 9999,
/* 346 */ 9999,
/* 347 */ 9999,
/* 348 */ 149010,
/* 349 */ 9999,
/* 350 */ 9999,
/* 351 */ 9999,
/* 352 */ 150012,
/* 353 */ 9999,
/* 354 */ 154003,
/* 355 */ 9999,
/* 356 */ 154012,
/* 357 */ 9999,
/* 358 */ 155003,
/* 359 */ 9999,
/* 360 */ 155013,
/* 361 */ 9999,
/* 362 */ 159003,
/* 363 */ 9999,
/* 364 */ 159006,
/* 365 */ 9999,
/* 366 */ 160003,
/* 367 */ 9999,
/* 368 */ 160055,
/* 369 */ 9999,
/* 370 */ 160006,
/* 371 */ 9999,
/* 372 */ 9999,
/* 373 */ 9999,
/* 374 */ 165033,
/* 375 */ 9999,
/* 376 */ 9999,
/* 377 */ 165009,
/* 378 */ 9999,
/* 379 */ 165071,
/* 380 */ 9999,
/* 381 */ 165035,
/* 382 */ 9999,
/* 383 */ 9999,
/* 384 */ 165035,
/* 385 */ 9999,
/* 386 */ 9999,
/* 387 */ 169016,
/* 388 */ 9999,
/* 389 */ 9999,
/* 390 */ 169014,
/* 391 */ 9999,
/* 392 */ 9999,
/* 393 */ 170016,
/* 394 */ 9999,
/* 395 */ 170084,
/* 396 */ 9999,
/* 397 */ 170014,
/* 398 */ 9999,
/* 399 */ 9999,
/* 400 */ 9999,
/* 401 */ 174009,
/* 402 */ 9999,
/* 403 */ 9999,
/* 404 */ 175130,
/* 405 */ 9999,
/* 406 */ 175009,
/* 407 */ 9999,
/* 408 */ 9999,
/* 409 */ 176013,
/* 410 */ 9999,
/* 411 */ 176011,
/* 412 */ 9999,
/* 413 */ 9999,
/* 414 */ 177013,
/* 415 */ 9999,
/* 416 */ 177011,
/* 417 */ 9999,
/* 418 */ 178003,
/* 419 */ 9999,
/* 420 */ 9999,
/* 421 */ 178010,
/* 422 */ 9999,
/* 423 */ 179003,
/* 424 */ 9999,
/* 425 */ 9999,
/* 426 */ 179010,
/* 427 */ 9999,
/* 428 */ 9999,
/* 429 */ 9999,
/* 430 */ 183011,
/* 431 */ 9999,
/* 432 */ 9999,
/* 433 */ 9999,
/* 434 */ 184012,
/* 435 */ 9999,
/* 436 */ 9999,
/* 437 */ 9999,
/* 438 */ 185006,
/* 439 */ 9999,
/* 440 */ 9999,
/* 441 */ 9999,
/* 442 */ 186009,
/* 443 */ 9999,
/* 444 */ 9999,
/* 445 */ 9999,
/* 446 */ 187008,
/* 447 */ 9999,
/* 448 */ 191003,
/* 449 */ 9999,
/* 450 */ 191065,
/* 451 */ 9999,
/* 452 */ 191010,
/* 453 */ 9999,
/* 454 */ 195003,
/* 455 */ 9999,
/* 456 */ 195006,
/* 457 */ 9999,
/* 458 */ 196003,
/* 459 */ 9999,
/* 460 */ 196017,
/* 461 */ 9999,
/* 462 */ 9999,
/* 463 */ 9999,
/* 464 */ 200026,
/* 465 */ 9999,
/* 466 */ 200049,
/* 467 */ 9999,
/* 468 */ 200067,
/* 469 */ 9999,
/* 470 */ 200103,
/* 471 */ 9999,
/* 472 */ 200005,
/* 473 */ 9999,
/* 474 */ 9999,
/* 475 */ 201010,
/* 476 */ 9999,
/* 477 */ 9999,
/* 478 */ 201044,
/* 479 */ 9999,
/* 480 */ 9999,
/* 481 */ 9999,
/* 482 */ 201008,
/* 483 */ 9999,
/* 484 */ 9999,
/* 485 */ 9999,
/* 486 */ 9999,
/* 487 */ 9999,
/* 488 */ 9999,
/* 489 */ 9999,
/* 490 */ 202312,
/* 491 */ 9999,
/* 492 */ 202009,
/* 493 */ 9999,
/* 494 */ 200028,
/* 495 */ 9999,
/* 496 */ 200034,
/* 497 */ 9999,
/* 498 */ 9999,
/* 499 */ 200034,
/* 500 */ 9999,
/* 501 */ 200069,
/* 502 */ 9999,
/* 503 */ 200079,
/* 504 */ 9999,
/* 505 */ 9999,
/* 506 */ 200079,
/* 507 */ 9999,
/* 508 */ 206003,
/* 509 */ 206011,
/* 510 */ 206035,
/* 511 */ 9999,
/* 512 */ 206006,
/* 513 */ 9999,
/* 514 */ 207003,
/* 515 */ 9999,
/* 516 */ 207008,
/* 517 */ 9999,
/* 518 */ 211003,
/* 519 */ 211013,
/* 520 */ 211038,
/* 521 */ 9999,
/* 522 */ 211008,
/* 523 */ 9999,
/* 524 */ 212003,
/* 525 */ 9999,
/* 526 */ 212009,
/* 527 */ 9999,
/* 528 */ 9999,
/* 529 */ 9999,
/* 530 */ 216011,
/* 531 */ 9999,
/* 532 */ 9999,
/* 533 */ 9999,
/* 534 */ 217012,
/* 535 */ 9999,
/* 536 */ 9999,
/* 537 */ 218022,
/* 538 */ 9999,
/* 539 */ 9999,
/* 540 */ 218020,
/* 541 */ 9999,
/* 542 */ 222003,
/* 543 */ 9999,
/* 544 */ 222006,
/* 545 */ 9999,
/* 546 */ 223003,
/* 547 */ 223011,
/* 548 */ 223026,
/* 549 */ 9999,
/* 550 */ 223006,
/* 551 */ 9999,
/* 552 */ 9999,
/* 553 */ 224022,
/* 554 */ 9999,
/* 555 */ 9999,
/* 556 */ 224020,
/* 557 */ 9999,
/* 558 */ 225003,
/* 559 */ 9999,
/* 560 */ 225018,
/* 561 */ 9999,
/* 562 */ 226003,
/* 563 */ 9999,
/* 564 */ 226010,
/* 565 */ 9999,
/* 566 */ 227003,
/* 567 */ 9999,
/* 568 */ 227011,
/* 569 */ 9999,
/* 570 */ 9999,
/* 571 */ 228017,
/* 572 */ 9999,
/* 573 */ 228015,
/* 574 */ 9999,
/* 575 */ 9999,
/* 576 */ 229007,
/* 577 */ 9999,
/* 578 */ 229005,
/* 579 */ 9999,
/* 580 */ 9999,
/* 581 */ 9999,
/* 582 */ 233025,
/* 583 */ 9999,
/* 584 */ 233052,
/* 585 */ 233147,
/* 586 */ 9999,
/* 587 */ 233004,
/* 588 */ 9999,
/* 589 */ 9999,
/* 590 */ 9999,
/* 591 */ 9999,
/* 592 */ 9999,
/* 593 */ 9999,
/* 594 */ 9999,
/* 595 */ 9999,
/* 596 */ 234101,
/* 597 */ 9999,
/* 598 */ 9999,
/* 599 */ 234153,
/* 600 */ 9999,
/* 601 */ 9999,
/* 602 */ 234008,
/* 603 */ 9999,
/* 604 */ 9999,
/* 605 */ 233154,
/* 606 */ 9999,
/* 607 */ 233152,
/* 608 */ 9999,
/* 609 */ 9999,
/* 610 */ 233152,
/* 611 */ 9999,
/* 612 */ 9999,
/* 613 */ 9999,
/* 614 */ 9999,
/* 615 */ 234127,
/* 616 */ 234106,
/* 617 */ 9999,
/* 618 */ 234106,
/* 619 */ 9999,
/* 620 */ 9999,
/* 621 */ 234106,
/* 622 */ 9999,
/* 623 */ 9999,
/* 624 */ 9999,
/* 625 */ 9999,
/* 626 */ 238006,
/* 627 */ 9999,
/* 628 */ 9999,
/* 629 */ 9999,
/* 630 */ 9999,
/* 631 */ 242009,
/* 632 */ 9999,
/* 633 */ 246003,
/* 634 */ 9999,
/* 635 */ 9999,
/* 636 */ 246017,
/* 637 */ 9999,
/* 638 */ 247003,
/* 639 */ 9999,
/* 640 */ 247016,
/* 641 */ 9999,
/* 642 */ 248003,
/* 643 */ 9999,
/* 644 */ 248011,
/* 645 */ 9999,
/* 646 */ 249003,
/* 647 */ 9999,
/* 648 */ 9999,
/* 649 */ 249018,
/* 650 */ 9999,
/* 651 */ 9999,
/* 652 */ 250025,
/* 653 */ 9999,
/* 654 */ 9999,
/* 655 */ 250008,
/* 656 */ 9999,
/* 657 */ 251003,
/* 658 */ 9999,
/* 659 */ 9999,
/* 660 */ 251010,
/* 661 */ 9999,
/* 662 */ 252003,
/* 663 */ 9999,
/* 664 */ 252012,
/* 665 */ 9999,
/* 666 */ 9999,
/* 667 */ 9999,
/* 668 */ 9999,
/* 669 */ 253007,
/* 670 */ 9999,
/* 671 */ 9999,
/* 672 */ 9999,
/* 673 */ 9999,
/* 674 */ 254010,
/* 675 */ 9999,
/* 676 */ 9999,
/* 677 */ 9999,
/* 678 */ 255029,
/* 679 */ 9999,
/* 680 */ 9999,
/* 681 */ 9999,
/* 682 */ 255008,
/* 683 */ 9999,
/* 684 */ 250027,
/* 685 */ 9999,
/* 686 */ 250030,
/* 687 */ 9999,
/* 688 */ 9999,
/* 689 */ 250030,
0
};
/* only for BIGHASH (see art.c)
extern int DHITS[];
int DHITS[691];
*/
int TABLE[144][256];
init_dirsets() {
TABLE[117][0] = 1;
TABLE[1][0] = 1;
TABLE[1][289] = 1;
TABLE[1][288] = 1;
TABLE[2][309] = 1;
TABLE[2][293] = 1;
TABLE[2][304] = 1;
TABLE[2][310] = 1;
TABLE[2][296] = 1;
TABLE[2][300] = 1;
TABLE[2][260] = 1;
TABLE[2][315] = 1;
TABLE[2][317] = 1;
TABLE[2][318] = 1;
TABLE[2][319] = 1;
TABLE[2][297] = 1;
TABLE[2][302] = 1;
TABLE[2][321] = 1;
TABLE[3][309] = 1;
TABLE[3][293] = 1;
TABLE[3][304] = 1;
TABLE[3][310] = 1;
TABLE[3][296] = 1;
TABLE[3][300] = 1;
TABLE[3][260] = 1;
TABLE[3][315] = 1;
TABLE[3][317] = 1;
TABLE[3][318] = 1;
TABLE[3][319] = 1;
TABLE[3][297] = 1;
TABLE[3][302] = 1;
TABLE[3][321] = 1;
TABLE[4][319] = 1;
TABLE[4][321] = 1;
TABLE[4][302] = 1;
TABLE[4][318] = 1;
TABLE[4][317] = 1;
TABLE[4][315] = 1;
TABLE[4][260] = 1;
TABLE[4][300] = 1;
TABLE[4][296] = 1;
TABLE[4][310] = 1;
TABLE[4][304] = 1;
TABLE[4][293] = 1;
TABLE[4][309] = 1;
TABLE[4][297] = 1;
TABLE[5][321] = 1;
TABLE[5][302] = 1;
TABLE[5][309] = 1;
TABLE[5][293] = 1;
TABLE[5][304] = 1;
TABLE[5][310] = 1;
TABLE[5][296] = 1;
TABLE[5][300] = 1;
TABLE[5][260] = 1;
TABLE[5][315] = 1;
TABLE[5][317] = 1;
TABLE[5][318] = 1;
TABLE[6][319] = 1;
TABLE[7][318] = 1;
TABLE[7][317] = 1;
TABLE[7][315] = 1;
TABLE[7][260] = 1;
TABLE[7][300] = 1;
TABLE[7][296] = 1;
TABLE[7][310] = 1;
TABLE[7][304] = 1;
TABLE[7][293] = 1;
TABLE[7][309] = 1;
TABLE[8][321] = 1;
TABLE[9][302] = 1;
TABLE[10][318] = 1;
TABLE[10][317] = 1;
TABLE[10][315] = 1;
TABLE[10][260] = 1;
TABLE[10][300] = 1;
TABLE[10][296] = 1;
TABLE[10][310] = 1;
TABLE[10][304] = 1;
TABLE[10][293] = 1;
TABLE[10][309] = 1;
TABLE[11][318] = 1;
TABLE[11][317] = 1;
TABLE[11][315] = 1;
TABLE[11][260] = 1;
TABLE[11][300] = 1;
TABLE[11][296] = 1;
TABLE[11][310] = 1;
TABLE[11][304] = 1;
TABLE[11][293] = 1;
TABLE[11][309] = 1;
TABLE[12][289] = 1;
TABLE[12][288] = 1;
TABLE[13][285] = 1;
TABLE[14][285] = 1;
TABLE[15][309] = 1;
TABLE[15][293] = 1;
TABLE[15][304] = 1;
TABLE[15][310] = 1;
TABLE[15][296] = 1;
TABLE[15][300] = 1;
TABLE[15][260] = 1;
TABLE[15][315] = 1;
TABLE[15][317] = 1;
TABLE[15][318] = 1;
TABLE[16][309] = 1;
TABLE[16][293] = 1;
TABLE[16][304] = 1;
TABLE[16][310] = 1;
TABLE[16][296] = 1;
TABLE[16][300] = 1;
TABLE[16][260] = 1;
TABLE[16][315] = 1;
TABLE[16][317] = 1;
TABLE[16][318] = 1;
TABLE[17][309] = 1;
TABLE[17][293] = 1;
TABLE[17][304] = 1;
TABLE[17][310] = 1;
TABLE[17][296] = 1;
TABLE[17][300] = 1;
TABLE[17][260] = 1;
TABLE[17][315] = 1;
TABLE[17][317] = 1;
TABLE[17][318] = 1;
TABLE[118][309] = 1;
TABLE[118][293] = 1;
TABLE[118][304] = 1;
TABLE[118][310] = 1;
TABLE[118][296] = 1;
TABLE[118][300] = 1;
TABLE[118][260] = 1;
TABLE[118][315] = 1;
TABLE[118][317] = 1;
TABLE[118][318] = 1;
TABLE[132][288] = 1;
TABLE[119][309] = 1;
TABLE[119][293] = 1;
TABLE[119][304] = 1;
TABLE[119][310] = 1;
TABLE[119][296] = 1;
TABLE[119][300] = 1;
TABLE[119][260] = 1;
TABLE[119][315] = 1;
TABLE[119][317] = 1;
TABLE[119][318] = 1;
TABLE[133][288] = 1;
TABLE[18][302] = 1;
TABLE[19][321] = 1;
TABLE[20][321] = 1;
TABLE[120][309] = 1;
TABLE[120][293] = 1;
TABLE[120][304] = 1;
TABLE[120][310] = 1;
TABLE[120][296] = 1;
TABLE[120][300] = 1;
TABLE[120][260] = 1;
TABLE[120][315] = 1;
TABLE[120][317] = 1;
TABLE[120][318] = 1;
TABLE[134][288] = 1;
TABLE[121][309] = 1;
TABLE[121][293] = 1;
TABLE[121][304] = 1;
TABLE[121][310] = 1;
TABLE[121][296] = 1;
TABLE[121][300] = 1;
TABLE[121][260] = 1;
TABLE[121][315] = 1;
TABLE[121][317] = 1;
TABLE[121][318] = 1;
TABLE[135][288] = 1;
TABLE[21][309] = 1;
TABLE[22][293] = 1;
TABLE[23][304] = 1;
TABLE[24][310] = 1;
TABLE[25][296] = 1;
TABLE[26][300] = 1;
TABLE[27][260] = 1;
TABLE[28][315] = 1;
TABLE[29][317] = 1;
TABLE[30][318] = 1;
TABLE[31][309] = 1;
TABLE[31][293] = 1;
TABLE[31][304] = 1;
TABLE[31][310] = 1;
TABLE[31][296] = 1;
TABLE[31][300] = 1;
TABLE[31][260] = 1;
TABLE[31][315] = 1;
TABLE[31][317] = 1;
TABLE[31][318] = 1;
TABLE[31][297] = 1;
TABLE[122][297] = 1;
TABLE[136][309] = 1;
TABLE[136][293] = 1;
TABLE[136][304] = 1;
TABLE[136][310] = 1;
TABLE[136][296] = 1;
TABLE[136][300] = 1;
TABLE[136][260] = 1;
TABLE[136][315] = 1;
TABLE[136][317] = 1;
TABLE[136][318] = 1;
TABLE[32][273] = 1;
TABLE[32][271] = 1;
TABLE[32][260] = 1;
TABLE[33][273] = 1;
TABLE[33][271] = 1;
TABLE[33][260] = 1;
TABLE[34][260] = 1;
TABLE[34][271] = 1;
TABLE[34][273] = 1;
TABLE[35][273] = 1;
TABLE[35][271] = 1;
TABLE[35][260] = 1;
TABLE[36][319] = 1;
TABLE[37][283] = 1;
TABLE[125][284] = 1;
TABLE[125][309] = 1;
TABLE[125][293] = 1;
TABLE[125][304] = 1;
TABLE[125][310] = 1;
TABLE[125][296] = 1;
TABLE[125][300] = 1;
TABLE[125][260] = 1;
TABLE[125][315] = 1;
TABLE[125][317] = 1;
TABLE[125][318] = 1;
TABLE[125][297] = 1;
TABLE[125][313] = 1;
TABLE[125][298] = 1;
TABLE[125][294] = 1;
TABLE[125][306] = 1;
TABLE[125][312] = 1;
TABLE[125][305] = 1;
TABLE[125][320] = 1;
TABLE[125][322] = 1;
TABLE[125][307] = 1;
TABLE[125][316] = 1;
TABLE[125][273] = 1;
TABLE[125][271] = 1;
TABLE[137][284] = 1;
TABLE[123][271] = 1;
TABLE[123][273] = 1;
TABLE[123][316] = 1;
TABLE[123][307] = 1;
TABLE[123][322] = 1;
TABLE[123][320] = 1;
TABLE[123][305] = 1;
TABLE[123][312] = 1;
TABLE[123][306] = 1;
TABLE[123][294] = 1;
TABLE[123][298] = 1;
TABLE[123][313] = 1;
TABLE[123][284] = 1;
TABLE[123][318] = 1;
TABLE[123][317] = 1;
TABLE[123][315] = 1;
TABLE[123][260] = 1;
TABLE[123][300] = 1;
TABLE[123][296] = 1;
TABLE[123][310] = 1;
TABLE[123][304] = 1;
TABLE[123][293] = 1;
TABLE[123][309] = 1;
TABLE[123][297] = 1;
TABLE[124][260] = 1;
TABLE[124][271] = 1;
TABLE[124][273] = 1;
TABLE[124][316] = 1;
TABLE[124][307] = 1;
TABLE[124][322] = 1;
TABLE[124][320] = 1;
TABLE[124][305] = 1;
TABLE[124][312] = 1;
TABLE[124][306] = 1;
TABLE[124][294] = 1;
TABLE[124][298] = 1;
TABLE[124][313] = 1;
TABLE[38][274] = 1;
TABLE[39][272] = 1;
TABLE[40][276] = 1;
TABLE[41][275] = 1;
TABLE[42][277] = 1;
TABLE[43][279] = 1;
TABLE[44][281] = 1;
TABLE[45][282] = 1;
TABLE[46][280] = 1;
TABLE[47][278] = 1;
TABLE[48][274] = 1;
TABLE[49][272] = 1;
TABLE[50][276] = 1;
TABLE[51][275] = 1;
TABLE[52][277] = 1;
TABLE[53][279] = 1;
TABLE[54][281] = 1;
TABLE[55][282] = 1;
TABLE[56][280] = 1;
TABLE[57][278] = 1;
TABLE[58][269] = 1;
TABLE[59][263] = 1;
TABLE[60][267] = 1;
TABLE[61][265] = 1;
TABLE[62][266] = 1;
TABLE[63][268] = 1;
TABLE[64][274] = 1;
TABLE[64][272] = 1;
TABLE[64][276] = 1;
TABLE[64][275] = 1;
TABLE[64][277] = 1;
TABLE[64][279] = 1;
TABLE[64][281] = 1;
TABLE[64][282] = 1;
TABLE[64][280] = 1;
TABLE[64][278] = 1;
TABLE[65][269] = 1;
TABLE[65][263] = 1;
TABLE[65][267] = 1;
TABLE[65][265] = 1;
TABLE[65][266] = 1;
TABLE[65][268] = 1;
TABLE[66][287] = 1;
TABLE[66][260] = 1;
TABLE[66][273] = 1;
TABLE[66][271] = 1;
TABLE[66][257] = 1;
TABLE[66][293] = 1;
TABLE[66][256] = 1;
TABLE[66][262] = 1;
TABLE[66][261] = 1;
TABLE[66][272] = 1;
TABLE[66][264] = 1;
TABLE[67][287] = 1;
TABLE[67][260] = 1;
TABLE[67][273] = 1;
TABLE[67][271] = 1;
TABLE[67][257] = 1;
TABLE[67][293] = 1;
TABLE[67][256] = 1;
TABLE[67][262] = 1;
TABLE[67][261] = 1;
TABLE[67][272] = 1;
TABLE[67][264] = 1;
TABLE[68][260] = 1;
TABLE[126][264] = 1;
TABLE[126][272] = 1;
TABLE[126][261] = 1;
TABLE[126][262] = 1;
TABLE[126][256] = 1;
TABLE[126][293] = 1;
TABLE[126][257] = 1;
TABLE[126][271] = 1;
TABLE[126][273] = 1;
TABLE[126][260] = 1;
TABLE[126][287] = 1;
TABLE[138][288] = 1;
TABLE[69][285] = 1;
TABLE[70][285] = 1;
TABLE[71][260] = 1;
TABLE[72][260] = 1;
TABLE[73][271] = 1;
TABLE[74][273] = 1;
TABLE[75][260] = 1;
TABLE[75][271] = 1;
TABLE[75][273] = 1;
TABLE[76][260] = 1;
TABLE[76][271] = 1;
TABLE[76][273] = 1;
TABLE[77][261] = 1;
TABLE[78][262] = 1;
TABLE[79][256] = 1;
TABLE[80][293] = 1;
TABLE[81][257] = 1;
TABLE[82][260] = 1;
TABLE[82][271] = 1;
TABLE[82][273] = 1;
TABLE[83][287] = 1;
TABLE[83][260] = 1;
TABLE[83][273] = 1;
TABLE[83][271] = 1;
TABLE[83][257] = 1;
TABLE[83][293] = 1;
TABLE[83][256] = 1;
TABLE[83][262] = 1;
TABLE[83][261] = 1;
TABLE[83][272] = 1;
TABLE[83][264] = 1;
TABLE[84][273] = 1;
TABLE[84][271] = 1;
TABLE[84][260] = 1;
TABLE[85][305] = 1;
TABLE[86][320] = 1;
TABLE[87][322] = 1;
TABLE[127][290] = 1;
TABLE[127][318] = 1;
TABLE[127][317] = 1;
TABLE[127][315] = 1;
TABLE[127][260] = 1;
TABLE[127][300] = 1;
TABLE[127][296] = 1;
TABLE[127][310] = 1;
TABLE[127][304] = 1;
TABLE[127][293] = 1;
TABLE[127][309] = 1;
TABLE[127][297] = 1;
TABLE[139][290] = 1;
TABLE[128][260] = 1;
TABLE[128][271] = 1;
TABLE[128][273] = 1;
TABLE[128][264] = 1;
TABLE[128][272] = 1;
TABLE[128][261] = 1;
TABLE[128][262] = 1;
TABLE[128][256] = 1;
TABLE[128][293] = 1;
TABLE[128][257] = 1;
TABLE[128][287] = 1;
TABLE[140][288] = 1;
TABLE[88][261] = 1;
TABLE[88][262] = 1;
TABLE[88][287] = 1;
TABLE[89][287] = 1;
TABLE[89][262] = 1;
TABLE[89][261] = 1;
TABLE[90][287] = 1;
TABLE[90][262] = 1;
TABLE[90][261] = 1;
TABLE[91][261] = 1;
TABLE[91][262] = 1;
TABLE[91][287] = 1;
TABLE[92][261] = 1;
TABLE[93][262] = 1;
TABLE[94][287] = 1;
TABLE[95][261] = 1;
TABLE[95][262] = 1;
TABLE[95][287] = 1;
TABLE[96][287] = 1;
TABLE[96][260] = 1;
TABLE[96][273] = 1;
TABLE[96][271] = 1;
TABLE[96][257] = 1;
TABLE[96][293] = 1;
TABLE[96][256] = 1;
TABLE[96][262] = 1;
TABLE[96][261] = 1;
TABLE[96][272] = 1;
TABLE[96][264] = 1;
TABLE[97][287] = 1;
TABLE[98][260] = 1;
TABLE[99][260] = 1;
TABLE[99][271] = 1;
TABLE[99][273] = 1;
TABLE[100][261] = 1;
TABLE[100][262] = 1;
TABLE[100][256] = 1;
TABLE[100][293] = 1;
TABLE[100][257] = 1;
TABLE[101][272] = 1;
TABLE[102][264] = 1;
TABLE[103][307] = 1;
TABLE[104][316] = 1;
TABLE[129][301] = 1;
TABLE[141][318] = 1;
TABLE[141][317] = 1;
TABLE[141][315] = 1;
TABLE[141][260] = 1;
TABLE[141][300] = 1;
TABLE[141][296] = 1;
TABLE[141][310] = 1;
TABLE[141][304] = 1;
TABLE[141][293] = 1;
TABLE[141][309] = 1;
TABLE[141][271] = 1;
TABLE[141][273] = 1;
TABLE[141][316] = 1;
TABLE[141][307] = 1;
TABLE[141][322] = 1;
TABLE[141][320] = 1;
TABLE[141][305] = 1;
TABLE[141][312] = 1;
TABLE[141][306] = 1;
TABLE[141][294] = 1;
TABLE[141][298] = 1;
TABLE[141][313] = 1;
TABLE[141][297] = 1;
TABLE[141][284] = 1;
TABLE[130][295] = 1;
TABLE[142][299] = 1;
TABLE[105][306] = 1;
TABLE[106][260] = 1;
TABLE[107][273] = 1;
TABLE[107][271] = 1;
TABLE[107][260] = 1;
TABLE[108][307] = 1;
TABLE[108][316] = 1;
TABLE[109][305] = 1;
TABLE[109][320] = 1;
TABLE[109][322] = 1;
TABLE[110][260] = 1;
TABLE[111][312] = 1;
TABLE[112][306] = 1;
TABLE[113][260] = 1;
TABLE[114][294] = 1;
TABLE[115][298] = 1;
TABLE[116][313] = 1;
TABLE[131][287] = 1;
TABLE[131][260] = 1;
TABLE[131][273] = 1;
TABLE[131][271] = 1;
TABLE[131][257] = 1;
TABLE[131][293] = 1;
TABLE[131][256] = 1;
TABLE[131][262] = 1;
TABLE[131][261] = 1;
TABLE[131][272] = 1;
TABLE[131][264] = 1;
TABLE[143][290] = 1;
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
      case 9: return 1; break;
      case 18: return 1; break;
      case 30: return 0; break;
      case 42: return 0; break;
      case 52: return 1; break;
      case 69: return 0; break;
      case 75: return 0; break;
      case 93: return 1; break;
      case 100: return 1; break;
      case 107: return 0; break;
      case 114: return 0; break;
      case 132: return 1; break;
      case 139: return 1; break;
      case 146: return 0; break;
      case 186: return 1; break;
      case 193: return 1; break;
      case 200: return 0; break;
      case 210: return 0; break;
      case 218: return 0; break;
      case 227: return 0; break;
      case 233: return 1; break;
      case 241: return 1; break;
      case 249: return 0; break;
      case 257: return 0; break;
      case 289: return 0; break;
      case 329: return 0; break;
      case 353: return 0; break;
      case 361: return 0; break;
      case 371: return 0; break;
      case 378: return 1; break;
      case 385: return 0; break;
      case 398: return 0; break;
      case 427: return 0; break;
      case 447: return 0; break;
      case 453: return 0; break;
      case 461: return 0; break;
      case 493: return 1; break;
      case 500: return 1; break;
      case 507: return 0; break;
      case 517: return 0; break;
      case 527: return 0; break;
      case 541: return 0; break;
      case 579: return 0; break;
      case 603: return 1; break;
      case 611: return 1; break;
      case 622: return 0; break;
      case 627: return 0; break;
      case 632: return 0; break;
      case 683: return 1; break;
   }
}
char * yyprintname(n)
   int n;
{
   if (n <= 50000)
      switch(n) {
         case 1: return "YYSTART"; break;
         case 6: return "null_point"; break;
         case 9: return "program"; break;
         case 18: return "program_parts"; break;
         case 30: return "func_proc"; break;
         case 42: return "arguments"; break;
         case 52: return "array_dcl"; break;
         case 69: return "argument"; break;
         case 75: return "func_dcl"; break;
         case 93: return "Subphrase"; break;
         case 100: return "Subphrase"; break;
         case 107: return "extern_dcl"; break;
         case 114: return "proc_dcl"; break;
         case 132: return "Subphrase"; break;
         case 139: return "Subphrase"; break;
         case 146: return "type"; break;
         case 186: return "var_dcl"; break;
         case 193: return "Subphrase"; break;
         case 200: return "var_dcl_cnts"; break;
         case 210: return "var_dcl_cnt"; break;
         case 218: return "struct_dec"; break;
         case 227: return "block"; break;
         case 233: return "Subphrase"; break;
         case 241: return "Subphrase"; break;
         case 249: return "arithmatic_low_level"; break;
         case 257: return "arithmatic_high_level"; break;
         case 289: return "arithmatic"; break;
         case 329: return "conditional"; break;
         case 353: return "binary_op"; break;
         case 361: return "parameters"; break;
         case 371: return "method_call_expr"; break;
         case 378: return "Subphrase"; break;
         case 385: return "array_complete_dcl"; break;
         case 398: return "variable"; break;
         case 427: return "const_val"; break;
         case 447: return "assignment_expr"; break;
         case 453: return "expr_assign"; break;
         case 461: return "loop_stmt"; break;
         case 493: return "Subphrase"; break;
         case 500: return "Subphrase"; break;
         case 507: return "term"; break;
         case 517: return "factor"; break;
         case 527: return "primary"; break;
         case 541: return "expr"; break;
         case 579: return "cond_statement"; break;
         case 603: return "Subphrase"; break;
         case 611: return "Subphrase"; break;
         case 622: return "gotofunc"; break;
         case 627: return "labeltoken"; break;
         case 632: return "statement_expr"; break;
         case 683: return "Subphrase"; break;
   }
   else 
      switch(n-50000) {
         case 325: return "UNTIL"; break;
         case 324: return "IN"; break;
         case 323: return "OF"; break;
         case 322: return "FOREACH"; break;
         case 321: return "PROCEDURE"; break;
         case 320: return "REPEAT"; break;
         case 319: return "RECORD"; break;
         case 318: return "AUTO"; break;
         case 317: return "VOID"; break;
         case 316: return "SWITCH"; break;
         case 315: return "STRINGKEYWORD"; break;
         case 314: return "STATIC"; break;
         case 313: return "SIZEOF"; break;
         case 312: return "RETURN"; break;
         case 311: return "OUTPUT"; break;
         case 310: return "LONG"; break;
         case 309: return "INT"; break;
         case 308: return "INPUT"; break;
         case 307: return "IF"; break;
         case 306: return "GOTO"; break;
         case 305: return "FOR"; break;
         case 304: return "FLOAT"; break;
         case 303: return "FUNCTION"; break;
         case 302: return "EXTERN"; break;
         case 301: return "ELSE"; break;
         case 300: return "DOUBLE"; break;
         case 299: return "DEFAULT"; break;
         case 298: return "CONTINUE"; break;
         case 297: return "CONST"; break;
         case 296: return "CHARKEYWORD"; break;
         case 295: return "CASE"; break;
         case 294: return "BREAK"; break;
         case 293: return "BOOLEAN"; break;
         case 292: return "EOF"; break;
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
