#include "lista.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
  Lista *lista = criar_lista();
  lista = gerar_aleatorios(lista, 4);
  //   imprimir(lista);
  //   lista = remover_final(lista);
  //   imprimir(lista);
  lista = inserir_final(lista, 391);
  lista = inserir_final(lista, 182);
  imprimir(lista);
  lista = remover_valor(lista, 391);
  imprimir(lista);
  lista = inserir_final(lista, 10);
  imprimir(lista);
  lista = remover_inicio(lista);
  imprimir(lista);
  lista = inserir_inicio(lista, 10020);
  imprimir(lista);

  return 0;
}