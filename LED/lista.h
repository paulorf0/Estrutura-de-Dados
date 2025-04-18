#define MAX 100

struct _led_ {
  int valor;
  int prox;
};
struct _lista_ {
  struct _led_ led[MAX];
  int vago;
  int primeiro;
};
typedef struct _led_ LED;
typedef struct _lista_ Lista;

Lista *criar_lista();
void liberar_lista(Lista *lista);

Lista *inserir_inicio(Lista *lista, int n);
Lista *inserir_final(Lista *lista, int n);
Lista *remover_valor(Lista *lista, int n);
Lista *remover_inicio(Lista *lista);
Lista *remover_final(Lista *lista);
void imprimir(Lista *lista);

Lista *gerar_aleatorios(Lista *lista, int n);