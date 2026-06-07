#include "rbtree/find_rbtree.h"

RBNode *rbtree_find(RBTree *tree, int key)
{
    RBNode *x = tree->root;
    while (x != tree->nil)
    {
        if (key == x->key)
            return x;
        else if (key < x->key)
            x = x->left;
        else
            x = x->right;
    }
    return NULL;
}

bool rbtree_contains(RBTree *tree, int key)
{
    return rbtree_find(tree, key) != NULL;
}
