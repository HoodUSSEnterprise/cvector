#include "rbtree/operator_rbtree.h"

/* 取两整数较大值（辅助函数） */
static int max_int(int a, int b)
{
    return a > b ? a : b;
}

/* 递归计算子树高度 */
static int tree_height(RBTree *tree, RBNode *x)
{
    if (x == tree->nil)
    {
        return 0;
    }
    return 1 + max_int(tree_height(tree, x->left),
                       tree_height(tree, x->right));
}

/* 返回树中最小键值（沿左链走到黑） */
int rbtree_min(RBTree *tree)
{
    if (tree->root == tree->nil)
    {
        return 0;
    }
    RBNode *x = tree->root;
    while (x->left != tree->nil)
    {
        x = x->left;
    }
    return x->key;
}

/* 返回树中最大键值（沿右链走到黑） */
int rbtree_max(RBTree *tree)
{
    if (tree->root == tree->nil)
    {
        return 0;
    }
    RBNode *x = tree->root;
    while (x->right != tree->nil)
    {
        x = x->right;
    }
    return x->key;
}

/* 返回树的高度 */
int rbtree_height(RBTree *tree)
{
    return tree_height(tree, tree->root);
}

/* 返回树的结点数量 */
int rbtree_size(RBTree *tree)
{
    return tree->size;
}

/* 判断树是否为空 */
bool rbtree_is_empty(RBTree *tree)
{
    return tree->size == 0;
}
