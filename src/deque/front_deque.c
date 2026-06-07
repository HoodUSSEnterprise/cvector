#include "deque.h"

int front(Deque *deque, int *data)
{
    if (!deque || is_empty_deque(deque) || !data)
    {
        return -1;
    }

    *data = deque->front->data;
    return 0;
}