#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct no {
  int vidas;
  char nome[10];
  float distancia;
  struct no *prox;
};

typedef struct no No;

void insere_lista_de(No **li, int v, char *n, float a) {
  struct no *novo;
  novo = (No *)malloc(sizeof(No));
  novo->vidas = v;
  novo->distancia = a;
  strcpy(novo->nome, n);
  novo->prox = *li;
  *li = novo;
}
void imprime(No *li) {
  if (li == NULL)
    printf("\nLista Vazia");
  else {
    No *aux;
    aux = li;
    while (aux != NULL) {
      printf("\n%3d \t%s \t%f", aux->vidas, aux->nome, aux->distancia);
      aux = aux->prox;
    }
  }
}

void remover_menor_dist(No **lista) {
  No *no = NULL, *anterior = NULL;
  No *menor = *lista, *aux = *lista;

  // 1 -> 2 -> 3 -> 4 -> 5

  while (aux != NULL) {
    if (aux->distancia < menor->distancia) {
      menor = aux;
      anterior = no;
    }
    no = aux;
    aux = aux->prox;
  }

  if (anterior == NULL) {
    *lista = menor->prox;
  } else {
    anterior->prox = menor->prox;
  }
  free(menor);
}

int main(void) {
  No *lista;
  lista = NULL;
  insere_lista_de(&lista, 100, "hackr", 6.33);
  insere_lista_de(&lista, 60, "gamr", 7.2);
  insere_lista_de(&lista, 70, "strkid", 10.7);
  insere_lista_de(&lista, 110, "jog1", 9.65);
  imprime(lista);

  remover_menor_dist(&lista);
  printf("\nLista de ataques: \nVidas \tJogador \tDistancia");
  imprime(lista);
}

/*
Seja o código abaixo para registrar ataques recebidos por um personagem em um
jogo virtual em uma lista encadeada. Cada ataque vem de um outro personagem e
deve ser registrado com: nome do personagem, número de vidas e distância em que
os personagens se encontram. A partir do código fornecido, faça uma nova função
que retire da lista o personagem que está à uma menor distância.*/