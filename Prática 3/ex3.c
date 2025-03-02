#include <stdio.h>
#include <stdlib.h>

int main() {
  int p;
  int q;
  scanf("%d %d", &p, &q);

  printf("%p, %p, %p", &p, &q, &p > &q ? &p : &q);
  return 0;
}