#include "set/create_set.h"

Set *create_set(void)
{
    Set *set = (Set *)malloc(sizeof(Set));
    if (set == NULL) return NULL;
    set->tree = create_rbtree();
    if (set->tree == NULL)
    {
        free(set);
        return NULL;
    }
    return set;
}
