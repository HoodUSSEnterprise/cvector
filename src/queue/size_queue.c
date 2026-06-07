#include "queue.h"

int get_queue_size(Queue *queue)
{
    return queue ? queue->size : 0;
}