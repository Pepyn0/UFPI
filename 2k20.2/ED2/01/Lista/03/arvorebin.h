/* TAD: arvore binária */

#ifndef ARVOREBIN_H
#define ARVOREBIN_H

/* Dependencia de módulos: */
#include "lista.h"

typedef struct no Node;

void treeInitialize(Node **root);
void treeInsert(Node **root, char *wold, int line);
void treeSearch(Node *root, char *wold, Node **result, int count);
void treePrint(Node *root);
void treeFree(Node *root);

#endif /* ARVOREBIN_H */
