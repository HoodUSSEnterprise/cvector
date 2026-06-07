#include "priorityqueue/push_priorityqueue.h"

void push_priorityqueue(PriorityQueue *pq, int data)
{
    if (pq->size == pq->capacity)
    {
        pq->capacity *= 2;
        pq->data = (int *)realloc(pq->data, sizeof(int) * pq->capacity);
        if (!pq->data) return;
    }

    int i = pq->size++;
    pq->data[i] = data;

    /* bubble up */
    while (i > 0)
    {
        int parent = (i - 1) / 2;
        if (pq->data[i] <= pq->data[parent]) break;
        int tmp = pq->data[i];
        pq->data[i] = pq->data[parent];
        pq->data[parent] = tmp;
        i = parent;
    }
}
