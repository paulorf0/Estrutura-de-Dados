#include "pilha.h"
#include <stdlib.h>
#include <string.h>

pilha *clear(pilha *h) {
  if (h == NULL)
    return NULL;

  pilha *temp = h;
  pilha *toFree = NULL;
  while (temp != NULL) {
    toFree = temp;
    temp = temp->prox;
    free(toFree);
  }

  return h;
}
int isEmpty(pilha *h) {
  if (h == NULL)
    return 1;

  return 0;
}
pilha *push(pilha *h, char el) {
  pilha *obj = (pilha *)malloc(sizeof(pilha));
  obj->delimitador = el;
  obj->prox = NULL;

  if (h == NULL)
    return obj;

  obj->prox = h;
  return obj;
}
char pop(pilha **h) {
  if (h == NULL)
    return '.';

  char el = (*h)->delimitador;

  pilha *temp = (*h);
  (*h) = (*h)->prox;
  free(temp);

  return el;
}
char topEl(pilha *h) { return h->delimitador; }