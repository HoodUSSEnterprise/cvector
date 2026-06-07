#include "stack/free_stack.h"

void free_stack(Stack *stack)
{
    if (!stack)
    {
        return;
    }

    clear_stack(stack);
    free(stack);
}