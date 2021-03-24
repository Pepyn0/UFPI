#include <stdio.h>

//EXECUÇÃO
/*
	A execução do algoritimo consiste em por um número inteiro e, em seguida,
	o algoritmo irá mostrar todos os seus divisores e finalizará.

	* Exemplo de entrada:
	10

	* Exemplo de saída:
	10
	5
	2
	1

*/

// Recebe um inteiro dado pelo usuário e um índice com o mesmo valor
void divisor(int valor, int i);

int main(int argc, char const *argv[])
{
	int n;
	scanf("%d", &n);
	divisor(n, n);
	return 0;
}

void divisor(int valor, int i)
{
	if(valor == 0) // Verifica se o valor digitado é 0 e finaliza
	{
		printf("%d\n", valor);
		return;
	}

	if(i == 0) // Finaliza o algoritimo quando o índice chega a zero
	{
		return;
	}

	if(valor % i == 0) // Verifica quando o índice é divisivel pelo valor e mostra-o
		printf("%d\n", i);

	divisor(valor, --i); // Chama a função novamente, decrementando o valor do índice
}
