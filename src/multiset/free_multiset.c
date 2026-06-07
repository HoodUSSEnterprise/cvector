#include "multiset/free_multiset.h"
#include "rbtree/create_rbtree.h"

void clear_multiset(MultiSet *set)
{
    free_rbtree(set->tree);
    set->tree = create_rbtree();
}

void free_multiset(MultiSet *set)
{
    if (!set) return;
    free_rbtree(set->tree);
    free(set);
}
