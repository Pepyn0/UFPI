#include "lista.h"
#include <stdlib.h>
#include <stdio.h>

struct linha
{
	int nLine;
	Line *next;
};




void listInitialize(Line **head)
{
	*head = NULL;
}

void listInsert(Line **head, int line)
{
	if(*head == NULL)
	{
		*head = (Line *) malloc(sizeof(Line));
		(*head)->nLine = line;
		(*head)->next = NULL;
	}
	else
	{
		Line *new;
		new = (Line *) malloc(sizeof(Line));
		new->nLine = line;
		new->next = *head;
		*head = new;
	}
}

void listPrint(Line *head)
{
	if(head != NULL)
	{
		printf("Linha: %d\n", head->nLine);
		listPrint(head->next);
	}
}

void listFree(Line *head)
{
	if(head != NULL)
	{
		listFree(head->next);
		free(head);
	}
}
