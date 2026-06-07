#include "queue.h"
#include <stdlib.h>

void clear_queue(Queue *queue)
{
    if (!queue)
    {
        return;
    }

    while (!is_empty_queue(queue))
    {
        QueueNode *temp = queue->front;
        queue->front = temp->next;
        free(temp);
    }
    queue->rear = NULL;
    queue->size = 0;
}