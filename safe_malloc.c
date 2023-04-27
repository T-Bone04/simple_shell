#include <stdio.h>
#include <stdlib.h>
#include "shell.h"

void *safe_malloc(size_t size) {
    void *ptr = malloc(size);
    if (ptr == NULL) {
        perror("tsh: memory allocation error");
        exit(EXIT_FAILURE);
    }
    return ptr;
}

