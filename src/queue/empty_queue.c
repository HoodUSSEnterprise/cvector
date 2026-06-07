#include "queue.h"

int is_empty_queue(Queue *queue)
{
    return (!queue || queue->size == 0) ? 1 : 0;
}