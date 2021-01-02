/*Atribuindo valores em uma matriz*/
#include <stdio.h>
#define LINHAS 2
#define COLUNAS 5

int main(void){
	int matriz[LINHAS][COLUNAS];
	int *p = &matriz[0][0];

	for(int i=0; i<LINHAS; i++)
		for(int j=0; j<COLUNAS; j++){
			*(p+(i*COLUNAS)+j) = i;
			//matriz[i][j] = i;
		}


	for(int i=0; i<LINHAS; i++){
		for(int j=0; j<COLUNAS; j++){
			printf("%d ", *(p+(i*COLUNAS)+j));
			//printf("%d ", matriz[i][j]);
		}
		putchar('\n');
	}

	return 0;
}