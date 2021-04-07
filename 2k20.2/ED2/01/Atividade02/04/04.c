#include "arvore.h"
#include <stdio.h>

int main(int argc, char const *argv[])
{
	Node *arvore;
	treeInitialize(&arvore);
	treeInsert(&arvore, 10);
	treeInsert(&arvore, 12);
	treeInsert(&arvore, 25);
	treeInsert(&arvore, 15);
	treeInsert(&arvore, 14);
	int result = 1;
	treeMult5(arvore, &result);
	printf("%d\n", result);
	treeFree(arvore);
	return 0;
}
