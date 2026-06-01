#include "lists.h"

/**
 * get_dnodeint_at_index - returns node at a given index
 * @head: head of list
 * @index: position of node (starting from 0)
 *
 * Return: pointer to node, or NULL if not found
 */
dlistint_t *get_dnodeint_at_index(dlistint_t *head, unsigned int index)
{
    unsigned int i = 0;
    dlistint_t *current = head;

    while (current != NULL)
    {
        if (i == index)
            return (current);

        current = current->next;
        i++;
    }

    return (NULL);
}
