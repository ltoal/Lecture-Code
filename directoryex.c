#include <stdio.h>
#include <dirent.h>

int main(int argc, char ** argv) {
    struct dirent *entry;
    DIR *d = opendir(argv[1]);

    if (d == NULL) {
        printf("couldn't open directory");
        return 0;
    }

    while ((entry = readdir(d)) != 0) {
        printf("%s\n", entry->d_name);
        //do something to your files here
    }
    closedir(d);
    return 0;
}
