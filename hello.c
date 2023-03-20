#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *f(char *s) {
  char *buf = malloc(80);
  strcpy(buf, "s: ");
  strcat(buf, s);
  return buf;
}

int main()
{
  /* FIXME: fix me!*/
  char *p = f("hello, world\n");
  printf("%s", p);
  return 0;
}
