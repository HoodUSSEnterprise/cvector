#include "multiset/delete_multiset.h"

void multiset_delete(MultiSet *set, int key)
{
    if (!rbtree_contains(set->tree, key)) return;
    rbtree_delete(set->tree, key);
}
