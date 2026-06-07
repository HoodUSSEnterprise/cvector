#ifndef FIND_RBTREE_H
#define FIND_RBTREE_H

#include "rbtree/base_rbtree.h"
#include <stdbool.h>

/* 在树中查找 key，返回结点指针；未找到返回 NULL */
RBNode *rbtree_find(RBTree *tree, int key);
/* 判断 key 是否存在于树中 */
bool rbtree_contains(RBTree *tree, int key);

#endif
