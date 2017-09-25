#define _CRT_SECURE_NO_DEPRECATE
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "Arvore.h"
#include "Aluno.h"

struct arvore
{
    long reg;
    No* raiz;
};

struct no
{
	Aluno* aluno;
    No* esquerda;
    No* direita;
};

Arvore* criarArvore()
{
    Arvore* arv = (Arvore*)malloc(sizeof(Arvore));
    arv->reg = 1;
    arv->raiz = NULL;
    return arv;
}

int deletarArvore(Arvore* arv)
{
	return -1;
}

No* inserirAluno_rec(No* raiz, long matricula, char* nome, char* email, char* telefone)
{
	if (raiz != NULL) {		
		if (matricula < getMatricula(raiz->aluno)) {
			raiz->esquerda = inserirAluno_rec(raiz->esquerda, matricula, nome, email, telefone);
		}
		else {
			raiz->direita = inserirAluno_rec(raiz->direita, matricula, nome, email, telefone);
		}
	}
	else {
		raiz = (No*)malloc(sizeof(No));
		raiz->aluno = criarAluno(nome, matricula, email, telefone);
		raiz->esquerda = NULL;
		raiz->direita = NULL;
		return raiz;
	}

	return raiz;
}

void inserirAluno(Arvore* arv, char* nome, char* email, char* telefone)
{
	arv->raiz = inserirAluno_rec(arv->raiz, arv->reg++, nome, email, telefone);
}

void inserirAluno2(Arvore* arv, long matricula, char* nome, char* email, char* telefone)
{
	arv->raiz = inserirAluno_rec(arv->raiz, matricula, nome, email, telefone);
}

No* buscarAluno_rec(No* raiz, long matricula) 
{
	if (raiz != NULL)
	{
		if (matricula < getMatricula(raiz->aluno)) {
			return buscarAluno_rec(raiz->esquerda, matricula);
		}
		else if( matricula > getMatricula(raiz->aluno)) {
			return buscarAluno_rec(raiz->direita, matricula);
		}
		else {			
			return raiz;
		}
	}

	return NULL;
}

No* buscarAluno(Arvore* arv, long matricula)
{
	return buscarAluno_rec(arv->raiz, matricula);
}

void imprimir_rec(No* raiz)
{	
	if (raiz != NULL)
	{			
		printInfo(raiz->aluno);
		imprimir_rec(raiz->esquerda);		
		imprimir_rec(raiz->direita);
	}
}

long imprimir_ordenado_rec(No* raiz)
{
	if (raiz != NULL)
	{
		No* esq = raiz->esquerda;
		No* dir = raiz->direita;
		long mEsq = getMatricula(esq->aluno);
		long mDir = getMatricula(dir->aluno);
		return (mEsq < mDir) ? mEsq : mDir;
		//printf("Matr: %d\n", getMatricula(raiz->aluno));
	}

	return -1;
}

void imprimir(Arvore* arv)
{		
	imprimir_rec(arv->raiz);
	//std::cout << imprimir_ordenado_rec(arv->raiz) << "\n";
}

void printAlunoInfo(No* no)
{
	if (no != NULL) {
		if (no->aluno != NULL) {
			printInfo(no->aluno);
		}
	}
}

int removerAluno(Arvore* arv, long matricula)
{
	return -1;
}

long getMaiorMatricula_rec(No* raiz, long maior)
{
	if (raiz != NULL) {
		long matricula = getMatricula(raiz->aluno);
		if (matricula < maior) {
			return getMaiorMatricula_rec(raiz->esquerda, maior);
		}
		else {
			return getMaiorMatricula_rec(raiz->direita, matricula);
		}
	}
	return maior;
}

long getMaiorMatricula(Arvore* a)
{
	if (a != NULL) return getMaiorMatricula_rec(a->raiz, -1);
	return -1;
}

int atualizarAluno(No* no, char* nome, char* email, char* telefone)
{
	return atualizar(&no->aluno, nome, email, telefone);
}

void salvar_rec(No* raiz, char* directory)
{
	if (raiz != NULL)
	{
		char* info = getAlunoInfo(raiz->aluno);		
		if (info != NULL) {
			FILE *f = fopen(directory, "a");
			fprintf(f, info);
			fclose(f);
		}
		salvar_rec(raiz->esquerda, directory);
		salvar_rec(raiz->direita, directory);
	}	
}

int salvar(Arvore* arvore)
{
	char filename[100];
	char directory[100];
	char line[200];
	int timestamp = (int)time(NULL);
	sprintf_s(filename, "database-%d.txt", timestamp);
	sprintf_s(directory, "./db/%s", filename);	
	salvar_rec(arvore->raiz, directory);	
	return 1;
}