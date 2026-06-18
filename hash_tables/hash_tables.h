#ifndef HASH_TABLES_H
#define HASH_TABLES_H

#include <stdlib.h>

/**
 * struct hash_table_s - hash table structure
 * @size: size of the array
 * @array: array of pointers
 */
typedef struct hash_table_s
{
    unsigned long int size;
    struct hash_node_s **array;
} hash_table_t;

/**
 * struct hash_node_s - node of a hash table
 * @key: key string
 * @value: value string
 * @next: pointer to next node
 */
typedef struct hash_node_s
{
    char *key;
    char *value;
    struct hash_node_s *next;
} hash_node_t;

/* function prototype */
hash_table_t *hash_table_create(unsigned long int size);
unsigned long int hash_djb2(const unsigned char *str);
unsigned long int key_index(const unsigned char *key, unsigned long int size);
int hash_table_set(hash_table_t *ht, const char *key, const char *value);
#endif
