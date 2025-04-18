#include "pilha.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

pilha *sol(pilha **h, pilha **num1, pilha **num2) {
  int carry = 0;

  while (!isEmpty(*num1) || !isEmpty(*num2)) {
    int n1 = pop(num1);
    int n2 = pop(num2);

    int soma = n1 + n2 + carry;
    carry = 0;

    if (soma >= 10) {
      carry = 1;
      soma -= 10;
    }

    *h = push(*h, soma);
  }

  if (carry)
    *h = push(*h, carry);

  return *h;
}

int main() {
  char num1[100];
  char num2[100];
  printf("Digite num1 e depois num2: \n");
  scanf("%s", num1);
  scanf("%s", num2);

  pilha **p_num1 = (pilha **)malloc(sizeof(pilha *));
  pilha **p_num2 = (pilha **)malloc(sizeof(pilha *));
  pilha *soluc = NULL;
  *p_num1 = NULL;
  *p_num2 = NULL;

  for (int i = 0; i < strlen(num1); i++) {
    int el = num1[i] - '0';
    printf("%d\n", el);
    *p_num1 = push(*p_num1, el);
  }
  printf("\n");
  for (int i = 0; i < strlen(num2); i++) {
    int el = num2[i] - '0';
    printf("%d\n", el);

    *p_num2 = push(*p_num2, el);
  }

  soluc = sol(&soluc, p_num1, p_num2);
  int len = size(soluc);
  char *soma = (char *)malloc((len + 1) * sizeof(char));
  *(soma + len) = '\0';

  for (int i = 0; i < len; i++) {
    int valor = pop(&soluc);
    soma[i] = valor + '0';
  }
  printf("Resultado: %s\n", soma);
  free(soma);
  clear(soluc);
}