#include <stdio.h>
#include <stdlib.h>

int main() {
  int v[] = {1, 2, 9, 10, 12};
  int n = sizeof(v) / sizeof(v[0]);

  int valor = 0;
  int *buf = (int *)malloc(sizeof(int) * (n + 1));

  int j = 0;
  for (int i = 0, inserted = 0; i < n;
       i++) { // i = 0, ..., n-1, n de "tamanho". For executado n vezes
    if (!inserted && v[i] > valor) { // if executado n-1 vezes
      buf[j++] = valor; // Executado 1 vez
      inserted = 1;     // Executado 1 vez
    }

    buf[j++] = v[i]; // Executado n-1 vezes

    // T(n) = c_1*n + c_2*(n-1) + c_3*(n-1) = O(n)
  }

  for (int i = 0; i < n + 1; i++)
    printf("%d  ", buf[i]);

  return 0;
}