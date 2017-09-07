typedef struct aluno {
	long matricula;
	char* nome;
	char* email;
	long telefone;
} Aluno;

Aluno* criarAluno(char* nome, long matricula, char* email, long telefone);
