/*
Um jogo da velha onde o objetivo é vencer a maquina.
*/

#include <stdio.h>


// constantes
#define LINHAS 3
#define COLUNAS 3

// globais


// protótipos
void reset_matriz(char *matriz, int linhas, int colunas);
void display_matriz(char *matriz, int linhas, int colunas);
char checar_linha(char *matriz, int colunas);
char checar_coluna(char *matriz, int linhas, int colunas);
char checar_diagonal(char *matriz, int linhas, int colunas);
char checar_diagonal_inverso(char *matriz, int linhas, int colunas);

// principal
int main(void){
	char matriz[][COLUNAS] = {
		'o', 'o', 'x',
		'o', 'x', 'x',
		'x', 'o', 'o'
	};
    // testes
	display_matriz(&matriz[0][0], LINHAS, COLUNAS);
    // printf("%c \n", checar_linha(&matriz[1][0], COLUNAS));
	// printf("%c \n", checar_coluna(&matriz[0][2], LINHAS, COLUNAS));
    // printf("%c \n", checar_diagonal(&matriz[0][0], LINHAS, COLUNAS));
    printf("%c \n", checar_diagonal_inverso(&matriz[0][COLUNAS-1], LINHAS, COLUNAS));

	return 0;
}


/*
Definir espaços vazios em cada elemento da matriz.

parametros
----------
matriz : ponteiro do tipo char
	um ponteiro para o primeiro elemento da matriz.

linhas : int
    quantidade de linhas da matriz.

colunas : int
    quantidade colunas em cada uma das linhas da matriz.
*/
void reset_matriz(char *matriz, int linhas, int colunas){
    for(register int i=0; i<linhas; i++)
        for(register int j=0; j<colunas; j++)
           *(matriz+(i*colunas)+j) = ' ';
}


/*
Imprime os elementos da matriz.

parametros
----------
matriz : ponteiro do tipo char
	um ponteiro para o primeiro elemento da matriz.

linhas : int
    quantidade de linhas da matriz.

colunas : int
    quantidade de colunas em cada linha da matriz.
*/
void display_matriz(char *matriz, int linhas, int colunas){
	for(register int i=0; i<linhas; i++){
		for(register int j=0; j<colunas; j++){
            printf("[%c] ", *(matriz+(i*colunas)+j));
		}
        printf("\n");
	}	
}


/*
Verificar se os elementos da linha são iguais.

parametros
----------
matriz : ponteiro do tipo char.
    ponteiro para o primeiro elemento da linha.

colunas : int
    quantidade de colunas que a linha possui.

retorno
-------
'\0'
    (caractere nulo); se a linha não possuir elementos iguais.

char
    (penultimo elemento da linha); se a linha possuir elementos iguais.
*/
char checar_linha(char *matriz, int colunas){
    if(colunas-1){
        if(*matriz != *(matriz+1)) return '\0';
        else return checar_linha(++matriz, --colunas);
    }            
    else return *matriz;
}


/*
Verificar se os elementos da coluna são iguais.

parametros
----------
matriz : ponteiro do tipo char.
    ponteiro para o primeiro elemento da coluna.

linhas : int
    quantidade de linhas da matriz.

colunas : int
    quantidade de colunas em cada linha.

retorno
-------
'\0'
    (caractere nulo); coluna não possui elementos iguais.

char
    (penultimo elemento da coluna); se a linha possuir elementos iguais.
*/
char checar_coluna(char *matriz, int linhas, int colunas){
    if(linhas-1){
        if(*matriz != *(matriz+colunas)) return '\0';
        else return checar_coluna(matriz+colunas, --linhas, colunas);        
    }
    else return *matriz;
}


/*
Verificar os elementos na diagonal da matriz.

parametros
----------
matriz : ponteiro do tipo char
    ponteiro do primeiro elemento da matriz.

linhas : int
    quantidade de linhas na matriz.

colunas : int
    quantidade de colunas em cada linha.

retorno
-------
'\0'
    (caractere nulo); elementos na diagonal diferentes.

char
    (penultimo elemento na diagonal); elementos na diagonal iguais.
*/
char checar_diagonal(char *matriz, int linhas, int colunas){
    if(linhas-1){
        if(*matriz != *(matriz+colunas+1)) return '\0';
        else return checar_diagonal(matriz+colunas+1, --linhas, colunas); 
    }
    else return *matriz;
}


/*
*/
char checar_diagonal_inverso(char *matriz, int linhas, int colunas){
    return *matriz;
}
