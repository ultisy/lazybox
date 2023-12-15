#include <stdio.h>
#include <stdlib.h>

#define BUFFER_SIZE 4096

void catFile(char *filename) {
    FILE *file = fopen(filename, "r");

    if (file == NULL) {
        perror("fopen");
        exit(EXIT_FAILURE);
    }

    char buffer[BUFFER_SIZE];
    size_t bytesRead;

    while ((bytesRead = fread(buffer, 1, sizeof(buffer), file)) > 0) {
        fwrite(buffer, 1, bytesRead, stdout);
    }

    fclose(file);
}
