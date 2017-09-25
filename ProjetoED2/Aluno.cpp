#define _CRT_SECURE_NO_DEPRECATE
#define _CRT_SECURE_NO_WARNINGS

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

char* getAlunoInfo(Aluno* aluno)
{	
	if (aluno != NULL) {
		char* info = (char*)malloc(sizeof(char) * 300);		
		sprintf(info, "Matricula: %d | Nome: %s | Email: %s | Telefone: %s\n", aluno->matricula, aluno->nome, aluno->email, aluno->telefone);		
		return info;
	}
	return NULL;
}

void printInfo(Aluno* aluno)
{
	if (aluno != NULL) {
		printf("Matricula: %d | Nome: %s | Email: %s | Telefone: %s\n", aluno->matricula, aluno->nome, aluno->email, aluno->telefone);
	}
	else {
		printf("Aluno Invalido.");
	}
}

int atualizar(Aluno** aluno, char* nome, char* email, char* telefone)
{
	if (aluno != NULL) {
		(*aluno)->nome = nome;
		(*aluno)->email = email;
		(*aluno)->telefone = telefone;
		return 1;
	}
	return 0;
}