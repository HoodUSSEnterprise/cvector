#include "deque.h"

int is_empty_deque(Deque *deque)
{
    return (!deque || deque->size == 0) ? 1 : 0;
}