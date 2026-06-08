#ifndef PRINT_STACK_H
#define PRINT_STACK_H

#include "stack/base_stack.h"
#include "stack/create_stack.h"
#include "stack/free_stack.h"
#include "stack/operator_stack.h"
#include "stack/pop_stack.h"
#include "stack/push_stack.h"

void print_stack_int(StackInt *s);

void print_stack_float(StackFloat *s);

void print_stack_double(StackDouble *s);

#define print_stack(stack) _Generic((stack), \
    StackInt *: print_stack_int,             \
    StackFloat *: print_stack_float,         \
    StackDouble *: print_stack_double)(stack)

#endif // PRINT_STACK_H