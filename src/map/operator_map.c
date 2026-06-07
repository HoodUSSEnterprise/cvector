#include "map/operator_map.h"

int map_size(Map *map)
{
    return map->size;
}

bool map_is_empty(Map *map)
{
    return map->size == 0;
}

static void print_inorder(Map *map, MapNode *x)
{
    if (x == map->nil) return;
    print_inorder(map, x->left);
    printf("{%d: %d} ", x->key, x->value);
    print_inorder(map, x->right);
}

void map_print(Map *map)
{
    printf("Map: ");
    print_inorder(map, map->root);
    printf("\n");
}
