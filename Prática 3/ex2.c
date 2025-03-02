#include <stdio.h>
#include <stdlib.h>

int main() {
  int p = 1;
  int q = 2;

  printf("%p, %p, %p", &p, &q, &p > &q ? &p : &q);
  return 0;
}