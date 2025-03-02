

struct _alunos_ {
  char *nome;
  float notas[2];
  struct _alunos_ *prox;
};
typedef struct _alunos_ Aluno;
typedef struct _alunos_ *Lista;

// Função simples para preencher com dados padronizados a lista
Aluno *preencher(int max);
//////////////////////////////////////////////////////////////

Lista *criar_lista();
Aluno *criar_aluno(char *nome, float nota1, float nota2);
Aluno *inserir_inicio(Aluno *cabeca, Aluno *aluno);
Aluno *inserir_final(Aluno *cabeca, Aluno *aluno);
Aluno *remover_aluno(Aluno *cabeca, char *nome);
Aluno *media_maior_70(Aluno *cabeca);
Aluno *buscar_nota(Aluno *cabeca, char *nome);
void destruir_lista(Lista *lista);
void printar(Aluno *alunos);