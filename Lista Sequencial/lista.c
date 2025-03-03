#include "lista.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/////////////////// Uso privado ///////////////////
Dados criar_struct(int n) {
  Dados dado;
  dado.valor = n;
  return dado;
}

Lista *criar_lista() {
  Lista *lista = (Lista *)malloc(sizeof(Lista));
  if (lista != NULL)
    lista->tamanho = 0;

  return lista;
}

void liberar_lista(Lista *lista) { free(lista); }

Lista *inserir_inicio(Lista *lista, int n) {

  for (int i = lista->tamanho; i > 0; i--)
    lista->info[i] = lista->info[i - 1];
  lista->info[0] = criar_struct(n);
  lista->tamanho++;
  return lista;
}
Lista *inserir_final(Lista *lista, int n) {
  if (lista->tamanho < MAX)
    lista->info[lista->tamanho++] = criar_struct(n);

  return lista;
}
Lista *remover_valor(Lista *lista, int n) {
  int index;

  for (int i = 0; i < lista->tamanho; i++)
    if (lista->info[i].valor == n) {
      index = i;
      break;
    }

  for (int i = index; i < lista->tamanho - 1; i++)
    lista->info[i] = lista->info[i + 1];
  lista->tamanho--;

  return lista;
}
Lista *remover_inicio(Lista *lista) {
  for (int i = 0; i < lista->tamanho - 1; i++)
    lista->info[i] = lista->info[i + 1];
  lista->tamanho--;
  return lista;
}
Lista *remover_final(Lista *lista) {
  lista->tamanho--;
  return lista;
}
void imprimir(Lista *lista) {
  for (int i = 0; i < lista->tamanho; i++)
    printf("%d ", lista->info[i].valor);
  printf("\n");
}
Lista *gerar_aleatorios(Lista *lista, int n) {
  if (n > 100)
    return NULL;

  srand(time(NULL));

  for (int i = 0; i < n; i++)
    lista->info[i] = criar_struct(rand() % 100);
  lista->tamanho = n;
  return lista;
}
