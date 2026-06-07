#include "rbtree/create_rbtree.h"

RBTree *create_rbtree(void)
{
    RBTree *tree = (RBTree *)malloc(sizeof(RBTree));
    if (tree == NULL) return NULL;

    tree->nil = (RBNode *)malloc(sizeof(RBNode));
    if (tree->nil == NULL)
    {
        free(tree);
        return NULL;
    }
    tree->nil->color = BLACK;
    tree->nil->left = NULL;
    tree->nil->right = NULL;
    tree->nil->parent = NULL;

    tree->root = tree->nil;
    tree->size = 0;
    return tree;
}
