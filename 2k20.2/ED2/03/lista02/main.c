#include "grafos.h"
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int main(int argc, char const *argv[])
{
	time_t vTime[2];
	double tempo;

	int vertices, arestas, origem, destino;
	float pedagio, valor;
	printf("Entre com o número de cidades e ruas respectivamente\n");
	scanf("%d", &vertices);
	scanf("%d", &arestas);

	int ehPonderado = 1;
	int ehDigrafo = 0;


	Grafo *gr;
	criarGrafo(&gr, vertices, arestas, 1);
	
	for(int i = 0; i < arestas; i++)
	{
		printf("Entre com o numero que identifica a cidade origem de uma estrada:\n");
		scanf("%d", &origem);
		printf("Entre com o numero que identifica a cidade destino de uma estrada:\n");
		scanf("%d", &destino);
		printf("Entre com o valor do pedágio dessa estrada:\n");
		scanf("%f", &pedagio);

		inserirAresta(&gr, origem, destino, ehDigrafo, pedagio);
	}

	int **matriz = (int **) calloc(vertices, sizeof(int *));
	for(int i = 0; i < vertices; i++)
	{
		matriz[i] = (int *) calloc(2, sizeof(int));
	}

	printf("Entre com o numero correspondente a cidade onde esta:\n");
	scanf("%d", &origem);
	printf("Entre com o valor maximo a ser gasto:\n");
	scanf("%f", &valor);


	printf("\nBusca em profundiadade:\n");
	
	vTime[0] = clock();
	buscaProfundidadeGrafo(gr, origem, valor, matriz);
	vTime[1] = clock();

	tempo = (vTime[1] - vTime[0]) * 1e+6;
	printf("Tempo gasto: %g\n\n", tempo);

	for(int i = 0; i < vertices; i++)
	{
		if(matriz[i][1])
			printf("cidade %d gastando %d\n", i, matriz[i][1]);
	}

	printf("\nBusca em largura:\n");

	vTime[0] = clock();
	buscaLarguraGrafo(gr, origem, valor, matriz);
	vTime[1] = clock();


	tempo = (vTime[1] - vTime[0]) * 1e+6;
	printf("Tempo gasto: %g\n\n", tempo);

	for(int i = 0; i < vertices; i++)
	{
		if(matriz[i][1])
			printf("cidade %d gastando %d\n", i, matriz[i][1]);
	}

	for(int i = 0; i < vertices; i++)
	{
		free(matriz[i]);
	}
	free(matriz);

	liberarGrafo(gr);
	return 0;
}
