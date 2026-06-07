#include "rbtree/insert_rbtree.h"

/*
 * 左旋：以 x 为轴向左旋转
 *     x               y
 *    / \     -->     / \
 *   a   y           x   r
 *      / \         / \
 *     b   r       a   b
 */
static void left_rotate(RBTree *tree, RBNode *x)
{
    RBNode *y = x->right;
    x->right = y->left;
    if (y->left != tree->nil)
        y->left->parent = x;
    y->parent = x->parent;
    if (x->parent == tree->nil)
        tree->root = y;
    else if (x == x->parent->left)
        x->parent->left = y;
    else
        x->parent->right = y;
    y->left = x;
    x->parent = y;
}

/*
 * 右旋：以 x 为轴向右旋转
 *       x             y
 *      / \    -->    / \
 *     y   r         a   x
 *    / \               / \
 *   a   b             b   r
 */
static void right_rotate(RBTree *tree, RBNode *x)
{
    RBNode *y = x->left;
    x->left = y->right;
    if (y->right != tree->nil)
        y->right->parent = x;
    y->parent = x->parent;
    if (x->parent == tree->nil)
        tree->root = y;
    else if (x == x->parent->right)
        x->parent->right = y;
    else
        x->parent->left = y;
    y->right = x;
    x->parent = y;
}

/*
 * 插入修正：保持红黑树性质
 * 循环处理双红冲突，分三种情况：
 *   情况 1：叔结点为红色 → 变色后上移
 *   情况 2：叔结点为黑色，z 为内侧孩子 → 旋转变为情况 3
 *   情况 3：叔结点为黑色，z 为外侧孩子 → 旋转 + 变色
 */
static void insert_fixup(RBTree *tree, RBNode *z)
{
    while (z->parent->color == RED)
    {
        if (z->parent == z->parent->parent->left)
        {
            /* 父结点是祖父的左孩子 */
            RBNode *y = z->parent->parent->right;  /* 叔结点 */
            if (y->color == RED)
            {
                /* 情况 1：叔结点为红 → 变色 */
                z->parent->color = BLACK;
                y->color = BLACK;
                z->parent->parent->color = RED;
                z = z->parent->parent;
            }
            else
            {
                /* 情况 2：z 为右孩子 → 左旋转化 */
                if (z == z->parent->right)
                {
                    z = z->parent;
                    left_rotate(tree, z);
                }
                /* 情况 3：z 为左孩子 → 右旋 + 变色 */
                z->parent->color = BLACK;
                z->parent->parent->color = RED;
                right_rotate(tree, z->parent->parent);
            }
        }
        else
        {
            /* 父结点是祖父的右孩子（对称） */
            RBNode *y = z->parent->parent->left;   /* 叔结点 */
            if (y->color == RED)
            {
                /* 情况 1（对称） */
                z->parent->color = BLACK;
                y->color = BLACK;
                z->parent->parent->color = RED;
                z = z->parent->parent;
            }
            else
            {
                /* 情况 2（对称）：z 为左孩子 */
                if (z == z->parent->left)
                {
                    z = z->parent;
                    right_rotate(tree, z);
                }
                /* 情况 3（对称）：z 为右孩子 */
                z->parent->color = BLACK;
                z->parent->parent->color = RED;
                left_rotate(tree, z->parent->parent);
            }
        }
    }
    /* 根结点必须始终为黑色 */
    tree->root->color = BLACK;
}

/* 向红黑树中插入键值为 key 的新结点 */
void rbtree_insert(RBTree *tree, int key)
{
    RBNode *z = (RBNode *)malloc(sizeof(RBNode));
    if (z == NULL) return;
    z->key = key;
    z->left = tree->nil;
    z->right = tree->nil;
    z->color = RED;  /* 新结点默认为红色 */

    /* 标准的 BST 插入 */
    RBNode *y = tree->nil;
    RBNode *x = tree->root;
    while (x != tree->nil)
    {
        y = x;
        if (key < x->key)
            x = x->left;
        else
            x = x->right;
    }
    z->parent = y;
    if (y == tree->nil)
        tree->root = z;
    else if (key < y->key)
        y->left = z;
    else
        y->right = z;

    tree->size++;
    insert_fixup(tree, z);  /* 修复红黑树性质 */
}
