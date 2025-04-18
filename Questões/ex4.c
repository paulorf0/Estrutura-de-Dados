#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

struct dados_tecnicos {
  int potencia;
  int cilindradas;
  int valvulas;
};

struct veiculo {
  char marca[30];
  char modelo[40];
  int ano;
  struct dados_tecnicos dados;
};

struct lista {
  struct veiculo *veiculos;
  int qtd;
};

typedef struct veiculo Veiculo;
typedef struct lista Lista;

Lista criar_lista() {
  Lista lista;
  lista.qtd = 0;
  lista.veiculos = (Veiculo *)malloc(MAX * sizeof(Veiculo));
  if (lista.veiculos == NULL)
    printf("Erro em alocar memória.\n");

  return lista;
}

void inserir(Lista *lista, Veiculo veic) {
  if (lista->qtd >= MAX) {
    printf("Lista cheia, não é possível inserir.\n");
    return;
  }
  lista->veiculos[lista->qtd] = veic;
  lista->qtd++;
}

double performace(Veiculo v) {
  double performance;
  if (v.dados.valvulas >= 16)
    performance = ((v.dados.potencia * 3) + v.dados.cilindradas) /
                  (double)v.dados.valvulas;
  else
    performance = ((v.dados.potencia * 2) + v.dados.cilindradas) /
                  (double)v.dados.valvulas;
  return performance;
}

void performace_inferior_150(Lista lista) {
  int i = 0;
  int qtd = 0;
  while (i < lista.qtd) {
    double perf = performace(lista.veiculos[i]);
    if (perf < 150)
      qtd++;
    i++;
  }
  printf("Numero de veiculos com performance inferior a 150: %d\n", qtd);
}

void info_veic(Veiculo veic) {
  double perf = performace(veic);
  printf("  Marca: %s\n", veic.marca);
  printf("  Modelo: %s\n", veic.modelo);
  printf("  Ano de fabricacao: %d\n", veic.ano);
  printf("  Potencia: %d CV\n", veic.dados.potencia);
  printf("  Cilindradas: %.2f\n", veic.dados.cilindradas);
  printf("  Numero de valvulas: %d\n", veic.dados.valvulas);
  printf("  Performance estrutural: %.2f\n", perf);
}

void info_todos(Lista lista) {
  int i = 0;
  while (i < lista.qtd) {
    info_veic(lista.veiculos[i]);
    printf("\n");
    i++;
  }
}

int main(void) {
  Lista lista = criar_lista();

  Veiculo v1 = {"Toyota", "Corolla", 2020, {132, 1798, 16}};
  Veiculo v2 = {"Honda", "Civic", 2019, {158, 1996, 16}};
  Veiculo v3 = {"Ford", "Fiesta", 2018, {120, 1498, 12}};
  Veiculo v4 = {"Chevrolet", "Cruze", 2021, {153, 1796, 16}};

  inserir(&lista, v1);
  inserir(&lista, v2);
  inserir(&lista, v3);
  inserir(&lista, v4);

  printf("Informacoes de todos os veiculos:\n");
  info_todos(lista);

  performace_inferior_150(lista);
  return 0;
}