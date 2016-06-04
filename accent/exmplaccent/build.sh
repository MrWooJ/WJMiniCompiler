#!/bin/sh

ACCENT=../accent/./accent
ENTIRE=../entire/entire.c
LEX=flex
CC=g++

$ACCENT spec.acc

$LEX spec.lex

$CC -o program -w yygrammar.c lex.yy.c auxil.c $ENTIRE

./program < input
