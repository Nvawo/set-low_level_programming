#include "lists.h"
#include <stdlib.h>

/**
 * insert_nodeint_at_index - inserts a new node at a given index
 * @head: pointer to head of list
 * @idx: index to insert at (0-based)
 * @n: value of new node
 *
 * Return: address of new node, or NULL if failure
 */
listint_t *insert_nodeint_at_index(listint_t **head,
				    unsigned int idx, int n)
{
	listint_t *new_node;
	listint_t *temp;
	unsigned int i = 0;

	if (!head)
		return (NULL);

	if (idx == 0)
		return (add_nodeint(head, n));

	temp = *head;

	while (temp && i < idx - 1)
	{
		temp = temp->next;
		i++;
	}

	if (!temp)
		return (NULL);

	new_node = malloc(sizeof(listint_t));
	if (!new_node)
		return (NULL);

	new_node->n = n;
	new_node->next = temp->next;
	temp->next = new_node;

	return (new_node);
}
