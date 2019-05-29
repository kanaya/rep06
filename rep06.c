#include <stdio.h>

int main(void) {
  char str[100];
  char *p;

  fgets(&str[0], 100, stdin);
  p = &str[0];
  while (*p != '\0' && *p != 'c') {
    ++p;
  }
  if (*p != '\0') {
    fputs(p, stdout);
  }
  else {
    printf("Not found.\n");
  }
  return 0;
}
