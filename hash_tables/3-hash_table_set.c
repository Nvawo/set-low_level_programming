#include "hash_tables.h"
#include <string.h>
#include <stdlib.h>

/**
 * hash_table_set - adds or updates a key/value in the hash table
 * @ht: the hash table
 * @key: the key (cannot be empty)
 * @value: the value (must be duplicated)
 *
 * Return: 1 on success, 0 on failure
 */
int hash_table_set(hash_table_t *ht, const char *key, const char *value)
{
    unsigned long int index;
    hash_node_t *node, *temp;
    char *value_copy, *key_copy;

    if (ht == NULL || key == NULL || *key == '\0')
        return (0);

    value_copy = strdup(value);
    if (value_copy == NULL)
        return (0);

    index = key_index((const unsigned char *)key, ht->size);

    temp = ht->array[index];

    /* check if key already exists → update value */
    while (temp != NULL)
    {
        if (strcmp(temp->key, key) == 0)
        {
            free(temp->value);
            temp->value = value_copy;
            return (1);
        }
        temp = temp->next;
    }

    /* create new node */
    node = malloc(sizeof(hash_node_t));
    if (node == NULL)
    {
        free(value_copy);
        return (0);
    }

    key_copy = strdup(key);
    if (key_copy == NULL)
    {
        free(value_copy);
        free(node);
        return (0);
    }

    node->key = key_copy;
    node->value = value_copy;

    /* insert at beginning (collision handling) */
    node->next = ht->array[index];
    ht->array[index] = node;

    return (1);
}
