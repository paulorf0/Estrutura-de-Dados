#include "lista.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
  int tamanho;
  No *no = criarListaVazia();
  no = valoresAleatorios(no);
  no = insereInicio(no, 190);
  printf("%d\n\n", listaVazia(no));

  percorrerLista(no);

  tamanho = tamanhoLista(no);
  printf("%d\n\n", tamanho);

  int *vec = criarVetor(no);

  //   for (int i = 0; i < tamanho; i++)
  //     printf("%d  ", *(vec + i));

  //   printf("\n\n");
  //   printf("\n%d\n\n", removerMaiorElemento(no));
  //   percorrerLista(no);
  no = removerValor(no, 190);
  percorrerLista(no);
  printf("\n\n");

  exibirMaiorElemento(no);
  printf("\n\n");

  no = removerMaiorElemento(no);
  percorrerLista(no);
  printf("\n\n");

  tamanho = tamanhoLista(no);
  printf("%d\n", tamanho);

  return 0;
}