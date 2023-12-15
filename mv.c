#include <stdio.h>
#include <stdlib.h>

void func_mv(int argc, char *argv[]) {
    if (argc != 4) {
        fprintf(stderr, "Usage: %s mv <source_path> <destination_path>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    if (rename(argv[2], argv[3]) == -1) {
        perror("rename");
        exit(EXIT_FAILURE);
    }

    printf("File moved successfully.\n");
}
