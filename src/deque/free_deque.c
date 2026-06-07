#include "deque/deque.h"
#include <stdlib.h>

void free_deque(Deque *deque)
{
    if (!deque)
    {
        return;
    }
    clear_deque(deque);
    free(deque);
}