#include "lists.h"

/**
 * sum_listint - returns sum of all nodes
 * @head: pointer to list
 *
 * Return: sum or 0 if empty
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
