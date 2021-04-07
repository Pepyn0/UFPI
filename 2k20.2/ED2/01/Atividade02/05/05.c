#include "arvore.h"
#include <stdio.h>

int main(int argc, char const *argv[])
{
    Node *arvore;
    treeInitialize(&arvore);
    treeInsert(&arvore, 400);
    treeInsert(&arvore, 150);
    treeInsert(&arvore, 500);
    treeInsert(&arvore, 80);

    int valor;
    valor = treeFather(arvore, 20);
    printf("%d\n", valor);

    treeFree(arvore);
    return 0;
}
