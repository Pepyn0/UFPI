/* Cabeçalho */

#ifndef ARVBIN_H
#define ARVBIN_H

typedef struct no Node;

void treeInitialize(Node **root);
void treeInsert(Node **root, int value);
void treeSearch(Node *root, Node **result, int key);
void treePrint(Node *root);
void treeFree(Node *root);

int treeHeight(Node *root);
void treeNumberNodes(Node *root, int *count);
int treeDepthNode(Node *root, int value, int count);

#endif /* ARVBIN_H */
