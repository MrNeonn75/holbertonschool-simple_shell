#include "main.h"
/**
 * line_div - Splits given string into parts.
 * @cmd: The command string to parse.
 * @arr: An array of strings to store the arguments.
 * Return: modified char array.
 */
char **line_div(char *cmd, char **arr)
{
	char *token;
	int i = 0;

	token = strtok(cmd, " \n\t");
	while (token != NULL && i < 63)
	{
		arr[i++] = token;
		token = strtok(NULL, " \n\t");
	}
	arr[i++] = NULL;
	return (arr);
}
