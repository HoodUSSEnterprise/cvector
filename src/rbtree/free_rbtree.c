#include "rbtree/free_rbtree.h"

/* 递归后序遍历释放所有结点 */
static void free_nodes(RBTree *tree, RBNode *x)
{
    if (x == tree->nil)
        return;
    free_nodes(tree, x->left);
    free_nodes(tree, x->right);
    free(x);
}

/* 释放整棵红黑树 */
void free_rbtree(RBTree *tree)
{
    if (tree == NULL) return;
    free_nodes(tree, tree->root);
    free(tree->nil);  /* 释放哨兵结点 */
    free(tree);
}
