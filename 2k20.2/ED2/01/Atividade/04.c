#include <stdio.h>


int mdc1(int a, int b, int *resp);
int mdc2(int n, int resto);

int main(int argc, char const *argv[])
{
	int numeros[4];
	for(int i = 0; i < 4; i++)
		scanf("%d", &numeros[i]);

	int resultado;
	//Sem pendência
	mdc1(numeros[0], numeros[1], &resultado);
	mdc1(numeros[2], resultado, &resultado);
	mdc1(numeros[3], resultado, &resultado);
	printf("%d\n", resultado);

	//Com pendência
	resultado = mdc2(numeros[0], mdc2(numeros[1], mdc2(numeros[2], numeros[3])));
	printf("%d\n", resultado);



	return 0;
}

int mdc1(int a, int b, int *resp)
{
	if(a > b)
		if(a % b == 0)
			*resp = b;
		else mdc1(b, a % b, resp);
	else mdc1(b, a, resp);
}


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
