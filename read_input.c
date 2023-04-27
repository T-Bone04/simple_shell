#include <stdio.h>
#include <stdlib.h>
#include "shell.h"

int read_input(char **lineptr, size_t *n) {
    return getline(lineptr, n, stdin);
}

