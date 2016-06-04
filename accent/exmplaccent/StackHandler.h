#ifndef StackHandler   /* Include guard */
#define StackHandler

#include "HashTableHandler.h"

#define STACK_MAX 1000

struct Stack {
	hashtable_t* data[STACK_MAX];
	int size;
};

typedef struct Stack Stack;

hashtable_t* Stack_Top(Stack *S);

void Stack_Push(Stack *S, hashtable_t* d);

void Stack_Pop(Stack *S);

hashtable_t* Stack_Element(Stack *S, int i);

#endif