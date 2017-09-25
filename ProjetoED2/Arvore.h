typedef struct no No;
typedef struct arvore Arvore;

Arvore* criarArvore();
int deletarArvore(Arvore* arv);
int removerAluno(Arvore* arv, long matricula);
long getMaiorMatricula(Arvore* a);
void inserirAluno(Arvore* arv, char* nome, char* email, char* telefone); // PEGAR SEMPRE A MAIOR MATRICULA E INCREMENTAR 1.
void inserirAluno2(Arvore* arv, long matricula, char* nome, char* email, char* telefone); 
int atualizarAluno(No* no, char* nome, char* email, char* telefone);
void imprimir(Arvore* arv);
int salvar(Arvore* arvore);
No* buscarAluno(Arvore* arv, long matricula);

void printAlunoInfo(No* no);