/*
Calcular a quantidade de consoantes e vogais em uma string.
*/

#include <stdio.h>
#include <ctype.h> // toupper

int eh_vogal(char letra);
int eh_consoante(char letra);
int calc_vogal(char *string);
int calc_consoante(char *string);

int main(void){
    printf("abacaxi tem %d vogais. \n", calc_vogal("abacaxi"));
    printf("abacaxi tem %d consoantes. \n", calc_consoante("abacaxi"));
    
    return 0;
}

// Retorna 1(um) se for vogal. Retorna 0(zero) se não for vogal.
int eh_vogal(char letra){
    char vogais[] = {'A', 'E', 'I', 'O', 'U', '\0'};
    char *vogal = vogais;
   
    while(*vogal != '\0'){
        if( *vogal == toupper(letra) ) return 1;
        vogal++;
    }
    
    return 0;
}

// Retorna 1(um) se for consoante. Retorna 0(zero) se não for consoante.
int eh_consoante(char letra){
    char consoantes[] = {'B', 'C', 'D', 'F', 'G', 'H', 'J', 'K', 'L', 'M', 'N',
                         'P', 'Q', 'R', 'S', 'T', 'V', 'W', 'X', 'Y', 'Z', '\0'};
    char *consoante = consoantes;
    
    while(*consoante != '\0'){
        if( *consoante == toupper(letra) ) return 1;
        consoante++;
    }
    
    return 0;
}

// Retorna a quantidade de vogais em uma string.
int calc_vogal(char *string){
    if(*string){
        if( eh_vogal(*string) ) return 1 + calc_vogal(++string);
        else return 0 + calc_vogal(++string);
    } 
    
    return 0;
}

// Retorna a quantidade de consoantes em uma string.
int calc_consoante(char *string){
    if(*string){
        if( eh_consoante(*string) ) return 1 + calc_consoante(++string);
        else return 0 + calc_consoante(++string);
    }
    
    return 0;
}

