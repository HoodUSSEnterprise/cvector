#include "priorityqueue/create_priorityqueue.h"

PriorityQueue *create_priorityqueue(void)
{
    PriorityQueue *pq = (PriorityQueue *)malloc(sizeof(PriorityQueue));
    if (!pq)
    {
        return NULL;
    }
    pq->data = (int *)malloc(sizeof(int) * INITIAL_CAPACITY);
    if (!pq->data)
    {
        free(pq);
        return NULL;
    }
    pq->size = 0;
    pq->capacity = INITIAL_CAPACITY;
    return pq;
}
