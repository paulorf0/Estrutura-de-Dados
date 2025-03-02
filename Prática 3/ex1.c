#include <stdio.h>
#include <stdlib.h>

int main() {
  int p = 1;
  char l = 'p';
  float f = 1.5f;
  int *p_ = &p;
  char *l_ = &l;
  float *f_ = &f;

  *p_ = 2;
  *l_ = 'a';
  *f_ = 0.4f;

  printf("%d, %f, %c\n", p, f, l);
  p = 10;
  f = 15.2f;
  l = 'm';
  printf("%d, %f, %c\n", *p_, *f_, *l_);
  printf("%p, %p, %p\n", p_, f_, l_);

  return 0;
}