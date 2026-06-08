#ifndef PUSH_STACK_H
#define PUSH_STACK_H

#include "stack/base_stack.h"

int push_int(StackInt *stack, int data);

float push_float(StackFloat *stack, float data);

double push_double(StackDouble *stack, double data);

#endif // PUSH_STACK_H