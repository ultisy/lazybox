#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void func_ls();
void func_cp(int argc, char *argv[]);
void func_mv(int argc, char *argv[]);
void func_rm(int argc, char *argv[]);
void catFile(char *filename);
void grepFile(char *filename, char *pattern);

int main(int argc, char *argv[]) {
    if (argc < 3) {
        fprintf(stderr, "Usage:\n");
        fprintf(stderr, "    %s ls\n", argv[0]);
        fprintf(stderr, "    %s cp <source_file> <destination_file>\n", argv[0]);
        fprintf(stderr, "    %s mv <source_path> <destination_path>\n", argv[0]);
        fprintf(stderr, "    %s rm <file1> [file2 file3 ...]\n", argv[0]);
        fprintf(stderr, "    %s cat <file1> [file2 file3 ...]\n", argv[0]);
        fprintf(stderr, "    %s grep <pattern> <file>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    char *command = argv[1];

    if (strcmp(command, "ls") == 0) {
        func_ls();
    } else if (strcmp(command, "cp") == 0) {
        func_cp(argc, argv);
    } else if (strcmp(command, "mv") == 0) {
        func_mv(argc, argv);
    } else if (strcmp(command, "rm") == 0) {
        func_rm(argc, argv);
    } else if (strcmp(command, "cat") == 0) {
        for (int i = 2; i < argc; i++) {
            catFile(argv[i]);
        }
    } else if (strcmp(command, "grep") == 0) {
        if (argc != 4) {
            fprintf(stderr, "Usage: %s grep <pattern> <file>\n", argv[0]);
            exit(EXIT_FAILURE);
        }

        char *pattern = argv[2];
        char *filename = argv[3];
        grepFile(filename, pattern);
    } else {
        fprintf(stderr, "Unknown command: %s\n", command);
        exit(EXIT_FAILURE);
    }

    return EXIT_SUCCESS;
}