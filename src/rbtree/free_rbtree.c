#include "rbtree/free_rbtree.h"

static void free_nodes(RBTree *tree, RBNode *x)
{
    if (x == tree->nil)
        return;
    free_nodes(tree, x->left);
    free_nodes(tree, x->right);
    free(x);
}

void free_rbtree(RBTree *tree)
{
    if (tree == NULL) return;
    free_nodes(tree, tree->root);
    free(tree->nil);
    free(tree);
}
