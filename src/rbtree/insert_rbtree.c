#include "rbtree/insert_rbtree.h"

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

static void insert_fixup(RBTree *tree, RBNode *z)
{
    while (z->parent->color == RED)
    {
        if (z->parent == z->parent->parent->left)
        {
            RBNode *y = z->parent->parent->right;
            if (y->color == RED)
            {
                z->parent->color = BLACK;
                y->color = BLACK;
                z->parent->parent->color = RED;
                z = z->parent->parent;
            }
            else
            {
                if (z == z->parent->right)
                {
                    z = z->parent;
                    left_rotate(tree, z);
                }
                z->parent->color = BLACK;
                z->parent->parent->color = RED;
                right_rotate(tree, z->parent->parent);
            }
        }
        else
        {
            RBNode *y = z->parent->parent->left;
            if (y->color == RED)
            {
                z->parent->color = BLACK;
                y->color = BLACK;
                z->parent->parent->color = RED;
                z = z->parent->parent;
            }
            else
            {
                if (z == z->parent->left)
                {
                    z = z->parent;
                    right_rotate(tree, z);
                }
                z->parent->color = BLACK;
                z->parent->parent->color = RED;
                left_rotate(tree, z->parent->parent);
            }
        }
    }
    tree->root->color = BLACK;
}

void rbtree_insert(RBTree *tree, int key)
{
    RBNode *z = (RBNode *)malloc(sizeof(RBNode));
    if (z == NULL) return;
    z->key = key;
    z->left = tree->nil;
    z->right = tree->nil;
    z->color = RED;

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
    insert_fixup(tree, z);
}
