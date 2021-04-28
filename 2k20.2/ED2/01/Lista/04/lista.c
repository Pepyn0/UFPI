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
		Line *anterior;
		Line *aux;
		aux = *head;
		anterior = NULL;
		while(aux != NULL && aux->nLine != line)
		{
			anterior = aux;
			aux = aux->next;
		}

		if(anterior == NULL)
		{
			*head = aux->next;
			free(aux);
		}
		else if(aux != NULL)
		{
			anterior->next = aux->next;
			free(aux);
		}
		
	}
}

void listLen(Line *head, int *result)
{
	*result = 0;

	if(head != NULL)
	{
		*result += 1;
		Line *aux;
		aux = head;
		while (aux->next != NULL)
		{
			*result += 1;
			aux = aux->next;
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
