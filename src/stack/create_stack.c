#include "stack/create_stack.h"

StackInt *create_stack_int(void)
{
    StackInt *stack = (StackInt *)malloc(sizeof(StackInt));
    if (!stack)
    {
        return NULL;
    }

    stack->top = NULL;
    stack->size = 0;
    return stack;
}

StackFloat *create_stack_float(void)
{
    StackFloat *stack = (StackFloat *)malloc(sizeof(StackFloat));
    if (!stack)
    {
        return NULL;
    }

    stack->top = NULL;
    stack->size = 0;
    return stack;
}

StackDouble *create_stack_double(void)
{
    StackDouble *stack = (StackDouble *)malloc(sizeof(StackDouble));
    if (!stack)
    {
        return NULL;
    }

    stack->top = NULL;
    stack->size = 0;
    return stack;
}