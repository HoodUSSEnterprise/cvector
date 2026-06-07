#include "forwardlist/free_forwardlist.h"

void clear_forwardlist(ForwardList *list)
{
    ForwardListNode *cur = list->head;
    while (cur)
    {
        ForwardListNode *tmp = cur;
        cur = cur->next;
        free(tmp);
    }
    list->head = NULL;
    list->size = 0;
}

void free_forwardlist(ForwardList *list)
{
    if (!list) return;
    clear_forwardlist(list);
    free(list);
}
