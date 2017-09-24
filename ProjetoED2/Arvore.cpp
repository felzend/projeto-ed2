#include <stdio.h>
#include <stdlib.h>
#include <iostream>

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

void imprimir_rec(No* raiz)
{	
	if (raiz != NULL)
	{		
		std::cout << "Matricula: " << getMatricula(raiz->aluno) << "\n";
		imprimir_rec(raiz->esquerda);		
		imprimir_rec(raiz->direita);
	}
}

void imprimir(Arvore* arv)
{		
	imprimir_rec(arv->raiz);
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
