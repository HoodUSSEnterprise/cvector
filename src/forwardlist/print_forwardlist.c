#include "forwardlist/print_forwardlist.h"

void print_forwardlist(ForwardList *list)
{
    printf("[");
    for (ForwardListNode *cur = list->head; cur; cur = cur->next)
    {
        if (cur != list->head)
        {
            printf(" -> ");
        }
        printf("%d", cur->data);
    }
    printf("]\n");
}
