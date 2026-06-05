#include <stdio.h>
#include "lists.h"

int main(void)
{
    listint_t *head = NULL;

    add_nodeint_end(&head, 10);
    add_nodeint_end(&head, 20);

    print_listint(head);

    return 0;
}
