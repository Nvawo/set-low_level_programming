#include "hash_tables.h"

/**
 * key_index - gives the index of a key
 * @key: the key string
 * @size: size of the hash table array
 *
 * Return: index where the key/value pair should be stored
 */
unsigned long int key_index(const unsigned char *key, unsigned long int size)
{
    unsigned long int hash;

    hash = hash_djb2(key);

    return (hash % size);
}
