#include "arvore.h"
#include <stdlib.h>
#include <stdio.h>

struct no
{
	int value;
	Node *right;
	Node *left;
};

//Inicializa o ponteiro, passado por referencia, com null;
void treeInitialize(Node **root)
{
	*root = NULL;
}

//Recebe o nó raiz da árvore e o valor do novo nó e o insere na árvore;
void treeInsert(Node **root, int value)
{
	if(*root == NULL)
	{
		*root = (Node *) malloc(sizeof(Node));
		(*root)->value = value;
		(*root)->left = NULL;
		(*root)->right = NULL;
	}
	else
		if(value > (*root)->value)
			treeInsert(&(*root)->right, value);
		else
			treeInsert(&(*root)->left, value);
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

//Recebe a raiz da arvore e um valor a ser procurado na arvore e a função retorna o pai do valor se encontrado na arvore;
int treeFather(Node *root, int key)
{
	int result = -1;
	if(root != NULL)
	{
		if(root->left)
			if ((root->left)->value == key)
				result = root->value;

		else if(root->right)
			if ((root->right)->value == key)
				result = root->value;

		else
			if(root->value > key)
				result = treeFather(root->left, key);
			else
				result = treeFather(root->right, key);
	}
	return result;
}
