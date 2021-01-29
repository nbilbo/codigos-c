/*
Contar a quantidade de casas decimais um número 
flutuante possui.
*/

#include <stdio.h>

// protótipo
int decilen(float num);

int main(void){
	/* code */
	printf("1.23 possui %d casas decimais. \n", decilen(1.23));
	printf("3.14 possui %d casas decimais. \n", decilen(3.14));
	printf("1.8976 possui %d casas decimais. \n", decilen(1.8976));
	printf("1 possui %d casas decimais. \n", decilen(1));

	return 0;
}

/*
Contar a quantidade de casas decimais um número 
flutuante possui.

parametros
----------
num : o numero a ser analisado.

retornos
--------
int : a quantidade de casas decimais.
*/
int decilen(float num){
	if( num - (int)num ) return 1 + decilen(num*10);
	else return 0;
}
