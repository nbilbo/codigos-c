/*
 Uma funcao que recebe uma matriz bidimensional
 como parametro deve definir pelo menos o comprimento
 da segunda dimensao. O compilador precisa saber o 
 comprimento de cada linha para indexar a matriz
 corretamente.
 */

#include <stdio.h>

void func1(int matriz[][10]){

}

int main(void){
	int matriz[10][10];
	func1(matriz);

	return 0;
}
