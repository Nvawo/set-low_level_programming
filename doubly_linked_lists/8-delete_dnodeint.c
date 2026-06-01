#include <stdlib.h>
#include "lists.h"

/**
 * delete_dnodeint_at_index - deletes node at index
 * @head: pointer to head pointer
 * @index: index of node to delete
 *
 * Return: 1 if success, -1 if failed
 */
int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
    dlistint_t *current;
    unsigned int i;

    if (head == NULL || *head == NULL)
        return (-1);

    current = *head;

    /* delete head */
    if (index == 0)
    {
        *head = current->next;

        if (*head != NULL)
            (*head)->prev = NULL;

        free(current);
        return (1);
    }

    /* move to node */
    for (i = 0; current != NULL && i < index; i++)
        current = current->next;

    if (current == NULL)
        return (-1);

    if (current->prev != NULL)
        current->prev->next = current->next;

    if (current->next != NULL)
        current->next->prev = current->prev;

    free(current);

    return (1);
}
