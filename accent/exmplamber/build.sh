#!/bin/sh

ACCENTHOME=..
ACCENT=$ACCENTHOME/accent/./accent
AMBER=$ACCENTHOME/amber/amber.c

set -e
set -x

echo "ACCENT PROCESS START"
$ACCENT spec.acc
echo "ACCENT PROCESS ENDS"

cc -o amber -w -O3 yygrammar.c $AMBER

./amber examples 500
