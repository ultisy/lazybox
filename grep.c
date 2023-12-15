#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 4096

void grepFile(char *filename, char *pattern) {
    FILE *file = fopen(filename, "r");

    if (file == NULL) {
        perror("fopen");
        exit(EXIT_FAILURE);
    }

    char buffer[BUFFER_SIZE];

    while (fgets(buffer, sizeof(buffer), file) != NULL) {
        if (strstr(buffer, pattern) != NULL) {
            printf("%s", buffer);
        }
    }

    fclose(file);
}
