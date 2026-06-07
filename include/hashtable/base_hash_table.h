#ifndef BASE_HASH_TABLE_H
#define BASE_HASH_TABLE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct HashNode
{
    char *key;
    int value;
    struct HashNode *next;
} HashNode;

typedef struct HashTable
{
    HashNode **buckets;
    int size;
    int table_size;
} HashTable;

#endif