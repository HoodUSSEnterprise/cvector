#include "multiset/insert_multiset.h"

void multiset_insert(MultiSet *set, int key)
{
    rbtree_insert(set->tree, key);
}
