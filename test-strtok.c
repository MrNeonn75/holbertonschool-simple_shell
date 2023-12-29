#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int get_number_word(char *str) {
    int i = 0; 
    int count = 1;

    while (str[i]) {
        if (str[i] == ' ')
            count++;

        i++;
    }

    return (count);
}

int main(void) {
    char str[] = "MrNeonn was here";
    char *delim = " ";
    char *token;
    int i = 0;
    int number_word = get_number_word(str);
    char *command[number_word];

    token = strtok(str, delim);

    while (token != NULL) {
        printf("%s\n", token);
        command[i] = strdup(token);
        token = strtok(NULL, delim);
        i++;
    }
    
    printf("---------------------------\n");

    for (i = 0; i < number_word; i++) {
        printf("%s\n", command[i]);
        free(command[i]);
    }

}