#include "queue/queue.h"

int front(Queue *queue, int *data)
{
    if (!queue || is_empty_queue(queue) || !data)
    {
        return -1;
    }

    *data = queue->front->data;
    return 0;
}