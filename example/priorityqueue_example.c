#include "priorityqueue/priorityqueue.h"

int main(void)
{
    PriorityQueue *pq = create_priorityqueue();

    printf("Pushing: 3, 1, 4, 1, 5, 9, 2, 6\n");
    push_priorityqueue(pq, 3);
    push_priorityqueue(pq, 1);
    push_priorityqueue(pq, 4);
    push_priorityqueue(pq, 1);
    push_priorityqueue(pq, 5);
    push_priorityqueue(pq, 9);
    push_priorityqueue(pq, 2);
    push_priorityqueue(pq, 6);

    printf("Heap array: ");
    print_priorityqueue(pq);
    printf("Size: %d\n\n", size_priorityqueue(pq));

    printf("Top: %d\n\n", top_priorityqueue(pq));

    printf("Pop all:\n");
    while (!is_empty_priorityqueue(pq))
    {
        printf("%d ", top_priorityqueue(pq));
        pop_priorityqueue(pq);
    }
    printf("\n\n");

    printf("Is empty? %s\n", is_empty_priorityqueue(pq) ? "yes" : "no");

    free_priorityqueue(pq);
    return 0;
}
