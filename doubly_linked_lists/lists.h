#ifndef LISTS_H
#define LISTS_H

#include <stddef.h>

/**
 * struct dlistint_s - doubly linked list node
 * @n: integer
 * @prev: pointer to previous node
 * @next: pointer to next node
 */
typedef struct dlistint_s
{
    int n;
    struct dlistint_s *prev;
    struct dlistint_s *next;
} dlistint_t;

/* function prototypes */
size_t print_dlistint(const dlistint_t *h);
size_t dlistint_len(const dlistint_t *h);

#endif
