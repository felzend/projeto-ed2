#include <stdio.h>
#include <stdlib.h>
#include <iostream>

#include "Aluno.h"

Aluno* criarAluno(char* nome, long matricula, char* email, long telefone)
{
    Aluno* al = (Aluno*)malloc(sizeof(Aluno));
    al->nome = nome;
	al->matricula = matricula;
    al->email = email;
    al->telefone = telefone;
    return al;
}
