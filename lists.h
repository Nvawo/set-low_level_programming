#ifndef LISTS_H
#define LISTS_H

#include <stdlib.h>

/**
 * struct listint_s - singly linked list
 * @n: integer
 * @next: points to next node
 */
typedef struct listint_s
{
    int n;
    struct listint_s *next;
} listint_t;

/* Task 0 */
int sum_listint(listint_t *head);

/* Task 1 */
listint_t *insert_nodeint_at_index(listint_t **head,
                                    unsigned int idx, int n);

/* Task 2 */
int delete_nodeint_at_index(listint_t **head, unsigned int index);

/* Task 3 */
listint_t *reverse_listint(listint_t **head);

/* Task 4 */
size_t print_listint_safe(const listint_t *head);

/* Task 5 */
size_t free_listint_safe(listint_t **h);

/* Task 6 */
listint_t *find_listint_loop(listint_t *head);

#endif
