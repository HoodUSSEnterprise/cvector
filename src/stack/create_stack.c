#include "stack/stack.h"
#include <stdlib.h>

Stack *create_stack(void)
{
    Stack *stack = (Stack *)malloc(sizeof(Stack));
    if (!stack)
    {
        return NULL;
    }

    stack->top = NULL;
    stack->size = 0;
    return stack;
}