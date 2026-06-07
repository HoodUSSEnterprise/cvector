#ifndef OPERATOR_RBTREE_H
#define OPERATOR_RBTREE_H

#include "rbtree/base_rbtree.h"
#include <stdbool.h>
#include <limits.h>

int rbtree_min(RBTree *tree);
int rbtree_max(RBTree *tree);
int rbtree_height(RBTree *tree);
int rbtree_size(RBTree *tree);
bool rbtree_is_empty(RBTree *tree);

#endif
