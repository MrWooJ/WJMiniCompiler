#include "StackHandler.h"

void Stack_Init(stack *S)
{
	S->size = 0;
}

hashtable_t* Stack_Top(stack *S)
{
	if (S->size == 0) {
		fprintf(stderr, "Error: stack empty\n");
		return;
	} 

	return S->data[S->size-1];
}

void Stack_Push(stack *S, hashtable_t* d)
{
	if (S->size < STACK_MAX)
		S->data[S->size++] = d;
	else
		fprintf(stderr, "Error: stack full\n");
}

void Stack_Pop(stack *S)
{
	if (S->size == 0)
		fprintf(stderr, "Error: stack empty\n");
	else
		S->size--;
}

hashtable_t* Stack_Element(stack *S, int i)
{
	if (S->size == 0) {
		fprintf(stderr, "Error: stack empty\n");
		return;
	} 

	return S->data[i];
}