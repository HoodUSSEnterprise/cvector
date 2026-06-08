#include "stack/push_stack.h"

int push_int(StackInt *stack, int data)
{
    if (!stack)
    {
        return -1;
    }

    StackIntNode *new_node = (StackIntNode *)malloc(sizeof(StackIntNode));
    if (!new_node)
    {
        return -1;
    }

    new_node->data = data;
    new_node->next = stack->top;
    stack->top = new_node;
    stack->size++;

    return 0;
}

float push_float(StackFloat *stack, float data)
{
    if (!stack)
    {
        return -1;
    }

    StackFloatNode *new_node = (StackFloatNode *)malloc(sizeof(StackFloatNode));
    if (!new_node)
    {
        return -1;
    }

    new_node->data = data;
    new_node->next = stack->top;
    stack->top = new_node;
    stack->size++;

    return 0;
}

double push_double(StackDouble *stack, double data)
{
    if (!stack)
    {
        return -1;
    }

    StackDoubleNode *new_node = (StackDoubleNode *)malloc(sizeof(StackDoubleNode));
    if (!new_node)
    {
        return -1;
    }

    new_node->data = data;
    new_node->next = stack->top;
    stack->top = new_node;
    stack->size++;

    return 0;
}