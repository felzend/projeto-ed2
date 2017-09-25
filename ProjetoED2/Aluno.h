typedef struct aluno Aluno;

Aluno* criarAluno(char* nome, long matricula, char* email, char* telefone);
void printInfo(Aluno* aluno);
int atualizar(Aluno** aluno, char* nome, char* email, char* telefone);
long getMatricula(Aluno* a);
char* getAlunoInfo(Aluno* aluno);