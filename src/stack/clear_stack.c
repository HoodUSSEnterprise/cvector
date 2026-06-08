#include "stack/clear_stack.h"

void clear_stack_int(StackInt *stack)
{
    if (!stack)
    {
        return;
    }

    while (!is_empty_stack(stack))
    {
        StackIntNode *temp = stack->top;
        stack->top = temp->next;
        free(temp);
    }
    stack->size = 0;
}

void clear_stack_float(StackFloat *stack)
{
    if (!stack)
    {
        return;
    }

    while (!is_empty_stack(stack))
    {
        StackFloatNode *temp = stack->top;
        stack->top = temp->next;
        free(temp);
    }
    stack->size = 0;
}

void clear_stack_double(StackDouble *stack)
{
    if (!stack)
    {
        return;
    }

    while (!is_empty_stack(stack))
    {
        StackDoubleNode *temp = stack->top;
        stack->top = temp->next;
        stack->size--;
        free(temp);
    }
    stack->size = 0;
}