#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
  char *p = malloc(20);
  strcpy(p, "hello, world\n");
  printf("%s", p);
  return 0;
}
