#include "lista.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Evitar o problema de buffer após scanf
void flush_in() {
  int ch;
  while ((ch = getchar()) != '\n' && ch != EOF)
    ;
}

void opcoes() {
  printf("1. Inserir Aluno\n");
  printf("2. Buscar aluno\n");
  printf("3. Alunos na media\n");
  printf("4. Remover aluno\n");
  printf("5. Listar Alunos\n");
  printf("6. Sair\n");
}

float *capturar_notas() {
  float *notas = (float *)malloc(sizeof(float) * 2);

  printf("Digite a primeira nota: ");
  scanf("%f", &notas[0]);
  flush_in();
  printf("Digite a segunda nota: ");
  scanf("%f", &notas[1]);
  flush_in();

  return notas;
}

char *capturar_nome() {
  char buf[100];
  printf("Digite o nome do aluno: ");
  fgets(buf, sizeof(buf), stdin);

  size_t len = strlen(buf);
  if (len > 0 && buf[len - 1] == '\n') {
    buf[len - 1] = '\0';
  }

  char *nome = malloc(strlen(buf) + 1);
  strcpy(nome, buf);
  return nome;
}

int main() {
  int running = 1;
  Lista *lista = criar_lista();
  // *lista = preencher(20);
  while (running) {
    printf("\n\n----------------- Manipulacoes na lista -----------------\n\n");
    opcoes();

    char escolha[2];
    char *nome;
    printf("Escolha a opcao: ");
    scanf("%c", escolha);
    flush_in();
    if (strcmp(escolha[0], ' ') == 0)
      escolha[0] = escolha[1];
    switch (escolha[0]) {
    case '1':
      nome = capturar_nome();
      float *notas = capturar_notas(notas);
      Aluno *aluno = criar_aluno(nome, notas[0], notas[1]);

      // Poderia criar um menu de adicionar no fim ou inicio.
      *lista = inserir_final(*lista, aluno);
      break;
    case '2':
      nome = capturar_nome();
      Aluno *alunos = buscar_nota(*lista, nome);
      printar(alunos);

      break;
    case '3':
      Aluno *alunos_media = media_maior_70(*lista);
      printar(alunos_media);
      break;
    case '4':
      nome = capturar_nome();
      *lista = remover_aluno(*lista, nome);

      break;
    case '5':
      printar(*lista);
      break;
    case '6':
      running = 0;
      destruir_lista(lista);
      break;
    default:
      printf("Opcao invalida");
      break;
    }
  }

  return 0;
}