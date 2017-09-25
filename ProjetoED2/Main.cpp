#define _CRT_SECURE_NO_DEPRECATE
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Arvore.h"

void loadFromDatabase(Arvore** arvore)
{
	FILE* file = fopen("./db/BDAlunos10e1v1.txt", "r+");
	char separator[] = "|";
	char line[200];

	char* email = (char*)malloc(sizeof(char) * 200);
	char* nome = (char*)malloc(sizeof(char) * 200);
	char* telefone = (char*)malloc(sizeof(char) * 200);
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
					nome = (char*)malloc(sizeof(char) * 200);
					strcpy(nome, content);
					break;
				}
				case 2:
				{
					email = (char*)malloc(sizeof(char) * 200);
					strcpy(email, content);
					break;
				}
				case 3:
				{
					telefone = (char*)malloc(sizeof(char) * 200);
					strcpy(telefone, content);
					break;
				}
				default: break;
			}
			content = strtok(NULL, separator);
			index++;
		}		
		inserirAluno2(*arvore, matricula, nome, email, telefone);
	}

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
		printf("10 - Salvar Arvore em Arquivo");
		printf("\n\n");

		printf("Selecione uma opcao: ");
		scanf("%d", &option);

		switch (option)
		{
			case 0: system("exit"); break;
			case 1: // Carregar alunos do arquivo. OK
			{
				loadFromDatabase(&arvore);
				printf("Dados carregados com sucesso!\n");
				break;
			}
			case 2: // Inserir Aluno na Arvore. OK
			{
				char* email = (char*)malloc(sizeof(char) * 100);
				char* nome = (char*)malloc(sizeof(char) * 100);
				char* telefone = (char*)malloc(sizeof(char) * 100);
				long matricula;				
				
				printf("Nome do Aluno: ");				
				scanf("%s", nome);
				printf("Email do Aluno: ");				
				scanf("%s", email);
				printf("Telefone do Aluno: ");				
				scanf("%s", telefone);

				inserirAluno2(arvore, getMaiorMatricula(arvore) + 1, nome, email, telefone);
				break;
			}
			case 3: // IMPRIMIR EM ORDEM DE MATRICULA. AINDA NÃO FEITO.
			{
				imprimir(arvore);
				printf("\nMaior Matricula: %d\n", getMaiorMatricula(arvore));
				break;
			}
			case 5: // Imprimir Informações do Aluno por Matricula. OK
			{
				long matricula;
				printf("Matricula do Aluno: ");
				scanf("%d", &matricula);
				printAlunoInfo(buscarAluno(arvore, matricula));
				break;
			}
			case 6: // Alterar Dados do Aluno. OK
			{
				long matricula;
				char* email = (char*)malloc(sizeof(char) * 200);
				char* nome = (char*)malloc(sizeof(char) * 200);
				char* telefone = (char*)malloc(sizeof(char) * 200);

				printf("Matricula: ");
				scanf("%d", &matricula);
				printf("Nome do Aluno: ");
				scanf("%s", nome);
				printf("Email do Aluno: ");
				scanf("%s", email);
				printf("Telefone do Aluno: ");
				scanf("%s", telefone);			

				No* no = buscarAluno(arvore, matricula);
				atualizarAluno(no, nome, email, telefone);
				break;
				
			}
			case 10: // Salvar Arvore atual num arquivo txt. OK
			{
				salvar(arvore);
				break;
			}
			default: break;
		}

		system("PAUSE");
	}

	free(arvore);

	printf("\n\n");
    system("PAUSE");
    return 1;
}
