/* TAD: lista encadeada */

#ifndef LISTA_H
#define LISTA_H

// Apelidando lista
typedef struct linha Line;

// Inicializar a lista
void listInitialize(Line **head);

// Recebe a linha e insere na cabeça  da lista
void listInsert(Line **head, int line);

// Remove um elemento da lista que contenha a chave
void listRemove(Line **head, int line);

// Recebe a lista e retorna o número de elementos
void listLen(Line *head, int *result);

// Recebe a lista e mostra todos os elementos
void listPrint(Line *head);

// Libera a memóriade toda a lista
void listFree(Line *head);


#endif /* LISTA_H */
