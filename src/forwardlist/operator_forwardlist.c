#include "forwardlist/operator_forwardlist.h"

int front_forwardlist(ForwardList *list)
{
    if (!list->head)
    {
        return 0;
    }
    return list->head->data;
}

int size_forwardlist(ForwardList *list)
{
    return list->size;
}

int is_empty_forwardlist(ForwardList *list)
{
    return list->size == 0;
}
