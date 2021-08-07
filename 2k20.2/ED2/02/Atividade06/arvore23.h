/* TAD: arvore 2-3 */

#ifndef ARVORE23_H
#define ARVORE23_H


// Apelidando árvore
typedef struct no Node;

// Inicializar a arvore
void treeInitialize(Node **root);

// Mostra todos os valores contidos na árvore
void treePrint(Node *root);

// Liberara memória de toda a árvore
void treeFree(Node *root);

// Recebe uma árvore e um valor e o adiciona na arvore
Node *treeInsert(Node **root, int value, int *promove, Node **father);

/* Funções auxiliares na inserção e balanceamemto dos elementos na árvore */
// Recebe um valor e adiciona num nó já existente além de poder adicionar seu filho ao mesmo
void treeUpdateNode(Node **root, int value, Node *child);

// Recebe um valor e cria um novo nó com eles além de poder adicionar seu filhos ao mesmo
Node *treeCreateNode(int value1, Node *childLeft, Node *childCennter, Node *childRight);

// recebe uma árvore e retorna 1 se não tiver filhos, caso contrário, retorna 0
int treeIsLeaf(Node *root);

// Recebe uma árvore e um valor e retorna essa árvore dividida em 2 
Node *treeBreakingNode(Node **root, int value, int *promove, Node *child);


#endif /* ARVORE23_H */
