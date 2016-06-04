#include <stdbool.h>

typedef union {
	int intval;
	float floatval;
	long longval;
	char charval;
	char* stringval;
	bool boolval;
	char* result;
} ATTRIBUTE;

#define YYSTYPE ATTRIBUTE