#ifndef StackHandler   /* Include guard */
#define StackHandler

#include "HashTableHandler.h"

#define STACK_MAX 1000

struct Stack {
	hashtable_s data[STACK_MAX];
	int size;
};

typedef struct Stack Stack;

hashtable_s Stack_Top(Stack *S);

void Stack_Push(Stack *S, hashtable_s d);

void Stack_Pop(Stack *S);

hashtable_s Stack_Element(Stack *S, int i);

#endif