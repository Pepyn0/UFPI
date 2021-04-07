/* Cabeçalho */

#ifndef ARVORE_H
#define ARVORE_H

typedef struct no Node;

void treeInitialize(Node **root);
void treeInsert(Node **root, int value);
void treeMult5(Node *root, int *result);
void treeFree(Node *root);

#endif /* ARVORE_H */
