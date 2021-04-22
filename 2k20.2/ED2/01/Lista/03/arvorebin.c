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

void treeInsert(Node **root, char *wold, int line)
{
	if(*root == NULL)
	{
		*root = (Node *) malloc(sizeof(Node));
		(*root)->left = NULL;
		(*root)->right = NULL;
		strcpy((*root)->word, wold);
		
		listInitialize(&(*root)->line);
		listInsert(&(*root)->line, line);
	}
	else
	{
		int cmp = strcmp(wold, (*root)->word);

		if(cmp > 0)
			treeInsert(&(*root)->right, wold, line);
		else
			if(cmp < 0)
				treeInsert(&(*root)->left, wold, line);
			else
				listInsert(&(*root)->line, line);
	}
}

void treeSearch(Node *root, char *wold, int count)
{
	if(root != NULL)
	{
		int cmp = strcmp(wold, root->word);
		if(cmp == 0)
		{
			printf("%s ::", root->word);
			listPrint(root->line);
			printf("\n%d passos\n", count);
		}
		else
			if(cmp < 0)
				treeSearch(root->left, wold, ++count);
			else
				treeSearch(root->right, wold, ++count);
	}
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
