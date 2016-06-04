#ifndef Utility   /* Include guard */
#define Utility

typedef struct {
  char* *array;
  size_t used;
  size_t size;
} Array;

char* GetSizeOf(char* input);

char* ProduceTempVar();
char* UseOfTempVar();

char* ProduceBlockLabel();
char* UseOfBlockLabel();

void initArray(Array *a, size_t initialSize);
void insertArray(Array *a, char* element);
void freeArray(Array *a);

char* ProduceParameters(Array *a);

char* Int2String(int a);

#endif