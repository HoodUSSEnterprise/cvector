#include "rbtree/find_rbtree.h"

/* 在树中查找键值为 key 的结点，返回结点指针；未找到返回 NULL */
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

/* 判断 key 是否存在于树中 */
bool rbtree_contains(RBTree *tree, int key)
{
    return rbtree_find(tree, key) != NULL;
}
