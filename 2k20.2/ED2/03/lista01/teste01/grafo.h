/* TAD: Grafos */

#ifndef GRAFO_H
#define GRAFO_H

/* Dependencia de módulos: */

// Apelidando grafo
typedef struct grafo Grafo;

void criarGrafo(Grafo **gr, int nVertices, int grauMax, int ehPonderado);
int inserirAresta(Grafo **gr, int origem, int destino, int ehDigrafo, float peso);
int removerAresta(Grafo ** gr, int origem, int destino, int ehDigrafo);

void buscaProfundidadeGrafo(Grafo *gr, int inicio, int *visitado);
void buscaProfundidade(Grafo *gr, int inicio, int *visitado, int cont);

void buscaLarguraGrafo(Grafo *gr, int inicio, int *visitado);

int procuraMenorDistancia(float *distancia, int *vistado, int nVertices);
void buscaMenorCaminhoGrafo(Grafo *gr, int inicio, int *anterior, float *distancia);

void liberarGrafo(Grafo *gr);

#endif /* GRAFO_H */
