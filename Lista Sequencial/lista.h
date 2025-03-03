#include <stdlib.h>

#define MAX 100

struct _dados_ {
  int valor;
};

struct _lista_ {
  int tamanho;
  struct _dados_ info[MAX];
};

typedef struct _lista_ Lista;
typedef struct _dados_ Dados;

Lista *criar_lista();
void liberar_lista(Lista *lista);

Lista *inserir_inicio(Lista *lista, int n);
Lista *inserir_final(Lista *lista, int n);
Lista *remover_valor(Lista *lista, int n);
Lista *remover_inicio(Lista *lista);
Lista *remover_final(Lista *lista);
void imprimir(Lista *lista);

Lista *gerar_aleatorios(Lista *lista, int n);