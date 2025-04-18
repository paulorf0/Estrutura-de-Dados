typedef struct _pilha_ {
  char delimitador;
  struct _pilha_ *prox;
} pilha;

pilha *clear(pilha *h);
int isEmpty(pilha *h); // 1 se vazio, 0 se não vazio.
pilha *push(pilha *h, char el);
char pop(pilha **h);
char topEl(pilha *h);