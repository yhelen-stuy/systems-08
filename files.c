#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <time.h>
#include <unistd.h>
#include <string.h>

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

char * mode_to_string (int i, char * buff) {

  char *temp = (char *)malloc(sizeof(char));
  if (i == 0) {
    strcpy(buff, "---");
    //return "---";
  }
  if (i == 1) {
    strcpy(buff, "--x");
      //      return "--x";
  }
  else if (i == 2) {
    //    return "-w-";
    strcpy(buff, "-w-");
  }
  else if (i == 3) {
    //return "-wx";
    strcpy(buff, "-wx");
  }
  else if (i == 4) {
    //return "r--";
    strcpy(buff, "r--");
  }
  else if (i == 5) {
    //return "r-x";
    strcpy(buff, "r-x");
  }
  else if (i == 6) {
    //return "rw-";
    strcpy(buff, "rw-");
  }
  else {
    //return "rwx";
    strcpy(buff, "rwx");
  }
  return buff;

}

void print_mode(mode_t mode) {
    mode %= 01000;
    int other = mode % 010;
    mode /= 010;
    int group = mode % 010;
    mode /= 010;
    int user = mode % 010;
    mode /= 010;
    char temp1[250] = "";
    char temp2[250] = "";
    char temp3[250] = "";
    printf("%d%d%d\n", user, group, other);
    printf("%s%s%s\n", mode_to_string(user, temp1), mode_to_string(group, temp2), mode_to_string(other, temp3));
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
