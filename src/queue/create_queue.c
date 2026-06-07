#include "queue.h"
#include <stdlib.h>

Queue *create_queue(void)
{
    Queue *queue = (Queue *)malloc(sizeof(Queue));
    if (!queue)
    {
        return NULL;
    }

    queue->front = NULL;
    queue->rear = NULL;
    queue->size = 0;
    return queue;
}