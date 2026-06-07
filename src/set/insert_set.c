#include "set/insert_set.h"
#include "rbtree/rbtree.h"

void set_insert(Set *set, int key)
{
    if (rbtree_contains(set->tree, key))
    {
        return;
    }
    rbtree_insert(set->tree, key);
}
