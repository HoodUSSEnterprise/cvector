#include "rbtree/operator_rbtree.h"

static int max_int(int a, int b)
{
    return a > b ? a : b;
}

static int tree_height(RBTree *tree, RBNode *x)
{
    if (x == tree->nil)
        return 0;
    return 1 + max_int(tree_height(tree, x->left),
                       tree_height(tree, x->right));
}

int rbtree_min(RBTree *tree)
{
    if (tree->root == tree->nil) return 0;
    RBNode *x = tree->root;
    while (x->left != tree->nil)
        x = x->left;
    return x->key;
}

int rbtree_max(RBTree *tree)
{
    if (tree->root == tree->nil) return 0;
    RBNode *x = tree->root;
    while (x->right != tree->nil)
        x = x->right;
    return x->key;
}

int rbtree_height(RBTree *tree)
{
    return tree_height(tree, tree->root);
}

int rbtree_size(RBTree *tree)
{
    return tree->size;
}

bool rbtree_is_empty(RBTree *tree)
{
    return tree->size == 0;
}
