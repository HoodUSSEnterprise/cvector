#include "priorityqueue/pop_priorityqueue.h"

void pop_priorityqueue(PriorityQueue *pq)
{
    if (pq->size == 0) return;

    pq->data[0] = pq->data[--pq->size];

    /* sift down */
    int i = 0;
    while (1)
    {
        int largest = i;
        int left = 2 * i + 1;
        int right = 2 * i + 2;

        if (left < pq->size && pq->data[left] > pq->data[largest])
            largest = left;
        if (right < pq->size && pq->data[right] > pq->data[largest])
            largest = right;
        if (largest == i) break;

        int tmp = pq->data[i];
        pq->data[i] = pq->data[largest];
        pq->data[largest] = tmp;
        i = largest;
    }
}
