#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void test_null_check() {
    char *p = malloc(100);
    char *q = calloc(100, 2);
    free(p);
    free(q);
}

char *f(char *s) {
  char *buf = malloc(80);
  strcpy(buf, "s: ");
  strcat(buf, s);
  return buf;
}

void overflow_check(long a, size_t b) {
  if (a + b > a) {
    printf("overflow!");
  }
}

int main()
{
  /* FIXME: fix me!*/
  char *p = f("hello, world\n");
  printf("%s", p);
  free(p);
  printf("%s", p);
  return 0;
}
