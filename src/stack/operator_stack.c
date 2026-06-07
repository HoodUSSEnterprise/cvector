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