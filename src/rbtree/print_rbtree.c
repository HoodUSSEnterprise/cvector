#include "rbtree/print_rbtree.h"

/* 中序遍历（递归），输出 "键值r/b" 格式 */
static void inorder(RBTree *tree, RBNode *x)
{
    if (x == tree->nil)
    {
        return;
    }
    inorder(tree, x->left);
    printf("%d%c ", x->key, x->color == RED ? 'r' : 'b');
    inorder(tree, x->right);
}

/* 前序遍历（递归） */
static void preorder(RBTree *tree, RBNode *x)
{
    if (x == tree->nil)
    {
        return;
    }
    printf("%d%c ", x->key, x->color == RED ? 'r' : 'b');
    preorder(tree, x->left);
    preorder(tree, x->right);
}

/* 后序遍历（递归） */
static void postorder(RBTree *tree, RBNode *x)
{
    if (x == tree->nil)
    {
        return;
    }
    postorder(tree, x->left);
    postorder(tree, x->right);
    printf("%d%c ", x->key, x->color == RED ? 'r' : 'b');
}

/* 中序打印，输出为升序序列 */
void rbtree_print_inorder(RBTree *tree)
{
    printf("In-order:  ");
    inorder(tree, tree->root);
    printf("\n");
}

/* 前序打印 */
void rbtree_print_preorder(RBTree *tree)
{
    printf("Pre-order: ");
    preorder(tree, tree->root);
    printf("\n");
}

/* 后序打印 */
void rbtree_print_postorder(RBTree *tree)
{
    printf("Post-order:");
    postorder(tree, tree->root);
    printf("\n");
}
