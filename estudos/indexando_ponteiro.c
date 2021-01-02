/*
Um nome de matriz sem o indice é 
um ponteiro para o primeiro elemento.
*/
#include <stdio.h>

int main(void)
{
	int vetor[10], *p;

	p = vetor;
	vetor[5] = 100;
	*(p+5) = 100; // aritimetica de ponteiro

	return 0;
}