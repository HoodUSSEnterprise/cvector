#include "priorityqueue/print_priorityqueue.h"

void print_priorityqueue(PriorityQueue *pq)
{
    printf("[");
    for (int i = 0; i < pq->size; i++)
    {
        if (i > 0)
        {
            printf(", ");
        }
        printf("%d", pq->data[i]);
    }
    printf("]\n");
}
