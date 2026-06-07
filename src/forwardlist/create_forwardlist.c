#include "forwardlist/create_forwardlist.h"

ForwardList *create_forwardlist(void)
{
    ForwardList *list = (ForwardList *)malloc(sizeof(ForwardList));
    if (!list) return NULL;
    list->head = NULL;
    list->size = 0;
    return list;
}
