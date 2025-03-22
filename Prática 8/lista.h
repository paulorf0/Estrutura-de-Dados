typedef struct No {
  int valor;       // Valor armazenado no nó
  struct No *prox; // Ponteiro para o próximo nó
} No;

typedef struct {
  No *inicio;
  No *fim;
  int quantidade;
} Descritor;

void inicializarLista(Descritor *lista);
void adicionarNoInicio(Descritor *lista, int valor);
void adicionarNoFinal(Descritor *lista, int valor);
void removerDoInicio(Descritor *lista);
void removerDoFinal(Descritor *lista);
void removerElemento(Descritor *lista, int elemento);
void exibirLista(Descritor *lista);