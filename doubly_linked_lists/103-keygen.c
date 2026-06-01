#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * main - generates valid key for crackme5
 * @argc: argument count
 * @argv: argument vector
 *
 * Return: 0 on success
 */
int main(int argc, char **argv)
{
	int i = 0;
	unsigned long int key = 0;
	char *username;

	if (argc != 2)
		return (1);

	username = argv[1];

	while (username[i])
	{
		key += (username[i] ^ (i + 1)) + username[i];
		i++;
	}

	printf("%lu\n", key);

	return (0);
}
