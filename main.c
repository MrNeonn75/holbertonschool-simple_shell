#include "main.h"

int main() {
    char *line;
    char **tokens;
    pid_t p;

    while (1) {
        p = fork();

        if (p < 0) {
            perror("Fork fail");
            exit(EXIT_FAILURE);
        } else if (p == 0) {
            /* Child process */
            line = _getline();
            if (line == NULL) {
                /* Handle case where _getline returns NULL (EOF or empty line) */
                exit(EXIT_SUCCESS); /* Exit the child process gracefully */
            }

            tokens = _strtok(line);

            if (tokens == NULL || tokens[0] == NULL) {
                fprintf(stderr, "Tokenization error\n");
                exit(EXIT_FAILURE);
            }

            /* Execute the command in the child process */
            if (execvp(tokens[0], tokens) == -1) {
                perror("The command not found");
                exit(EXIT_FAILURE);
            }
        } else {
            /* Parent process */
            int status;
            waitpid(p, &status, 0);

            /* Check if the child process terminated normally */
            if (WIFEXITED(status) && WEXITSTATUS(status) != 0) {
                fprintf(stderr, "Child process exited with non-zero status: %d\n", WEXITSTATUS(status));
            }

            /* Free allocated memory in the parent process */
            
            
        }
    }

    return 0;
}
