#define TAM 100
struct no {
  char palavra[TAM];
  struct no *prox;
};
typedef struct no No;

void criaListaVazia(No **l);
void insereNoFim(No **l, const char *palavra);
void ler_arquivo(No **l, char *path);
void imprimeLista(No *l);
void remover_duplicados(No **l);
int tamanho_recursivo(No *l, int tam);
void tamanho_it(No *l);
No *copiar_palavras_primas(No *l);