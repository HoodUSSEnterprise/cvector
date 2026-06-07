#include "forwardlist/pop_front_forwardlist.h"

void pop_front_forwardlist(ForwardList *list)
{
    if (!list->head) return;

    ForwardListNode *tmp = list->head;
    list->head = list->head->next;
    free(tmp);
    list->size--;
}

void erase_after_forwardlist(ForwardList *list, int pos)
{
    if (pos < 0 || pos >= list->size - 1) return;

    ForwardListNode *cur = list->head;
    for (int i = 0; i < pos; i++)
        cur = cur->next;

    ForwardListNode *tmp = cur->next;
    cur->next = tmp->next;
    free(tmp);
    list->size--;
}
