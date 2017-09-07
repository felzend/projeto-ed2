#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>

#include "Arvore.h"

int main()
{
    Arvore* arvore = criarArvore();
	inserirAluno(arvore, "fel", "fel", 141);

	imprimir(arvore);
    
    std::cout << "\n\n";
    system("PAUSE");
    return 1;
}
