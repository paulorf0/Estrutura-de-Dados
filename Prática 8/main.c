#include "lista.h"
#include <stdio.h>

int main() {
  Descritor lista;

  inicializarLista(&lista);
  printf("Lista inicializada.\n");

  adicionarNoInicio(&lista, 10);
  adicionarNoInicio(&lista, 20);
  adicionarNoInicio(&lista, 30);
  printf("Apos adicionar no inicio: ");
  exibirLista(&lista);
  printf("\n");

  adicionarNoFinal(&lista, 40);
  adicionarNoFinal(&lista, 50);
  printf("Apos adicionar no final: ");
  exibirLista(&lista);
  printf("\n");

  removerDoInicio(&lista);
  printf("Apos remover do inicio: ");
  exibirLista(&lista);
  printf("\n");

  removerDoFinal(&lista);
  printf("Apos remover do final: ");
  exibirLista(&lista);
  printf("\n");

  removerElemento(&lista, 20);
  printf("Apos remover o elemento 20: ");
  exibirLista(&lista);
  printf("\n");

  removerElemento(&lista, 100);
  printf("Apos tentar remover o elemento 100 (inexistente): ");
  exibirLista(&lista);
  printf("\n");

  removerDoInicio(&lista);
  removerDoInicio(&lista);
  printf("Apos remover todos os elementos: ");
  exibirLista(&lista);
  printf("\n");

  return 0;
}