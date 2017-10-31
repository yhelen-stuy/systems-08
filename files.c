#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <time.h>
#include <unistd.h>

void print_size(size_t file_size) {
    char str_size[100];
    size_t gb = 0;
    size_t mb = 0;
    size_t kb = 0;
    size_t b = file_size;
    kb = b / 1024;
    b %= 1024;
    mb = kb / 1024;
    kb %= 1024;
    gb = mb / 1024;
    mb %= 1024;
    sprintf(str_size, "%lu GB %lu MB %lu KB %lu B", gb, mb, kb, b);
    printf("size formatted: %s\n", str_size);
}

void print_mode(mode_t mode) {
    mode %= 01000;
    int other = mode % 010;
    mode /= 010;
    int group = mode % 010;
    mode /= 010;
    int user = mode % 010;
    mode /= 010;
    printf("%d %d %d\n", user, group, other);
}

int main() {
    struct stat sb;
    stat("README.md", &sb);

    printf("size: %lu\n", sb.st_size);
    printf("mode: %o\n", sb.st_mode);
    printf("size: %s\n", ctime(&(sb.st_atime)));
    print_size(sb.st_size);
    print_mode(sb.st_mode);
}
