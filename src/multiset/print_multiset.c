#include "multiset/print_multiset.h"

void multiset_print(MultiSet *set)
{
    rbtree_print_inorder(set->tree);
}
