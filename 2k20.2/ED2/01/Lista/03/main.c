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
	for(int linha = 0; (caracter = fgetc(fPtr)) != EOF; )
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
			treeInsert(&raiz, auxPalavra, linha + 1);
			cCaracter = 0;
		}
		else
		{
			auxPalavra[cCaracter] = '\0';
			//printf("%s", auxPalavra);
			treeInsert(&raiz, auxPalavra, linha + 1);
			cCaracter = 0;
		}
	}
	fclose(fPtr);

	treePrint(raiz);
	treeFree(raiz);
	return 0;
}
