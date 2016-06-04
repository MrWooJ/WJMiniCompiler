#ifndef SymbolTableHandler   /* Include guard */
#define SymbolTableHandler

#include "StackHandler.h"
#include "HashTableHandler.h"

Stack stackTable;

void PrepareST();

void EnterScope();

void ExitScope();

void AddId(char * id, char * info);

char * Lookup(char * sym);

char * Probe(char * sym);

void ErrorPrump_IdNotFound(int line, char * id);

void ErrorPrump_IdDuplicated(int line, char * id);

#endif