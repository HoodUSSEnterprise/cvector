#include "stack/operator_stack.h"

bool is_empty_stack_int(StackInt *stack)
{
    return (!stack || stack->size == 0) ? true : false;
}

bool is_empty_stack_float(StackFloat *stack)
{
    return (!stack || stack->size == 0) ? true : false;
}

bool is_empty_stack_double(StackDouble *stack)
{
    return (!stack || stack->size == 0) ? true : false;
}

int get_stack_size_int(StackInt *stack)
{
    return stack ? stack->size : 0;
}

float get_stack_size_float(StackFloat *stack)
{
    return stack ? stack->size : 0;
}

double get_stack_size_double(StackDouble *stack)
{
    return stack ? stack->size : 0;
}

int top_int(StackInt *stack, int *data)
{
    if (!stack || is_empty_stack(stack) || !data)
    {
        return -1;
    }

    *data = stack->top->data;
    return 0;
}

float top_float(StackFloat *stack, float *data)
{
    if (!stack || is_empty_stack(stack) || !data)
    {
        return -1;
    }

    *data = stack->top->data;
    return 0;
}

double top_double(StackDouble *stack, double *data)
{
    if (!stack || is_empty_stack(stack) || !data)
    {
        return -1;
    }

    *data = stack->top->data;
    return 0;
}