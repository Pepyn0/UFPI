#include "grafo.h"
#include <stdio.h>

int main(int argc, char const *argv[])
{
	Grafo *gr;
	int ehDigrafo = 1;
	int ant[5];
	float dist[5];

	criarGrafo(&gr, 5, 5, 1);
	inserirAresta(&gr, 0, 1, ehDigrafo, 1);
	inserirAresta(&gr, 1, 3, ehDigrafo, 1);
	inserirAresta(&gr, 1, 2, ehDigrafo, 1);
	inserirAresta(&gr, 2, 4, ehDigrafo, 1);
	inserirAresta(&gr, 3, 0, ehDigrafo, 1);
	inserirAresta(&gr, 3, 4, ehDigrafo, 1);
	inserirAresta(&gr, 4, 1, ehDigrafo, 1);

	buscaMenorCaminhoGrafo(gr, 0, ant, dist);

	printf("Num | Dis | Ant\n");
	for(int i = 0; i < 5; i++)
		printf("%d   | %.1f | %d\n", i, dist[i], ant[i]);

	liberarGrafo(gr);
	return 0;
}
