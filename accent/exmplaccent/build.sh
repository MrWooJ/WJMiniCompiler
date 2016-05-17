#!/bin/sh

ACCENT=../accent/./accent
ENTIRE=../entire/entire.c
LEX=flex
CC=cc

$ACCENT spec.acc

$LEX spec.lex

$CC -o calculator -w yygrammar.c lex.yy.c auxil.c $ENTIRE

./calculator < input
