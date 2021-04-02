#include <stdio.h>

//EXECUÇÃO
/*
	A execução do algoritimo consiste em por 4 valores inteiros a serem armazenadas no vetor. Por fim, o algoritmo irá mostrar o maior divisor comum entre os 4(com uma função recursiva sem pendência e em seguida com uma função recursiva com pendência).

	* Exemplo de entrada:
	5 11 21 30

	* Exemplo de saída:
	1
	1

*/

//Recebe 2 valores e uma variável por referência que retornará o maior divisor comum sem pendência;
int mdc1(int a, int b, int *resp);

//Recebe 2 valores e retorna o maior divisor comum utilizando pendência;
int mdc2(int n, int resto);

int main(int argc, char const *argv[])
{
	int numeros[4];
	for(int i = 0; i < 4; i++)
		scanf("%d", &numeros[i]);

	int resultado;
	//Sem pendência
	mdc1(numeros[0], numeros[1], &resultado);	//
	mdc1(numeros[2], resultado, &resultado);	//
	mdc1(numeros[3], resultado, &resultado);	//Buscando o mdc dos 4 numeros;
	printf("%d\n", resultado);

	//Com pendência
	resultado = mdc2(numeros[0], mdc2(numeros[1], mdc2(numeros[2], numeros[3]))); //Buscando o mdc dos 4 numeros com pendencia;
	printf("%d\n", resultado);



	return 0;
}

//Recebe 2 valores e uma variável por referência que retornará o maior divisor comum sem pendência;
int mdc1(int a, int b, int *resp)
{
	if(a > b)
		if(a % b == 0)
			*resp = b;
		else mdc1(b, a % b, resp);
	else mdc1(b, a, resp);
}

//Recebe 2 valores e retorna o maior divisor comum utilizando pendência;
int mdc2(int valor, int resto)
{
	int result;
	if(valor > resto)
		if(valor % resto == 0)
			result = resto;
		else
			result = mdc2(resto, valor % resto);
	else
		result = mdc2(resto, valor);

	return result;
}
