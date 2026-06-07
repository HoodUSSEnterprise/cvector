#ifndef BASE_RBTREE_H
#define BASE_RBTREE_H

#include <stdio.h>
#include <stdlib.h>

/* 红黑树结点颜色 */
typedef enum { RED, BLACK } Color;

/* 红黑树结点 */
typedef struct RBNode
{
    int key;                 /* 键值 */
    Color color;             /* 结点颜色 */
    struct RBNode *left;     /* 左孩子 */
    struct RBNode *right;    /* 右孩子 */
    struct RBNode *parent;   /* 父结点 */
} RBNode;

/* 红黑树 */
typedef struct
{
    RBNode *root;  /* 根结点 */
    RBNode *nil;   /* 哨兵叶子结点（黑色） */
    int size;      /* 结点数量 */
} RBTree;

#endif
