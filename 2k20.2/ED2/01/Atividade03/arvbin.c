#include <stdlib.h>
#include <stdio.h>
#include "arvbin.h"

struct no
{
	int value;
	Node *right;
	Node *left;
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
		(*root)->left = NULL;
		(*root)->right = NULL;
	}
	else
		if(value > (*root)->value)
			treeInsert(&(*root)->right, value);
		else
			treeInsert(&(*root)->left, value);
}

void treePrint(Node *root)
{
	
	if(root != NULL)
	{
		treePrint(root->left);
		printf("%d\n", root->value);
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

void treeNumberNodes(Node *root, int *count)
{
	if(root != NULL)
	{
		*count += 1;
		treeNumberNodes(root->left, count);
		treeNumberNodes(root->right, count);
	}
}

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
