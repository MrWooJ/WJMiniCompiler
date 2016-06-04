#include <stdio.h>
#include "Utility.h"
#include "outputHandler.h"

int i = 0;
int j = 0;

char* ProduceTempVar()
{
	char* str3 = (char *) malloc( 1 + strlen("$t")+ strlen(itoa(i)) );
	strcpy(str3, "$t");
	strcat(str3, itoa(i));
	i=i+1;
	return str3;
}

char* UseOfTempVar()
{
	i--;
	char* str3 = (char *) malloc( 1 + strlen("$t")+ strlen(itoa(i)) );
	strcpy(str3, "$t");
	strcat(str3, itoa(i));
	return str3;
}

char* ProduceBlockLabel()
{
	char* str3 = (char *) malloc( 1 + strlen("BLK")+ strlen(itoa(j)) );
	strcpy(str3, "BLK");
	strcat(str3, itoa(j));
	j=j+1;
	return str3;
}

char* UseOfBlockLabel()
{
	j--;
	char* str3 = (char *) malloc( 1 + strlen("BLK")+ strlen(itoa(j)) );
	strcpy(str3, "BLK");
	strcat(str3, itoa(j));
	return str3;
}

char* GetSizeOf(char* input)
{
	char* status = "0";

	if (strcmp(input, "int") == 0)
	{
		status = "2";
	}
	else if (strcmp(input, "bool") == 0)
	{
		status = "2";
	}
	else if (strcmp(input, "float") == 0)
	{
		status = "4";
	}
	else if (strcmp(input, "long") == 0)
	{
		status = "4";
	}
	else if (strcmp(input, "char") == 0)
	{
		status = "1";
	}
	else if (strcmp(input, "double") == 0)
	{
		status = "8";
	}
	else if (strcmp(input, "string") == 0)
	{
		status = "12";
	}
	else if (strcmp(input, "void") == 0)
	{
		status = "0";
	}
	else if (strcmp(input, "auto") == 0)
	{
		status = "2";
	}
	else
	{
		status = "12";
	}
	return status;
}

void initArray(Array *a, size_t initialSize) {
  a->array = (char* *)malloc(initialSize * sizeof(char*));
  a->used = 0;
  a->size = initialSize;
}

void insertArray(Array *a, char* element) {
  if (a->used == a->size) {
    a->size *= 2;
    a->array = (char* *)realloc(a->array, a->size * sizeof(char*));
  }
  a->array[a->used++] = element;
}

void freeArray(Array *a) {
  free(a->array);
  a->array = NULL;
  a->used = a->size = 0;
}

char* ProduceParameters(Array *a)
{
	int i = 0;
	char* res = "";
	for (i = 0; i < a->size; i++)
		res = Concat2Strings(res,a->array[i]);
	return res;
}