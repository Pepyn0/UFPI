#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int numberVertex; 	/* Número de Vertices */
int unvisited = 0; 	/* Não Visitado */
int wait = 1;		/* Esperar Sua Vez */
int visited = 2;	/* Visitado */

typedef struct fork fork;
typedef struct row row;


struct fork
{
	int **weights;  /* Pesos */
	int **edges;    /* Arestas */
	int *degree;    /* Grau */
	int *status;   	/* Visitado ou Não Visitado */
	int *distance;  /* Distância */
	int *previous;  /* Anterior */
	int *cash;      /* Dinheiro */
	int vertex;     /* Vertices */ 
	int weighted;   /* É ponderado */
};

struct row
{
	int vertex; /* Vertices */
	row *next;  /* Proximo */
};

void forkStart(fork **forks); /* montagem do grafo */
fork *forkCreate(int vertex, int weighted); /* Criar grafo */
void insertEdges(fork **forks, int origin, int destiny, int weights, int weighted); /* inserir dados nas aresta */
int searchDepth(fork **forks, int origin, int *visiteds, int **route, int pass, int cash); /* serve para montar todas as rotas possiveis, só que levando em conta o dinheiro disponivel. */
/* Todas as rotas ja visitadas ficam salvo na addFinalRow, para que no final consiga retornar o dinheiro restante com a maior rota encontrada */
int searchWidth(fork **forks, int origin, int **routeFinal, int cash); /* a partir de uma info, mapeia a distancia de cada vertice em relação a origem e retorna o valor que sobrou considerando a maior rota nesse caso. */

/* Funções para registrar rota */
void rideRoute(fork **forks, int origin, int **routeFinal, int final); /* montagem da rota */
int checkTheRow(int *list, int sizes, int number); /* ira retorna 1 caso ja exista na lista e 0 caso não exista */
int length(int *list); /* retorna o comprimento de um ponteiro */
void append(int **copys, int value, int local); /* adcionar no final da lista, utilizado no copy list */
void copyList(int **copys, int *original, int syzes, int local); /* faz um copia de um ponteiro para a primeira posição de um ponteiro de ponteiro inteiros. a fim de guardar as rotas da busca*/
row *addFinalRow(row *rows, int vertex); /* Adiciona um item no final da fila e retorna a fila modificada */
row *removeInitialRow(row ** rows); /* remove rota do inicial da fila */
void printRow(row *rows); /* printa a rota*/


int main()
{
	fork *forks;
	clock_t start, stop;

	int *visiteds = calloc (numberVertex, sizeof(int));
	int **routeFinal = malloc (sizeof(int*));
	routeFinal[0] = calloc (numberVertex, sizeof(int));
	routeFinal[1] = calloc (numberVertex, sizeof(int));

	int cashDepth = 0;
	int cashWidth = 0;
	double elapsed;

	forkStart(&forks);
	
	start = clock();
	cashDepth = searchDepth(&forks, 1, visiteds, routeFinal, 0, 60);
	stop = clock();
	elapsed = (stop - start) * 1000000.0;
	printf("\nBusca em Profundidade\nTempo decorrido em ns: %g\n", elapsed);

	start = clock();
	cashWidth = searchWidth(&forks, 1, routeFinal, 60);
	stop = clock();
	elapsed = (stop - start) * 1000000.0;
	printf("\nBusca em Largura\nTempo decorrido em ns: %g\n\n", elapsed);

	printf("Melhor Rota Com Profundidade: ");
	for (int i = 1; i < numberVertex && routeFinal[0][i] != 0; i++) 
		printf("%d ", routeFinal[0][i]);
	printf("\n");

	printf("Melhor Rota Com Largura: ");
	for (int i = 1; i < numberVertex && routeFinal[1][i] != 0; i++) 
		if (routeFinal[1][i] <= numberVertex)
			printf("%d ", routeFinal[1][i]);

	printf("\n\nProfundidade: %d\n", cashDepth);
	printf("Largura: %d\n", cashWidth);
    
	return 0;
}

void forkStart(fork **forks)
{
	int origin, destiny, weights;
	scanf("%d", &numberVertex);  /* Recebe o valor de vertices */
	*forks = forkCreate(numberVertex, 1);
	
	for (int i = 0; i < numberVertex; i++)
	{
		scanf("%d %d %d", &origin, &destiny, &weights);  /* Recebe os valores de origem, destino e o seu peso */
		insertEdges(forks, origin, destiny, weights, 0);
	}
}

fork *forkCreate(int vertex, int weighted)
{
	fork *forks;
	forks = (fork*) malloc (sizeof(fork));

	if (forks != NULL)
	{
		forks->vertex = vertex;
		forks->weighted = (weighted != 0)? 1:0;

		forks->degree = (int*) calloc (vertex, sizeof(int));
		forks->status = (int*) calloc (vertex, sizeof(int)); 
		forks->distance = (int*) calloc (vertex, sizeof(int));
		forks->previous = (int*) calloc (vertex, sizeof(int));
		forks->cash = (int*) calloc (vertex, sizeof(int));

		forks->edges = (int**) malloc (vertex*sizeof(int*));
		for (int i = 0; i < vertex; i++)
			forks->edges[i] = (int*) calloc (vertex, sizeof(int));

		if (forks->weighted)
		{
			forks->weights = (int**) malloc(vertex * sizeof(int*));
			for (int i = 0; i < vertex; i++)
				forks->weights[i] = (int*) calloc (vertex, sizeof(int));
		}
	}
	return forks;
}

void insertEdges(fork **forks, int origin, int destiny, int weights, int weighted)
{
	if (forks != NULL)
	{ 
		if (origin > 0 && origin <= (**forks).vertex)
		{
			if (destiny > 0 && destiny <= (**forks).vertex)
			{
				(**forks).edges[origin-1][(**forks).degree[origin-1]] = destiny;
				if((**forks).weighted)
					(**forks).weights[origin-1][(**forks).degree[origin-1]] = weights;

				(**forks).degree[origin-1]++;

				if (!weighted)
					insertEdges(forks, destiny, origin, weights, 1);
			}
		}
	}
}

int searchDepth(fork **forks, int origin, int *visiteds, int **routeFinal, int pass, int cash)
{
	int exchange = 60;
	
	if (forks != NULL) 
	{
		visiteds[pass] = origin;
		if (length(*routeFinal) < length(visiteds))
		{
			copyList(routeFinal, visiteds, numberVertex, 0);
			for(int i = 1; i < numberVertex && routeFinal[0][i] != 0; i++) 
				printf("%d ", routeFinal[0][i]);
			printf("\n");
			exchange = cash;
		}

		for (int i = 0; i < (*forks)->degree[origin-1]; i++)
		{
			if (!checkTheRow(visiteds, pass, (*forks)->edges[origin-1][i]) && cash >= (*forks)->weights[origin-1][i])
			{
				exchange = searchDepth(forks, (*forks)->edges[origin-1][i], visiteds, routeFinal, pass+1, cash-(*forks)->weights[origin-1][i]);
				if (exchange > cash) 
					exchange = cash;
				visiteds[pass+1] = 0;
			}
		}
	}
	return exchange;
}

int searchWidth(fork **forks, int origin, int **routeFinal, int cash)
{
	(*forks)->status[origin-1] = wait;
	(*forks)->distance[origin-1] = 0;
	(*forks)->previous[origin-1] = -1;
	(*forks)->cash[origin-1] = cash;
	row *scheduled = NULL;
	int exchange = cash, final = 0;

	scheduled = addFinalRow(scheduled, origin);
	while (scheduled != NULL)
	{
		row *aux = removeInitialRow(&scheduled);
		for (int i = 0; i < (*forks)->degree[aux->vertex-1]; i++)
		{
			if ((*forks)->status[((*forks)->edges[aux->vertex-1][i])-1] == unvisited && (*forks)->weights[aux->vertex-1][i] <= (*forks)->cash[aux->vertex-1])
			{
				(*forks)->status[((*forks)->edges[aux->vertex-1][i])-1] = wait;
				(*forks)->distance[((*forks)->weights[aux->vertex-1][i])-1] = ((*forks)->distance[aux->vertex-1])+1;
				(*forks)->previous[((*forks)->edges[aux->vertex-1][i])-1] = aux->vertex;
				(*forks)->cash[((*forks)->edges[aux->vertex-1][i])-1] = ((*forks)->cash[aux->vertex-1])-(*forks)->weights[aux->vertex-1][i];
				scheduled = addFinalRow(scheduled, (*forks)->edges[aux->vertex-1][i]);
			}
		}
		(*forks)->status[aux->vertex-1] = visited;
		final = aux->vertex;
		if (exchange > (*forks)->cash[aux->vertex-1]) 
			exchange = (*forks)->cash[aux->vertex-1];
		/* printf("dinheiro %d: %d\n", aux->vertex, (*forks)->cash[aux->vertex-1]); */
	}
	
	rideRoute(forks, origin, routeFinal, final);
	return exchange;
}

void rideRoute(fork **forks, int origin, int **routeFinal, int final)
{
	if (forks != NULL) 
		for (int i = 0; final != origin; i++)
		{
			append(routeFinal, final, 1);
			/* printf("final: %d\n", final); */
			final = (*forks)->previous[final-1];
		}   
}

int checkTheRow(int *list, int sizes, int number)
{
	int check = 0;
	for (int i = 0; i < sizes; i++)
		if (list[i] == number) 
			check = 1;
	return check;
}

int length(int *lista)
{
	int count = 0;
	for (int i = 1; i < numberVertex && lista[i] != 0; i++, count++);
	return count;
}

void append(int **copys, int value, int local)
{
	int i;
	for (i = 0; i < numberVertex && copys[local][i] != 0; i++);
	if (i < numberVertex) 
		copys[local][i] = value;
}

void copyList(int **copys, int *original, int syzes, int local)
{
	int i = 0;
	for (i = 0; i < syzes && original[i] != 0; i++, copys[local][i] = original[i]);
	for (i; i < syzes; i++) 
		copys[local][i] = 0;
}

row *addFinalRow(row *rows, int vertex)
{
	row *elemento = malloc (sizeof(row));
	elemento->vertex = vertex;
	elemento->next = NULL;

	row *aux;
	if (rows != NULL)
	{
		for (aux = rows; aux != NULL && aux->next != NULL; aux = aux->next);

		if (aux == NULL) 
			rows = elemento;
		else 
			aux->next = elemento;
	}
	else 
		rows = elemento;
	return rows;
}

row *removeInitialRow(row ** rows)
{
	row *aux = (*rows);
	(*rows) = (*rows)->next;
	return aux;
}

void printRow(row *rows)
{
	if (rows != NULL)
	{
		printf("%d ", rows->vertex);
		printRow(rows->next);
	}
}
