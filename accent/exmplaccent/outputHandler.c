#include <stdio.h>
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

char* Concat2Strings(char* str1, char* str2)
{
	char* str3 = (char *) malloc( 1 + strlen(str1)+ strlen(str2) );
	strcpy(str3, str1);
	strcat(str3, str2);
	return str3;
}

char* Concat3Strings(char* str1, char* str2, char* str3)
{
	char* str4 = (char *) malloc( 1 + strlen(str1)+ strlen(str2) );
	strcpy(str4, str1);
	strcat(str4, str2);

	char* str5 = (char *) malloc( 1 + strlen(str4)+ strlen(",") );
	strcpy(str5, str4);
	strcat(str5, ",");

	char* str6 = (char *) malloc( 1 + strlen(str5)+ strlen(str3) );
	strcpy(str6, str5);
	strcat(str6, str3);

	return str6;
}

char* Concat4Strings(char* str1, char* str2, char* str3, char* str4)
{
	char* str5 = (char *) malloc( 1 + strlen(str1)+ strlen(str2) );
	strcpy(str5, str1);
	strcat(str5, str2);

	char* str6 = (char *) malloc( 1 + strlen(str5)+ strlen(",") );
	strcpy(str6, str5);
	strcat(str6, ",");

	char* str7 = (char *) malloc( 1 + strlen(str6)+ strlen(str3) );
	strcpy(str7, str6);
	strcat(str7, str3);

	char* str8 = (char *) malloc( 1 + strlen(str7)+ strlen(",") );
	strcpy(str8, str7);
	strcat(str8, ",");

	char* str9 = (char *) malloc( 1 + strlen(str8)+ strlen(str4) );
	strcpy(str9, str8);
	strcat(str9, str4);

	return str9;
}

HandleCodeGenerator(char* command, char* op1, char* op2, char* op3)
{
	char* res;

	if (strcmp(command, "=") == 0)
	{
		res = Concat4Strings("= ",op1,op2);
	}
	else if (strcmp(command, "+") == 0)
	{
		res = Concat4Strings("+ ",op1,op2,op3);
	}
	else if (strcmp(command, "-") == 0)
	{
		res = Concat4Strings("- ",op1,op2,op3);
	}
	else if (strcmp(command, "*") == 0)
	{
		res = Concat4Strings("* ",op1,op2,op3);
	}
	else if (strcmp(command, "/") == 0)
	{
		res = Concat4Strings("/ ",op1,op2,op3);
	}
	else if (strcmp(command, "%") == 0)
	{
		res = Concat4Strings("% ",op1,op2,op3);
	}
	else if (strcmp(command, "&") == 0)
	{
		res = Concat4Strings("& ",op1,op2,op3);
	}
	else if (strcmp(command, "|") == 0)
	{
		res = Concat4Strings("| ",op1,op2,op3);
	}
	else if (strcmp(command, "^") == 0)
	{
		res = Concat4Strings("^ ",op1,op2,op3);
	}
	else if (strcmp(command, ">") == 0)
	{
		res = Concat4Strings("> ",op1,op2,op3);
	}
	else if (strcmp(command, "<") == 0)
	{
		res = Concat4Strings("< ",op1,op2,op3);
	}
	else if (strcmp(command, "!=") == 0)
	{
		res = Concat4Strings("!= ",op1,op2,op3);
	}
	else if (strcmp(command, "==") == 0)
	{
		res = Concat4Strings("== ",op1,op2,op3);
	}
	else if (strcmp(command, ">=") == 0)
	{
		res = Concat4Strings(">= ",op1,op2,op3);
	}
	else if (strcmp(command, "<=") == 0)
	{
		res = Concat4Strings("<= ",op1,op2,op3);
	}
	else if (strcmp(command, "JMP") == 0)
	{
		res = Concat2Strings("JMP ",op1)
	}
	else if (strcmp(command, "JZ") == 0)
	{
		res = Concat3Strings("JZ ",op1,op2);
	}
	else if (strcmp(command, "JNZ") == 0)
	{
		res = Concat3Strings("JNZ ",op1,op2);
	}
	else if (strcmp(command, "LB") == 0)
	{
		res = Concat2Strings("LB ",op1);
	}
	else if (strcmp(command, "CONST") == 0)
	{
		// should be fixed
	}
	else if (strcmp(command, "VAR") == 0)
	{
		if (strcmp(op3,"") == 0)
		{
			res = Concat3Strings("VAR ",op1,op2);
		}
		else
		{
			res = Concat4Strings("VAR ",op1,op2,op3);
		}
	}
	else if (strcmp(command, "ARR") == 0)
	{
		res = Concat4Strings("ARR ",op1,op2,op3);
	}
	else if (strcmp(command, "FUN") == 0)
	{
		res = Concat3Strings("FUN ",op1,op2);
	}
	else if (strcmp(command, "END") == 0)
	{
		res = Concat2Strings("END ",op1);
	}
	else if (strcmp(command, "ARG") == 0)
	{
		if (strcmp(op3,"") == 0)
		{
			res = Concat3Strings("ARG ",op1,op2);
		}
		else
		{
			res = Concat4Strings("ARG ",op1,op2,op3);
		}
	}
	else if (strcmp(command, "RET") == 0)
	{
		if (strcmp(op1,"") == 0)
		{
			res = "RET";
		}
		else
		{
			res = Concat2Strings("RET ",op1);
		}		
	}
	else if (strcmp(command, "CALL") == 0)
	{
		if(strcmp(op2,"") == 0)
		{
			res = Concat2Strings("CALL ",op1);
		}
		else
		{
			res = Concat3Strings("CALL ",op1,op2);
		}
		
	}
	else
	{
		// Nothing to Handle
	}

	writeOutput(res);
}

WriteOutput(char* input) {

	printf("INPUT: %s\n", input);

	FILE *fp;

	fp = fopen("/home/output.txt", "a+");

	int status = fputs(input, fp);
	fputs("\n", fp);

	if (status < 0)
		printf("Error in Output File!");

	fclose(fp);
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