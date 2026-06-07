#include "queue.h"
#include <stdlib.h>

void free_queue(Queue *queue)
{
    if (!queue)
    {
        return;
    }
    clear_queue(queue);
    free(queue);
}