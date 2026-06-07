#include "multimap/print_multimap.h"

static void inorder_print(MultiMapNode *node, MultiMapNode *nil, int *first)
{
    if (node == nil) return;
    inorder_print(node->left, nil, first);
    if (!*first) printf(", ");
    printf("%d: %d", node->key, node->value);
    *first = 0;
    inorder_print(node->right, nil, first);
}

void multimap_print(MultiMap *map)
{
    printf("{");
    int first = 1;
    inorder_print(map->root, map->nil, &first);
    printf("}\n");
}
