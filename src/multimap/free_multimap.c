#include "multimap/free_multimap.h"

static void post_order_free(MultiMapNode *node, MultiMapNode *nil)
{
    if (node == nil) return;
    post_order_free(node->left, nil);
    post_order_free(node->right, nil);
    free(node);
}

void clear_multimap(MultiMap *map)
{
    post_order_free(map->root, map->nil);
    map->root = map->nil;
    map->size = 0;
}

void free_multimap(MultiMap *map)
{
    if (!map) return;
    clear_multimap(map);
    free(map->nil);
    free(map);
}
