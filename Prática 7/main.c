#include "lista.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  No **l = (No **)malloc(sizeof(No *));

  criaListaVazia(l);
  ler_arquivo(l, "teste.txt");
  imprimeLista(*l);
  remover_duplicados(l);
  imprimeLista(*l);
  int t = tamanho_recursivo(*l, 0);
  printf("Tamanho por recursividade: %d\n", t);
  tamanho_it(*l);
  No *primos = copiar_palavras_primas(*l);
  imprimeLista(primos);
  return 0;
}
