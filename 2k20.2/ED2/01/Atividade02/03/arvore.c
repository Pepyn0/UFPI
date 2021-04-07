#include "arvore.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct no
{
	int code;
	char model[20];
	char tissue[20];
	float size;
	float length;
	char color[10];

	Node *right;
	Node *left;
};

//Inicializa o ponteiro, passado por referencia, com null;
void treeInitialize(Node **root)
{
	*root = NULL;
}

//Recebe o nó raiz da árvore e os valores do novo nó e o insere na árvore;
void treeInsert(Node **root, int code, char *model, char *tissue, float size, float length, char *color)
{
	if(*root == NULL)
	{
		*root = (Node *) malloc(sizeof(Node));
		(*root)->code = code;
		strcpy((*root)->model, model);
		strcpy((*root)->tissue, tissue);
		(*root)->size = size;
		(*root)->length = length;
		strcpy((*root)->color, color);

		(*root)->right = NULL;
		(*root)->left = NULL;
	}
	else
		if(code < (*root)->code)
			treeInsert(&(*root)->left, code, model, tissue, size, length, color);
		else
			treeInsert(&(*root)->right, code, model, tissue, size, length, color);
}

//Mostra os nós da arvore;
void treeShow(Node *root)
{
	if(root != NULL)
	{
		treeShow(root->left);
		treeShow(root->right);
		printf("%d\n", root->code);
		printf("%s\n", root->model);
	}
}

//Recebe a raiz da árvore e a libera por completo;
void treeFree(Node *root)
{
	if(root != NULL)
	{
		treeFree(root->left);
		treeFree(root->right);
		free(root);
	}
}
