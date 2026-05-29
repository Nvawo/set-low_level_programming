#ifndef LISTS_H
#define LISTS_H

#include <stdlib.h>
#include <stddef.h>

typedef struct listint_s
{
    int n;
    struct listint_s *next;
} listint_t;

/* prototypes */
size_t print_listint(const listint_t *h);
int sum_listint(listint_t *head);

#endif
