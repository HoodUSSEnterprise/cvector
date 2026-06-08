#include "stack/pop_stack.h"

int pop(StackInt *stack, int *data)
{
    if (!stack || is_empty_stack(stack) || !data)
    {
        return -1;
    }

    StackIntNode *temp = stack->top;
    *data = temp->data;
    stack->top = temp->next;
    free(temp);
    stack->size--;

    return 0;
}

float pop_float(StackFloat *stack, float *data)
{
    if (!stack || is_empty_stack(stack) || !data)
    {
        return -1;
    }

    StackFloatNode *temp = stack->top;
    *data = temp->data;
    stack->top = temp->next;
    free(temp);
    stack->size--;

    return 0;
}

double pop_double(StackDouble *stack, double *data)
{
    if (!stack || is_empty_stack(stack) || !data)
    {
        return -1;
    }

    StackDoubleNode *temp = stack->top;
    *data = temp->data;
    stack->top = temp->next;
    free(temp);
    stack->size--;

    return 0;
}