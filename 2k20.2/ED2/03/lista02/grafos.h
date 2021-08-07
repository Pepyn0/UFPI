/* TAD: Grafos */

#ifndef GRAFOS_H
#define GRAFOS_H

/* Dependencia de módulos: */

// Apelidando grafo
typedef struct grafo Grafo;

// Recebe um ponteiro do tipo grafo e aloca espaço para um grafo de acordo o que é exigido
void criarGrafo(Grafo **gr, int nVertices, int grauMax, int ehPonderado);

// Recebe os pontos de origem e destino e insere a aresta com seu peso
int inserirAresta(Grafo **gr, int origem, int destino, int ehDigrafo, float peso);

// Libera o Grafo
void liberarGrafo(Grafo *gr);

// Remove uma aresta entre 2 pontos
int removerAresta(Grafo ** gr, int origem, int destino, int ehDigrafo);


// Algoritmo de busca de profundidade
void buscaProfundidadeGrafo(Grafo *gr, int inicio, float dinheiro, int **visitado);
void buscaProfundidade(Grafo *gr, int inicio, float dinheiro, float dinheiroGasto, int **visitado, int cont);

// Algoritmo de busca de largura
void buscaLarguraGrafo(Grafo *gr, int inicio, float dinheiro, int **visitado);


#endif /* GRAFOS_H */
