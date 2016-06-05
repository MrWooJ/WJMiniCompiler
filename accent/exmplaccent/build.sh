#!/bin/sh

clear
clear

ACCENT=../accent/./accent
ENTIRE=../entire/entire.c
LEX=flex
CC=cc

$ACCENT spec.acc

$LEX spec.lex

$CC -w yygrammar.c lex.yy.c auxil.c OutputHandler.c SymbolTableHandler.c HashTableHandler.c StackHandler.c Utility.c $ENTIRE -o program

./program < input
