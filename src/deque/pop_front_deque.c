#include "deque.h"
#include <stdlib.h>

int pop_front(Deque *deque, int *data)
{
    if (!deque || is_empty_deque(deque) || !data)
    {
        return -1;
    }

    DequeNode *temp = deque->front;
    *data = temp->data;
    deque->front = temp->next;

    if (deque->front)
    {
        deque->front->prev = NULL;
    }
    else
    {
        deque->rear = NULL;
    }

    free(temp);
    deque->size--;

    return 0;
}