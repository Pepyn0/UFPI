#include <stdio.h>
#include <stdlib.h>
#include "arvore.h"


int main(int argc, char const *argv[])
{
	Node *arvore;
	treeInitialize(&arvore);
	treeInsert(&arvore, 1, "ab", "ab", 1, 1, "ab");
	treeShow(arvore);
	treeFree(arvore);
	return 0;
}
