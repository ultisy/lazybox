#include <stdio.h>
#include <stdlib.h>

void func_rm(int argc, char *argv[]) {
    if (argc < 3) {
        fprintf(stderr, "Usage: %s rm <file1> [file2 file3 ...]\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    for (int i = 2; i < argc; i++) {
        if (remove(argv[i]) != 0) {
            perror("remove");
            exit(EXIT_FAILURE);
        }
    }
}
