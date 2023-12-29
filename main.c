#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define MAX_ARGS 64

int main() {
    char *input_data = NULL;
    size_t input_size = 0;

    while (1) {
        char *args[MAX_ARGS];
        size_t arg_count = 0;
        pid_t pid;

        char *token;

        printf("%c ", '$');

        /* Read input */
        if (getline(&input_data, &input_size, stdin) == -1) {
            exit(EXIT_FAILURE);
        }

        /* Remove the newline character from input_data */
        input_data[strcspn(input_data, "\n")] = '\0';

        /* Tokenize input into arguments */
        token = strtok(input_data, " ");
        
        while (token != NULL && arg_count < MAX_ARGS - 1) {
            args[arg_count++] = strdup(token);
            token = strtok(NULL, " ");
        }

        args[arg_count] = NULL; /* Ensure the last element is NULL */

        /* Fork and execute command */
        pid = fork();

        if (pid < 0) {
            perror("Fork fail");
            exit(EXIT_FAILURE);
        } else if (pid == 0) {
            /* Child process */
            if (execvp(args[0], args) == -1) {
                perror("Command execution failed");
                exit(EXIT_FAILURE);
            }
        } else {
            /* Parent process */
            wait(NULL);

            /* Free memory allocated for arguments */
            for (size_t i = 0; i < arg_count; i++) {
                free(args[i]);
            }

            /* Free memory allocated for input_data */
            free(input_data);
        }
    }

    return 0;
}
