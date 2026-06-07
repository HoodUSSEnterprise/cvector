#include "priorityqueue/operator_priorityqueue.h"

int top_priorityqueue(PriorityQueue *pq)
{
    if (pq->size == 0)
    {
        return 0;
    }
    return pq->data[0];
}

int size_priorityqueue(PriorityQueue *pq)
{
    return pq->size;
}

int is_empty_priorityqueue(PriorityQueue *pq)
{
    return pq->size == 0;
}
