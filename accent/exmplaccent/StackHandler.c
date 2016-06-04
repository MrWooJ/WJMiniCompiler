#include "StackHandler.h"

void Stack_Init(Stack *S)
{
	S->size = 0;
}

hashtable_t* Stack_Top(Stack *S)
{
	if (S->size == 0) {
		fprintf(stderr, "Error: stack empty\n");
		return;
	} 

	return S->data[S->size-1];
}

void Stack_Push(Stack *S, hashtable_t* d)
{
	if (S->size < STACK_MAX)
		S->data[S->size++] = d;
	else
		fprintf(stderr, "Error: stack full\n");
}

void Stack_Pop(Stack *S)
{
	if (S->size == 0)
		fprintf(stderr, "Error: stack empty\n");
	else
		S->size--;
}

hashtable_t* Stack_Element(Stack *S, int i)
{
	if (S->size == 0) {
		fprintf(stderr, "Error: stack empty\n");
		return;
	} 

	return S->data[i];
}