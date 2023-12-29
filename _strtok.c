#include "main.h"

/**
 * _strtok - Tokenize a string into an array of tokens.
 * @line: The input string to be tokenized.
 * Return: An array of tokens.
 */
char **_strtok(char *line) {
    char **tokens = malloc(MAX_ARGS * sizeof(char *));
    size_t token_count = 0;
    char *token;

    if (tokens == NULL) {
        perror("malloc");
        exit(EXIT_FAILURE);
    }

    token = strtok(line, " \t\n");
    while (token != NULL && token_count < MAX_ARGS - 1) {
        tokens[token_count++] = strdup(token);
        if (tokens[token_count - 1] == NULL) {
            perror("strdup");
            exit(EXIT_FAILURE);
        }
        token = strtok(NULL, " \t\n");
    }

    tokens[token_count] = NULL; /* Ensure the last element is NULL */

    return tokens;
}
