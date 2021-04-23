#include "arvorebin.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{

	FILE *fPtr = fopen(argv[1], "r");
	if(!fPtr)
		return 0;

	Node *raiz;
	char auxPalavra[20];
	char caracter;
	int cCaracter = 0;

	treeInitialize(&raiz);
	for(int linha = 1; (caracter = fgetc(fPtr)) != EOF; )
	{
		if(caracter != 32 && caracter != '\n')
		{
			auxPalavra[cCaracter++] = caracter;
		}
		else if(caracter == '\n')
		{
			linha++;
			auxPalavra[cCaracter - 1] = '\0';
			//printf("%s", auxPalavra);
			treeInsert(&raiz, auxPalavra, linha);
			cCaracter = 0;
		}
		else
		{
			auxPalavra[cCaracter] = '\0';
			//printf("%s", auxPalavra);
			treeInsert(&raiz, auxPalavra, linha);
			cCaracter = 0;
		}
	}
	fclose(fPtr);

	treePrint(raiz);

	int opc = 0;
	do
	{

		printf("[1] - buscar palavra\n");
		printf("[2] - apagar palavra de uma linha\n");
		printf("[0] - sair\n");
		scanf("%d", &opc);

		if(opc == 1)
		{
			char palavra[20];
			printf("Digite a palavra a ser buscada:\n");
			scanf("%s", palavra);

			Node *result;
			treeSearch(raiz, palavra, &result, 1);

			if(!result)
				printf("palavra não encontrada!\n");
		}
		if(opc == 2)
		{
			char palavra[20];
			printf("Digite a palavra a ser buscada:\n");
			scanf("%s", palavra);

			Node *result;
			treeSearch(raiz, palavra, &result, 1);

			if(!result)
				printf("palavra não encontrada!\n");
			else
			{
				int linha;
				printf("Digite a linha que a palavra será removida:\n");
			}
		}
	} while (opc != 0);


	treeFree(raiz);
	return 0;
}
