#include "grafo.h"
#include <stdio.h>

int main(int argc, char const *argv[])
{
    Grafo *gr;
    int ehDigrafo = 1;
    int vis[5];
    int ant[5];
    float dist[5];
    criarGrafo(&gr, 5, 5, 0);
    inserirAresta(&gr, 0, 1, ehDigrafo, 0);
    inserirAresta(&gr, 1, 3, ehDigrafo, 0);
    inserirAresta(&gr, 1, 2, ehDigrafo, 0);
    inserirAresta(&gr, 2, 4, ehDigrafo, 0);
    inserirAresta(&gr, 3, 0, ehDigrafo, 0);
    inserirAresta(&gr, 3, 4, ehDigrafo, 0);
    inserirAresta(&gr, 4, 1, ehDigrafo, 0);

    //removerAresta(&gr, 0, 1, 0);

    //buscaProfundidadeGrafo(gr, 2, vis);
    //buscaLarguraGrafo(gr, 0, vis);

    buscaMenorCaminhoGrafo(gr, 0, ant, dist);

    for(int i = 0; i < 5; i++)
        printf("%d %.1f %d\n", i, dist[i], ant[i]);

    liberarGrafo(gr);
    return 0;
}
