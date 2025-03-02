#include "lista.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

Lista *criar_lista() {
  Lista *lista = (Lista *)malloc(sizeof(Lista));
  if (lista != NULL)
    // Cabeça da lista como NULL
    *lista = NULL;

  return lista;
}
// Retorna a cabeça para a lista
Aluno *preencher(int max) {
  if (max <= 0)
    return NULL;
  srand(time(NULL));

  Aluno *cabeca = (Aluno *)malloc(sizeof(Aluno));

  if (cabeca == NULL)
    return cabeca;

  sprintf(cabeca->nome, "Aluno_%d", 1);
  cabeca->notas[0] = (rand() % 101) / 10.0;
  cabeca->notas[1] = (rand() % 101) / 10.0;
  cabeca->prox = NULL;

  Aluno *temp = cabeca;

  for (int i = 2; i <= max; i++) {
    temp->prox = (Aluno *)malloc(sizeof(Aluno));
    if (temp->prox == NULL)
      break;

    temp = temp->prox;

    sprintf(temp->nome, "Aluno_%d", i);
    temp->notas[0] = (rand() % 101) / 10.0;
    temp->notas[1] = (rand() % 101) / 10.0;

    temp->prox = NULL;
  }

  return cabeca;
}

Aluno *criar_aluno(char *nome, float nota1, float nota2) {
  Aluno *aluno = (Aluno *)malloc(sizeof(Aluno));
  aluno->nome = nome;
  aluno->notas[0] = nota1;
  aluno->notas[1] = nota2;
  aluno->prox = NULL;

  return aluno;
}

Aluno *inserir_inicio(Aluno *cabeca, Aluno *aluno) {
  if (cabeca == NULL) {
    cabeca = aluno;
    return cabeca;
  }

  aluno->prox = cabeca;
  return aluno;
}
Aluno *inserir_final(Aluno *cabeca, Aluno *aluno) {
  if (cabeca == NULL) {
    cabeca = aluno;
    return cabeca;
  }

  Aluno *temp = cabeca;
  while (temp->prox != NULL)
    temp = temp->prox;

  temp->prox = aluno;
  return cabeca;
}

Aluno *remover_aluno(Aluno *cabeca, char *nome) {
  if (cabeca == NULL)
    return NULL;

  if (strcmp(cabeca->nome, nome) == 0) {
    Aluno *temp = cabeca->prox;
    free(cabeca->nome);
    free(cabeca);
    return temp;
  }

  Aluno *temp = cabeca;
  while (temp->prox != NULL && strcmp(temp->prox->nome, nome) != 0)
    temp = temp->prox;

  if (temp->prox != NULL) {
    Aluno *remover = temp->prox;
    temp->prox = temp->prox->prox;
    free(remover->nome);
    free(remover);
  }

  return cabeca;
}

Aluno *media_maior_70(Aluno *cabeca) {
  if (cabeca == NULL)
    return NULL;

  Aluno *cabeca_nova_lista = NULL;
  Aluno *temp = cabeca;
  while (temp != NULL) {
    float media = (temp->notas[0] + temp->notas[1]) / 2.f;
    if (media > 70)
      cabeca_nova_lista = inserir_final(cabeca_nova_lista, temp);

    temp = temp->prox;
  }

  return cabeca_nova_lista;
}
Aluno *buscar_nota(Aluno *cabeca, char *nome) {

  if (cabeca == NULL)
    return NULL;

  Aluno *cabeca_nova_lista = NULL;
  Aluno *temp = cabeca;
  while (temp != NULL) {
    if (strcmp(temp->nome, nome) == 0) {
      Aluno *adicionar =
          criar_aluno(temp->nome, temp->notas[0], temp->notas[1]);
      cabeca_nova_lista = inserir_final(cabeca_nova_lista, adicionar);
    }

    temp = temp->prox;
  }

  return cabeca_nova_lista;
}

void destruir_lista(Lista *lista) {
  Aluno *temp = *lista;
  while (*lista != NULL) {
    temp = *lista;
    (*lista) = (*lista)->prox;
    free(temp);
  }
}

void printar(Aluno *aluno) {
  Aluno *temp = aluno;

  while (temp != NULL) {
    printf("Nome: %s, Nota Pratica: %.2f, Nota Teorica: %.2f\n", temp->nome,
           temp->notas[0], temp->notas[1]);
    temp = temp->prox;
  }
}
