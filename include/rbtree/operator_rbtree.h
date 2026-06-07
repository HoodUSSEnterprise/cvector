#ifndef OPERATOR_RBTREE_H
#define OPERATOR_RBTREE_H

#include "rbtree/base_rbtree.h"
#include <stdbool.h>

/* 返回树中最小键值（空树返回 0） */
int rbtree_min(RBTree *tree);
/* 返回树中最大键值（空树返回 0） */
int rbtree_max(RBTree *tree);
/* 返回树的高度（空树为 0） */
int rbtree_height(RBTree *tree);
/* 返回树的结点数 */
int rbtree_size(RBTree *tree);
/* 判断树是否为空 */
bool rbtree_is_empty(RBTree *tree);

#endif
