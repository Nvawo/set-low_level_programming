#include "hash_tables.h"
#include <stdio.h>

/**
 * hash_table_print - prints a hash table
 * @ht: hash table to print
 */
void hash_table_print(const hash_table_t *ht)
{
    unsigned long int i, flag = 0;
    hash_node_t *node;

    if (ht == NULL)
        return;

    printf("{");

    for (i = 0; i < ht->size; i++)
    {
        node = ht->array[i];

        while (node != NULL)
        {
            if (flag == 1)
                printf(", ");

            printf("'%s': '%s'", node->key, node->value);
            flag = 1;

            node = node->next;
        }
    }

    printf("}\n");
}
