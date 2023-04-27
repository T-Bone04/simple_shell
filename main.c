#include "shell.h"
#include <stdio.h>  /* for printf(), perror(), and stdin */
#include <stdlib.h> /* for malloc() and free() */
#include <string.h> /* for strtok(), strcpy(), and strlen() */


/* Print the shell prompt */
void print_prompt(char *prompt) {
    printf("%s", prompt);
}

/* Read user input from stdin */
int read_input(char **lineptr, size_t *n) {
    return getline(lineptr, n, stdin);
}

/* Exit the shell */
void exit_shell() {
    printf("Exiting shell.....\n");
    exit(EXIT_FAILURE);
}

/* Safely allocate memory */
void *safe_malloc(size_t size) {
    void *ptr = malloc(size);
    if (ptr == NULL) {
        perror("tsh: memory allocation error");
        exit(EXIT_FAILURE);
    }
    return ptr;
}

/* Count the number of tokens in a string */
int count_tokens(char *str, const char *delim) {
    int count = 0;
    char *token = strtok(str, delim);
    while (token != NULL) {
        count++;
        token = strtok(NULL, delim);
    }
    return count;
}

/* Split a string into an array of tokens */
void split_string(char **argv, char *lineptr, const char *delim) {
    /* Allocate memory for a copy of lineptr */
    char *lineptr_copy = safe_malloc(sizeof(char) * strlen(lineptr) + 1);
    strcpy(lineptr_copy, lineptr);

    /* Count the number of tokens in lineptr */
    int num_tokens = count_tokens(lineptr, delim);

    /* Split lineptr into an array of tokens */
    char *token = strtok(lineptr_copy, delim);
    for (int i = 0; token != NULL; i++) {
        argv[i] = safe_malloc(sizeof(char) * strlen(token) + 1);
        strcpy(argv[i], token);
        token = strtok(NULL, delim);
    }
    argv[num_tokens] = NULL;

    /* Free the memory allocated for lineptr_copy */
    free(lineptr_copy);
}

/* Execute a command */
void execute_command(char **argv) {
    /* TODO: Implement the logic for executing a command */
}

/* Main function */
int main(int argc, char **argv) {
    char *prompt = "shell$ ";
    char *lineptr = NULL;
    size_t n = 0;
    ssize_t nchars_read;
    const char *delim = " \n";

    /* Ignore unused argc */
    (void)argc;

    /* Loop indefinitely */
    while (1) {
        /* Print the shell prompt */
        print_prompt(prompt);

        /* Read user input from stdin */
        nchars_read = read_input(&lineptr, &n);

        /* Check for end-of-file or error */
        if (nchars_read == -1) {
            exit_shell();
        }

        /* Split the user input into an array of tokens */
        char **argv = safe_malloc(sizeof(char *) * (count_tokens(lineptr, delim) + 1));
        split_string(argv, lineptr, delim);

        /* Execute the command */
        execute_command(argv);

        /* Free the memory allocated for argv and lineptr */
        for (int i = 0; argv[i] != NULL; i++) {
            free(argv[i]);
        }
        free(argv);
        free(lineptr);
    }

    return 0;
}

