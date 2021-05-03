#include "arvore23.h"
#include <stdio.h>

int main(int argc, char const *argv[])
{
    Node * raiz;
    int promove = 0;
    treeInitialize(&raiz);

    treeInsert(&raiz, 10, &promove, NULL);
    treeInsert(&raiz, 5, &promove, NULL);
    treeInsert(&raiz, 25, &promove, NULL);
    treeInsert(&raiz, 20, &promove, NULL);
    treeInsert(&raiz, 7, &promove, NULL);
    treePrint(raiz);
    treeFree(raiz);
    return 0;
}
