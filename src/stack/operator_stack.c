#include "stack/stack.h"
#include <stdbool.h>

bool is_empty_stack(Stack *stack)
{
    return (!stack || stack->size == 0) ? true : false;
}

int get_stack_size(Stack *stack)
{
    return stack ? stack->size : 0;
}

int top(Stack *stack, int *data)
{
    if (!stack || is_empty_stack(stack) || !data)
    {
        return -1;
    }

    *data = stack->top->data;
    return 0;
}