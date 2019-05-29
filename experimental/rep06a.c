#include <stdio.h>
#include <string.h>

#define DEFAULT_SEPARATOR ':'
#define N 256

void usage(void) {
  fputs("Usage: rep06a [-cX] [-] [FILENAME1] [FILENAME2]...\n", stderr);
}

void print_rest_of_file(FILE *fin, FILE *fout) {
  char buffer[N];
  char *r;

  r = fgets(buffer, N, fin);
  while (r) {
    fputs(buffer, fout);
    r = fgets(buffer, N, fin);
  }
}

void process(FILE *fin, int separator) {
  char buffer[N];
  char *r;

  r = fgets(buffer, N, fin);
  while (r) {
    const char *p;

    p = strchr(buffer, separator);
    if (p && *p != '\0') {
      fputs(p, stdout);
      print_rest_of_file(fin, stdout);
      r = NULL;
    }
    else {
      r = fgets(buffer, N, fin);
    }
  }
}

int main(int argc, const char *const *argv) {
  int separator = DEFAULT_SEPARATOR;

  if (argc == 1) {
    usage();
    return 0;
  }
  while (--argc > 0) {
    ++argv;
    if ((*argv)[0] == '-') {
      switch ((*argv)[1]) {
        case '\0':
          process(stdin, separator);
          break;
        case 'c':
          if ((*argv)[2] != '\0') {
            separator = (*argv)[2];
          }
          else {
            fprintf(stderr, "Warning: separator is not given.\n");
          }
          break;
        case 'h':
        case 'H':
        case '?':
          usage();
          break;
        default:
          fprintf(stderr, "Waring: unknown parameter: %s\n", *argv);
          break;
      }
    }
    else {
      FILE *fin;

      fin = fopen(*argv, "r");
      if (fin) {
        process(fin, separator);
        fclose(fin);
      }
      else {
        fprintf(stderr, "Warning: cannot open: %s\n", *argv);
      }
    }
  }
  return 0;
}
