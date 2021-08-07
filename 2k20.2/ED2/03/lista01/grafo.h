/* TAD: Grafos */

#ifndef GRAFO_H
#define GRAFO_H

// Apelidando grafo
typedef struct grafo Grafo;

// recebe um ponteiro do tipo grafo e aloca espaço para um grafo de acordo o que é exigido
void criarGrafo(Grafo **gr, int nro_vertices, int grau_max, int eh_ponderado);

// Recebe os pontos de origem e destino e insere a aresta com seu peso
int inserirAresta(Grafo **gr, int origem, int destino, int ehDigrafo, float peso);

// Libera o Grafo
void liberarGrafo(Grafo *gr);

// Algoritmo de Dijkstra
int procuraMenorDistancia(float *distancia, int *vistado, int nVertices);
void buscaMenorCaminhoGrafo(Grafo *gr, int inicio, int *anterior, float *distancia);


#endif /* GRAFO_H */
