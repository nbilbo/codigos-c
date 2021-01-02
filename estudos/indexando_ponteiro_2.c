// Atribuindo valores em vetor usando ponteiros
#include <stdio.h>

int main(void){
	int vetor[10], *p;

	p = vetor;
	for(register int i=0; i<10; i++){
		*(p+i) = i;
		//vetor[i] = i;
	}
	return 0;
}