#include "deque.h"
#include <stdlib.h>

int push_rear(Deque *deque, int data)
{
    if (!deque)
    {
        return -1;
    }

    DequeNode *new_node = (DequeNode *)malloc(sizeof(DequeNode));
    if (!new_node)
    {
        return -1;
    }

    new_node->data = data;
    new_node->next = NULL;
    new_node->prev = deque->rear;

    if (is_empty_deque(deque))
    {
        deque->front = new_node;
    }
    else
    {
        deque->rear->next = new_node;
    }
    deque->rear = new_node;
    deque->size++;

    return 0;
}