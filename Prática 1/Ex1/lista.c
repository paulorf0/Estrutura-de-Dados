#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct _no_ {
  int elem;
  struct _no_ *prox;
};
typedef struct _no_ No;

// ----------------- Funções para uso ------------------- //
No *criarNo(int elem) {
  No *no = (No *)malloc(sizeof(No));
  no->elem = elem;
  no->prox = NULL;
  return no;
}

// ----------------- Funções para uso ------------------- //

No *criarListaVazia() { return NULL; }
No *insereInicio(No *no, int elem) {
  No *novoNo = (No *)malloc(sizeof(No));
  novoNo->elem = elem;
  novoNo->prox = no;

  return novoNo;
}
No *novaListaElementosPares(No *no) {
  if (no == NULL)
    return NULL;
  No *tail = NULL;
  No *head = NULL;
  while (no != NULL) {
    if (no->elem % 2 == 0) {
      No *novoNo = criarNo(no->elem);
      if (head == NULL) {
        head = novoNo;
        tail = head;
      } else {
        tail->prox = novoNo;
        tail = tail->prox;
      }
    }
    no = no->prox;
  }

  return head;
}
No *valoresAleatorios(No *no) {
  // 20 valores aleatórios
  srand((unsigned)time(NULL));
  no = criarNo(rand() % 100);
  No *head = no;
  for (int i = 0; i < 19; i++) {
    no->prox = criarNo(rand() % 100);
    no = no->prox;
  }
  return head;
}
No *removerValor(No *no, int elem) {
  if (no == NULL)
    return no;

  No *ant = NULL, *current = no;
  while (current != NULL) {
    if (current->elem == elem)
      break;

    ant = current;
    current = current->prox;
  }
  if (current == NULL)
    return no;

  if (ant == NULL)
    no = current->prox;
  else
    ant->prox = current->prox;

  free(current);
  return no;
}
No *removerMaiorElemento(No *no) {
  if (no == NULL)
    return no;
  No *ant = NULL, *current = no, *maiorNo = no;
  int maior = no->elem;
  while (current->prox != NULL) {
    if (current->prox->elem > maior) {
      maior = current->prox->elem;
      maiorNo = current->prox;
      ant = current;
    }
    current = current->prox;
  }

  if (ant == NULL)
    no = maiorNo->prox;
  else
    ant->prox = maiorNo->prox;

  free(maiorNo);
  return no;
}
int tamanhoLista(No *no) {
  No *temp = no;
  int tamanho = 0;
  while (temp != NULL) {
    temp = temp->prox;
    tamanho++;
  }
  return tamanho;
}
int *criarVetor(No *no) {
  int tamanho = tamanhoLista(no);
  int i = 0;
  int *vec = (int *)malloc(tamanho * sizeof(int));
  No *temp = no;
  while (temp != NULL) {
    vec[i++] = temp->elem;
    temp = temp->prox;
  }

  return vec;
}
int listaVazia(No *no) { return no == NULL; }
void percorrerLista(No *no) {
  No *temp = no;
  while (temp != NULL) {
    printf("%d ; ", temp->elem);
    temp = temp->prox;
  }
}
void exibirMaiorElemento(No *no) {
  No *current = no;
  int maior = no->elem;
  while (current != NULL) {
    if (current->elem > maior)
      maior = current->elem;
    current = current->prox;
  }

  while (no != NULL) {
    if (no->elem == maior)
      printf("--> %d <-- ; ", no->elem);
    else
      printf("%d ; ", no->elem);
    no = no->prox;
  }
}