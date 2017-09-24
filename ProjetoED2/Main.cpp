#define _CRT_SECURE_NO_DEPRECATE

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Arvore.h"

void loadFromDatabase(Arvore** arvore)
{
	FILE* file = fopen("./db/BDAlunos10e1v1.txt", "r+");
	char separator[] = "|";
	char line[200];

	char* email = (char*)malloc(sizeof(char));
	char* nome = (char*)malloc(sizeof(char));
	char* telefone = (char*)malloc(sizeof(char));
	long matricula;

	while (fgets(line, sizeof(line), file) != NULL)
	{
		int index = 0;
		char* content = strtok(line, separator);
		while (content != NULL)
		{
			switch (index)
			{
			case 0:
			{
				matricula = atoi(content);
				break;
			}
			case 1:
			{
				nome = (char*)malloc(sizeof(char) * strlen(nome));
				break;
			}
			case 2:
			{
				email = (char*)malloc(sizeof(char) * strlen(email));
				break;
			}
			case 3:
			{
				telefone = (char*)malloc(sizeof(char) * strlen(telefone));
				break;
			}
			default: break;
			}
			content = strtok(NULL, separator);
			index++;
		}
		inserirAluno(*arvore, nome, email, telefone);
	}

	free(nome);
	free(email);
	free(telefone);
	fclose(file);
}

int main()
{
	Arvore* arvore = criarArvore();
	int option = -1;
	while ( option != 0 )
	{
		system("cls");
		printf("0 - Sair\n");
		printf("1 - Carregar Alunos da Database\n");
		printf("2 - Inserir Aluno\n");
		printf("3 - Listar Alunos por ordem de Matricula\n");
		printf("4 - Listar Alunos da Database\n");
		printf("5 - Listar Dados do Aluno por Matricula\n");
		printf("6 - Alterar Dados de Aluno por Matricula\n");
		printf("7 - Remover Aluno por Matricula\n");
		printf("\n\n");

		printf("Selecione uma opcao: ");
		scanf("%d", &option);

		switch (option)
		{
			case 0: system("exit"); break;
			case 1:
			{
				loadFromDatabase(&arvore);
				imprimir(arvore);
			}
			case 2:
			{
				char* email = (char*)malloc(sizeof(char));
				char* nome = (char*)malloc(sizeof(char));
				char* telefone = (char*)malloc(sizeof(char));
				long matricula;
				printf("Nome do Aluno: ");
				scanf("%s", nome);
				printf("Email do Aluno: ");
				scanf("%s", email);
				printf("Telefone do Aluno: ");
				scanf("%s", telefone);
				break;
			}
			default: break;
		}

		system("PAUSE");
	}

	printf("\n\n");
    system("PAUSE");
    return 1;
}
