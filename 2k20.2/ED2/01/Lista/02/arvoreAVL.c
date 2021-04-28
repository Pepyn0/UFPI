#include "arvoreAVL.h"
#include <stdio.h>
#include <stdlib.h>

struct no
{
	int value;	// valor
	int height; // altura
	Node *right;// direita
	Node *left;	// esquerda
};


void treeInitialize(Node **root)
{
	*root = NULL;
}


void treeInsert(Node **root, int value)
{
	if(*root == NULL)
	{
		*root = (Node *) malloc(sizeof(Node));
		(*root)->value = value;
		(*root)->height = 0;
		(*root)->left = NULL;
		(*root)->right = NULL;
	}
	else if(value > (*root)->value)
	{
		treeInsert(&(*root)->right, value);
		if(treeBalancingFactor((*root)) >= 2)
		{
			if(value > (*root)->right->value)
				treeRotationRR(root);
			else
				treeRotationRL(root);
		}
	}
	else
	{
		treeInsert(&(*root)->left, value);
		if(treeBalancingFactor((*root)) >= 2)
		{
			if(value < (*root)->left->value)
				treeRotationLL(root);
			else
				treeRotationLR(root);
		}
	}

	(*root)->height = treeBalancingMax(
		treeHeightOf((*root)->left),
		treeHeightOf((*root)->right)
		) + 1;
}


void treeSearch(Node *root, int key)
{
	if(root != NULL)
	{
		printf("%d\n", root->value);
		if(root->value == key)
			printf("Encontrou:sdklfjlasdjflasdjflaksjdlfkajsdlkfjalsdkjfaldskjflasdj %d\n", root->value);
		else
			if(key < root->value)
				treeSearch(root->left, key);
			else
				treeSearch(root->right, key);
	}
}


void treePrint(Node *root)
{
	
	if(root != NULL)
	{
		printf("%d\n", root->value);
		treePrint(root->left);
		treePrint(root->right);
	}
}


void treeFree(Node *root)
{
	if(root != NULL)
	{
		treeFree(root->left);
		treeFree(root->right);
		free(root);
	}
}


void treeRotationLL(Node **root)
{
	Node *aux;
	aux = (*root)->left;
	(*root)->left = aux->right;
	aux->right = *root;

	(*root)->height = treeBalancingMax(
		treeHeightOf((*root)->left),
		treeHeightOf((*root)->right)
		) + 1;

	aux->height = treeBalancingMax(
		treeHeightOf(aux->left),
		(*root)->height
		) + 1;

	*root = aux;
}

void treeRotationRR(Node **root)
{
	Node *aux;
	aux = (*root)->right;
	(*root)->right = aux->left;
	aux->left = *root;
	(*root)->height = treeBalancingMax(
		treeHeightOf((*root)->left),
		treeHeightOf((*root)->right)
		) + 1;

	aux->height = treeBalancingMax(
		treeHeightOf(aux->right),
		(*root)->height
		) + 1;

	*root = aux;
}

void treeRotationLR(Node **root)
{
	treeRotationRR(&(*root)->left);
	treeRotationLL(root);
}

void treeRotationRL(Node **root)
{
	treeRotationLL(&(*root)->right);
	treeRotationRR(root);
}

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

int treeHeightOf(Node *root)
{
	int result = -1;
	if(root)
		result = root->height;

	return result;
}

int treeBalancingFactor(Node *root)
{
	return labs(treeHeightOf(root->left) - treeHeightOf(root->right));
}

int treeBalancingMax(int x, int y)
{
	int result = y;
	if(x < y)
		result = x;

	return result;
}
