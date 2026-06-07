#ifndef PRINT_RBTREE_H
#define PRINT_RBTREE_H

#include "rbtree/base_rbtree.h"

/* 中序遍历打印（升序） */
void rbtree_print_inorder(RBTree *tree);
/* 前序遍历打印 */
void rbtree_print_preorder(RBTree *tree);
/* 后序遍历打印 */
void rbtree_print_postorder(RBTree *tree);

#endif
