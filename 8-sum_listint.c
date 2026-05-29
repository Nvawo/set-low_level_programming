#include "lists.h"

/**
 * sum_listint - returns sum of all n in list
 * @head: pointer to list
 *
 * Return: sum of nodes or 0
 */
int sum_listint(listint_t *head)
{
    int sum = 0;

    while (head)
    {
        sum += head->n;
        head = head->next;
    }

    return (sum);
}
