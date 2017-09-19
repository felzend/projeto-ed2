typedef struct aluno Aluno;

Aluno* criarAluno(char* nome, long matricula, char* email, char* telefone);
long getMatricula(Aluno* a);