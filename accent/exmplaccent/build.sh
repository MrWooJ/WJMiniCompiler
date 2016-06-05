#!/bin/sh

clear
clear

ACCENT=../accent/./accent
ENTIRE=../entire/entire.c
LEX=lex
CC=cc

$ACCENT spec1.acc

$LEX spec.lex

$CC -o program -w yygrammar.c lex.yy.c auxil.c $ENTIRE OutputHandler.c SymbolTableHandler.c HashTableHandler.c StackHandler.c Utility.c

./program < input
