#include "arvore23.h"
#include <stdlib.h>
#include <stdio.h>


struct no
{
	int lValue;       // Valor da esqerda(primeiro valor)
	int rValue;       // Valor da direita(segundo valor)
	int nValues;      // Número de valores no nó
	Node *left;     // Nó da esquerda
	Node *center;   // Nó do meio
	Node *right;	// Nó da direita
};


void treeInitialize(Node **root)
{
	*root = NULL;
}

void treeUpdateNode(Node **root, int value, Node *child)
{
	if(value >= (*root)->lValue)
	{
		(*root)->rValue = value;
		(*root)->right = child;
	}
	else
	{
		(*root)->rValue = (*root)->lValue;
		(*root)->lValue = value;
		(*root)->right = (*root)->center;
		(*root)->center = child;
	}
	(*root)->nValues = 2;
}

Node *treeCreateNode(int value1, Node *childLeft, Node *childCenter, Node *childRight)
{
	Node *new;
	new = (Node *) malloc(sizeof(Node));
	new->lValue = value1;
	new->rValue = 0;
	new->nValues = 1;
	new->left = childLeft;
	new->center = childCenter;
	new->right = childRight;

	return new;
}

int treeIsLeaf(Node *root)
{
	int leaf = 0;
	if(root->left == NULL && root->center == NULL && root->right == NULL)
		leaf = 1;

	return leaf;
}

Node *treeBreakingNode(Node **root, int value, int *promove, Node *child)
{
	Node *aux;
	if(value < (*root)->lValue)
	{
		*promove = (*root)->lValue;
		(*root)->lValue = value;
	}
	else if(value > (*root)->rValue)
	{
		*promove = (*root)->rValue;
		(*root)->rValue = value;
	}
	else
	{
		*promove = value;
	}
	aux = treeCreateNode((*root)->rValue, (*root)->right, child, NULL);

	(*root)->nValues = 1;
	(*root)->rValue = 0;
	(*root)->right = NULL;

	return aux;
}

Node *treeInsert(Node **root, int value, int *promove, Node **father)
{
	Node *paux;
	if(*root == NULL)
	{
		*root = treeCreateNode(value, NULL, NULL, NULL);
		paux = NULL;
	}
	else
	{
		if(treeIsLeaf(*root))
		{
			if((*root)->nValues == 1)
			{
				treeUpdateNode(root, value, NULL);
				paux = NULL;
			}
			else
			{
				paux = treeBreakingNode(root, value, promove, NULL);
			}
		}
		else
		{
			if(value < (*root)->lValue)
				paux = treeInsert(&(*root)->left, value, promove, root);

			else if(((*root)->nValues == 1) || (value < (*root)->rValue))
				paux = treeInsert(&(*root)->center, value, promove, root);

			else
				paux = treeInsert(&(*root)->right, value, promove, root);
		}
	}

	if(paux != NULL)
	{
		if(father == NULL)
		{
			*root = treeCreateNode(*promove, (*root), paux, NULL);
			paux = NULL;
		}
		else if((*father)->nValues == 1)
		{
			treeUpdateNode(father, *promove, paux);
			paux = NULL;
		}
		else
		{
			int guardar = *promove;
			paux = treeBreakingNode(father, guardar, promove, paux);
		}
	}

	return paux;
}

void treeFree(Node *root)
{
	if(root != NULL)
	{
		treeFree(root->left);
		treeFree(root->center);
		treeFree(root->right);

		free(root);
	}
}

void treePrint(Node *root)
{
	if(root != NULL)
	{
		treePrint(root->left);
		printf("%d\n", root->lValue);
		treePrint(root->center);
		if(root->rValue)
		{
			printf("%d\n", root->rValue);
			treePrint(root->right);
		}
	}
}
