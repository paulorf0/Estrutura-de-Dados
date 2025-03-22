#include "lista.h"
#include <stdio.h>
#include <stdlib.h>

void inicializarLista(Descritor *lista) {
  if (lista != NULL) {
    lista->fim = NULL;
    lista->inicio = NULL;
    lista->quantidade = 0;
  }
}
void adicionarNoInicio(Descritor *lista, int valor) {
  if (lista == NULL)
    return;

  No *no = (No *)malloc(sizeof(No));
  if (no == NULL)
    return;

  no->valor = valor;
  no->prox = lista->inicio;
  if (lista->inicio == NULL)
    lista->fim = no;

  lista->inicio = no;
  lista->quantidade++;
}
void adicionarNoFinal(Descritor *lista, int valor) {
  if (lista == NULL)
    return;

  No *no = (No *)malloc(sizeof(No));
  if (no == NULL)
    return;

  no->valor = valor;
  no->prox = NULL;

  if (lista->fim == NULL) {
    lista->inicio = no;
    lista->fim = no;
  } else {
    lista->fim->prox = no;
    lista->fim = no;
  }

  lista->quantidade++;
}
void removerDoInicio(Descritor *lista) {
  if (lista == NULL || lista->inicio == NULL)
    return;

  No *temp = lista->inicio;

  if (lista->inicio == lista->fim) {
    lista->inicio = NULL;
    lista->fim = NULL;
  } else {
    lista->inicio = temp->prox;
  }

  free(temp);
  lista->quantidade--;
}
void removerDoFinal(Descritor *lista) {
  if (lista == NULL || lista->fim == NULL)
    return;

  No *final = lista->fim;

  if (lista->inicio == lista->fim) {
    lista->inicio = NULL;
    lista->fim = NULL;
  } else {
    No *temp = lista->inicio;
    while (temp->prox != lista->fim)
      temp = temp->prox;

    lista->fim = temp;
    lista->fim->prox = NULL;
  }

  free(final);
  lista->quantidade--;
}
void removerElemento(Descritor *lista, int elemento) {
  if (lista == NULL || lista->inicio == NULL)
    return;

  No *temp = lista->inicio;
  No *anterior = NULL;

  while (temp != NULL && temp->valor != elemento) {
    anterior = temp;
    temp = temp->prox;
  }

  if (temp == NULL)
    return;

  if (anterior == NULL) {
    lista->inicio = temp->prox;
    if (lista->inicio == NULL)
      lista->fim = NULL;
  } else {
    anterior->prox = temp->prox;
    if (temp->prox == NULL)
      lista->fim = anterior;
  }

  free(temp);
  lista->quantidade--;
}
void exibirLista(Descritor *lista) {
  if (lista == NULL || lista->inicio == NULL) {
    printf("Sem elementos\n");
    return;
  }
  No *temp = lista->inicio;

  while (temp->prox != NULL) {
    printf("%d -> ", temp->valor);
    temp = temp->prox;
  }
  printf("%d", temp->valor);
}