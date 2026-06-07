#include "deque.h"
#include <stdlib.h>

int push_front(Deque *deque, int data)
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
    new_node->prev = NULL;
    new_node->next = deque->front;

    if (is_empty_deque(deque))
    {
        deque->rear = new_node;
    }
    else
    {
        deque->front->prev = new_node;
    }
    deque->front = new_node;
    deque->size++;

    return 0;
}