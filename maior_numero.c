/*
   Procurar pelo maior numero em um vetor.
*/

#include <stdio.h>

// macros
#define MAX 4

// prototipos
void mostrar_vetor(int vetor[], int quant);
int get_maior(int vetor[], int quant);

int main(void){
    /* codigo */
    int meu_vetor[MAX] = {56, 78, 99, 31};
    
    mostrar_vetor(meu_vetor, MAX);
    printf("%d\n", get_maior(meu_vetor, MAX));

    return 0;
}


/*Imprime um vetor de inteiros.
 param vetor[] : ponteiro para um vetor de inteiros.
 param quant : quantidade de elementos do vetor.*/
void mostrar_vetor(int vetor[], int quant){
    for(; quant > 0; quant--) printf("[%d] ", vetor[quant-1]);
    putchar('\n');
}


/*Procura pelo maior numero em um vetor.

param vetor[] : ponteiro para um vetor de inteiros.
param quant : quantidade de elementos no vetor.

retorno : maior numero.*/
int get_maior(int vetor[], int quant){
    int maior, aux;

    if(quant > 2){
        maior = vetor[quant-1] > vetor[quant-2] ? vetor[quant-1] : vetor[quant-2];
        return maior > ( aux=get_maior(vetor, quant-2) ) ? maior : aux;
    }

    else if(quant == 2){
        return vetor[0] > vetor[1] ? vetor[0] : vetor[1];
    }

    else if(quant == 1){
        return vetor[0];
    }

}

