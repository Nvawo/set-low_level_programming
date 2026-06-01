#include "lists.h"

/**
 * insert_nodeint_at_index - inserts a node at index
 * @head: pointer to head
 * @idx: index
 * @n: value
 *
 * Return: new node or NULL
 */
listint_t *insert_nodeint_at_index(listint_t **head,
                                    unsigned int idx, int n)
{
	listint_t *new_node;
	listint_t *temp;
	unsigned int i;

	if (head == NULL)
		return (NULL);

	if (idx == 0)
	{
		new_node = malloc(sizeof(listint_t));
		if (!new_node)
			return (NULL);

		new_node->n = n;
		new_node->next = *head;
		*head = new_node;
		return (new_node);
	}

	temp = *head;

	for (i = 0; temp && i < idx - 1; i++)
		temp = temp->next;

	if (temp == NULL)
		return (NULL);

	new_node = malloc(sizeof(listint_t));
	if (!new_node)
		return (NULL);

	new_node->n = n;
	new_node->next = temp->next;
	temp->next = new_node;

	return (new_node);
}
