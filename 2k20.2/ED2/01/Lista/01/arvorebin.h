/* Cabeçalho */

#ifndef ARVOREBIN_H
#define ARVOREBIN_H

typedef struct no Node;

void treeInitialize(Node **root);
void treeInsert(Node **root, int value);
void treeSearch(Node *root, int key);
void treePrint(Node *root);
void treeFree(Node *root);

int treeHeight(Node *root);

#endif /* ARVOREBIN_H */
