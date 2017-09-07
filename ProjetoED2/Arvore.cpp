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

int inserirAluno_rec(No* raiz, long matricula, char* nome, char* email, long telefone)
{
	if (raiz != NULL) 
	{
		inserirAluno_rec(raiz->esquerda, matricula, nome, email, telefone);
		inserirAluno_rec(raiz->direita, matricula, nome, email, telefone);
	}
	else
	{
		
		raiz = (No*)malloc(sizeof(No));		
		raiz->aluno = criarAluno(nome, matricula, email, telefone);		
		raiz->esquerda = NULL;
		raiz->direita = NULL;
		return 1;
	}	

	return -1;
}

int inserirAluno(Arvore* arv, char* nome, char* email, long telefone)
{
	return inserirAluno_rec(arv->raiz, arv->reg++, nome, email, telefone);
}

void imprimir_rec(No* raiz)
{
	if (raiz != NULL)
	{		
		imprimir_rec(raiz->esquerda);
		std::cout << "Matricula: " << raiz->aluno->matricula;
		imprimir_rec(raiz->direita);
	}

	std::cout << "Out Print";
}

void imprimir(Arvore* arv)
{	
	imprimir_rec(arv->raiz);
}

int removerAluno(Arvore* arv, long matricula)
{
	return -1;
}
