#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>

#include "Arvore.h"

int main()
{
    Arvore* arvore = criarArvore();
	for (int a = 0; a < 100; a++) {
		inserirAluno(arvore, "fel", "fel", 32526079);		
	}
	imprimir(arvore);
    
    std::cout << "\n\n";
    system("PAUSE");
    return 1;
}
