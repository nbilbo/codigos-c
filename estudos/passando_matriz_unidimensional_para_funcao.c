/*
 Todos os tres metodos de declaracao produzem resultados identicos,
porque cada um diz ao compilador que um ponteiro inteiro deve ser recebido.
  */

#include <stdio.h>

void func1(int *matriz){ // ponteiro.
}

void func2(int matriz[10]){ // matriz dimensionada.

}

void func3(int matriz[]){ // matriz nao dimensionada.

}

int main(void){
	int matriz[10];
	
	func1(matriz);
	func2(matriz);
	func3(matriz);
	return 0;
}

