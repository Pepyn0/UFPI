#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM 10 // tamanho maximo de caracteres numa string;

//EXECUÇÃO
/*
	A execução do algoritimo consiste em por um número de strings a serem armazenadas no vetor e,
	em seguida, as strings. Por fim, o algoritmo irá mostrar a maior string, o numero de strings
	que começam com vogal e as strings maiores que 3 que começam com letra miúscula(se existirem).

	* Exemplo de entrada:
	3
	Abcd
	efghi
	Jkl

	* Exemplo de saída:
	efghi
	2
	Abcd

*/

//Função encarregada de preencher a matriz;
void preencher(char v[][TAM], int n);

//Função recursiva com pendência que devolva a string de maior tamanho;
char *maiorString(char v[][TAM], int n);

//Função recursiva sem pendência que devolva a quantidade de strings que iniciam com vogal;
int nVogal(char v[][TAM], int n, int count);
int isVogal(char *v);

//Função recursiva que devolva um vetor contendo somente as strings com tamanho >=4 e que iniciam com letra maiúscula;
void vMaiuscula(char v[][TAM], char vm[][TAM], int n, int *i);
int isMaiuscula(char *v);



int main(int argc, char const *argv[])
{
	int n;
	scanf("%d", &n);

	char vString[n][TAM];
	char mString[TAM];
	char vm[n][TAM];
	int tMaiuscula = 0;

	preencher(vString, n);
	strcpy(mString, maiorString(vString, n));
	printf("%s\n", mString);
	printf("%d\n", nVogal(vString, n, 0));
	
	vMaiuscula(vString, vm, n, &tMaiuscula);
	for(int i = 0; i < tMaiuscula; i++)
	{
		printf("%s\n", vm[i]);
	}
	return 0;
}

void preencher(char v[][TAM], int n)
{
	for(int i = 0; i < n; i++)
	{
		scanf("%s", v[i]);
	}
}

char *maiorString(char v[][TAM], int n)
{
	char string[TAM];	//
	char *str;			//
	str = string;		// Maneira simples de retornar um ponteiro sem alocação dinãmica;

	if(n == 0)// Condição de parada da função;
		return v[0];

	strcpy(str, maiorString(v, n - 1));// Empilhando a função e armazenando seu resultado em str com strcpy;

	// printf("\nValor de str: %s\n", str);
	// printf("Valor de v[n]: %s\n", v[n - 1]);
	// printf("Valor de n = %d\n", n - 1);

	if(strlen(str) <= strlen(v[n - 1]))// Comparando o tamanho do str com a do vetor[n - 1] com strlen;
		return v[n - 1];// Retornando o novo resultado do str;
	else
		return str;// Caso contrário, conservando o resultao do str;
}

int isVogal(char *v)// Função secundária que verifica se uma string inicia com vogal;
{
	if (*v == 'a' || *v == 'e' || *v == 'i' || *v == 'o'|| *v == 'u')
		return 1;

	if(*v == 'A' || *v == 'E' || *v == 'I' || *v == 'O'|| *v == 'U')
		return 1;

	return 0;
}

int nVogal(char v[][TAM], int n, int count)
{
	if(n == 0)// Condição de parada da função;
		return count;

	if(isVogal(v[n - 1]))// Verifica se a string é válida e chama a função novamente decrementando n e incrementando mais 1 no contador;
		nVogal(v, --n, ++count);
	else
		nVogal(v, --n, count);// Caso contrário, chama a função novamente sem alterar o contador;
}

int isMaiuscula(char *v)// Função secundária que verifica se uma string inicia com letra amiúscula e se tem mais que 3 caracteres;
{
	if(*v > 64 && *v < 91)
	{
		if(strlen(v) >= 4)
			return 1;
	}
	return 0;
}

void vMaiuscula(char v[][TAM], char vm[][TAM], int n, int *i)
{
	if(n == 0)// Condição de parada da função;
		return;

	if(isMaiuscula(v[n - 1]))// Verifica se é uma string válida;
	{
		strcpy(vm[(*i)], v[n - 1]);// Adiciona ao vetor;
		*i += 1;
	}
	vMaiuscula(v, vm, --n, i);// Chama a função novamente aplicando as mudancas(se ouveram) e decrementando n;
}
