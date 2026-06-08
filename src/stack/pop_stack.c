#include "stack/pop_stack.h"
#include "stack/operator_stack.h"

int pop(Stack *stack, int *data)
{
    if (!stack || is_empty_stack(stack) || !data)
    {
        return -1;
    }

    StackNode *temp = stack->top;
    *data = temp->data;
    stack->top = temp->next;
    free(temp);
    stack->size--;

    return 0;
}