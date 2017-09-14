typedef struct aluno Aluno;

Aluno* criarAluno(char* nome, long matricula, char* email, long telefone);
long getMatricula(Aluno* a);