#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>

void func_ls() {
    DIR *dir;
    struct dirent *entry;

    if ((dir = opendir(".")) == NULL) {
        perror("opendir");
        exit(EXIT_FAILURE);
    }

    while ((entry = readdir(dir)) != NULL) {
        printf("%s\n", entry->d_name);
    }

    closedir(dir);
}
