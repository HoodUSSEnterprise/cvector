#include "queue/queue.h"
#include <stdlib.h>

int dequeue(Queue *queue, int *data)
{
    if (!queue || is_empty_queue(queue) || !data)
    {
        return -1;
    }

    QueueNode *temp = queue->front;
    *data = temp->data;
    queue->front = temp->next;

    if (!queue->front)
    {
        queue->rear = NULL;
    }

    free(temp);
    queue->size--;

    return 0;
}