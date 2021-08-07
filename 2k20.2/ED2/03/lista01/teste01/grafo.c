#include "grafo.h"
#include <stdio.h>
#include <stdlib.h>

struct grafo
{
	int ehPonderado;
	int nVertices;
	int grauMax;
	int **arestas;
	float **pesos;
	int *grau;
};

void criarGrafo(Grafo **gr, int nVertices, int grauMax, int ehPonderado)
{
	*gr = (Grafo *) malloc(sizeof(Grafo));
	(*gr)->nVertices = nVertices;
	(*gr)->grauMax = grauMax;
	(*gr)->ehPonderado = ehPonderado;
	(*gr)->grau = (int *) calloc(nVertices, sizeof(int));

	(*gr)->arestas = (int **) malloc(nVertices * sizeof(int *));
	for(int i = 0; i < nVertices; i++)
		(*gr)->arestas[i] = (int *) malloc(grauMax * sizeof(int));
	
	if((*gr)->ehPonderado)
	{
		(*gr)->pesos = (float **) malloc(nVertices * sizeof(float *));
		for(int i = 0; i < nVertices; i++)
			(*gr)->pesos[i] = (float *) malloc(grauMax * sizeof(float));
	}
}

void liberarGrafo(Grafo *gr)
{
	if(gr != NULL)
	{
		for(int i = 0; i < gr->nVertices; i++)
			free(gr->arestas[i]);
		free(gr->arestas);

		if(gr->ehPonderado)
		{
			for(int i = 0; i < gr->nVertices; i++)
				free(gr->pesos[i]);
			free(gr->pesos);
		}
		free(gr->grau);
		free(gr);
	}
}

int inserirAresta(Grafo **gr, int origem, int destino, int ehDigrafo, float peso)
{
	int inseriu = 1;
	if(*gr == NULL)
		inseriu = 0;

	else if(origem < 0 || origem >= (*gr)->nVertices)
		inseriu = 0;
	
	else if(destino < 0 || destino >= (*gr)->nVertices)
		inseriu = 0;
	else
	{
		(*gr)->arestas[origem][(*gr)->grau[origem]] = destino;
		if((*gr)->ehPonderado)
			(*gr)->pesos[origem][(*gr)->grau[origem]] = peso;
		(*gr)->grau[origem]++;

		if(!ehDigrafo)
			inseriu = inserirAresta(gr, destino, origem, 1, peso);
	}
	return inseriu;
}

int removerAresta(Grafo ** gr, int origem, int destino, int ehDigrafo)
{
	int inseriu = 1;
	int i;
	if(*gr == NULL)
		inseriu = 0;
	else if(origem < 0 || origem >= (*gr)->nVertices)
		inseriu = 0;
	else if(destino < 0 || destino >= (*gr)->nVertices)
		inseriu = 0;
	else
	{
		for(i = 0; i < (*gr)->grau[origem] && (*gr)->arestas[origem][i] != destino; i++);
		if(i == (*gr)->grau[origem])
			inseriu = 0;
		else
		{
			(*gr)->grau[origem]--;
			(*gr)->arestas[origem][i] = (*gr)->arestas[origem][(*gr)->grau[origem]];

			if((*gr)->ehPonderado)
				(*gr)->pesos[origem][i] = (*gr)->pesos[origem][(*gr)->grau[origem]];
			
			if(!ehDigrafo)
				inseriu = removerAresta(gr, destino, origem, 1);
		}
	}
	return inseriu;
}

void buscaProfundidade(Grafo *gr, int inicio, int *visitado, int cont)
{
	visitado[inicio] = cont;
	for(int i = 0; i < gr->grau[inicio]; i++)
	{
		if(visitado[gr->arestas[inicio][i]] == 0)
			buscaProfundidade(gr, gr->arestas[inicio][i], visitado, cont + 1);
	}
}

void buscaProfundidadeGrafo(Grafo *gr, int inicio, int *visitado)
{
	int cont = 1;
	for(int i = 0; i < gr->nVertices; i++)
		visitado[i] = 0;
	buscaProfundidade(gr, inicio, visitado, cont);
}


void buscaLarguraGrafo(Grafo *gr, int inicio, int *visitado)
{
	int cont = 1;
	int IF = 0;				//Inicio da fila
	int FF = 0;				//Fim da fila
	int NV = gr->nVertices;	//Numero de vertices
	int fila[NV];
	int vert;

	for(int i = 0; i < NV; i++)
		visitado[i] = 0;

	FF++;
	fila[FF] = inicio;
	visitado[inicio] = cont;
	while (IF != FF)
	{
		IF = (IF + 1) % NV;
		vert = fila[IF];
		cont++;
		for(int i = 0; i < gr->grau[vert];i++)
		{
			if(!visitado[gr->arestas[vert][i]])
			{
				FF = (FF + 1) % NV;
				fila[FF] = gr->arestas[vert][i];
				visitado[gr->arestas[vert][i]] = cont;
			}
		}
	}
}

int procuraMenorDistancia(float *distancia, int *visitado, int nVertices)
{
	int menor = -1, primeiro = 1;
	for(int i = 0; i < nVertices; i++)
	{
		if(distancia[i] >= 0 && visitado[i] == 0)
		{
			if(primeiro)
			{
				menor = i;
				primeiro = 0;
			}
			else
			{
				if(distancia[menor] > distancia[i])
					menor = i;
			}
		}
	}
	return menor;
}

void buscaMenorCaminhoGrafo(Grafo *gr, int inicio, int *anterior, float *distancia)
{
	int cont = gr->nVertices;
	int visitado[cont];
	int indiceAux;
	for(int i = 0; i < cont; i++)
	{
		visitado[i] = 0;
		anterior[i] = -1;
		distancia[i] = -1;
	}
	
	distancia[inicio] = 0;
	for( ; cont > 0; cont--)
	{
		int aux = procuraMenorDistancia(distancia, visitado, gr->nVertices);
		if(aux != -1)
		{
			visitado[aux] = 1;
			for(int i = 0; i < gr->grau[aux]; i++)
			{
				indiceAux = gr->arestas[aux][i];
				if(distancia[indiceAux] < 0)
				{
					distancia[indiceAux] = distancia[aux] + 1;
					//distancia[indiceAux] = distancia[aux] + gr->pesos[aux][i];
					anterior[indiceAux] = aux;
				}
				else
				{
					if(distancia[indiceAux] > distancia[aux] + 1) // distancia[indiceAux] > distancia[aux] + gr->pesos[aux][i]
					{
						distancia[indiceAux] = distancia[aux] + 1;
						//distancia[indiceAux] = distancia[aux] + gr->pesos[aux][i];
						anterior[indiceAux] = aux;
					}
				}
			}
		}
	}
}

