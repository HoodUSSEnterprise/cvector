#ifndef BASE_SET_H
#define BASE_SET_H

#include "rbtree/rbtree.h"

/* Set 是对红黑树的简单包装 */
typedef struct
{
    RBTree *tree;
} Set;

#endif
