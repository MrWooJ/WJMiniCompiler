#ifndef outputHandler   /* Include guard */
#define outputHandler

typedef struct {
  char* *array;
  size_t used;
  size_t size;
} Array;

HandleCodeGenerator(char* command, char* op1, char* op2, char* op3);

char* GetSizeOf(char* input);

char* ProduceTempVar();
char* UseOfTempVar();

void initArray(Array *a, size_t initialSize);
void insertArray(Array *a, char* element);
void freeArray(Array *a);

char* ProduceParameters(Array *a);

#endif