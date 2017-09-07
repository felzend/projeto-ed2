typedef struct no No;
typedef struct arvore Arvore;

Arvore* criarArvore();
int deletarArvore(Arvore* arv);
int inserirAluno(Arvore* arv, char* nome, char* email, long telefone);
int removerAluno(Arvore* arv, long matricula);
void imprimir(Arvore* arv);