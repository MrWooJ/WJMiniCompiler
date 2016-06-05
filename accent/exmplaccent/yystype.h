#include <stdbool.h>

typedef union {
	int num;
	float numf;
	char* str;
} ATTRIBUTE;

#define YYSTYPE ATTRIBUTE