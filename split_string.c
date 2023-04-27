#include <string.h>
#include <stdlib.h>
#include "shell.h"

void split_string(char **argv, char *lineptr, const char *delim) {
    // Allocate memory for a copy of lineptr
    char *lineptr_copy = safe_malloc(sizeof(char) * strlen(lineptr) + 1);
    strcpy(lineptr_copy, lineptr);

    // Count the number of tokens in lineptr
    int num_tokens = count_tokens(lineptr, delim);

    // Split lineptr into an array of tokens
    char *token = strtok(lineptr_copy, delim);
    for (int i = 0; token != NULL; i++) {
        argv[i] = safe_malloc(sizeof(char) * strlen(token) + 1);
        strcpy(argv[i], token);
        token = strtok(NULL, delim);
    }
    argv[num_tokens] = NULL;

    // Free the memory allocated for lineptr_copy
    free(lineptr_copy);
}

