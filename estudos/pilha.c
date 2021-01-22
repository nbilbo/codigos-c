/*
Uma demostração de uma estrutura do tipo pilha.
Será usado ponteiros.
*/

#include <stdio.h>

// constantes
#define TAM 10

// globais
int *inicio, *fim, pilha[TAM];

// protótipos
void display(int *inicio, int *fim);
void push(int valor);
int pop(void);

int main(void){
    int valor;

    // inicializando a pilha.
    inicio = fim = pilha;    
    
    // lendo os valores.
    do
    {
        putchar('\n');
        display(pilha, fim);
        puts("menu:");
        puts("0 executar pop()");
        puts("-1 encerrar o programa.");
        putchar('\n');

        printf("Digite o valor:");
        scanf("%d", &valor);

        if(valor == 0) pop();
        else if(valor != -1) push(valor);
    }
    while(valor != -1);

    return 0;
}


/*
Imprime os valores da pilha.

parametros
----------
inicio : endereco do primeiro elemento da pilha.

fim : endereco do ultimo elemento da pilha.
*/ 
void display(int *inicio, int *fim)
{   
    while(inicio != fim)
    {
        printf("[%d] ", *inicio);
        inicio++;
    }
    putchar('\n');
}


/*
Inserir um valor na pilha.

parametros
----------
valor : valor há ser adicionado na pilha.
*/
void push(int valor)
{
    if(fim == (inicio+TAM)) puts("Erro, pilha já está cheia");
    else
    {
       *fim = valor; 
        fim++;
    }
}


/*
Remover o ultimo elemento adicionado na pilha.

retorno
-------
-1 : se não houveer elementos na pilha.

inteiro : o ultimo elemento na pilha.
*/
int pop(void)
{
    if(inicio == fim) puts("Erro, pilha vazia");
    else
    {
        fim--;
        return *(fim+1);
    }
    
    return -1;
}
