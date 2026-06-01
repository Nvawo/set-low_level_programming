#ifndef LISTS_H
#define LISTS_H

#include <stdlib.h>

/**
 * struct listint_s - singly linked list
 * @n: integer
 * @next: pointer to next node
 */
typedef struct listint_s
{
	int n;
	struct listint_s *next;
} listint_t;

int sum_listint(listint_t *head);

#endif
