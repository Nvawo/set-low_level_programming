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

/* required prototypes */
int sum_listint(listint_t *head);

listint_t *insert_nodeint_at_index(listint_t **head,
                                    unsigned int idx, int n);

#endif
