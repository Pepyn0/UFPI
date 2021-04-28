/* TAD: arvore AVL */

#ifndef ARVOREAVL_H
#define ARVOREAVL_H

/* Dependencia de módulos: */
#include "lista.h"

// Apelidando árvore
typedef struct no Node;

// Inicializar a arvore
void treeInitialize(Node **root);

// Recebe a palavra e a linha onde ela se encontra e a insere na arvore
void treeInsert(Node **root, char *wold, int line);

// Recebe uma palavra e busca a existencia na arvore, além de contar o numero de passos
void treeSearch(Node *root, char *wold, Node **result, int count);

// Remove um elemento da árvore que contenha a palavra chave
void treeRemove(Node **root, char *word);

// Remove um elemento da lista e, se existir apenas 1 elemento, remove o elemento da árvore 
int treeRemoveLine(Node **root, char *word, int line);

// Mostra todos os valores contidos na árvore
void treePrint(Node *root);

// Liberara memória de toda a árvore
void treeFree(Node *root);

/* Funções de balanceamento da arvore */
// Função de rotação simples a esquerda
void treeRotationRR(Node **root);

// Função de rotação simples a direita
void treeRotationLL(Node **root);

// Função de rotação dupla a direita
void treeRotationLR(Node **root);

// Função de rotação dupla a esquerda
void treeRotationRL(Node **root);

/* Funções auxiliares para o balanceamento da arvore AVL */
// Retorna a altura armazenada no nó da arvore
int treeHeightOf(Node *root);

// Retorna a diferença dos filhos da direita em relação aos filhos da esquerda
int treeBalancingFactor(Node *root);

// retorna o maior valor
int treeBalancingMax(int x, int y);

/* Funções auxiliares a remoção de um elemento da árvore */
// Retorna o menor elemento da árvore
void treeMin(Node *root, Node **result);

#endif /* ARVOREAVL_H */
