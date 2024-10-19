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

void switch_cases(const char *data) {
	float a, b, c;

	switch (sscanf(data, "%f %f %f", &a, &b, &c)) {
		case 2:
			use(a); // GOOD
			use(b); // GOOD
			break;
		case 3:
			use(a); // GOOD
			use(b); // GOOD
			use(c); // GOOD
			break;
		default:
			break;
	}

	float d, e, f;

	switch (sscanf(data, "%f %f %f", &d, &e, &f)) {
		case 2:
			use(d); // GOOD
			use(e); // GOOD
			use(f); // BAD
			break;
		case 3:
			use(d); // GOOD
			use(e); // GOOD
			use(f); // GOOD
			break;
		default:
			break;
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
