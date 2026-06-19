#ifndef HASH_TABLES_H
#define HASH_TABLES_H

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

/**
 * struct hash_node_s - node of a hash table
 */
typedef struct hash_node_s
{
	char *key;
	char *value;
	struct hash_node_s *next;
} hash_node_t;


/**
 * struct hash_table_s - hash table
 */
typedef struct hash_table_s
{
	unsigned long int size;
	hash_node_t **array;
} hash_table_t;


/**
 * struct shash_node_s - sorted hash node
 */
typedef struct shash_node_s
{
	char *key;
	char *value;
	struct shash_node_s *next;
	struct shash_node_s *sprev;
	struct shash_node_s *snext;
} shash_node_t;


/**
 * struct shash_table_s - sorted hash table
 */
typedef struct shash_table_s
{
	unsigned long int size;
	shash_node_t **array;
	shash_node_t *shead;
	shash_node_t *stail;
} shash_table_t;


/* Task 1 */
unsigned long int hash_djb2(const unsigned char *str);

/* Task 2 */
unsigned long int key_index(const unsigned char *key,
		unsigned long int size);

/* Task 0 */
hash_table_t *hash_table_create(unsigned long int size);

/* Task 3 */
int hash_table_set(hash_table_t *ht,
		const char *key,
		const char *value);

/* Task 4 */
char *hash_table_get(const hash_table_t *ht,
		const char *key);

/* Task 5 */
void hash_table_print(const hash_table_t *ht);

/* Task 6 */
void hash_table_delete(hash_table_t *ht);


/* Task 7 */
shash_table_t *shash_table_create(unsigned long int size);
int shash_table_set(shash_table_t *ht,
		const char *key,
		const char *value);
char *shash_table_get(const shash_table_t *ht,
		const char *key);
void shash_table_print(const shash_table_t *ht);
void shash_table_print_rev(const shash_table_t *ht);
void shash_table_delete(shash_table_t *ht);


#endif
