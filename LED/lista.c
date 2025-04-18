#include "lista.h"
#include <stdio.h>
#include <stdlib.h>

Lista *criar_lista() {
  Lista *lista = (Lista *)malloc(sizeof(Lista));
  if (lista != NULL) {
    lista->vago = 0; // NO INICIO A POSIÇÃO VAGA É O 0.
    lista->primeiro = -1;
    for (int i = 1; i < MAX - 1; i++)
      lista->led[i].prox = i; // PRÓXIMOS

    lista->led[MAX - 1].prox = -1; // FIM DE LISTA
  }

  return lista;
}

void liberar_lista(Lista *lista) { free(lista); }

Lista *inserir_inicio(Lista *lista, int n) {
  if (lista->vago == -1)
    return lista;

  int ptlivre = lista->vago;
  lista->vago = lista->led[ptlivre].prox;

  lista->led[ptlivre].valor = n;
  lista->led[ptlivre].prox = lista->primeiro;
  lista->primeiro = ptlivre;
}
Lista *inserir_final(Lista *lista, int n) {
  if (lista->vago == -1)
    return lista;

  int index = lista->primeiro;
  while(lista->led[index].prox != -1)
    index++;
    
  

}
Lista *remover_valor(Lista *lista, int n);
Lista *remover_inicio(Lista *lista);
Lista *remover_final(Lista *lista);
void imprimir(Lista *lista);

Lista *gerar_aleatorios(Lista *lista, int n);