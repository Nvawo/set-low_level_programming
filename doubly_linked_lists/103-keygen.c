#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * keygen5 - generates valid key for crackme5
 */

int main(int argc, char *argv[])
{
    char *username;
    int i, len;
    unsigned long key = 0;

    if (argc != 2)
    {
        printf("Usage: ./keygen5 username\n");
        return (1);
    }

    username = argv[1];
    len = strlen(username);

    /* core transformation */
    for (i = 0; i < len; i++)
    {
        key += (username[i] * (i + 1));
        key ^= (i * 0x55);
    }

    /* final mixing (common in crackmes) */
    key ^= 0x5A5A5A5A;

    printf("%lu\n", key);
    return (0);
}
