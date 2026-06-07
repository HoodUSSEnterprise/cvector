#include "deque.h"

int get_deque_size(Deque *deque)
{
    return deque ? deque->size : 0;
}