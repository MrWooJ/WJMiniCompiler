#include "SymbolTableHandler.h"
#include "Utility.h"

void PrepareST()
{
	Stack_Init(stackTable);
}

void EnterScope()
{
	hashtable_t *hashtable = ht_create( 65536 );
	Stack_Push(&stackTable, hashtable);
}

void ExitScope()
{
	Stack_Pop(&stackTable);
}

void AddId(char* id, char * info)
{
	hashtable_t *hashtable = Stack_Top(stackTable);
	ht_set(hashtable, id, info);
}

char * Lookup(char* sym)
{
	printf("Lookup");
	printf("%s\n", sym);
	char *info;
	int i;

	for (i = 0 ; i < stackTable->size; i++)
	{
		hashtable_t *hashtable = Stack_Element(stackTable, i);
		char *str = ht_get(hashtable, sym);

		if ((str != NULL) && (str[0] != '\0'))
		{
   			strcpy(info,str);
   			break;
		}
	}

	return info;
}

char * Probe(char* sym)
{
	hashtable_t *hashtable = Stack_Top(stackTable);
	char* res = ht_get(hashtable, sym);
	return res;
}

void ErrorPrump_IdNotFound(int line, char* id)
{
	printf("Error in line: %d \n => Identifier %s Not Found!", line, id);
}

void ErrorPrump_IdDuplicated(int line, char* id)
{
	printf("Error in line: %d \n => Identifier %s Duplicated!", line, id);
}