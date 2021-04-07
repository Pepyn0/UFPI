/* Cabeçalho */

#ifndef ARVORE_H
#define ARVORE_H

typedef struct no Node;

void treeInitialize(Node **root);
void treeInsert(Node **root, int code, char *model, char *tissue, float size, float length, char *color);
void treeFree(Node *root);
void treeShow(Node *root);

#endif /* ARVORE_H */
