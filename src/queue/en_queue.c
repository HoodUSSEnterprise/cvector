#include "queue.h"
#include <stdlib.h>

int enqueue(Queue *queue, int data)
{
    if (!queue)
    {
        return -1;
    }

    QueueNode *new_node = (QueueNode *)malloc(sizeof(QueueNode));
    if (!new_node)
    {
        return -1;
    }

    new_node->data = data;
    new_node->next = NULL;

    if (is_empty_queue(queue))
    {
        queue->front = new_node;
        queue->rear = new_node;
    }
    else
    {
        queue->rear->next = new_node;
        queue->rear = new_node;
    }
    queue->size++;

    return 0;
}