#include "stack/clear_stack.h"

void clear_stack(Stack *stack)
{
    if (!stack)
    {
        return;
    }

    while (!is_empty_stack(stack))
    {
        StackNode *temp = stack->top;
        stack->top = temp->next;
        stack->size--;
        free(temp);
    }
    stack->size = 0;
}