#include "priorityqueue/free_priorityqueue.h"

void clear_priorityqueue(PriorityQueue *pq)
{
    pq->size = 0;
}

void free_priorityqueue(PriorityQueue *pq)
{
    if (!pq) return;
    free(pq->data);
    free(pq);
}
