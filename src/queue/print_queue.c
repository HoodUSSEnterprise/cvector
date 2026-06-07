#include "queue/queue.h"

void print_queue(Queue *q)
{
    if (!q || is_empty_queue(q))
    {
        printf("队列为空\n");
        return;
    }

    Queue *temp = create_queue();
    int val;

    printf("队列内容: ");
    while (dequeue(q, &val) == 0)
    {
        printf("%d ", val);
        enqueue(temp, val);
    }

    while (dequeue(temp, &val) == 0)
    {
        enqueue(q, val);
    }

    free_queue(temp);
    printf("\n");
}