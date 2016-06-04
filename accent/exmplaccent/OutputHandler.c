#include <stdio.h>
#include "OutputHandler.h"

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

void HandleCodeGenerator(char* command, char* op1, char* op2, char* op3)
{
	char* res;

	if (strcmp(command, "=") == 0)
	{
		res = Concat3Strings("= ",op1,op2);
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
		res = Concat2Strings("JMP ",op1);
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

	WriteOutput(res);
}

void WriteOutput(char* input) {

	printf("INPUT: %s\n", input);

	FILE *fp;

	fp = fopen("/home/output.txt", "a+");

	int status = fputs(input, fp);
	fputs("\n", fp);

	if (status < 0)
		printf("Error in Output File!");

	fclose(fp);
}