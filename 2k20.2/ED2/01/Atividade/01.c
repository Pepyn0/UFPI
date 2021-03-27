#include <stdio.h>
#include <stdlib.h>

void altera1(int **p, int *a)
{
	**p = *a;
	*a = *a + 50;
}
void altera2(int **p, int *b)
{
	*p = b;
	*b = *b +30;
}

int main()
{ 
	int x,y, *px, *py;
	x = 10;
	y = x + 20;
	px = &x;
	py = &y;
	printf("x = %d, End. x = %p, px = %p, y = %d \n",x,&x, px,y);

	altera1(&px, &y);

	printf("x = %d, End. x = %p, px = %p, y = %d \n",x,&x, px,y);

	getchar();

	printf("y = %d, End. y = %p, py = %p, x = %d \n",y,&y, py,x);

	altera2(&py, &x);

	printf("y = %d, End. y = %p, py = %p, x = %d \n",y,&y, py,x);

	getchar();
	return(0);
}

/*
a) Qual a diferença entre px e x?
	R = x é uma variável e px é um ponteiro que, neste caso aponta para o endereço da variavel x.

b) Qual a diferença entre px e py?
	R = px é um ponteiro que está apontando para o endereço de memória da variavel x e py é um ponteiro que está apontando para o endereço de memória da variavel y.

c) Quais são os valores impressos pelo primeiro printf?
	R = Mostra o valor inicial de x(10), o endereço de x(0061FF1C), o endereço que o ponteiro px está apontando(0061FF1C) e o valor de y(30).

d) O que muda do primeiro printf para o segundo?
	R = O valor de x é alterado pelo valor de y(30) devido a função altera1 que faz o ponteiro px, que aponta para o endereço de x, receber a referencia de y e, em seguida, fazer a referencia de y receber mais 50.

e) Quais os valores impressos pelo terceiro print?
	R = Mostra o valor de y(80), o endereço de y(0061FF18), o endereço que o ponteiro py está apontando(0061FF18) e o valor de x(30).

f) O que muda do terceiro para o quarto print?
	R = O valor de x é alterado para 60 devido a função altera2 que faz a referencia de x receber mais 30 e também altera o py que começa a apontar para o endereco de x.

g) Explique a diferença entre o altera1 e o altera2.
	R = A função altera1 faz o endereço que p aponta receber o conteúdo do endereço de a, já a função altera2 faz p apontar para o endereço de memória de b.
*/
