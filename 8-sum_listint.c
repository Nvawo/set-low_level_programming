#include "lists.h"

/**
 * sum_listint - returns sum of all elements in a listint_t list
 * @head: pointer to list
 *
 * Return: sum of all n values, or 0 if list is empty
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
