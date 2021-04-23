#include "arvorebin.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct no
{
	char word[20];
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
		strcpy((*root)->word, word);
		
		listInitialize(&(*root)->line);
		listInsert(&(*root)->line, line);
	}
	else
	{
		int cmp = strcmp(word, (*root)->word);

		if(cmp > 0)
			treeInsert(&(*root)->right, word, line);
		else
			if(cmp < 0)
				treeInsert(&(*root)->left, word, line);
			else
				listInsert(&(*root)->line, line);
	}
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
			treeRemove(&(*root)->left, word);
		else if(cmp > 0)
			treeRemove(&(*root)->right, word);
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
				treeRemove(root, aux->word);
				(*root)->line = auxLine;
				strcpy((*root)->word, auxWord);
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
