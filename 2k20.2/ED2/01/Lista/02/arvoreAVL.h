/* TAD: árvore AVL */

#ifndef ARVOREAVL_H
#define ARVOREAVL_H

// Apelidando árvore
typedef struct no Node;

// Inicializar a arvore
void treeInitialize(Node **root);

// Recebe um valor e a insere na arvore
void treeInsert(Node **root, int value);

// Recebe um valor e busca a existencia na arvore
void treeSearch(Node *root, int key);

// Mostra todos os valores contidos na árvore
void treePrint(Node *root);

// Liberara memória de toda a árvore
void treeFree(Node *root);

// Retorna a altura da arvore
int treeHeight(Node *root);

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

// Retorna o maior valor
int treeBalancingMax(int x, int y);

#endif /* ARVOREAVL_H */
