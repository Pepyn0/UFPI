#include <stdio.h>
#include "arvbin.h"


int main(int argc, char const *argv[])
{
	Node *arvore;
	treeInitialize(&arvore);
	treeInsert(&arvore, 150);
	treeInsert(&arvore, 100);
	treeInsert(&arvore, 180);
	treeInsert(&arvore, 180);
	treeInsert(&arvore, 200);
	treeInsert(&arvore, 50);
	treeInsert(&arvore, 80);

	int nNos = 0;
	treeNumberNodes(arvore, &nNos);
	printf("nós: %d\n", nNos);
	printf("ramos: %d\n", nNos - 1);

	int profundidade = treeDepthNode(arvore, 80, 0);
	printf("profundidade: %d\n", profundidade);

	Node *elemento;
	treeSearch(arvore, &elemento, 150);
	printf("altura do elemento: %d\n", treeHeight(elemento));

	int nDescendentes = 0;
	treeNumberNodes(elemento, &nDescendentes);
	printf("descendentes do elemento: %d\n", nDescendentes);


	treeFree(arvore);
	return 0;
}
