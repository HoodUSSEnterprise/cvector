#include "stack/free_stack.h"
#include "stack/clear_stack.h"

void free_stack_int(StackInt *stack)
{
    if (!stack)
    {
        return;
    }

    clear_stack(stack);
    free(stack);
}

void free_stack_float(StackFloat *stack)
{
    if (!stack)
    {
        return;
    }

    clear_stack(stack);
    free(stack);
}

void free_stack_double(StackDouble *stack)
{
    if (!stack)
    {
        return;
    }

    clear_stack(stack);
    free(stack);
}