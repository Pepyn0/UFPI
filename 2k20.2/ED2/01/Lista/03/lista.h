/* TAD lista encadeada */

#ifndef LISTA_H
#define LISTA_H

typedef struct linha Line;

void listInitialize(Line **head);
void listInsert(Line **head, int line);
void listRemove(Line **head, int line);
void listPrint(Line *head);
void listFree(Line *head);


#endif /* LISTA_H */
