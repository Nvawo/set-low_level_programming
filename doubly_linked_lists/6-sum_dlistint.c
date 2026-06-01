#include "lists.h"

/**
 * sum_dlistint - returns sum of all n values in list
 * @head: head of list
 *
 * Return: sum of all nodes, or 0 if empty
 */
int sum_dlistint(dlistint_t *head)
{
    int sum = 0;
    dlistint_t *current = head;

    while (current != NULL)
    {
        sum += current->n;
        current = current->next;
    }

    return (sum);
}
