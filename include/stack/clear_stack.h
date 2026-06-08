#ifndef CLEAR_STACK_H
#define CLEAR_STACK_H

#include "stack/base_stack.h"
#include "stack/operator_stack.h"

void clear_stack_int(StackInt *stack);

void clear_stack_float(StackFloat *stack);

void clear_stack_double(StackDouble *stack);

#define clear_stack(stack) _Generic((stack), \
    StackInt *: clear_stack_int,             \
    StackFloat *: clear_stack_float,         \
    StackDouble *: clear_stack_double)(stack)

#endif // CLEAR_STACK_H