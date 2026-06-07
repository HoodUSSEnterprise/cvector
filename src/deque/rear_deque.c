#include "deque/deque.h"

int rear(Deque *deque, int *data)
{
    if (!deque || is_empty_deque(deque) || !data)
    {
        return -1;
    }

    *data = deque->rear->data;
    return 0;
}