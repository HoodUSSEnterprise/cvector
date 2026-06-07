#ifndef FREE_RBTREE_H
#define FREE_RBTREE_H

#include "rbtree/base_rbtree.h"

/* 释放整棵红黑树（所有结点和哨兵） */
void free_rbtree(RBTree *tree);

#endif
