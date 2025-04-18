#include <string.h>
struct Produto {
  char nome[20], descricao[20], categoria[20];
  float preco;
};

void X(struct Produto p[], int *n, struct Produto p1) {
  p[*n] = p1;
  (*n)++;
}

int main() {
  int n = 0; // n demarca a posição 0 pois o array acabou de ser criado.
  struct Produto p[3]; // Pode ser 3 produtos ou N produtos
  struct Produto p1;
  strcpy(p1.nome, "Sapato");
  strcpy(p1.descricao, "Colocar no pe");
  strcpy(p1.categoria, "A");
  p1.preco = 99.9;
  X(p, &n, p1);

  return 0;
}

/*
a) Que operação está sendo implementada pela função X?

b) Explique qual é o modelo de comunicação (entre funções) definido por cada
parâmetro formal da função X.

c) Produza uma função main com chamadas à função X, mostrando como ela pode ser
utilizada.
*/

/*
    a) A função está adicionando a posição (*n) da lista de produtos o produto
   p1 e depois incrementando o valor de (*n). Provavelmente, n demarca a posição
   vaga na lista de produtos

   b) Utiliza um array de produto, um ponteiro n que provavelmente armazena o
   indice vago do array de produto e um estrutura Produto p1, que é o produto
   que se quer adicionar na posição que n demarca. O array de produto, e a
   variável n é feito a passagem por referência, enquanto o Produto p1 é feito
   passagem por valor.

   c)
   
*/