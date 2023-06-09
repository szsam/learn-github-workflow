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

void pass_by_reference(int *x) {
  *x = 2;
}

void test_unintialize_local() {
  int x;
  int y = 1;
  int z;

  pass_by_reference(&z);

  printf("%d %d %d\n", x, y, z);
}

void test_unintialize_local_path_sensitive() {
  int ret = rand() % 2;
  int x;
  int y;
  int z;

  if (ret == 0) {
    y = 1;
    pass_by_reference(&z);
  }

  if (ret == 0) {
    printf("%d %d %d\n", x, y, z);
  }
}

int main()
{
  /* FIXME: fix me!*/
  char *p = f("hello, world\n");
  printf("%s", p);
  free(p);
  printf("%s", p);
  test_unintialize_local();
  test_unintialize_local_path_sensitive();
  return 0;
}
