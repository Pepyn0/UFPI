/* Cabeçalho */

#ifndef ARVORE_H
#define ARVORE_H

typedef struct no Node;

void treeInitialize(Node **root);
void treeInsert(Node **root, int value);
int treeFather(Node *root, int key);
void treeFree(Node *root);

#endif /* ARVORE_H */
