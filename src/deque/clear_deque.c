#include "deque/deque.h"
#include <stdlib.h>

void clear_deque(Deque *deque)
{
    if (!deque)
    {
        return;
    }

    while (!is_empty_deque(deque))
    {
        DequeNode *temp = deque->front;
        deque->front = temp->next;
        free(temp);
    }
    deque->rear = NULL;
    deque->size = 0;
}