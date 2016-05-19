#include <stdbool.h>

typedef union {
	int intval;
	float floatval;
	long longval;
	char charval;
	char* stringval;
	bool boolval;
} ATTRIBUTE;

#define YYSTYPE ATTRIBUTE