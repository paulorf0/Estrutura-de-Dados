#include "pilha.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int sol(pilha **p, char *exp) {
  for (int i = 0; i < strlen(exp); i++) {
    if (exp[i] == '(' || exp[i] == '{' || exp[i] == '[') {
      *p = push(*p, *(exp + i));
    } else if (exp[i] == ')' || exp[i] == '}' || exp[i] == ']') {
      char fechamento = pop(p);
      if (exp[i] - fechamento != 2 && exp[i] - fechamento != 1)
        return 0;
    }
  }
  if (isEmpty(*p))
    return 1;

  return 0;
}

int main() {
  pilha **p = (pilha **)malloc(sizeof(pilha *));
  *p = NULL;

  int res = sol(p, "x[2] - 3 + 4*x+(4*x*{5+2/2{}})");
  printf("Resultado: %d", res);
}