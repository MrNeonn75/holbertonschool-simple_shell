#include "main.h"

/**
 * func_printenv - prints the current environment
 * @env: environment variable
 */
void func_printenv(char **env)
{
	int i = 0;

	for (; env[i] ; i++)
		_puts(env[i]);
}
