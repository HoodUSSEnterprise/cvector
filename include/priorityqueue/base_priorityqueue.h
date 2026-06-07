#ifndef BASE_PRIORITYQUEUE_H
#define BASE_PRIORITYQUEUE_H

#include <stdio.h>
#include <stdlib.h>

#define INITIAL_CAPACITY 16

typedef struct
{
    int *data;
    int size;
    int capacity;
} PriorityQueue;

#endif
