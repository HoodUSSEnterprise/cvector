#ifndef FIND_RBTREE_H
#define FIND_RBTREE_H

#include "rbtree/base_rbtree.h"
#include <stdbool.h>

RBNode *rbtree_find(RBTree *tree, int key);
bool rbtree_contains(RBTree *tree, int key);

#endif
