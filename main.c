#include "lists.h"
#include <stdio.h>

int main(void)
{
	listint_t *head = NULL;

	add_nodeint_end(&head, 0);
	add_nodeint_end(&head, 1);
	add_nodeint_end(&head, 2);
	add_nodeint_end(&head, 3);

	print_listint(head);

	printf("-----------------\n");

	insert_nodeint_at_index(&head, 2, 999);

	print_listint(head);

	free_listint2(&head);

	return (0);
}
