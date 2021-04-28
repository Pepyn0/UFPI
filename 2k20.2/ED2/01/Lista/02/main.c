#include "arvoreAVL.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char const *argv[])
{
	srand(time(NULL));

	int numeros[10] = {2252, 46445, 57861, 97962, 64556, 6229, 41059, 11870, 45857, 101761};
	time_t vTime[2];
	double tempo;

	Node *raiz;
	treeInitialize(&raiz);
	while (treeHeight(raiz) != 15)
	{
		int valor = rand() % 123456;
		treeInsert(&raiz, valor);
	}

	// treePrint(raiz);


	for(int i = 0; i < 10; i++)
	{
		vTime[0] = clock();
		treeSearch(raiz, numeros[i]);
		vTime[1] = clock();

		tempo = (vTime[1] - vTime[0]) * 1e+6;
		printf("Numero buscado: %d\n", numeros[i]);
		printf("Time: %g\n\n", tempo);
	}

	//treePrint(raiz);
	treeFree(raiz);
	return 0;
}
