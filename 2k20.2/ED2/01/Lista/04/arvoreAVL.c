#include "arvoreAVL.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct no
{
	char word[20];
	int height;
	Line *line;
	Node *right;
	Node *left;
};


void treeInitialize(Node **root)
{
	*root = NULL;
}

void treeInsert(Node **root, char *word, int line)
{
	if(*root == NULL)
	{
		*root = (Node *) malloc(sizeof(Node));
		(*root)->left = NULL;
		(*root)->right = NULL;
		(*root)->height = 0;
		strcpy((*root)->word, word);
		
		listInitialize(&(*root)->line);
		listInsert(&(*root)->line, line);
	}
	else
	{
		int cmp = strcmp(word, (*root)->word);

		if(cmp > 0)
		{
			treeInsert(&(*root)->right, word, line);
			if(treeBalancingFactor((*root)) >= 2)
			{
				if(strcmp(word, (*root)->right->word) > 0)
					treeRotationRR(root);
				else
					treeRotationRL(root);
			}
		}
		else if(cmp < 0)
		{
			treeInsert(&(*root)->left, word, line);
			if(treeBalancingFactor((*root)) >= 2)
			{
				if(strcmp(word, (*root)->left->word) < 0)
					treeRotationLL(root);
				else
					treeRotationLR(root);
			}
		}
		else
			listInsert(&(*root)->line, line);
	}

	(*root)->height = treeBalancingMax(
		treeHeightOf((*root)->left),
		treeHeightOf((*root)->right)
		) + 1;

}

void treeSearch(Node *root, char *word, Node **result, int count)
{
	*result = NULL;
	if(root != NULL)
	{
		int cmp = strcmp(word, root->word);
		if(cmp == 0)
		{
			*result = root;
			printf("%s ::", root->word);
			listPrint(root->line);
			printf("\n%d passos\n", count);
		}
		else
			if(cmp < 0)
				treeSearch(root->left, word, result, ++count);
			else
				treeSearch(root->right, word, result, ++count);
	}
}

void treeMin(Node *root, Node **result)
{
	*result = NULL;
	if(root != NULL)
	{
		Node *aux;
		aux = root;
		while (aux->left != NULL)
		{
			aux = aux->left;
		}
		*result = aux;
	}
}

void treeRemove(Node **root, char *word)
{
	if(*root != NULL)
	{
		int cmp = strcmp(word, (*root)->word);
		if(cmp < 0)
		{
			treeRemove(&(*root)->left, word);
			if(treeBalancingFactor((*root)) >= 2)
			{
				if(treeHeightOf((*root)->right->left) <= treeHeightOf((*root)->right->right))
					treeRotationRR(root);
				else
					treeRotationRL(root);
			}
		}
		else if(cmp > 0)
		{
			treeRemove(&(*root)->right, word);
			if(treeBalancingFactor((*root)) >= 2)
			{
				if(treeHeightOf((*root)->left->right) <= treeHeightOf((*root)->left->left))
					treeRotationLL(root);
				else
					treeRotationLR(root);
			}
		}
		else
		{
			if((*root)->left == NULL && (*root)->right == NULL)
			{
				free(*root);
				*root = NULL;
			}
			else if((*root)->left == NULL && (*root)->right != NULL)
			{
				Node *aux;
				aux = (*root)->right;
				free(*root);
				*root = aux;
			}
			else if((*root)->left != NULL && (*root)->right == NULL)
			{
				Node *aux;
				aux = (*root)->left;
				free(*root);
				*root = aux;
			}
			else
			{
				Node *aux;
				Line *auxLine;
				char auxWord[20];
				treeMin((*root)->right, &aux);

				auxLine = aux->line;
				strcpy(auxWord, aux->word);
				treeRemove(&(*root)->right, aux->word);
				(*root)->line = auxLine;
				strcpy((*root)->word, auxWord);
				if(treeBalancingFactor((*root)) >= 2)
				{
					if(treeHeightOf((*root)->left->right) <= treeHeightOf((*root)->left->left))
						treeRotationLL(root);
					else
						treeRotationLR(root);
				}
			}
		}
	}
}

int treeRemoveLine(Node **root, char *word, int line)
{
	int result = -1;
	int cmp = strcmp(word, (*root)->word);
	if(cmp < 0)
		treeRemoveLine(&(*root)->left, word, line);
	else if(cmp > 0)
		treeRemoveLine(&(*root)->right, word, line);
	else
	{
		int nlines;
		listLen((*root)->line, &nlines);
		if(nlines == 1)
		{
			listFree((*root)->line);
			treeRemove(root, word);
			result = 0;
		}
		else if(nlines > 1)
		{
			listRemove(&(*root)->line, line);
			result = 1;
		}
	}
	return result;
}

void treePrint(Node *root)
{
	
	if(root != NULL)
	{
		treePrint(root->left);
		printf("%s ::", root->word);
		listPrint(root->line);
		printf("\n");
		treePrint(root->right);
	}
}

void treeFree(Node *root)
{
	if(root != NULL)
	{
		treeFree(root->left);
		treeFree(root->right);

		listFree(root->line);
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
