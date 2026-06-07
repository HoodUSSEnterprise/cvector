#include "rbtree/rbtree.h"

int main(void)
{
    RBTree *tree = create_rbtree();

    /* 插入一组测试数据 */
    int vals[] = {7, 3, 18, 10, 22, 8, 11, 26, 2, 6, 13};
    int n = sizeof(vals) / sizeof(vals[0]);

    printf("Inserting:");
    for (int i = 0; i < n; i++)
    {
        printf(" %d", vals[i]);
        rbtree_insert(tree, vals[i]);
    }
    printf("\n\n");

    /* 三种遍历方式打印 */
    rbtree_print_preorder(tree);
    rbtree_print_inorder(tree);
    rbtree_print_postorder(tree);
    printf("\n");

    /* 基本信息 */
    printf("Size: %d\n", rbtree_size(tree));
    printf("Height: %d\n", rbtree_height(tree));
    printf("Min: %d\n", rbtree_min(tree));
    printf("Max: %d\n", rbtree_max(tree));

    /* 查找测试 */
    printf("\nContains 10? %s\n", rbtree_contains(tree, 10) ? "yes" : "no");
    printf("Contains 99? %s\n", rbtree_contains(tree, 99) ? "yes" : "no");

    /* 删除测试 */
    printf("\nDeleting 18, 3, 10\n");
    rbtree_delete(tree, 18);
    rbtree_delete(tree, 3);
    rbtree_delete(tree, 10);
    rbtree_print_inorder(tree);
    printf("Size after delete: %d\n\n", rbtree_size(tree));

    /* 删除后再插入 */
    printf("Inserting 1, 4, 5, 20:\n");
    rbtree_insert(tree, 1);
    rbtree_insert(tree, 4);
    rbtree_insert(tree, 5);
    rbtree_insert(tree, 20);
    rbtree_print_inorder(tree);
    printf("Size: %d | Height: %d\n", rbtree_size(tree), rbtree_height(tree));

    free_rbtree(tree);
    return 0;
}
