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

void listRemove(Line **head, int line)
{
	if(head != NULL)
	{
		Line *anterior = NULL;
		Line *aux = *head;
		while(aux->nLine != line && aux != NULL)
		{
			anterior = aux;
			aux = aux->next;
		}

		if(!anterior)
		{
			*head = (*head)->next;
			free(aux);
		}
		else
			if(aux != NULL)
			{
				anterior = aux->next;
				free(aux);
			}
		
	}
}

void listPrint(Line *head)
{
	if(head != NULL)
	{
		listPrint(head->next);
		printf(" %d", head->nLine);
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
