#include <stdio.h>
#include <stdlib.h>

int split(int A[], int p, int r) {
  if (p >= r)
    return 1;

  int metade = (p + r) / 2;

  if (A[metade] > A[metade + 1])
    return 0; // Desordem

  int esquerda = split(A, p, metade);
  int direita = split(A, metade + 1, r);

  return esquerda && direita;
}

int main() {
  //   int v[] = {1, 2, 3, 4, 5};
  int v[] = {1, 2, 3, 9, 8};
  int n = sizeof(v) / sizeof(v[0]);
  int ordenado = 1;
  // i = 0, ..., n-2 -> n-1 iterações
  for (int i = 0; i < n - 1;
       i++) // Executa t_j+1 iterações, t_j dependendo da estrutura do vetor
    if (v[i] > v[i + 1]) { // tj iterações
      ordenado = 0;
      break;
    }
  // Pior caso é t_j = n-2, que implica a execução de t_j = n-1 iterações do if.
  // Melhor caso é t_j = 1, que é a execução do for pela primeira vez e já
  // verificar a desordem.
  // Algoritmo O(n), linear

  if (ordenado)
    printf("Ordenado (Linear)\n");
  else
    printf("Nao ordenado (Linear)\n");

  if (split(v, 0, n - 1))
    printf("Ordenado (Dividir-Conquistar)\n");
  else
    printf("Nao ordenado (Dividir-Conquistar)\n");

  return 0;
}