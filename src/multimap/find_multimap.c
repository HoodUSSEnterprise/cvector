#include "multimap/find_multimap.h"

static MultiMapNode *find_node(MultiMap *map, int key)
{
    MultiMapNode *cur = map->root;
    while (cur != map->nil)
    {
        if (key < cur->key)
            cur = cur->left;
        else if (key > cur->key)
            cur = cur->right;
        else
            return cur;
    }
    return NULL;
}

int *multimap_get(MultiMap *map, int key)
{
    MultiMapNode *node = find_node(map, key);
    return node ? &node->value : NULL;
}

int multimap_contains(MultiMap *map, int key)
{
    return find_node(map, key) != NULL;
}
