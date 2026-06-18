#include "hash_tables.h"
#include <string.h>

/**
 * hash_table_get - retrieves a value by key
 * @ht: hash table to search
 * @key: key to look for
 *
 * Return: value associated with key, or NULL if not found
 */
char *hash_table_get(const hash_table_t *ht, const char *key)
{
    unsigned long int index;
    hash_node_t *node;

    if (ht == NULL || key == NULL || *key == '\0')
        return (NULL);

    index = key_index((const unsigned char *)key, ht->size);

    node = ht->array[index];

    while (node != NULL)
    {
        if (strcmp(node->key, key) == 0)
            return (node->value);

        node = node->next;
    }

    return (NULL);
}
