#include <stdlib.h>
#include <stdio.h>
#include "arvbin.h"

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

//mostra todos os nós da arvore;
void treePrint(Node *root)
{
	
	if(root != NULL)
	{
		treePrint(root->left);
		printf("%d\n", root->value);
		treePrint(root->right);
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

//Recebe a raiz da árvore e o valor a ser buscado na arvore e retorna um ponteiro para o nó se ele existir;
void treeSearch(Node *root, Node **result, int key)
{
	*result = NULL;
	if(root != NULL)
		if(root->value == key)
			*result = root;
		else
			if(key < root->value)
				treeSearch(root->left, result, key);
			else
				treeSearch(root->right, result, key);
}

//recebe a raiz da arvore e retorna o numero de nós que há na árvore através de um contador passado por referencia;
void treeNumberNodes(Node *root, int *count)
{
	if(root != NULL)
	{
		*count += 1;
		treeNumberNodes(root->left, count);
		treeNumberNodes(root->right, count);
	}
}

//Recebe a raiz da árvore e o valor de um nó e retorna a sua profundidade;
int treeDepthNode(Node *root, int value, int count)
{
	int result = 0;
	if(root != NULL)
	{
		if(value == root->value)
			result = count;
		else
			if(value < root->value)
				result = treeDepthNode(root->left, value, ++count);
			else
				result = treeDepthNode(root->right, value, ++count);
	}
	return result;
}

//Recebe a raiz da arvore e retorna a sua altura;
int treeHeight(Node *root)
{
	int result = -1;
	int left = 0, right = 0;
	if(root != NULL)
	{
		left = treeHeight(root->left);
		right = treeHeight(root->right);
		if(left > right)
			result = left + 1;
		else
			result = right + 1;
	}

	return result;
}
