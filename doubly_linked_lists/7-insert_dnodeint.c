#include <stdlib.h>
#include "lists.h"

/**
 * insert_dnodeint_at_index - inserts node at given index
 * @h: pointer to head pointer
 * @idx: index to insert at
 * @n: value of new node
 *
 * Return: address of new node, or NULL if failed
 */
dlistint_t *insert_dnodeint_at_index(dlistint_t **h, unsigned int idx, int n)
{
    dlistint_t *new_node;
    dlistint_t *current;
    unsigned int i;

    if (h == NULL)
        return (NULL);

    if (idx == 0)
        return (add_dnodeint(h, n));

    current = *h;

    for (i = 0; current != NULL && i < idx - 1; i++)
        current = current->next;

    if (current == NULL)
        return (NULL);

    new_node = malloc(sizeof(dlistint_t));
    if (new_node == NULL)
        return (NULL);

    new_node->n = n;
    new_node->next = current->next;
    new_node->prev = current;

    if (current->next != NULL)
        current->next->prev = new_node;

    current->next = new_node;

    return (new_node);
}
