#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define MAX_ARGS 64

/* --------- GETLINE --------- */

char *_getline(void);

/* --------- STRTOK --------- */

char **_strtok(char *line);

#endif
