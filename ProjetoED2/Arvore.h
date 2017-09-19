typedef struct no No;
typedef struct arvore Arvore;

Arvore* criarArvore();
int deletarArvore(Arvore* arv);
void inserirAluno(Arvore* arv, char* nome, char* email, char* telefone); // PEGAR SEMPRE A MAIOR MATRICULA E INCREMENTAR 1.
int removerAluno(Arvore* arv, long matricula);
void imprimir(Arvore* arv);

long getMaiorMatricula(Arvore* a);
long getMaiorMatricula(Arvore* a);