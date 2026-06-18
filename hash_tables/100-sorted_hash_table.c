#include "hash_tables.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>


shash_table_t *shash_table_create(unsigned long int size)
{
	shash_table_t *ht;

	ht = malloc(sizeof(shash_table_t));

	if (ht == NULL)
		return (NULL);

	ht->array = malloc(sizeof(shash_node_t *) * size);

	if (ht->array == NULL)
	{
		free(ht);
		return (NULL);
	}

	ht->size = size;
	ht->shead = NULL;
	ht->stail = NULL;

	return (ht);
}


void sorted_insert(shash_table_t *ht, shash_node_t *node)
{
	shash_node_t *current;

	current = ht->shead;


	if (current == NULL)
	{
		ht->shead = node;
		ht->stail = node;
		return;
	}


	while (current && strcmp(node->key, current->key) > 0)
		current = current->snext;


	if (current == ht->shead)
	{
		node->snext = ht->shead;
		ht->shead->sprev = node;
		ht->shead = node;
	}

	else if (current == NULL)
	{
		node->sprev = ht->stail;
		ht->stail->snext = node;
		ht->stail = node;
	}

	else
	{
		node->snext = current;
		node->sprev = current->sprev;

		current->sprev->snext = node;
		current->sprev = node;
	}
}


int shash_table_set(shash_table_t *ht,
		const char *key,
		const char *value)
{
	shash_node_t *node;
	unsigned long int index;


	if (ht == NULL || key == NULL || *key == '\0')
		return (0);


	node = malloc(sizeof(shash_node_t));

	if (node == NULL)
		return (0);


	node->key = strdup(key);
	node->value = strdup(value);


	if (node->key == NULL || node->value == NULL)
		return (0);


	index = key_index((unsigned char *)key, ht->size);


	node->next = ht->array[index];
	ht->array[index] = node;


	node->sprev = NULL;
	node->snext = NULL;


	sorted_insert(ht, node);


	return (1);
}


char *shash_table_get(const shash_table_t *ht,
		const char *key)
{
	unsigned long int index;
	shash_node_t *node;


	if (ht == NULL || key == NULL)
		return (NULL);


	index = key_index((unsigned char *)key, ht->size);


	node = ht->array[index];


	while (node)
	{
		if (strcmp(node->key, key) == 0)
			return (node->value);

		node = node->next;
	}


	return (NULL);
}


void shash_table_print(const shash_table_t *ht)
{
	shash_node_t *node;


	if (ht == NULL)
		return;


	node = ht->shead;


	printf("{");


	while (node)
	{
		printf("'%s': '%s'", node->key, node->value);


		if (node->snext)
			printf(", ");


		node = node->snext;
	}


	printf("}\n");
}


void shash_table_print_rev(const shash_table_t *ht)
{
	shash_node_t *node;


	if (ht == NULL)
		return;


	node = ht->stail;


	printf("{");


	while (node)
	{
		printf("'%s': '%s'", node->key, node->value);


		if (node->sprev)
			printf(", ");


		node = node->sprev;
	}


	printf("}\n");
}


void shash_table_delete(shash_table_t *ht)
{
	shash_node_t *node;
	shash_node_t *tmp;


	if (ht == NULL)
		return;


	node = ht->shead;


	while (node)
	{
		tmp = node->snext;

		free(node->key);
		free(node->value);
		free(node);

		node = tmp;
	}


	free(ht->array);
	free(ht);
}
