typedef struct _pilha_ {
  int num;
  struct _pilha_ *prox;
} pilha;

void clear(pilha *h);
int isEmpty(pilha *h); // 1 se vazio, 0 se não vazio.
pilha *push(pilha *h, int el);
int pop(pilha **h);
int size(pilha *h);
int *topEl(pilha *h);