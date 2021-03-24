#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM 10


void preencher(char v[][TAM], int n);
char *maiorString(char v[][TAM], int n);

int isVogal(char *v);
int nVogal(char v[][TAM], int n, int count);

int isMaiuscula(char *v);
void vMaiuscula(char v[][TAM], char vm[][TAM], int n, int *i);



int main(int argc, char const *argv[])
{
	int n;
	printf("Numero de strings:\n");
	scanf("%d", &n);

	char vString[n][TAM];
	char mString[TAM];
	char vm[n][TAM];
	int tMaiuscula = 0;

	preencher(vString, n);
	strcpy(mString, maiorString(vString, n));
	printf("Maior string: %s\n", mString);
	// printf("N. strings inicializadas com vogal: %d\n", nVogal(vString, n, 0));
	
	// vMaiuscula(vString, vm, n, &tMaiuscula);
	// printf("Palavras maiores que 3 e com maiuscula:\n");
	// for(int i = 0; i < tMaiuscula; i++)
	// {
		// printf("%s\n", vm[i]);
	// }
	return 0;
}

void preencher(char v[][TAM], int n)
{
	for(int i = 0; i < n; i++)
	{
		printf("string %d:\n", i + 1);
		scanf("%s", v[i]);
	}
}

char *maiorString(char v[][TAM], int n)
{
	char string[TAM];
	char *str;
	str = string;
	if(n == 0)
		return v[0];

	strcpy(str, maiorString(v, n - 1));

	// printf("\nValor de str: %s\n", str);
	// printf("Valor de v[n]: %s\n", v[n - 1]);
	// printf("Valor de n = %d\n", n - 1);

	if(strlen(str) <= strlen(v[n - 1]))
		return v[n - 1];
	else
		return str;
}

int isVogal(char *v)
{
	if (*v == 'a' || *v == 'e' || *v == 'i' || *v == 'o'|| *v == 'u')
		return 1;

	if(*v == 'A' || *v == 'E' || *v == 'I' || *v == 'O'|| *v == 'U')
		return 1;

	return 0;
}

int nVogal(char v[][TAM], int n, int count)
{
	if(n == 0)
		return count;

	if(isVogal(v[n - 1]))
		nVogal(v, --n, ++count);
	else
		nVogal(v, --n, count);
}

int isMaiuscula(char *v)
{
	if(*v > 64 && *v < 91)
	{
		printf("aqui");
		if(strlen(v) >= 4)
			return 1;
	}
	return 0;
}

void vMaiuscula(char v[][TAM], char vm[][TAM], int n, int *i)
{
	if(n == 0)
		return;

	if(isMaiuscula(v[n - 1]))
	{
		printf("%d\n", i);
		strcpy(vm[(*i)], v[n - 1]);
		*i += 1;
	}
	vMaiuscula(v, vm, --n, i);
}
