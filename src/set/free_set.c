#include "set/free_set.h"

void free_set(Set *set)
{
    if (set == NULL) return;
    free_rbtree(set->tree);
    free(set);
}
