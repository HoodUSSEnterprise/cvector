#include "rbtree/rbtree.h"

int main(void)
{
    RBTree *tree = create_rbtree();

    int vals[] = {7, 3, 18, 10, 22, 8, 11, 26, 2, 6, 13};
    int n = sizeof(vals) / sizeof(vals[0]);

    printf("Inserting:");
    for (int i = 0; i < n; i++)
    {
        printf(" %d", vals[i]);
        rbtree_insert(tree, vals[i]);
    }
    printf("\n\n");

    rbtree_print_preorder(tree);
    rbtree_print_inorder(tree);
    rbtree_print_postorder(tree);
    printf("\n");

    printf("Size: %d\n", rbtree_size(tree));
    printf("Height: %d\n", rbtree_height(tree));
    printf("Min: %d\n", rbtree_min(tree));
    printf("Max: %d\n", rbtree_max(tree));

    printf("\nContains 10? %s\n", rbtree_contains(tree, 10) ? "yes" : "no");
    printf("Contains 99? %s\n", rbtree_contains(tree, 99) ? "yes" : "no");

    printf("\nDeleting 18, 3, 10\n");
    rbtree_delete(tree, 18);
    rbtree_delete(tree, 3);
    rbtree_delete(tree, 10);
    rbtree_print_inorder(tree);
    printf("Size after delete: %d\n\n", rbtree_size(tree));

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
