#include "rbtree/delete_rbtree.h"

/* 左旋（同插入模块） */
static void left_rotate(RBTree *tree, RBNode *x)
{
    RBNode *y = x->right;
    x->right = y->left;
    if (y->left != tree->nil)
    {
        y->left->parent = x;
    }
    y->parent = x->parent;
    if (x->parent == tree->nil)
    {
        tree->root = y;
    }
    else if (x == x->parent->left)
    {
        x->parent->left = y;
    }
    else
    {
        x->parent->right = y;
    }
    y->left = x;
    x->parent = y;
}

/* 右旋（同插入模块） */
static void right_rotate(RBTree *tree, RBNode *x)
{
    RBNode *y = x->left;
    x->left = y->right;
    if (y->right != tree->nil)
    {
        y->right->parent = x;
    }
    y->parent = x->parent;
    if (x->parent == tree->nil)
    {
        tree->root = y;
    }
    else if (x == x->parent->right)
    {
        x->parent->right = y;
    }
    else
    {
        x->parent->left = y;
    }
    y->right = x;
    x->parent = y;
}

/* 在以 x 为根的子树中找最小结点 */
static RBNode *min_node(RBTree *tree, RBNode *x)
{
    while (x->left != tree->nil)
    {
        x = x->left;
    }
    return x;
}

/* 用子树 v 替换子树 u（不处理颜色） */
static void transplant(RBTree *tree, RBNode *u, RBNode *v)
{
    if (u->parent == tree->nil)
    {
        tree->root = v;
    }
    else if (u == u->parent->left)
    {
        u->parent->left = v;
    }
    else
    {
        u->parent->right = v;
    }
    v->parent = u->parent;
}

/*
 * 删除修正：弥补删除黑结点导致的黑高失衡
 * 四种情况（以 x 为左孩子为例，右孩子对称）：
 *   情况 1：兄弟为红 → 变色 + 左旋
 *   情况 2：兄弟为黑，两侄全黑 → 兄弟变红，上移 x
 *   情况 3：兄弟为黑，左侄红右侄黑 → 变色 + 右旋（转化为情况 4）
 *   情况 4：兄弟为黑，右侄红 → 变色 + 左旋，结束
 */
static void delete_fixup(RBTree *tree, RBNode *x)
{
    while (x != tree->root && x->color == BLACK)
    {
        if (x == x->parent->left)
        {
            RBNode *w = x->parent->right; /* 兄弟结点 */
            if (w->color == RED)
            {
                /* 情况 1：兄弟为红 */
                w->color = BLACK;
                x->parent->color = RED;
                left_rotate(tree, x->parent);
                w = x->parent->right;
            }
            if (w->left->color == BLACK && w->right->color == BLACK)
            {
                /* 情况 2：两侄全黑 */
                w->color = RED;
                x = x->parent;
            }
            else
            {
                if (w->right->color == BLACK)
                {
                    /* 情况 3：左侄红、右侄黑 */
                    w->left->color = BLACK;
                    w->color = RED;
                    right_rotate(tree, w);
                    w = x->parent->right;
                }
                /* 情况 4：右侄红 */
                w->color = x->parent->color;
                x->parent->color = BLACK;
                w->right->color = BLACK;
                left_rotate(tree, x->parent);
                x = tree->root;
            }
        }
        else
        {
            /* 对称：x 为右孩子 */
            RBNode *w = x->parent->left;
            if (w->color == RED)
            {
                w->color = BLACK;
                x->parent->color = RED;
                right_rotate(tree, x->parent);
                w = x->parent->left;
            }
            if (w->right->color == BLACK && w->left->color == BLACK)
            {
                w->color = RED;
                x = x->parent;
            }
            else
            {
                if (w->left->color == BLACK)
                {
                    w->right->color = BLACK;
                    w->color = RED;
                    left_rotate(tree, w);
                    w = x->parent->left;
                }
                w->color = x->parent->color;
                x->parent->color = BLACK;
                w->left->color = BLACK;
                right_rotate(tree, x->parent);
                x = tree->root;
            }
        }
    }
    x->color = BLACK;
}

/* 从红黑树中删除键值为 key 的结点 */
void rbtree_delete(RBTree *tree, int key)
{
    /* 先查找要删除的结点 */
    RBNode *z = tree->root;
    while (z != tree->nil)
    {
        if (key == z->key)
        {
            break;
        }
        else if (key < z->key)
        {
            z = z->left;
        }
        else
        {
            z = z->right;
        }
    }
    if (z == tree->nil)
    {
        return; /* 未找到 */
    }

    RBNode *y = z; /* y 记录实际被移除或移动的结点 */
    RBNode *x;     /* x 指向替换位置的孩子 */
    Color y_original_color = y->color;

    if (z->left == tree->nil)
    {
        /* 无左孩子：用右孩子替换 z */
        x = z->right;
        transplant(tree, z, z->right);
    }
    else if (z->right == tree->nil)
    {
        /* 无右孩子：用左孩子替换 z */
        x = z->left;
        transplant(tree, z, z->left);
    }
    else
    {
        /* 有两个孩子：找后继（右子树最小结点）替换 z */
        y = min_node(tree, z->right);
        y_original_color = y->color;
        x = y->right;
        if (y->parent == z)
        {
            x->parent = y;
        }
        else
        {
            transplant(tree, y, y->right);
            y->right = z->right;
            y->right->parent = y;
        }
        transplant(tree, z, y);
        y->left = z->left;
        y->left->parent = y;
        y->color = z->color; /* y 继承 z 的颜色，不影响黑高 */
    }

    free(z);
    tree->size--;

    /* 若移除的结点为黑色，需要修正 */
    if (y_original_color == BLACK)
    {
        delete_fixup(tree, x);
    }
}
