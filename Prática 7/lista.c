#include "lista.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//////////////////////////////////// Uso privado
int isPrime(int n) {
  if (n < 2)
    return 0;
  for (int i = 2; i * i <= n; i++) {
    if (n % i == 0)
      return 0;
  }
  return 1;
}

/////////////////////////////////////////

void criaListaVazia(No **l) { *l = NULL; }

void insereNoFim(No **l, const char *palavra) {
  No *novo = (No *)malloc(sizeof(No));
  if (novo == NULL) {
    printf("Erro na alocação de memória!\n");
    exit(1);
  }
  strncpy(novo->palavra, palavra, TAM);
  novo->palavra[TAM - 1] = '\0';
  novo->prox = NULL;

  if (*l == NULL) {
    *l = novo;
  } else {
    No *aux = *l;
    while (aux->prox != NULL)
      aux = aux->prox;
    aux->prox = novo;
  }
}

void ler_arquivo(No **l, char *path) {
  FILE *arqfrases;
  char frase[1000];
  int tam;
  char *palavras;

  arqfrases = fopen(path, "r");
  if (arqfrases == NULL) {
    printf("Erro ao abrir o arquivo!\n");
    return;
  }

  while (fscanf(arqfrases, "%[^\n]\n", frase) != EOF) {
    tam = strlen(frase);
    palavras = strtok(frase, " .,!?"); // separar as palavras
    while (palavras != NULL) {
      insereNoFim(l, palavras);
      palavras = strtok(NULL, " .,!?");
    }
  }

  fclose(arqfrases);
}

void imprimeLista(No *l) {
  if (l == NULL) {
    printf("Lista vazia.\n");
    return;
  }
  while (l != NULL) {
    printf("%s", l->palavra);
    if (l->prox != NULL) {
      printf(" -> ");
    }
    l = l->prox;
  }
  printf("\n");
}

void remover_duplicados(No **l) {
  No *h = *l;
  while (h != NULL && h->prox != NULL) {
    No *temp = h;
    No *ant = h;
    while (ant->prox != NULL) {
      temp = ant->prox;

      if (strcmp(h->palavra, temp->palavra) == 0) {
        ant->prox = temp->prox;
        free(temp);
      } else
        ant = ant->prox;
    }
    h = h->prox;
  }
}

No *copiar_palavras_primas(No *l) {
  No *novaLista;
  criaListaVazia(&novaLista);
  while (l != NULL) {
    int len = strlen(l->palavra);
    if (isPrime(len)) {
      insereNoFim(&novaLista, l->palavra);
    }
    l = l->prox;
  }
  return novaLista;
}

int tamanho_recursivo(No *l, int tam) {
  if (l == NULL)
    return tam;

  return tamanho_recursivo(l->prox, 1 + tam);
}
void tamanho_it(No *l) {
  No *temp = l;
  int tam = 0;
  while (temp != NULL) {
    temp = temp->prox;
    tam++;
  }
  printf("Tamanho por iteracao: %d\n", tam);
}