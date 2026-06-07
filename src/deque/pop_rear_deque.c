#include "deque.h"
#include <stdlib.h>

int pop_rear(Deque *deque, int *data)
{
    if (!deque || is_empty_deque(deque) || !data)
    {
        return -1;
    }

    DequeNode *temp = deque->rear;
    *data = temp->data;
    deque->rear = temp->prev;

    if (deque->rear)
    {
        deque->rear->next = NULL;
    }
    else
    {
        deque->front = NULL;
    }

    free(temp);
    deque->size--;

    return 0;
}