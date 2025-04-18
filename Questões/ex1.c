// Retornar maior e menor valor de um vetor.

void maior_menor(int *v, int tam, int *maior, int *menor) {
  int maior_ = v[0];
  int menor_ = v[0];
  for (int i = 0; i < tam; i++) {
    // Note que não é possível que v[i] > maior e v[i] < menor
    if (*(v + i) > maior_)
      maior_ = *(v + i);
    if (*(v + i) < menor_)
      menor_ = *(v + i);
  }
  *maior = maior_;
  *menor = menor_;
}