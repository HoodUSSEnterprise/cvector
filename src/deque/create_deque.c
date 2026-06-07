#include "deque/deque.h"
#include <stdlib.h>

Deque *create_deque(void)
{
    Deque *deque = (Deque *)malloc(sizeof(Deque));
    if (!deque)
    {
        return NULL;
    }

    deque->front = NULL;
    deque->rear = NULL;
    deque->size = 0;
    return deque;
}