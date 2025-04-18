#include <stdio.h>
#include <stdlib.h>

// Definição da estrutura Nó para encadeamento de inteiros
struct no {
  int item;
  struct no *prox;
};

// Definição do tipo No
typedef struct no No;

// Função para criar uma lista vazia
No *criaListaVazia() { return NULL; }

// Função para inserir um elemento na lista
No *insereInicio(No *l, int elem) {
  No *novo;
  novo = (No *)malloc(sizeof(No));
  if (novo == NULL)
    return novo;

  novo->item = elem;
  novo->prox = l;
  return novo;
}

int main() {
  No *lnum; // lista de números com encadeamento de nós
  int val;
  lnum = criaListaVazia();
  for (int i = 0; i < 10; i++) { //  inserir 10 elementos
    scanf("%d", &val);
    lnum = insereInicio(lnum, val);
  }
}