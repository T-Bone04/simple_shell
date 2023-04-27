#include <string.h>
#include "shell.h"

int count_tokens(char *str, const char *delim) {
    int count = 0;
    char *token = strtok(str, delim);
    while (token != NULL) {
        count++;
        token = strtok(NULL, delim);
    }
    return count;
}

