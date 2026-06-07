#include "rbtree/count_rbtree.h"

static int count_nodes(RBNode *node, RBNode *nil, int key)
{
    if (node == nil)
    {
        return 0;
    }
    int c = (node->key == key) ? 1 : 0;
    return c + count_nodes(node->left, nil, key) + count_nodes(node->right, nil, key);
}

int rbtree_count(RBTree *tree, int key)
{
    return count_nodes(tree->root, tree->nil, key);
}
