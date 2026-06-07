#ifndef DELETE_RBTREE_H
#define DELETE_RBTREE_H

#include "rbtree/base_rbtree.h"

/* 从红黑树中删除键值为 key 的结点（若存在） */
void rbtree_delete(RBTree *tree, int key);

#endif
