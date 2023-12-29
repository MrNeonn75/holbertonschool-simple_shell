#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    int i;

    /* Print argc parametr. */
    printf("argc: %d\n", argc);

    /* Print argv parametr. */
    for (i = 0; argv[i]; i++) {
        printf("argv[%d]: %s\n", i, argv[i]);
    }

    return 0;
}