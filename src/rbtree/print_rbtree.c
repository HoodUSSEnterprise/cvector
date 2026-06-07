#include "rbtree/print_rbtree.h"

static void inorder(RBTree *tree, RBNode *x)
{
    if (x == tree->nil) return;
    inorder(tree, x->left);
    printf("%d%c ", x->key, x->color == RED ? 'r' : 'b');
    inorder(tree, x->right);
}

static void preorder(RBTree *tree, RBNode *x)
{
    if (x == tree->nil) return;
    printf("%d%c ", x->key, x->color == RED ? 'r' : 'b');
    preorder(tree, x->left);
    preorder(tree, x->right);
}

static void postorder(RBTree *tree, RBNode *x)
{
    if (x == tree->nil) return;
    postorder(tree, x->left);
    postorder(tree, x->right);
    printf("%d%c ", x->key, x->color == RED ? 'r' : 'b');
}

void rbtree_print_inorder(RBTree *tree)
{
    printf("In-order:  ");
    inorder(tree, tree->root);
    printf("\n");
}

void rbtree_print_preorder(RBTree *tree)
{
    printf("Pre-order: ");
    preorder(tree, tree->root);
    printf("\n");
}

void rbtree_print_postorder(RBTree *tree)
{
    printf("Post-order:");
    postorder(tree, tree->root);
    printf("\n");
}
