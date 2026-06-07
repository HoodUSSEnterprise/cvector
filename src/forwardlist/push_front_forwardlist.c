#include "forwardlist/push_front_forwardlist.h"

void push_front_forwardlist(ForwardList *list, int data)
{
    ForwardListNode *node = (ForwardListNode *)malloc(sizeof(ForwardListNode));
    if (!node) return;
    node->data = data;
    node->next = list->head;
    list->head = node;
    list->size++;
}

void insert_after_forwardlist(ForwardList *list, int pos, int data)
{
    if (pos < 0 || pos >= list->size) return;

    ForwardListNode *cur = list->head;
    for (int i = 0; i < pos; i++)
        cur = cur->next;

    ForwardListNode *node = (ForwardListNode *)malloc(sizeof(ForwardListNode));
    if (!node) return;
    node->data = data;
    node->next = cur->next;
    cur->next = node;
    list->size++;
}
