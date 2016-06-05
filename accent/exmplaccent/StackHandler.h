#ifndef StackHandler   /* Include guard */
#define StackHandler

#include "HashTableHandler.h"

#define STACK_MAX 1000

struct Stack {
	hashtable_t* data[STACK_MAX];
	int size;
};

typedef struct Stack stack;

hashtable_t* Stack_Top(stack *S);

void Stack_Push(stack *S, hashtable_t* d);

void Stack_Pop(stack *S);

hashtable_t* Stack_Element(stack *S, int i);

#endif