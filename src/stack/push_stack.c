#include "stack/stack.h"
#include <stdlib.h>

int push(Stack *stack, int data)
{
    if (!stack)
    {
        return -1;
    }

    StackNode *new_node = (StackNode *)malloc(sizeof(StackNode));
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