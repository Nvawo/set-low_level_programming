#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * main - generates key for crackme5
 * @argc: argument count
 * @argv: argument vector
 *
 * Return: 0 on success
 */
int main(int argc, char **argv)
{
	int i, len, sum = 0;
	char *username;

	if (argc != 2)
		return (1);

	username = argv[1];
	len = strlen(username);

	for (i = 0; i < len; i++)
		sum += username[i];

	/* simple deterministic key */
	printf("%d%d%d\n",
		(sum % 90) + 10,
		(len * 7) % 90,
		(sum % len) + 33);

	return (0);
}
