#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>

#define BUF_SIZE 4096

void func_cp(int argc, char *argv[]) {
    if (argc != 4) {
        fprintf(stderr, "Usage: %s cp <source_file> <destination_file>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    char buffer[BUF_SIZE];
    ssize_t bytesRead, bytesWritten;

    int sourceFd = open(argv[2], O_RDONLY);
    if (sourceFd == -1) {
        perror("open source file");
        exit(EXIT_FAILURE);
    }

    int destFd = open(argv[3], O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
    if (destFd == -1) {
        perror("open destination file");
        close(sourceFd);
        exit(EXIT_FAILURE);
    }

    while ((bytesRead = read(sourceFd, buffer, BUF_SIZE)) > 0) {
        bytesWritten = write(destFd, buffer, bytesRead);
        if (bytesWritten != bytesRead) {
            perror("write to destination file");
            close(sourceFd);
            close(destFd);
            exit(EXIT_FAILURE);
        }
    }

    if (bytesRead == -1) {
        perror("read from source file");
        close(sourceFd);
        close(destFd);
        exit(EXIT_FAILURE);
    }

    if (close(sourceFd) == -1 || close(destFd) == -1) {
        perror("close file descriptor");
        exit(EXIT_FAILURE);
    }

    printf("File copied successfully.\n");
}
