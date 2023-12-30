#include "main.h"
/**
 * main - Main function.
 * Return: status
 */
int main(void)
{
	char *cmd;
	int status;

	while (1)
	{
		if (isatty(STDIN_FILENO))
			printf("$ ");
		cmd = _getline();
		if (cmd == NULL)
			break;
		if (strcmp(cmd, "exit") == 0)
		{
			free(cmd);
			exit(0);
		}
		status = execute(cmd);
		if (status == 2)
		{
			exit(2);
		}
	}
	return (status);
}
