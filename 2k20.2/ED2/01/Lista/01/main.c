#include "arvorebin.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char const *argv[])
{
	srand(time(NULL));

	int numeros[10] = {2252, 46445, 57861, 97962, 64556, 6229, 41059, 11870, 45857, 52874};

	Node *raiz;
	treeInitialize(&raiz);
	while (treeHeight(raiz) != 15)
	{
		int valor = rand() % 123456;
		treeInsert(&raiz, valor);
	}

	//treePrint(raiz);
	treeFree(raiz);
	return 0;
}
