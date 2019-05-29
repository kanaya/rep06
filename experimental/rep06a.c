#include <stdio.h>
#include <stdlib.h>

#define N 256

void usage(void) {
  fputs("Usage: rep06a [-cX] [-] [FILENAME1] [FILENAME2]...\n", stderr);
}

const char *find_separator(const char *buffer, int separator) {
  if (!buffer) {
    return NULL;
  }
  while (*buffer != '\0') {
    if (*buffer == separator) {
      return buffer;
    }
    else {
      ++buffer;
    }
  }
  return NULL;
}

void print_rest_of_file(FILE *in) {
  char buffer[N];
  char *r;

  r = fgets(buffer, N, in);
  if (r) {
    fputs(buffer, stdout);
    print_rest_of_file(in);
  }
}

void process(FILE *in, int separator) {
  char buffer[N];
  char *r;

  r = fgets(buffer, N, in);
  if (r) {
    const char *p;

    p = find_separator(buffer, separator);
    if (p) {
      fputs(p, stdout);
      print_rest_of_file(in);
    }
    else {
      process(in, separator);
    }
  }
}

int main(int argc, const char *const *argv) {
  FILE *in;
  int separator = ':';

  while (--argc > 0) {
    ++argv;
    if ((*argv)[0] == '-') {
      switch ((*argv)[1]) {
        case '\0':
          in = stdin;
          process(in, separator);
          break;
        case 'c':
          if ((*argv)[2] != '\0') {
            separator = (*argv)[2];
          }
          break;
        case 'h':
        case 'H':
        case '?':
          usage();
          exit(0);
          break;
        default:
          break;
      }
    }
    else {
      in = fopen(*argv, "r");
      if (in) {
        process(in, separator);
        fclose(in);
      }
    }
  }
  return 0;
}
