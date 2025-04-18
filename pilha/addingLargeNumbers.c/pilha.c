#include "pilha.h"
#include <stdlib.h>
#include <string.h>

void clear(pilha *h) {
  if (h == NULL)
    return;

  pilha *temp = h;
  pilha *toFree = NULL;
  while (temp != NULL) {
    toFree = temp;
    temp = temp->prox;
    free(toFree);
  }
}
int isEmpty(pilha *h) {
  if (h == NULL)
    return 1;

  return 0;
}
pilha *push(pilha *h, int el) {
  pilha *obj = (pilha *)malloc(sizeof(pilha));
  obj->num = el;
  obj->prox = NULL;

  if (h == NULL)
    return obj;

  obj->prox = h;
  return obj;
}
int pop(pilha **h) {
  if (*h == NULL)
    return 0;

  int el = (*h)->num;

  pilha *temp = (*h);
  (*h) = (*h)->prox;
  free(temp);

  return el;
}

int size(pilha *h) {
  pilha *temp = h;
  int size = 0;
  while (temp != NULL) {
    size++;
    temp = temp->prox;
  }
  return size;
}

int *topEl(pilha *h) { return &(h->num); }