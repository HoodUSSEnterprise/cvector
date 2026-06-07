#ifndef HASH_TABLE_H
#define HASH_TABLE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct HashNode
{
    char *key;
    int value;
    struct HashNode *next;
} HashNode;

typedef struct
{
    HashNode **buckets;
    int size;
    int table_size;
} HashTable;

#endif