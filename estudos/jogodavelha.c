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
char checar_ganhador(char *matriz, int linhas, int colunas);

void turno_jogador(char *matriz, int linhas, int colunas);
void turno_maquina(char *matriz, int linhas, int colunas);

int main(void){   
    // vars
    char matriz[LINHAS][COLUNAS];
    char jogadores[] = {'x', 'o'}, atual;
    char ganhador = '\0';
    int restantes = LINHAS*COLUNAS;
    
    // game loop
    reset_matriz(&matriz[0][0], LINHAS, COLUNAS);
    atual = jogadores[1];

    while(!ganhador && restantes){
        printf("\nJogadas restantes: %d\n", restantes);
        display_matriz(&matriz[0][0], LINHAS, COLUNAS);

        if(atual == 'x') turno_jogador(&matriz[0][0], LINHAS, COLUNAS);
        else turno_maquina(&matriz[0][0], LINHAS, COLUNAS);

        ganhador = checar_ganhador(&matriz[0][0], LINHAS, COLUNAS);
        if(ganhador == ' ') ganhador = '\0';

        atual = atual == 'x' ? 'o' : 'x';
        restantes--;
    }

    printf("\nFim\n");;
    printf("\nJogadas restantes: %d\n", restantes);
    display_matriz(&matriz[0][0], LINHAS, COLUNAS);
    if(ganhador) printf("\nVencedor: %c\n", ganhador);
    else printf("\nEmpate\n");
    
    return 0;
}


/*
Definir espaços vazios em cada elemento da matriz.

parametros
----------
matriz : um ponteiro para o primeiro elemento da matriz.

linhas : quantidade de linhas da matriz.

colunas : quantidade de colunas na matriz.
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
matriz : um ponteiro para o primeiro elemento da matriz.

linhas : iquantidade de linhas da matriz.

colunas : quantidade de colunas em cada linha da matriz.
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
matriz : ponteiro para o primeiro elemento da linha.

colunas : quantidade de colunas na matriz.

retorno
-------
'\0'
    (caractere nulo); se a linha não possuir elementos iguais.

char
    linha possui elementos iguais.
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
matriz : ponteiro para o primeiro elemento da coluna.

linhas : quantidade de linhas da matriz.

colunas : quantidade de colunas na matriz.

retorno
-------
'\0'
    (caractere nulo); coluna não possui elementos iguais.

char
    linha possui elementos iguais.
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
matriz : ponteiro do primeiro elemento da matriz.

linhas : quantidade de linhas na matriz.

colunas : quantidade de colunas na matriz.

retorno
-------
'\0'
    (caractere nulo); elementos na diagonal diferentes.

char
    elementos iguais na diagonal.
*/
char checar_diagonal(char *matriz, int linhas, int colunas){
    if(linhas-1){
        if(*matriz != *(matriz+colunas+1)) return '\0';
        else return checar_diagonal(matriz+colunas+1, --linhas, colunas); 
    }
    else return *matriz;
}


/*
Verificar os elementos na diagonal inversa da matriz.

parametros
----------
matriz : ponteiro do ultimo elemento da primeira linhda da matriz.

linhas : quantidade de linhas na matriz.

colunas : quantidade de colunas em cada linha.

retorno
-------
'\0'
    (caractere nulo); elementos na diagonal diferentes.

char
    elementos iguais na diagonal.
*/
char checar_diagonal_inverso(char *matriz, int linhas, int colunas){
    if(linhas-1){
        if(*matriz != *(matriz+colunas-1)) return '\0';
        else return checar_diagonal_inverso(matriz+colunas-1, --linhas, colunas);
    }
    else return *matriz;
}


/*
Realizar a jogada do jogador.

parametros
----------
matriz : ponteiro para o primeiro elemento da matriz.

linhas : quantidade de linhas da matriz.

colunas : quantidade de colunas da matriz.
*/
void turno_jogador(char *matriz, int linhas, int colunas){
    int linha, coluna;
    
    for(;;){
        printf("Informe a linha: ");
        scanf("%d", &linha);
        
        printf("Infome a coluna: ");
        scanf("%d", &coluna);
        
        /*verificar linha e coluna e se o elemento está vazio*/   
        if( (linha >= 0 && linha < LINHAS) && (coluna >= 0 && coluna < COLUNAS) )
            if( *(matriz+(linha*colunas)+coluna) == ' ' ){
                *(matriz+(linha*colunas)+coluna) = 'x';
                return;
            }
    }
}


/*
Checar todas as possibilidades por um vencedor na matriz.

parametros
----------
matriz : ponteiro para o primeiro elemento da matriz.

linhas : quantidade de linhas na matriz.

colunas : quantidade d ecolunas na matriz.

retorno
-------
'\0'
    (carctere nulo); nenhum vencedor encontrado.

char
    vencedor encontrado.
*/
char checar_ganhador(char *matriz, int linhas, int colunas){
    char *atual, *proximo;
    
    // linhas
    for(register int i=0; i<linhas; i++){
        atual = matriz+(i*colunas);
        if( checar_linha(atual, colunas) ) return *atual;
    }

    // colunas
    for(register int i=0; i<colunas; i++){
        atual = matriz+i;
        if( checar_coluna(atual, linhas, colunas) ) return *atual;
    }
    
    // diagonal
    atual = matriz;
    if( checar_diagonal(atual, linhas, colunas) ) return *atual;

    // diagonal inverso
    atual = matriz+colunas-1;
    if( checar_diagonal_inverso(atual, linhas, colunas) ) return *atual;    
    
    return '\0';
}


/*
Percorrer por toda matriz procurando um elemento disponivel p/ a maquina
realizar a jogada.

parametros
----------
matriz : ponteiro para o primeiro elemento da matriz.

linhas : quantidade de linhas da matriz.

colunas : quantidade de colunas da matriz.
*/
void turno_maquina(char *matriz, int linhas, int colunas){
    char *elemento, ganhador;
    
    for(register int i=0; i < linhas*colunas; i++){
        if( *(matriz+i) == ' ' ){
            elemento = matriz+i;
            *elemento = 'o';
            ganhador = checar_ganhador(matriz, linhas, colunas);
            if(ganhador && ganhador != ' ') return;
            else *elemento = ' ';
        }
    }
    
    *elemento = 'o';
}

