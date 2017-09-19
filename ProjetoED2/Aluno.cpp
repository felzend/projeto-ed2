#include <stdio.h>
#include <stdlib.h>
#include <iostream>

#include "Aluno.h"
#include "Arvore.h"

struct aluno {
	long matricula;
	char* nome;
	char* email;
	char* telefone;
};

Aluno* criarAluno(char* nome, long matricula, char* email, char* telefone)
{
    Aluno* al = (Aluno*)malloc(sizeof(Aluno));
    al->nome = nome;
	al->matricula = matricula;
    al->email = email;
    al->telefone = telefone;
    return al;
}

long getMatricula(Aluno* a)
{
	if (a != NULL) {
		return a->matricula;
	}
	return -1;
}