/*
Ponteiros podem ser organizados em matrizes como qualquer outro tipo de dado.
*/
#include <stdio.h>

// prototipos
void display_array(int *array[]);

int main(void)
{
    // ponteiro para uma matriz de ponteiros para inteiros.
    int *pont_mati[2];
    int salario = 1200, idade = 30;
    
    pont_mati[0] = &salario;
    *(pont_mati+1) = &idade;
    
    display_array(pont_mati);
    
    return 0;
}


void display_array(int *array[])
{
    for(register int i=0; i<2; i++) printf("%d ", *array[i]);
    printf("\n");
}


