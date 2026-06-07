#ifndef BASE_FORWARDLIST_H
#define BASE_FORWARDLIST_H

#include <stdio.h>
#include <stdlib.h>

typedef struct ForwardListNode
{
    int data;
    struct ForwardListNode *next;
} ForwardListNode;

typedef struct
{
    ForwardListNode *head;
    int size;
} ForwardList;

#endif
