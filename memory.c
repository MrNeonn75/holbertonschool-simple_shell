#include "main.h"

/**
 *_calloc -allocated memoria for nmeb elemn de zise bytes
 *@num: number of element in the array
 *@size: bytes for each position in the array
 *Return: pointer void
 */
void *_calloc(unsigned int num, unsigned int size)
{
	char *p;
	unsigned int i;

	if (num == 0 || size == 0)
		return (NULL);

	p = malloc(num * size);
	if (p == NULL)
		return (NULL);

	for (i = 0; i < num * size; i++)
		p[i] = 0;

	return (p);

}
