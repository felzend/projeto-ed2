#define _CRT_SECURE_NO_DEPRECATE

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>

#include "Arvore.h"

int main()
{
    Arvore* arvore = criarArvore();
	FILE* file = fopen("c:\\Users\\1410073\\Documents\\Visual Studio 2012\\Projects\\projeto-ed2\\ProjetoED2\\db\\BDAlunos10e1v1.txt", "r+");

	char token[] = "|";
	char line[200];
	char* email = (char*)malloc(sizeof(char));
	char* nome = (char*)malloc(sizeof(char));
	char* telefone = (char*)malloc(sizeof(char));
	long matricula;

	while(fgets(line, sizeof(line), file) != NULL) 
	{
		int index = 0;
		char* content = strtok(line, token);		

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
			//printf("%s\n", content);
			content = strtok(NULL, token);
			index++;
		}
		inserirAluno(arvore, nome, email, telefone);
		//printf("\n");
	}
	
	free(nome);
	free(email);
	free(telefone);
    fclose(file);

	imprimir(arvore);
	std::cout << "** Maior Matricula: " << getMaiorMatricula(arvore) << "\n";
    std::cout << "\n\n";
    system("PAUSE");
    return 1;
}
