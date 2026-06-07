#include "rbtree/create_rbtree.h"

/* 创建一棵空的红黑树 */
RBTree *create_rbtree(void)
{
    /* 分配树结构本身 */
    RBTree *tree = (RBTree *)malloc(sizeof(RBTree));
    if (tree == NULL) return NULL;

    /* 创建哨兵结点（代表所有叶子 NIL） */
    tree->nil = (RBNode *)malloc(sizeof(RBNode));
    if (tree->nil == NULL)
    {
        free(tree);
        return NULL;
    }
    tree->nil->color = BLACK;    /* 哨兵为黑色 */
    tree->nil->left = NULL;
    tree->nil->right = NULL;
    tree->nil->parent = NULL;

    tree->root = tree->nil;      /* 根初始指向哨兵 */
    tree->size = 0;
    return tree;
}
